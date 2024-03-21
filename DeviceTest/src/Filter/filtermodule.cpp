#include "filtermodule.h"
#include "ui_filtermodule.h"

#include <QMouseEvent>


filtermodule::filtermodule(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::filtermodule)
{
    ui->setupUi(this);
    setWindowTitle("滤波设置");
}

filtermodule::~filtermodule()
{
    delete ui;
}

void filtermodule::m_rev_information_line(QMap<QString, QString> m_rev_settings_information)
{
    m_settings_information = m_rev_settings_information;
    //lowpass
    if(m_settings_information["inf_lowpass_position"] != "-1"){
        ui->m_btn_lowpass->setChecked(true);
        ui->m_listWidget_lowpass->setSelectionMode(QAbstractItemView::SingleSelection);
        ui->m_listWidget_lowpass->setCurrentRow(m_settings_information.value("inf_lowpass_position").toInt());
    }else{
        ui->m_btn_lowpass->setChecked(false);
        ui->m_listWidget_lowpass->clearSelection();
        ui->m_listWidget_lowpass->setSelectionMode(QAbstractItemView::NoSelection);
    }
    //highpass
    if(m_settings_information["inf_highpass_position"] != "-1"){
        ui->m_listWidget_highpass->setCurrentRow(m_settings_information.value("inf_highpass_position").toInt());
        ui->m_btn_highpass->setChecked(true);
        ui->m_listWidget_highpass->setSelectionMode(QAbstractItemView::SingleSelection);
    }else{
        ui->m_btn_highpass->setChecked(false);
        ui->m_listWidget_highpass->clearSelection();
        ui->m_listWidget_highpass->setSelectionMode(QAbstractItemView::NoSelection);
    }
    //notch
    if(m_settings_information["inf_notch_position"] != "-1"){
        ui->m_listWidget_notch->setCurrentRow(m_settings_information.value("inf_notch_position").toInt());
        ui->m_btn_notch->setChecked(true);
        ui->m_listWidget_notch->setSelectionMode(QAbstractItemView::SingleSelection);
    }else{
        ui->m_btn_notch->setChecked(false);
        ui->m_listWidget_notch->clearSelection();
        ui->m_listWidget_notch->setSelectionMode(QAbstractItemView::NoSelection);
    }
    //highpass_impen
    if(m_settings_information["inf_highpass_impen_position"] != "-1"){
        ui->m_listWidget_highpass_impen->setCurrentRow(m_settings_information.value("inf_highpass_impen_position").toInt());
        ui->m_btn_highpass_impen->setChecked(true);
        ui->m_listWidget_highpass_impen->setSelectionMode(QAbstractItemView::SingleSelection);
    }else{
        ui->m_btn_highpass_impen->setChecked(false);
        ui->m_listWidget_highpass_impen->clearSelection();
        ui->m_listWidget_highpass_impen->setSelectionMode(QAbstractItemView::NoSelection);
    }
}

void filtermodule::on_m_btn_sure_clicked()
{
    m_filter_inf["inf_enable"] = 1;
    //lowpass
    if(ui->m_btn_lowpass->isChecked()){
        m_settings_information["inf_lowpass_position"] = QString::number(ui->m_listWidget_lowpass->currentRow());
        m_filter_inf["inf_lowpass"] = ui->m_listWidget_lowpass->currentItem()->text().split("Hz")[0].toDouble();
    }else{
        m_settings_information["inf_lowpass_position"] ="-1";
        m_filter_inf["inf_lowpass"] = -1;
    }
    //highpass
    if(ui->m_btn_highpass->isChecked()){
        m_settings_information["inf_highpass_position"] = QString::number(ui->m_listWidget_highpass->currentRow());
        m_filter_inf["inf_highpass"] = ui->m_listWidget_highpass->currentItem()->text().split("Hz")[0].toDouble();
    }else{
        m_settings_information["inf_highpass_position"] = "-1";
        m_filter_inf["inf_highpass"] = -1;
    }
    //notch
    if(ui->m_btn_notch->isChecked()){
        m_settings_information["inf_notch_position"] = QString::number(ui->m_listWidget_notch->currentRow());
        m_filter_inf["inf_notch"] = ui->m_listWidget_notch->currentItem()->text().split("Hz")[0].toDouble();
    }else{
        m_settings_information["inf_notch_position"] = "-1";
        m_filter_inf["inf_notch"] = -1;
    }
    //highpass_impen
    if(ui->m_btn_highpass_impen->isChecked()){
        m_settings_information["inf_highpass_impen_position"] = QString::number(ui->m_listWidget_highpass_impen->currentRow());
        m_filter_inf["inf_highpass_impen"] = ui->m_listWidget_highpass_impen->currentItem()->text().split("Hz")[0].toDouble();
    }else{
        m_settings_information["inf_highpass_impen_position"] = "-1";
        m_filter_inf["inf_highpass_impen"] = -1;
    }
    emit m_send_information(m_settings_information);
    emit m_filtermodule_send_filter_inf(m_filter_inf);
    close();
}


void filtermodule::on_m_btn_return_clicked()
{
    close();
}


void filtermodule::on_m_btn_deletemodule_clicked()
{
    QMessageBox::StandardButton m_delete_reply;
    m_delete_reply = QMessageBox::question(this, "确认删除", "是否确定删除？", QMessageBox::Yes | QMessageBox::No);
        if (m_delete_reply == QMessageBox::Yes) {
            m_filter_inf["inf_enable"] = 0;
            emit m_filtermodule_send_filter_inf(m_filter_inf);
            emit m_delete_module();
            close();
        } else {

        }
}


void filtermodule::on_m_listWidget_lowpass_currentTextChanged(const QString &currentText)
{
    // index = 0
    double _fc = currentText.split("Hz")[0].toDouble();
    emit sig_Filter_Changed(0, m_filter_order, QVector<double> {_fc, 0}, FilterType::Lowpass);
}


void filtermodule::on_m_listWidget_highpass_currentTextChanged(const QString &currentText)
{
    // index = 1
    double _fc = currentText.split("Hz")[0].toDouble();
    emit sig_Filter_Changed(1, m_filter_order, QVector<double> {_fc, 0}, FilterType::Highpass);
}


void filtermodule::on_m_listWidget_notch_currentTextChanged(const QString &currentText)
{
    // index = 2
    double _fc = currentText.split("Hz")[0].toDouble();
    emit sig_Filter_Changed(2, m_filter_order, QVector<double> {_fc - 0.1, _fc + 0.1}, FilterType::Bandstop);
}


void filtermodule::on_m_listWidget_highpass_impen_currentTextChanged(const QString &currentText)
{
    // index = 3
    double _fc = currentText.split("Hz")[0].toDouble();
    emit sig_Filter_Changed(3, m_filter_order, QVector<double> {_fc, 0}, FilterType::Highpass);
}


void filtermodule::on_m_btn_lowpass_clicked(bool checked)
{
    if(checked){
        ui->m_listWidget_lowpass->setSelectionMode(QAbstractItemView::SingleSelection);
        ui->m_listWidget_lowpass->setCurrentRow(2);
        emit sig_Filter_lowpass_enabled(checked);
    }else{
        ui->m_listWidget_lowpass->setSelectionMode(QAbstractItemView::NoSelection);
        ui->m_listWidget_lowpass->clearSelection();
        ui->m_listWidget_lowpass->setCurrentRow(-1);
    }
}


void filtermodule::on_m_btn_highpass_clicked(bool checked)
{
    if(checked){
        ui->m_listWidget_highpass->setSelectionMode(QAbstractItemView::SingleSelection);
        ui->m_listWidget_highpass->setCurrentRow(0);
        emit sig_Filter_highpass_enabled(checked);
    }else{
        ui->m_listWidget_highpass->setSelectionMode(QAbstractItemView::NoSelection);
        ui->m_listWidget_highpass->clearSelection();
        ui->m_listWidget_highpass->setCurrentRow(-1);
    }
}


void filtermodule::on_m_btn_notch_clicked(bool checked)
{
    if(checked){
        ui->m_listWidget_notch->setSelectionMode(QAbstractItemView::SingleSelection);
        ui->m_listWidget_notch->setCurrentRow(0);
        emit sig_Filter_notch_enabled(checked);
    }else{
        ui->m_listWidget_notch->setSelectionMode(QAbstractItemView::NoSelection);
        ui->m_listWidget_notch->clearSelection();
        ui->m_listWidget_notch->setCurrentRow(-1);
    }
}


void filtermodule::on_m_btn_highpass_impen_clicked(bool checked)
{
    if(checked){
        ui->m_listWidget_highpass_impen->setSelectionMode(QAbstractItemView::SingleSelection);
        ui->m_listWidget_highpass_impen->setCurrentRow(0);
        emit sig_Filter_highpass_impen_enabled(checked);
    }else{
        ui->m_listWidget_highpass_impen->setSelectionMode(QAbstractItemView::NoSelection);
        ui->m_listWidget_highpass_impen->clearSelection();
        ui->m_listWidget_highpass_impen->setCurrentRow(-1);
    }
}


