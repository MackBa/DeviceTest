#include "plotinf.h"
#include "ui_plotinf.h"


plotinf::plotinf(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::plotinf)
{
    ui->setupUi(this);
    setWindowTitle( "绘图设置" );
    ui->m_inf_xrange->setValue( m_chart_data.XRange );
    ui->m_inf_ymax->setValue( m_chart_data.YMax );
    ui->m_inf_ymin->setValue( m_chart_data.YMin );
    ui->m_autoadjust->setChecked(m_chart_data.AutoAdjust);
    if(m_chart_data.AutoAdjust == true){
        ui->m_inf_ymax->setEnabled(false);
        ui->m_inf_ymin->setEnabled(false);
    }else{
        ui->m_inf_ymax->setEnabled(true);
        ui->m_inf_ymin->setEnabled(true);
    }
}

plotinf::~plotinf()
{
    delete ui;
}


void plotinf::m_rev_information_line(QMap<QString, QString> m_rev_settings_information)
{
    m_settings_information = m_rev_settings_information;
    m_chart_data.YMax = m_settings_information.value("m_inf_ymax").toDouble();
    m_chart_data.YMin = m_settings_information.value("m_inf_ymin").toDouble();
    m_chart_data.XRange = m_settings_information.value("m_inf_xrange").toDouble();
    m_chart_data.AutoAdjust = m_settings_information.value("m_inf_autoAdjust").compare("true", Qt::CaseInsensitive) == 0;

    ui->m_inf_ymax->setValue(m_settings_information.value("m_inf_ymax").toDouble());
    ui->m_inf_ymin->setValue(m_settings_information.value("m_inf_ymin").toDouble());
    ui->m_inf_xrange->setValue(m_settings_information.value("m_inf_xrange").toDouble());
    ui->m_autoadjust->setChecked(m_chart_data.AutoAdjust);
    on_m_autoadjust_clicked(m_chart_data.AutoAdjust);
}

void plotinf::SetCurrentChartData(ChartSettingData current_data)
{
    m_chart_data = current_data;
    ui->m_inf_xrange->setValue( m_chart_data.XRange );
    ui->m_inf_ymax->setValue( m_chart_data.YMax );
    ui->m_inf_ymin->setValue( m_chart_data.YMin );
    ui->m_autoadjust->setChecked(m_chart_data.AutoAdjust);//按键自动调整
    on_m_autoadjust_clicked(m_chart_data.AutoAdjust);
}

void plotinf::SetAllChannelEnabled(bool enable)
{
    m_chart_data.AllChannelEnable = enable;
    if(enable)
    {
        ui->m_inf_ymax->setEnabled(false);
        ui->m_inf_ymin->setEnabled(false);
        ui->m_autoadjust->setEnabled(false);
    }
    else
    {
        ui->m_inf_ymax->setEnabled(true);
        ui->m_inf_ymin->setEnabled(true);
        ui->m_autoadjust->setEnabled(true);
    }
}

ChartSettingData plotinf::getCurrentChartData()
{
    return m_chart_data;
}

void plotinf::on_m_btn_sure_clicked()
{
    emit m_plot_send_chartSettingData(m_chart_data);
    emit m_send_information(m_settings_information);
    close();
}


void plotinf::on_m_btn_return_clicked()
{
    close();
}


void plotinf::on_m_btn_deletemodule_clicked()
{
    QMessageBox::StandardButton m_delete_reply;
    m_delete_reply = QMessageBox::question(this, "确认删除", "是否确定删除？", QMessageBox::Yes | QMessageBox::No);
    if (m_delete_reply == QMessageBox::Yes) {
        emit m_delete_module();
        close();
    } else {

    }
}

void plotinf::on_m_autoadjust_clicked(bool checked)
{
    //点击后，对y轴上限和下限的按键设置为灰色或者有用
    if(checked)
    {
        ui->m_inf_ymax->setEnabled(false);
        ui->m_inf_ymin->setEnabled(false);
    }
    else
    {
        if(m_chart_data.AllChannelEnable == false)
        {
            ui->m_inf_ymax->setEnabled(true);
            ui->m_inf_ymin->setEnabled(true);
        }
    }
    m_chart_data.AutoAdjust = checked;
    m_settings_information["m_inf_autoAdjust"] = QString::fromUtf8(m_chart_data.AutoAdjust ? "true" : "false");

}


void plotinf::on_m_inf_ymax_valueChanged(double arg1)
{
    m_settings_information["m_inf_ymax"] = QString::number(arg1);
    m_chart_data.YMax = arg1;
}


void plotinf::on_m_inf_ymin_valueChanged(double arg1)
{
    m_settings_information["m_inf_ymin"] = QString::number(arg1);
    m_chart_data.YMin = arg1;
}


void plotinf::on_m_inf_xrange_valueChanged(double arg1)
{
    m_settings_information["m_inf_xrange"] = QString::number(arg1);
    m_chart_data.XRange = arg1;
}

