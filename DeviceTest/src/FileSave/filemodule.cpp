#include "filemodule.h"
#include "ui_filemodule.h"


filemodule::filemodule(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::filemodule)
{
    ui->setupUi(this);
    setWindowTitle("保存设置");
}

filemodule::~filemodule()
{
    delete ui;
}

void filemodule::m_rev_information_line(QMap<QString, QString> m_rev_settings_information)
{
    m_settings_information = m_rev_settings_information;
    if(!m_settings_information["inf_filepath"].isEmpty()){
        ui->m_savepath->setText(m_settings_information.value("inf_filepath"));
    }
}

void filemodule::on_m_btn_selectpath_clicked()
{
    QString folderPath = QFileDialog::getExistingDirectory(this, tr("选择文件夹"), QDir::homePath());
    if (!folderPath.isEmpty()) {
        ui->m_savepath->setText(folderPath);
    }else{
        QMessageBox::warning(this, tr("警告"), tr("文件夹路径不能为空！"));
    }
}


void filemodule::on_m_btn_sure_clicked()
{
    if(!ui->m_savepath->text().isEmpty()){
        m_settings_information["inf_filepath"] = ui->m_savepath->text();
        emit m_send_information(m_settings_information);
        close();
    }else{
        QMessageBox::warning(this, tr("警告"), tr("文件夹路径不能为空,无法确认信息！"));
    }
}


void filemodule::on_m_btn_return_clicked()
{
    close();
}


void filemodule::on_m_btn_deletemodule_clicked()
{
    QMessageBox::StandardButton m_delete_reply;
    m_delete_reply = QMessageBox::question(this, "确认删除", "是否确定删除？", QMessageBox::Yes | QMessageBox::No);
    if (m_delete_reply == QMessageBox::Yes) {
        emit m_delete_module();
        close();
    } else {

    }
}

