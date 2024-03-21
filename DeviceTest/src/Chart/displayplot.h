#ifndef DISPLAYPLOT_H
#define DISPLAYPLOT_H

#include <QMainWindow>
#include <QMap>
#include <QThread>
#include "chartwork.h"
#include "src/Template/plotinf.h"
#include "src/Communicate/tcpcommunicate.h"
#include "ConstData.h"
#include "src/Filter/filterwork.h"
//#include "src/FileSave/filesave.h"

namespace Ui {
class displayplot;
}

class displayplot : public QMainWindow
{
    Q_OBJECT

public:
    explicit displayplot(QMap<QString, QString> communication_info,QWidget *parent = nullptr);
    ~displayplot();
    void handleChannelClicked();
    void handleSamplingClicked();
    void setCurrentChartData();
    void revCurrentChartData(ChartSettingData chart_setting_data);
    void revCurrent_Filter_inf(QMap<QString,double> filter_inf);
signals:
    void sig_Set_filter_sampling(SamplingFreq);
    void sig_filter_on();
    void startConnectServer(unsigned short port, QString ip);
private:
    Ui::displayplot *ui;
private:
    int m_filter_order = 2;
private:

    QMap<QString, QString> m_communication_info;
    plotinf m_plotinf;
    ChartSettingData m_chart_setting_data;
    QMap<QString,double> m_filter_inf;
    //tcp通信
    tcpcommunicate m_tcpcommunicate;
    QThread m_thread_tcpcommunicate;
    //保存
    QThread m_thread_filesave;
    //滤波
    filterWork m_filter_work;
    QThread m_thread_filter;


    // QWidget interface
//protected:
//    void paintEvent(QPaintEvent *event);
};

#endif // DISPLAYPLOT_H
