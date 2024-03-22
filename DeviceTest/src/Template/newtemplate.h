#ifndef NEWTEMPLATE_H
#define NEWTEMPLATE_H

#include <QMainWindow>
#include <QCloseEvent>
#include <QPoint>
#include <QPushButton>
#include "information.h"
#include "plotinf.h"
#include "mytemplate.h"
#include "src/FileSave/filemodule.h"
#include "src/Communicate/tcpmodule.h"
#include "src/Filter/filtermodule.h"
namespace Ui {
class newtemplate;
}

class newtemplate : public QMainWindow
{
    Q_OBJECT

public:
    explicit newtemplate(QWidget *parent = nullptr);
    ~newtemplate();

protected:
    void closeEvent(QCloseEvent *event) override;

public:
    void m_new_lab_template(QMap<QString, QString> m_information);
    void m_open_settingDiglog();
    void m_delete_template(QString m_delete_inf_text);
    void m_show_already_template(QMap<QString, QPoint> m_labels_position_infos,QMap<QString, QMap<QString, QString>> m_labels_setting_infos);
public:
    void m_communication_TCP_template();
    void m_communication_UDP_template();
    void m_communication_serialport_template();
    void m_filter_template();
    void m_save_template();
    void m_plot_template();
    void m_impedance_template();
    void m_other_template();
signals:
    void m_newtemplate_close(QMap<QString, QPoint> m_labels_position_infos,QMap<QString, QMap<QString, QString>> m_labels_setting_infos);
    void m_send_information(QMap<QString, QString> m_information);
    void m_save_information(QMap<QString, QString> m_information);
    void m_send_setCurrentChartData();
    void m_newtemplate_send_chartSettingData(ChartSettingData);
    void m_newtemplate_send_filter_inf(QMap<QString,double>);
private:
    Ui::newtemplate *ui;
    QMap<QString, QString> m_rev_information;
    QVector<QLabel*> m_labels;
    QMap<QString, QMap<QString, QString>> m_template_setting_infos;
    QMap<QString, QPoint> m_template_position_infos;
};

#endif // NEWTEMPLATE_H
