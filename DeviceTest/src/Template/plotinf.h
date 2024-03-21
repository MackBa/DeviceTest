#ifndef PLOTINF_H
#define PLOTINF_H

#include <QDialog>
#include <QObject>
#include <QMessageBox>
#include <QMap>

struct ChartSettingData
{
    double YMax   = 50;
    double YMin   = -50;
    double XRange = 5;
    bool AutoAdjust = true;
    bool AllChannelEnable = false;
};

namespace Ui {
class plotinf;
}

class plotinf : public QDialog
{
    Q_OBJECT

public:
    explicit plotinf(QWidget *parent = nullptr);
    ~plotinf();
public:
    void m_rev_information_line(QMap<QString, QString> m_rev_settings_information);
    void SetCurrentChartData( ChartSettingData current_data );
    void SetAllChannelEnabled(bool enable);
    ChartSettingData getCurrentChartData();
private slots:
    void on_m_btn_sure_clicked();
    void on_m_btn_return_clicked();
    void on_m_btn_deletemodule_clicked();
    void on_m_autoadjust_clicked(bool checked);

    void on_m_inf_ymax_valueChanged(double arg1);

    void on_m_inf_ymin_valueChanged(double arg1);

    void on_m_inf_xrange_valueChanged(double arg1);

signals:
    void m_send_information(QMap<QString, QString> m_settings_information);
    void m_delete_module();
    void m_plot_send_chartSettingData(ChartSettingData);
private:
    Ui::plotinf *ui;

private:
    ChartSettingData m_chart_data;
    QMap<QString, QString> m_settings_information;
};

#endif // PLOTINF_H
