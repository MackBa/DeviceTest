#include "chartwork.h"

#ifdef QCUSTOMPLOT
ChartWork::ChartWork(QWidget* parent)
    : QCustomPlot{parent}, m_total_ch_ticket(new QCPAxisTickerText), m_single_ch_ticket(new QCPAxisTicker)
{
    for(int i = 0; i < TOTAL_CH_NUM; i++)
    {
        addGraph();
        y.append(QVector<double> {});
    }
    m_update_timer.setInterval(20);
    connect(&m_update_timer, &QTimer::timeout, this, &ChartWork::UpdataData);
    m_update_timer.start();
    ChartSettingChange(m_chart_setting_data);

    {
        //ticket初始化
        m_single_ch_ticket->setTickCount(5);
        UpDataTotalChTicket();
    }
    yAxis->setRange(m_chart_setting_data.YMin, m_chart_setting_data.YMax );


}

void ChartWork::AddPoints(QVector<float> ch_data)
{
    if(x.size() > m_chart_setting_data.XRange * m_freq)
    {
        x.pop_front();
        for(int i = 0; i < TOTAL_CH_NUM; i++)
        {
            y[i].pop_front();
        }
    }

    assert(y.size() == TOTAL_CH_NUM);
    x.append(double(m_current_frame++) / m_freq);
    for(int i = 0; i < TOTAL_CH_NUM; i++)
    {
        y[i].append(ch_data[i]);
    }
}

void ChartWork::SetChIndex(int index)
{
    m_ch_plot_index = index;

    for(int i = 0; i < TOTAL_CH_NUM; i++)
    {
        graph(i)->data().data()->clear();
    }

    if(index < TOTAL_CH_NUM)
    {
        yAxis->setRange(m_chart_setting_data.YMin, m_chart_setting_data.YMax );
        yAxis->setTicker(m_single_ch_ticket);
    }
    else
    {
        UpDataTotalChTicket();
        yAxis->setTicker(m_total_ch_ticket);
        emit sig_Total_Ch_yRange_change(m_y_range);
    }
    replot();
}

void ChartWork::SetSamplingFrqe(SamplingFreq freq)
{
    m_freq = freq;
}

void ChartWork::ChartSettingChange(ChartSettingData chart_setting)
{
    m_chart_setting_data = chart_setting;
    double x_begin = x.size() == 0 ? 0 : x[0];
    xAxis->setRange(x_begin, x_begin + m_chart_setting_data.XRange);
    if(!m_chart_setting_data.AllChannelEnable)
    {
        if(!m_chart_setting_data.AutoAdjust)
        {
            yAxis->setRange(m_chart_setting_data.YMin, m_chart_setting_data.YMax );
        }
    }
    replot();
}

ChartSettingData ChartWork::GetChartSettingData()
{
    return m_chart_setting_data;
}

void ChartWork::StopPlot()
{
    m_update_timer.stop();
}

void ChartWork::StartPlot()
{
    m_update_timer.start();
}

void ChartWork::ClearPlot()
{
    x.clear();
    m_current_frame = 0;
    for(int i = 0; i < TOTAL_CH_NUM; i++)
    {
        y[i].clear();
        graph(i)->data().data()->clear();
    }
    ChartSettingChange(m_chart_setting_data);
    replot();
}

void ChartWork::wheelEvent(QWheelEvent* event)
{
    if(event->angleDelta().y() > 0)
    {
        m_y_range -= WHEEL_STEP;
    }
    else
    {
        m_y_range += WHEEL_STEP;
    }
    m_y_range = m_y_range < 10 ? 10 : m_y_range;
    if(m_ch_plot_index >= TOTAL_CH_NUM)
    {
        UpDataTotalChTicket();
        emit sig_Total_Ch_yRange_change(m_y_range);
    }
}

void ChartWork::UpdataData()
{
    if(x.isEmpty())
    {
        return;
    }
    if(m_ch_plot_index < TOTAL_CH_NUM)
    {
        graph(m_ch_plot_index)->setData(x, y[m_ch_plot_index]);
        //设置坐标轴标签
        //    xAxis->setLabel("x");
        //    yAxis->setLabel("y");
        //    double x_begin = x.size() == 0 ? 0 : x[0];
        xAxis->setRange(x[0], x[0] + m_chart_setting_data.XRange);

        if(m_chart_setting_data.AutoAdjust)
        {
            float _y_min = *std::min_element(std::begin(y[m_ch_plot_index]), std::end(y[m_ch_plot_index]));
            float _y_max = *std::max_element(std::begin(y[m_ch_plot_index]), std::end(y[m_ch_plot_index]));
            float _range = (_y_max - _y_min) * 0.125;
            yAxis->setRange(_y_min - _range, _y_max + _range );
        }
    }
    else
    {
        static QList<double> _tmp_y;
        //绘制所有曲线
        xAxis->setRange(x[0], x[0] + m_chart_setting_data.XRange);
        for(int i = 0; i < TOTAL_CH_NUM; i++)
        {
            _tmp_y.clear();
            for(auto iter = y[i].begin(); iter != y[i].end(); iter++)
            {
                _tmp_y.push_back(*iter - 2 * m_y_range * i);
            }
            graph(i)->setData(x, _tmp_y);
        }
    }

    replot();
}

void ChartWork::UpDataTotalChTicket()
{
    m_total_ch_ticket->clear();
    QVector<double> ticks;
    QVector<QString> labels;//坐标轴定制

    for(int i = 0; i < TOTAL_CH_NUM; i++)
    {
        ticks.push_back(-2 * m_y_range * i);
        labels.push_back(QString("ch") + QString::number(i + 1));
    }
    m_total_ch_ticket->addTicks(ticks, labels);

    yAxis->setRange(-2 * m_y_range * TOTAL_CH_NUM + m_y_range, m_y_range);
    replot();
}
#else
ChartWork::ChartWork(QWidget* parent)
    : QChartView(parent)
{
    initChart();
    for(int i = 0; i < TOTAL_CH_NUM; i++)
    {
        m_point_data.append(QList<QPointF> {});
    }

    m_update_timer.setInterval(20);
    connect(&m_update_timer, &QTimer::timeout, this, &ChartWork::UpdataData);
    m_update_timer.start();
}

ChartWork::~ChartWork()
{
    if (m_chart != nullptr)
    {
        m_chart->deleteLater();
    }
    if (m_spline_series != nullptr)
    {
        m_spline_series->deleteLater();
    }
    if (m_axisY != nullptr)
    {
        m_axisY->deleteLater();
    }
    if (m_axisX != nullptr)
    {
        m_axisX->deleteLater();
    }
}

void ChartWork::AddPoints(QVector<float> ch_data)
{
    if(m_point_data[0].size() > m_chart_setting_data.XRange * m_freq)
    {
        for(int i = 0; i < TOTAL_CH_NUM; i++)
        {
            m_point_data[i].pop_front();
        }
    }

    double _x = double(m_current_frame++) / m_freq;
    for(int i = 0; i < TOTAL_CH_NUM; i++)
    {
        m_point_data[i].append(QPointF(_x, ch_data[i]));
    }
}

void ChartWork::SetChIndex(int index)
{
    m_ch_plot_index = index;
}

void ChartWork::SetSamplingFrqe(SamplingFreq freq)
{
    m_freq = freq;
}

void ChartWork::ChartSettingChange(ChartSettingData chart_setting)
{
    m_chart_setting_data = chart_setting;

    if(m_point_data[0].isEmpty())
    {
        m_axisX->setRange(0, m_chart_setting_data.XRange);
    }
    else
    {
        m_axisX->setRange(m_point_data[0].front().x(), m_point_data[0].front().x() + m_chart_setting_data.XRange);
    }

    if(!m_chart_setting_data.AutoAdjust)
    {
        m_axisY->setRange(m_chart_setting_data.YMin, m_chart_setting_data.YMax);
    }
}

ChartSettingData ChartWork::GetChartSettingData()
{
    return m_chart_setting_data;
}

void ChartWork::StopPlot()
{
    m_update_timer.stop();
}

void ChartWork::StartPlot()
{
    m_update_timer.start();
}

void ChartWork::UpdataData()
{
    if(m_point_data[0].isEmpty())
    {
        return;
    }
    m_axisX->setRange(m_point_data[m_ch_plot_index].front().x(), m_point_data[m_ch_plot_index].front().x() + m_chart_setting_data.XRange);

    if(m_chart_setting_data.AutoAdjust)
    {
        float _min = m_point_data[m_ch_plot_index][0].y();
        float _max = m_point_data[m_ch_plot_index][0].y();
        for(auto iter = m_point_data[m_ch_plot_index].begin(); iter != m_point_data[m_ch_plot_index].end(); iter++)
        {
            _min = iter->y() < _min ? iter->y() : _min;
            _max = iter->y() > _max ? iter->y() : _max;
        }
        float _range = (_max - _min) * 0.125;
        m_axisY->setRange(_min - _range, _max + _range);
    }
    m_spline_series->replace(m_point_data[m_ch_plot_index]);
}

void ChartWork::initChart()
{
    if (m_chart == nullptr)
    {
        m_chart = new QChart();
        m_chart->setAnimationOptions(QChart::NoAnimation);
        // 将Chart添加到ChartView
        this->setChart(m_chart);
        this->setRenderHint(QPainter::Antialiasing);
        m_chart->legend()->setVisible(false);
        // 设置图表主题色
        //            ui->graphicsView->chart()->setTheme(QChart::ChartTheme(0));
    }
    if (m_spline_series == nullptr)
    {
        m_spline_series = new QSplineSeries(m_chart);
        m_spline_series->setUseOpenGL(true);
        m_chart->addSeries(m_spline_series);
    }
    if (m_axisY == nullptr)
    {
        m_axisY = new QValueAxis(m_chart);
        m_axisY->setRange(m_chart_setting_data.YMin, m_chart_setting_data.YMax);
        m_chart->addAxis(m_axisY, Qt::AlignLeft);
        m_spline_series->attachAxis(m_axisY);
    }
    if (m_axisX == nullptr)
    {
        m_axisX = new QValueAxis(m_chart);
        m_axisX->setRange(0, m_chart_setting_data.XRange);
        m_chart->addAxis(m_axisX, Qt::AlignBottom);
        m_spline_series->attachAxis(m_axisX);
    }
}
#endif


