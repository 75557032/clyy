#include <QDebug>
#include <libusb-1.0/libusb.h>
#include "mainwindow.h"
#include "ui_mainwindow.h"

#define VID 0x04B4
#define PID 0x00F1

void sing_setting(libusb_device_handle *dev_handle, const struct libusb_interface_descriptor *setting)
{
    for (int i = 0; i < setting->bNumEndpoints; ++i) {
        if (0x80 & setting->endpoint[i].bEndpointAddress) {
            int max = setting->endpoint[i].wMaxPacketSize;
            unsigned char *data = new unsigned char[max];
            int actual_length = 0;
            bool find = false;
            while (!find) {
                libusb_bulk_transfer(dev_handle, setting->endpoint[i].bEndpointAddress, data, max, &actual_length, 5000);
                for (int j = 0; j < max; ++j) {
                    if (0x5A == data[j]) {
                        find = true;
                    }
                    if (find) {
                        qDebug("0x%x", data[j]);
                    }
                }
            }
            delete[] data;
        }
    }
}

void sing_interface(libusb_device_handle *dev_handle, const struct libusb_interface *inter)
{
    for (int i = 0; i < inter->num_altsetting; ++i) {
        libusb_set_interface_alt_setting(dev_handle, inter->altsetting[i].bAlternateSetting,
                                         inter->altsetting[i].bAlternateSetting);
        sing_setting(dev_handle, &inter->altsetting[i]);
    }
}

void sing_config(libusb_device_handle *dev_handle, struct libusb_config_descriptor *config)
{
    for (int i = 0; i < config->bNumInterfaces; ++i) {
        libusb_claim_interface(dev_handle, config->interface[i].altsetting->bInterfaceNumber);
        sing_interface(dev_handle, &config->interface[i]);
        libusb_release_interface(dev_handle, config->interface[i].altsetting->bInterfaceNumber);
    }
}

void sing_dev(libusb_device *dev)
{
    struct libusb_device_descriptor desc;
    libusb_get_device_descriptor(dev, &desc);
    if ((PID == desc.idProduct) && (VID == desc.idVendor)) {
        libusb_device_handle *dev_handle = NULL;
        libusb_open(dev, &dev_handle);
        for (int i = 0; i < desc.bNumConfigurations; ++i) {
            struct libusb_config_descriptor *config = NULL;
            libusb_get_config_descriptor(dev, i, &config);
            libusb_set_configuration(dev_handle, config->bConfigurationValue);
            sing_config(dev_handle, config);
            libusb_free_config_descriptor(config);
        }
        libusb_close(dev_handle);
    }
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    libusb_context *ctx = NULL;
    libusb_init(&ctx);
    libusb_device **list = NULL;
    int dev_count = libusb_get_device_list(ctx, &list);
    for (int i = 0; i < dev_count; ++i) {
        libusb_device *dev = list[i];
        sing_dev(dev);
    }
    libusb_free_device_list(list, 1);
    libusb_exit(ctx);
}

MainWindow::~MainWindow()
{
    delete ui;
}
