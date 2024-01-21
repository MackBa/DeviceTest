#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_m_btn_newTemplate_clicked()
{
    setDisabled(true);
    if(m_is_newtemplate == false)
    {
        newtemplate * m_newtemplate = new newtemplate();
        m_newtemplate->show();
        m_is_newtemplate = true;
        connect(m_newtemplate,&newtemplate::m_newtemplate_close,this,[=](QMap<QString, QPoint> m_labels_position_infos,QMap<QString, QMap<QString, QString>> m_labels_setting_infos){
            m_template_position_infos = m_labels_position_infos;
            m_template_setting_infos = m_labels_setting_infos;
            setEnabled(true);
        });
    }else{
        newtemplate * m_newtemplate = new newtemplate();
        m_newtemplate->m_show_already_template(m_template_position_infos,m_template_setting_infos);
        m_newtemplate->show();
        connect(m_newtemplate,&newtemplate::m_newtemplate_close,this,[=](QMap<QString, QPoint> m_labels_position_infos,QMap<QString, QMap<QString, QString>> m_labels_setting_infos){
            m_template_position_infos = m_labels_position_infos;
            m_template_setting_infos = m_labels_setting_infos;
            setEnabled(true);
        });
    }
}


void Widget::on_m_btn_readTemplate_clicked()
{
    if(m_is_newtemplate == false)
    {
        QMessageBox::information(this, "提示", "暂无模板可加载，请先新建模板");
    }else{
        readtemplate *m_readtemplate = new readtemplate();
        m_readtemplate->m_showtemplate(m_template_position_infos);
        m_readtemplate->show();
    }

}

