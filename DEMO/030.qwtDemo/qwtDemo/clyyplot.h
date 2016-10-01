#ifndef CLYYPLOT_H
#define CLYYPLOT_H

#include <QObject>
#include <qwt_plot.h>

class QwtPlotSpectrogram;
class clyySpectrogramData;
class clyyLinearColorMapIndexed;

typedef double (*clyyPlotDataFunc)(double x, double y);

class clyyPlot : public QwtPlot
{
    Q_OBJECT

public:
    clyyPlot(const QwtText &title, QWidget *w = NULL);
    ~clyyPlot();
    void setFunc(clyyPlotDataFunc func);
    void setAxisMinMax(Qt::Axis axisid, double min, double max);
    void setBeginEndColor(const QColor &color1, const QColor &color2);
    void addColorStop(double value, const QColor& color);

private:
    QwtPlotSpectrogram *m_pSpectrogram;
    clyySpectrogramData *m_pSpectrogramData;
    clyyLinearColorMapIndexed *m_pLinearColorMap;
    clyyLinearColorMapIndexed *m_pAxisLinearColorMap;
};

#endif // CLYYPLOT_H
