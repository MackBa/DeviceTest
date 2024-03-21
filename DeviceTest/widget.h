#ifndef WIDGET_H
#define WIDGET_H

#include <QMap>
#include <QWidget>
#include "src/Template/newtemplate.h"
#include "src/Template/readtemplate.h"
#include "src/Template/plotinf.h"
#include "src/Chart/chartwork.h"
#include "src/Chart/displayplot.h"
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
private slots:
    void on_m_btn_newTemplate_clicked();

    void on_m_btn_readTemplate_clicked();

private:
    Ui::Widget *ui;
    QMap<QString, QPoint> m_template_position_infos;
    QMap<QString, QMap<QString, QString>> m_template_setting_infos;
    bool m_is_newtemplate = false;

    ChartSettingData m_chart_setting_data;
    QMap<QString,double> m_filter_inf;


};
#endif // WIDGET_H
