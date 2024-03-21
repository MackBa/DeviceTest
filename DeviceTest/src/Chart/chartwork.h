#ifndef CHARTWORK_H
#define CHARTWORK_H
#define QCUSTOMPLOT

#include <QTimer>
#include "ConstData.h"
#include "src/Template/plotinf.h"
#ifdef QCUSTOMPLOT
#include "qcustomplot.h"
#include <QWheelEvent>
#define WHEEL_STEP 10

class ChartWork : public QCustomPlot
{
    Q_OBJECT
public:
    explicit ChartWork(QWidget* parent = nullptr);

    void AddPoints(QVector<float> ch_data);

    void SetChIndex(int index);

    void SetSamplingFrqe(SamplingFreq freq);

    void ChartSettingChange(ChartSettingData chart_setting);

    ChartSettingData GetChartSettingData();

    void StopPlot();

    void StartPlot();

    void ClearPlot();
public:
    void wheelEvent(QWheelEvent* event);
private:
    quint64 m_current_frame = 0;
    QVector<QVector<double>> y;
    QVector<double> x;

    int m_ch_plot_index = 0;
    SamplingFreq m_freq = SamplingFreq::Freq1000;

    QTimer m_update_timer;
    void UpdataData();

    ChartSettingData m_chart_setting_data;

    double m_y_range = 50;
    QSharedPointer<QCPAxisTickerText> m_total_ch_ticket;
    QSharedPointer<QCPAxisTicker> m_single_ch_ticket;
    void UpDataTotalChTicket();
signals:
    void sig_Total_Ch_yRange_change(int yRange);
};
#else
#include <QtCharts>
#include <QChart>
#include <QLegendMarker>
#include <QPointF>
#include <QSplineSeries>
#include <QTimer>
#include <QValueAxis>
#include <QChartView>
class ChartWork : public QChartView
{
    Q_OBJECT
public:
    explicit ChartWork(QWidget* parent = nullptr);
    ~ChartWork();

    void AddPoints(QVector<float> ch_data);

    void SetChIndex(int index);

    void SetSamplingFrqe(SamplingFreq freq);

    void ChartSettingChange(ChartSettingData chart_setting);

    ChartSettingData GetChartSettingData();

    void StopPlot();

    void StartPlot();
private:
    quint64 m_current_frame = 0;

    int m_ch_plot_index = 0;
    SamplingFreq m_freq = SamplingFreq::Freq1000;

    QTimer m_update_timer;
    void UpdataData();

    ChartSettingData m_chart_setting_data;

    QChart*          m_chart         = nullptr;
    QSplineSeries*   m_spline_series = nullptr;
    QValueAxis*      m_axisY         = nullptr;
    QValueAxis*      m_axisX         = nullptr;
    QVector<QList<QPointF>>   m_point_data;
    void             initChart();

signals:

};
#endif

#endif // CHARTWORK_H
