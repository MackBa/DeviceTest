#include "information.h"
#include "ui_information.h"


information::information(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::information)
{
    ui->setupUi(this);
}

information::~information()
{
    delete ui;
}

void information::m_rev_information_line(QMap<QString, QString> m_rev_settings_information)
{
    ui->m_inf_1_1->setText(m_rev_settings_information.value("inf_name"));
    ui->m_inf_2_1->setText(m_rev_settings_information.value("inf2_1"));
    ui->m_inf_2_2->setText(m_rev_settings_information.value("inf2_2"));
    ui->m_inf_3_1->setText(m_rev_settings_information.value("inf3_1"));
    ui->m_inf_3_2->setText(m_rev_settings_information.value("inf3_2"));
    ui->m_inf_4_1->setText(m_rev_settings_information.value("inf4_1"));
    ui->m_inf_4_2->setText(m_rev_settings_information.value("inf4_2"));
}

void information::on_m_btn_sure_clicked()
{
    QMap<QString, QString> m_settings_information;
    if (!ui->m_inf_1_1->text().isEmpty())
        m_settings_information["inf_name"] = ui->m_inf_1_1->text();
    if (!ui->m_inf_2_1->text().isEmpty())
        m_settings_information["inf2_1"] = ui->m_inf_2_1->text();
    if (!ui->m_inf_2_2->text().isEmpty())
        m_settings_information["inf2_2"] = ui->m_inf_2_2->text();
    if (!ui->m_inf_3_1->text().isEmpty())
        m_settings_information["inf3_1"] = ui->m_inf_3_1->text();
    if (!ui->m_inf_3_2->text().isEmpty())
        m_settings_information["inf3_2"] = ui->m_inf_3_2->text();
    if (!ui->m_inf_4_1->text().isEmpty())
        m_settings_information["inf4_1"] = ui->m_inf_4_1->text();
    if (!ui->m_inf_4_2->text().isEmpty())
        m_settings_information["inf4_2"] = ui->m_inf_4_2->text();
    emit m_send_information(m_settings_information);
    close();
}


void information::on_m_btn_return_clicked()
{
    close();
}


void information::on_m_btn_deletemodule_clicked()
{
    QMessageBox::StandardButton m_delete_reply;
    m_delete_reply = QMessageBox::question(this, "确认删除", "是否确定删除？", QMessageBox::Yes | QMessageBox::No);
    if (m_delete_reply == QMessageBox::Yes) {
       emit m_delete_module();
        close();
    } else {

    }
}

