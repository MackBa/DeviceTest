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
        //接收绘图数据
        connect(m_newtemplate,&newtemplate::m_newtemplate_send_chartSettingData,this,[=](ChartSettingData chart_setting_data){
            m_chart_setting_data = chart_setting_data;
        });
        //接收滤波数据
        connect(m_newtemplate,&newtemplate::m_newtemplate_send_filter_inf,this,[=](QMap<QString,double> filter_inf){
            m_filter_inf = filter_inf;
        });
        m_newtemplate->show();
        m_is_newtemplate = true;
        connect(m_newtemplate,&newtemplate::m_newtemplate_close,this,[=](QMap<QString, QPoint> m_labels_position_infos,QMap<QString, QMap<QString, QString>> m_labels_setting_infos){
            m_template_position_infos = m_labels_position_infos;
            m_template_setting_infos = m_labels_setting_infos;
            setEnabled(true);
        });
    }else{
        newtemplate * m_newtemplate = new newtemplate();
        //接收绘图数据
        connect(m_newtemplate,&newtemplate::m_newtemplate_send_chartSettingData,this,[=](ChartSettingData chart_setting_data){
            m_chart_setting_data = chart_setting_data;
        });
        //接收滤波数据
        connect(m_newtemplate,&newtemplate::m_newtemplate_send_filter_inf,this,[=](QMap<QString,double> filter_inf){
            m_filter_inf = filter_inf;
        });
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
        m_readtemplate->revChartData(m_chart_setting_data);
        m_readtemplate->revFilterData(m_filter_inf);
        QStringList keys = m_template_setting_infos.keys();
        for (int i = 0; i < keys.size(); ++i) {
            QString key = keys.at(i);
            if(key == "通信"){
                QMap<QString, QString> m_communication_info = m_template_setting_infos[key];
                m_readtemplate->m_showtemplate(m_template_position_infos,m_communication_info);
            }
        }

        m_readtemplate->show();
        m_readtemplate->update();
    }

}

