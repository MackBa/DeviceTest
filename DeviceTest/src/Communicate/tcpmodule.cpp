#include "tcpmodule.h"
#include "ui_tcpmodule.h"

#include <QMessageBox>


tcpmodule::tcpmodule(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::tcpmodule)
{
    ui->setupUi(this);
    setWindowTitle("TCP设置");
    //设置端口
    ui->m_spinbox_port->setValue(8000);
    //tcp设置
    ui->m_comboBox_ip->setEditable(true);
    //获取本机ip地址
    ui->m_comboBox_ip->addItem("0.0.0.0");
    const QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();
    for(const QHostAddress& ipaddress : ipAddressesList)
    {
        if(ipaddress.toIPv4Address())
        {
            ui->m_comboBox_ip->addItem(ipaddress.toString());
        }
    }

}

tcpmodule::~tcpmodule()
{
    delete ui;
}

void tcpmodule::m_rev_information_line(QMap<QString, QString> m_rev_settings_information)
{
    m_settings_information = m_rev_settings_information;
    if(!m_settings_information["inf_ip"].isEmpty()){
        ui->m_comboBox_ip->setCurrentText(m_settings_information.value("inf_ip"));
    }
    if(!m_settings_information["inf_port"].isEmpty()){
        ui->m_spinbox_port->setValue(m_settings_information.value("inf_port").toInt());
    }
}

void tcpmodule::on_m_btn_sure_clicked()
{
    m_settings_information["inf_ip"] = ui->m_comboBox_ip->currentText();
    m_settings_information["inf_port"] = ui->m_spinbox_port->text();
    emit m_send_information(m_settings_information);
    close();
}


void tcpmodule::on_m_btn_return_clicked()
{
    close();
}


void tcpmodule::on_m_btn_deletemodule_clicked()
{
    QMessageBox::StandardButton m_delete_reply;
    m_delete_reply = QMessageBox::question(this, "确认删除", "是否确定删除？", QMessageBox::Yes | QMessageBox::No);
        if (m_delete_reply == QMessageBox::Yes) {
            emit m_delete_module();
            close();
        } else {

        }
}

