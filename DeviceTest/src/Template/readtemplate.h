#ifndef READTEMPLATE_H
#define READTEMPLATE_H

#include <QWidget>
#include <QLabel>
#include <QMap>
#include <QPoint>
#include "src/Chart/displayplot.h"
namespace Ui {
class readtemplate;
}

class readtemplate : public QWidget
{
    Q_OBJECT

public:
    explicit readtemplate(QWidget *parent = nullptr);
    ~readtemplate();
    void m_showtemplate(QMap<QString, QPoint> m_template_position_infos, QMap<QString, QString> communication_info);
    void revChartData(ChartSettingData chart_Data);
    void revFilterData(QMap<QString,double> filter_inf);
private slots:
    void on_m_btn_operation_clicked();

private:
    Ui::readtemplate *ui;
    QMap<QString, QString> m_communication_info;
    ChartSettingData m_chart_setting_data;
    QMap<QString,double> m_filter_inf;
};

#endif // READTEMPLATE_H
