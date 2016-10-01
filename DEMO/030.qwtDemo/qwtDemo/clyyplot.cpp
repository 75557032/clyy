#include <qwt_plot_spectrogram.h>
#include <qwt_color_map.h>
#include <qwt_scale_widget.h>
#include "clyyplot.h"

class clyySpectrogramData: public QwtRasterData
{
public:
    clyySpectrogramData()
    {
    }

    virtual double value(double x, double y) const
    {
        if (NULL == m_Func) {
            return 0;
        }
        return m_Func(x, y);
    }

public:
    void setFunc(clyyPlotDataFunc func)
    {
        m_Func = func;
    }
    void setAxisMinMax(Qt::Axis axisid, double min, double max)
    {
        setInterval(axisid, QwtInterval(min, max));
    }

private:
    clyyPlotDataFunc m_Func = NULL;
};

class clyyLinearColorMapIndexed: public QwtLinearColorMap
{
public:
    clyyLinearColorMapIndexed():
        QwtLinearColorMap(QwtColorMap::Indexed)
    {

    }
};

clyyPlot::clyyPlot(const QwtText &title, QWidget *w) :
    QwtPlot(title, w),
    m_pSpectrogram(new QwtPlotSpectrogram),
    m_pSpectrogramData(new clyySpectrogramData),
    m_pLinearColorMap(new clyyLinearColorMapIndexed),
    m_pAxisLinearColorMap(new clyyLinearColorMapIndexed)
{
    m_pSpectrogram->setData(m_pSpectrogramData);
    m_pSpectrogram->setColorMap(m_pLinearColorMap);
    QwtScaleWidget *axis = axisWidget(QwtPlot::yRight);
    const QwtInterval zInterval = m_pSpectrogram->data()->interval(Qt::ZAxis);
    axis->setColorMap(zInterval, m_pAxisLinearColorMap);
    QwtScaleWidget *rightAxis = axisWidget(QwtPlot::yRight);
    rightAxis->setTitle(QString::fromLocal8Bit("图例"));
    rightAxis->setColorBarEnabled(true);
    setAxisScale(QwtPlot::yRight, zInterval.minValue(), zInterval.maxValue());
    enableAxis(QwtPlot::yRight);
    m_pSpectrogram->attach(this);
}

clyyPlot::~clyyPlot()
{
    delete m_pSpectrogram;
}

void clyyPlot::setFunc(clyyPlotDataFunc func)
{
    m_pSpectrogramData->setFunc(func);
}

void clyyPlot::setAxisMinMax(Qt::Axis axisid, double min, double max)
{
    m_pSpectrogramData->setAxisMinMax(axisid, min, max);
}

void clyyPlot::setBeginEndColor(const QColor &color1, const QColor &color2)
{
    m_pLinearColorMap->setColorInterval(color1, color2);
    m_pAxisLinearColorMap->setColorInterval(color1, color2);
}

void clyyPlot::addColorStop(double value, const QColor &color)
{
    m_pLinearColorMap->addColorStop(value, color);
    m_pAxisLinearColorMap->addColorStop(value, color);
}
