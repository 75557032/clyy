#include <lusb0_usb.h>
#include <QDebug>
#include "mainwindow.h"
#include "ui_mainwindow.h"

void sing_setting(usb_dev_handle *udev, struct usb_interface_descriptor &altinterface)
{
    qDebug() << "usb_set_altinterface:"  << usb_set_altinterface(udev, altinterface.bAlternateSetting);
    for (int i = 0; i < altinterface.bNumEndpoints; ++i) {
        unsigned char ep = altinterface.endpoint[i].bEndpointAddress;
        if (ep & 0x80) {
            char temp[64] = {0x00};
            qDebug() << "ep_count:" << altinterface.endpoint[i].bmAttributes;
            qDebug() << "usb_clear_halt:"  << usb_clear_halt(udev, ep);
            qDebug() << QString::fromLocal8Bit(usb_strerror());
            qDebug() << "usb_bulk_read:"  << usb_bulk_read(udev, ep, temp, 64, 5000);
            qDebug() << QString::fromLocal8Bit(usb_strerror());
        }
    }
}


void sing_interface(usb_dev_handle *udev, struct usb_interface &interface)
{
    qDebug() << "usb_claim_interface:"  << usb_claim_interface(udev, interface.altsetting[0].bInterfaceNumber);
    for (int i = 0; i < interface.num_altsetting; ++i) {
        sing_setting(udev, interface.altsetting[i]);
    }
    qDebug() << "usb_release_interface:"  << usb_release_interface(udev, interface.altsetting[0].bInterfaceNumber);
}

void sing_config(usb_dev_handle *udev, struct usb_config_descriptor &config)
{
    qDebug() << "usb_set_configuration:" << usb_set_configuration(udev, config.bConfigurationValue);
    for (int i = 0; i < config.bNumInterfaces; ++i) {
        sing_interface(udev, config.interface[i]);
    }
}

void sing_usb(struct usb_device *dev)
{
    usb_dev_handle *udev;
    udev = usb_open(dev);
    if (udev) {
        for (int i = 0; i < dev->descriptor.bNumConfigurations; ++i) {
            sing_config(udev, dev->config[i]);
        }
        usb_close(udev);
    }
}

void init_usb()
{
    usb_init();
    usb_find_busses();
    usb_find_devices();
    for (struct usb_bus *bus = usb_busses; bus; bus = bus->next) {
        for (struct usb_device *dev = bus->devices; dev; dev = dev->next) {
            sing_usb(dev);
        }
    }
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    init_usb();
}

MainWindow::~MainWindow()
{
    delete ui;
}
