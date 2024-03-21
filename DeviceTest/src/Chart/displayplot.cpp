#include "displayplot.h"
#include "ui_displayplot.h"

displayplot::displayplot(QMap<QString, QString> communication_info,QWidget *parent) :
    QMainWindow(parent),m_filter_work(TOTAL_CH_NUM),
    ui(new Ui::displayplot)
{
    ui->setupUi(this);
    m_communication_info = communication_info;
    {//处理导联选择
        connect(ui->m_channel_1, &QAction::triggered, this, &displayplot::handleChannelClicked);
        connect(ui->m_channel_2, &QAction::triggered, this, &displayplot::handleChannelClicked);
        connect(ui->m_channel_3, &QAction::triggered, this, &displayplot::handleChannelClicked);
        connect(ui->m_channel_4, &QAction::triggered, this, &displayplot::handleChannelClicked);
        connect(ui->m_channel_5, &QAction::triggered, this, &displayplot::handleChannelClicked);
        connect(ui->m_channel_6, &QAction::triggered, this, &displayplot::handleChannelClicked);
        connect(ui->m_channel_7, &QAction::triggered, this, &displayplot::handleChannelClicked);
        connect(ui->m_channel_8, &QAction::triggered, this, &displayplot::handleChannelClicked);
        connect(ui->m_channel_all, &QAction::triggered, this, &displayplot::handleChannelClicked);
    }
    {//处理采样率
        connect(ui->m_sampling_250, &QAction::triggered, this, &displayplot::handleSamplingClicked);
        connect(ui->m_sampling_500, &QAction::triggered, this, &displayplot::handleSamplingClicked);
        connect(ui->m_sampling_1000, &QAction::triggered, this, &displayplot::handleSamplingClicked);
    }
    {//通信
        if(m_communication_info.value("inf_method") == "TCP"){
            m_tcpcommunicate.moveToThread(&m_thread_tcpcommunicate);
            connect(this,&displayplot::startConnectServer,&m_tcpcommunicate,&tcpcommunicate::ConnectServer);
            m_thread_tcpcommunicate.start();
            int port = m_communication_info.value("inf_port").toInt();
            QString ip = m_communication_info.value("inf_ip");
            emit startConnectServer(port,ip);
        }else if(m_communication_info.value("inf_method") == "UDP"){

        }else if(m_communication_info.value("inf_method") == "串口"){

        }
    }
    {//保存
//        FileSave m_filesave;
//        m_filesave.moveToThread(&m_thread_filesave);


    }

    {//绘图
        //导联默认导联1
        ui->m_channel_1->setCheckable(true);
        ui->m_channel_1->setChecked(true);
        ui->m_chart->SetChIndex(0);
        //采样率默认1000
        ui->m_sampling_1000->setCheckable(true);
        ui->m_sampling_1000->setChecked(true);
        ui->m_chart->SetSamplingFrqe(Freq1000);
        emit sig_Set_filter_sampling(Freq1000);
        //原始数据传输
        connect(&m_tcpcommunicate,&tcpcommunicate::sig_recv_ch_data,ui->m_chart,&ChartWork::AddPoints);
        m_plotinf.SetCurrentChartData(ui->m_chart->GetChartSettingData());

        //        connect(ui->m_chart, &ChartWork::sig_Total_Ch_yRange_change, this, [ = ](int yRange)
        //        {
        //            ui->m_label_total_ch_yRange->setText("显示范围：" + QString::number(yRange));
        //        });

    }
    {//滤波
        connect(this,&displayplot::sig_filter_on,this,[=](){
            if(m_filter_inf.value("inf_enable") == 1){//开启滤波
                qDebug()<<"启动了滤波";
                m_filter_work.moveToThread(&m_thread_filter);
                connect(this,&displayplot::sig_Set_filter_sampling,&m_filter_work,&filterWork::SetSamplingFreq);
                connect(&m_tcpcommunicate,&tcpcommunicate::sig_recv_ch_data,&m_filter_work,&filterWork::DoFilter);
                m_filter_work.OnFilterEnabled(true);
                if(m_filter_inf.value("inf_lowpass") != -1){
                    m_filter_work.OnFilterLowPassEnalbed(true);
                    m_filter_work.OnFilterChanged(0, m_filter_order, QVector<double> {m_filter_inf.value("inf_lowpass"), 0}, FilterType::Lowpass);
                }else{
                    m_filter_work.OnFilterLowPassEnalbed(false);
                }
                if(m_filter_inf.value("inf_highpass") != -1){
                    m_filter_work.OnFilterHighPassEnabled(true);
                    m_filter_work.OnFilterChanged(1, m_filter_order, QVector<double> {m_filter_inf.value("inf_highpass"), 0}, FilterType::Highpass);
                }else{
                    m_filter_work.OnFilterHighPassEnabled(false);
                }
                if(m_filter_inf.value("inf_notch") != -1){
                    m_filter_work.OnFilterNotchEnabled(true);
                    m_filter_work.OnFilterChanged(2, m_filter_order, QVector<double> {m_filter_inf.value("inf_notch")-0.1, m_filter_inf.value("inf_notch")+0.1}, FilterType::Bandstop);
                }else{
                    m_filter_work.OnFilterNotchEnabled(false);
                }
                if(m_filter_inf.value("inf_highpass_impen") != -1){
                    m_filter_work.OnFilterHighPassImpenEnabled(true);
                    m_filter_work.OnFilterChanged(3, m_filter_order, QVector<double> {m_filter_inf.value("inf_highpass_impen"), 0}, FilterType::Highpass);

                }else{
                    m_filter_work.OnFilterHighPassImpenEnabled(false);
                }
                connect(&m_filter_work, &filterWork::sig_Filter_output, ui->m_chart, &ChartWork::AddPoints);
                m_thread_filter.start();
            }else{//关闭滤波
                m_filter_work.OnFilterEnabled(false);
            }
        });
    }
}

displayplot::~displayplot()
{
    delete ui;
    m_thread_filter.quit();
    m_thread_filter.wait();

    m_thread_tcpcommunicate.quit();
    m_thread_tcpcommunicate.wait();
}

void displayplot::handleChannelClicked()
{
    QAction* action = qobject_cast<QAction*>(sender()); // 获取发送信号的QAction对象
    if (action)
    {
        foreach (QAction* otherAction, ui->m_channel->actions())
        {
            if (otherAction != action)
            {
                otherAction->setChecked(false);
            }
        }
        QString m_actionText = action->text();
        QString m_action_number = m_actionText.mid(m_actionText.indexOf("：") + 1);
        int m_channel_number;
        if(m_action_number == "全部")
        {
            m_channel_number = 8;
        }else{
            m_channel_number = m_action_number.toInt()-1;
        }
        ui->m_chart->SetChIndex(m_channel_number);
        action->setCheckable(true);
        action->setChecked(true);
    }
}

void displayplot::handleSamplingClicked()
{
    QAction* action = qobject_cast<QAction*>(sender()); // 获取发送信号的QAction对象
    if (action)
    {
        foreach (QAction* otherAction, ui->m_sampling->actions())
        {
            if (otherAction != action)
            {
                otherAction->setChecked(false);
            }
        }
        QString m_actionText = action->text();
        quint32 freq = m_actionText.toInt();
        //波特率
        switch (freq)
        {
        case 250:
            ui->m_chart->SetSamplingFrqe(Freq250);
            emit sig_Set_filter_sampling(Freq250);
            break;
        case 500:
            ui->m_chart->SetSamplingFrqe(Freq500);
            emit sig_Set_filter_sampling(Freq500);
            break;
        case 1000:
            ui->m_chart->SetSamplingFrqe(Freq1000);
            emit sig_Set_filter_sampling(Freq1000);
            break;
        default:
            QMessageBox::critical(this, "error", "采样率设置错误！");
            break;
        }
        action->setCheckable(true);
        action->setChecked(true);
    }
}

void displayplot::setCurrentChartData()
{
    m_plotinf.SetCurrentChartData(ui->m_chart->GetChartSettingData());
}

void displayplot::revCurrentChartData(ChartSettingData chart_setting_data)
{
    m_chart_setting_data = chart_setting_data;
    //绘图设计中的数据变了，图也跟着变
    ui->m_chart->ChartSettingChange(m_chart_setting_data);
}

void displayplot::revCurrent_Filter_inf(QMap<QString, double> filter_inf)
{
    m_filter_inf = filter_inf;
    emit sig_filter_on();
}

//void displayplot::paintEvent(QPaintEvent *event)
//{
//    ui->m_chart->update();
//    displayplot::paintEvent(event);
//}
