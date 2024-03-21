#include "newtemplate.h"
#include "ui_newtemplate.h"

newtemplate::newtemplate(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::newtemplate)
{
    ui->setupUi(this);
    //各个模板
    //通信模板
    connect(ui->m_action_TCP,&QAction::triggered,this,&newtemplate::m_communication_TCP_template);
    connect(ui->m_action_UDP,&QAction::triggered,this,&newtemplate::m_communication_UDP_template);
    connect(ui->m_action_serialport,&QAction::triggered,this,&newtemplate::m_communication_serialport_template);
    //滤波模板
    connect(ui->m_action_filter,&QAction::triggered,this,&newtemplate::m_filter_template);
    //保存模板
    connect(ui->m_action_save,&QAction::triggered,this,&newtemplate::m_save_template);
    //绘图模板
    connect(ui->m_action_plot,&QAction::triggered,this,&newtemplate::m_plot_template);
    //阻抗模板
    connect(ui->m_action_impedance,&QAction::triggered,this,&newtemplate::m_impedance_template);
    //其他模板
    connect(ui->m_action_other,&QAction::triggered,this,&newtemplate::m_other_template);
}

newtemplate::~newtemplate()
{
    delete ui;
}

void newtemplate::closeEvent(QCloseEvent *event)
{
    QMap<QString, QPoint> m_template_position_infos;
//    QStringList keys = m_template_setting_infos.keys();
//    for (int i = 0; i < keys.size(); ++i) {
//        QString key = keys.at(i);
//        for(int j = 0;j < m_labels.size(); ++j){
//            QLabel *m_but_label = m_labels[j];
//            if(key == m_but_label->text()){
//                m_template_position_infos[m_but_label->text()] = m_but_label->pos();
//            }
//        }
//    }
    QStringList keys = m_template_setting_infos.keys();
    for (int i = 0; i < keys.size(); ++i) {
        QString key = keys.at(i);
        for (int j = 0; j < m_labels.size(); ++j) {
            QLabel *m_but_label = m_labels[j];
            if(m_but_label->text() == key){
               m_template_position_infos[m_but_label->text()] = m_but_label->pos();
            }
        }
    }
//    for (int i = 0; i < m_labels.size(); ++i) {
//        QLabel *m_but_label = m_labels[i];
//        m_template_position_infos[m_but_label->text()] = m_but_label->pos();
//    }
    emit m_newtemplate_close(m_template_position_infos,m_template_setting_infos);
    event->accept();
}

void newtemplate::m_new_lab_template(QMap<QString, QString> m_information)
{
    m_rev_information = m_information;
    //标签
    MyTemplate *m_lab_module = new MyTemplate(this);
    m_lab_module->setFixedSize(100,100);
    QString text =m_rev_information.value("inf_name");
    m_lab_module->setText(text);
    m_lab_module->setStyleSheet("background-color: white; border: 1px solid black; padding: 5px;");
    m_lab_module->setAlignment(Qt::AlignCenter);
    m_lab_module->move(0,30);
    //    connect(m_lab_module,&MyTemplate::m_send_label_position,this,[=](QPoint m_template_postion){
    //        m_template_position_infos[text] = m_template_postion;
    //    });
    //设置按键
    QPushButton *m_settingsButton = new QPushButton(m_lab_module);
    m_settingsButton->setIcon(QIcon(":/res/setting icon.png"));
    m_settingsButton->setIconSize(QSize(29,29));
    m_settingsButton->setGeometry(m_lab_module->width() - 30, m_lab_module->height() - 30, 30, 30);
    m_labels.append(m_lab_module);
    m_template_setting_infos.insert(m_rev_information.value("inf_name"),m_rev_information);
    connect(m_settingsButton,&QPushButton::clicked,this,&newtemplate::m_open_settingDiglog);
    m_lab_module->show();
}

void newtemplate::m_open_settingDiglog()
{
    QLabel *m_but_label = nullptr;
    for (int i = 0; i < m_labels.size(); ++i) {
        if (m_labels[i]->underMouse()) {
            m_but_label = m_labels[i];
            break;
        }
    }
    if (m_but_label == nullptr)
        return;
    QString labelText = m_but_label->text();
    if (m_template_setting_infos.contains(labelText)) {
        if(labelText == "通信"){
            QStringList keys = m_template_setting_infos.keys();
            for (int i = 0; i < keys.size(); ++i) {
                QString key = keys.at(i);
                if(key == labelText){
                    QMap<QString,QString> m_communicate_infos;
                    m_communicate_infos = m_template_setting_infos[key];
                    if(m_communicate_infos.value("inf_method") == "TCP"){
                        tcpmodule m_tcpmodule(this);
                        connect(this,&newtemplate::m_send_information,&m_tcpmodule,&tcpmodule::m_rev_information_line);
                        connect(&m_tcpmodule,&tcpmodule::m_delete_module,this,[=](){
                            m_template_setting_infos.remove(labelText);

                            m_but_label->close();
                        });
                        connect(&m_tcpmodule,&tcpmodule::m_send_information,this,[=](QMap<QString,QString> m_information){
                            QStringList keys = m_template_setting_infos.keys();
                            for (int i = 0; i < keys.size(); ++i) {
                                QString key = keys.at(i);
                                if(key == labelText){
                                    key = m_information.value("inf_name");
                                    m_template_setting_infos[key] = m_information;
                                }
                            }
                            m_but_label->setText(m_information.value("inf_name"));
                        });
                        emit m_send_information(m_template_setting_infos[labelText]);
                        m_tcpmodule.exec();
                    }
                }
            }

        }else if(labelText == "绘图"){
            plotinf m_plotinf(this);
            connect(&m_plotinf,&plotinf::m_plot_send_chartSettingData,this,&newtemplate::m_newtemplate_send_chartSettingData);
            connect(this,&newtemplate::m_send_information,&m_plotinf,&plotinf::m_rev_information_line);
            connect(&m_plotinf,&plotinf::m_delete_module,this,[=](){
                m_template_setting_infos.remove(labelText);

                m_but_label->close();
            });
            connect(&m_plotinf,&plotinf::m_send_information,this,[=](QMap<QString,QString> m_information){
                QStringList keys = m_template_setting_infos.keys();
                for (int i = 0; i < keys.size(); ++i) {
                    QString key = keys.at(i);
                    if(key == labelText){
                        key = m_information.value("inf_name");
                        m_template_setting_infos[key] = m_information;
                    }
                }
                m_but_label->setText(m_information.value("inf_name"));
            });
            emit m_send_information(m_template_setting_infos[labelText]);
            m_plotinf.exec();
        }else if(labelText == "保存"){
            filemodule m_filemodule(this);
            connect(this,&newtemplate::m_send_information,&m_filemodule,&filemodule::m_rev_information_line);
            connect(&m_filemodule,&filemodule::m_delete_module,this,[=](){
                m_template_setting_infos.remove(labelText);

                m_but_label->close();
            });
            connect(&m_filemodule,&filemodule::m_send_information,this,[=](QMap<QString,QString> m_information){
                QStringList keys = m_template_setting_infos.keys();
                for (int i = 0; i < keys.size(); ++i) {
                    QString key = keys.at(i);
                    if(key == labelText){
                        key = m_information.value("inf_name");
                        m_template_setting_infos[key] = m_information;
                    }
                }
                m_but_label->setText(m_information.value("inf_name"));
            });
            emit m_send_information(m_template_setting_infos[labelText]);
            m_filemodule.exec();
        }else if(labelText == "滤波"){
            filtermodule m_filtermodule(this);
            connect(&m_filtermodule,&filtermodule::m_filtermodule_send_filter_inf,this,&newtemplate::m_newtemplate_send_filter_inf);
            connect(this,&newtemplate::m_send_information,&m_filtermodule,&filtermodule::m_rev_information_line);
            connect(&m_filtermodule,&filtermodule::m_delete_module,this,[=](){
                m_template_setting_infos.remove(labelText);

                m_but_label->close();
            });
            connect(&m_filtermodule,&filtermodule::m_send_information,this,[=](QMap<QString,QString> m_information){
                QStringList keys = m_template_setting_infos.keys();
                for (int i = 0; i < keys.size(); ++i) {
                    QString key = keys.at(i);
                    if(key == labelText){
                        key = m_information.value("inf_name");
                        m_template_setting_infos[key] = m_information;
                    }
                }
                m_but_label->setText(m_information.value("inf_name"));
            });
            emit m_send_information(m_template_setting_infos[labelText]);
            m_filtermodule.exec();
        }else{
            information m_information(this);
            connect(this,&newtemplate::m_send_information,&m_information,&information::m_rev_information_line);
            connect(&m_information,&information::m_delete_module,this,[=](){
                m_but_label->close();
            });
            connect(&m_information,&information::m_send_information,this,[=](QMap<QString,QString> m_information){
                QStringList keys = m_template_setting_infos.keys();
                for (int i = 0; i < keys.size(); ++i) {
                    QString key = keys.at(i);
                    if(key == labelText){
                        key = m_information.value("inf_name");
                        m_template_setting_infos[key] = m_information;
                    }
                }
                m_but_label->setText(m_information.value("inf_name"));
            });
            emit m_send_information(m_template_setting_infos[labelText]);
            m_information.exec();
        }
    }
}

void newtemplate::m_delete_template(QString m_delete_inf_text)
{

}

void newtemplate::m_show_already_template(QMap<QString, QPoint> m_labels_position_infos,QMap<QString, QMap<QString, QString>> m_labels_setting_infos)
{
    m_template_position_infos = m_labels_position_infos;
    m_template_setting_infos = m_labels_setting_infos;

    QStringList keys = m_template_setting_infos.keys();
    for (int i = 0; i < keys.size(); ++i) {
        QString key = keys.at(i);
        MyTemplate *m_lab_module = new MyTemplate(this);
        m_lab_module->setFixedSize(100,100);
        m_lab_module->setText(key);
        m_lab_module->setStyleSheet("background-color: white; border: 1px solid black; padding: 5px;");
        m_lab_module->setAlignment(Qt::AlignCenter);
        m_lab_module->move(m_template_position_infos.value(key));
        QPushButton *m_settingsButton = new QPushButton(m_lab_module);
        m_settingsButton->setIcon(QIcon(":/res/setting icon.png"));
        m_settingsButton->setIconSize(QSize(29,29));
        m_settingsButton->setGeometry(m_lab_module->width() - 30, m_lab_module->height() - 30, 30, 30);
        m_labels.append(m_lab_module);
        connect(m_settingsButton,&QPushButton::clicked,this,&newtemplate::m_open_settingDiglog);
        m_lab_module->show();
    }

}
//TCP
void newtemplate::m_communication_TCP_template()
{
    tcpmodule m_tcpmodule(this);
    connect(this,&newtemplate::m_send_information,&m_tcpmodule,&tcpmodule::m_rev_information_line);
    QMap<QString, QString> m_TCP_infor;
    m_TCP_infor["inf_name"] = "通信";
    m_TCP_infor["inf_method"] = "TCP";
    emit m_send_information(m_TCP_infor);
    connect(&m_tcpmodule,&tcpmodule::m_send_information,this,&newtemplate::m_new_lab_template);
    m_tcpmodule.exec();
}
//UDP
void newtemplate::m_communication_UDP_template()
{

}
//串口
void newtemplate::m_communication_serialport_template()
{

}

//滤波
void newtemplate::m_filter_template()
{
    filtermodule m_filtermodule(this);
    connect(&m_filtermodule,&filtermodule::m_filtermodule_send_filter_inf,this,&newtemplate::m_newtemplate_send_filter_inf);
    connect(this,&newtemplate::m_send_information,&m_filtermodule,&filtermodule::m_rev_information_line);
    QMap<QString, QString> m_filter_infor;
    m_filter_infor["inf_name"] = "滤波";
    m_filter_infor["inf_lowpass_position"] = "2";
    m_filter_infor["inf_highpass_position"] = "0";
    m_filter_infor["inf_notch_position"] = "0";
    m_filter_infor["inf_highpass_impen_position"] = "-1";
    emit m_send_information(m_filter_infor);
    connect(&m_filtermodule,&filtermodule::m_send_information,this,&newtemplate::m_new_lab_template);
    m_filtermodule.exec();
}
//保存
void newtemplate::m_save_template()
{
    filemodule m_filemodule(this);
    connect(this,&newtemplate::m_send_information,&m_filemodule,&filemodule::m_rev_information_line);
    QMap<QString, QString> m_file_infor;
    m_file_infor["inf_name"] = "保存";
    emit m_send_information(m_file_infor);
    connect(&m_filemodule,&filemodule::m_send_information,this,&newtemplate::m_new_lab_template);
    m_filemodule.exec();
}
//绘图
void newtemplate::m_plot_template()
{
    plotinf m_plot_information(this);
    emit m_send_setCurrentChartData();
    connect(&m_plot_information,&plotinf::m_plot_send_chartSettingData,this,&newtemplate::m_newtemplate_send_chartSettingData);
    connect(this,&newtemplate::m_send_information,&m_plot_information,&plotinf::m_rev_information_line);
    QMap<QString, QString> m_TCP_infor;
    m_TCP_infor["inf_name"] = "绘图";
    m_TCP_infor["m_inf_ymax"] = "50.00";
    m_TCP_infor["m_inf_ymin"] = "-50.00";
    m_TCP_infor["m_inf_xrange"] = "5.00";
    m_TCP_infor["m_inf_autoAdjust"] = "true";
    emit m_send_information(m_TCP_infor);
    connect(&m_plot_information,&plotinf::m_send_information,this,&newtemplate::m_new_lab_template);
    m_plot_information.exec();
}
//阻抗
void newtemplate::m_impedance_template()
{

}
//其他
void newtemplate::m_other_template()
{
    information m_TCP_information(this);
    connect(this,&newtemplate::m_send_information,&m_TCP_information,&information::m_rev_information_line);
    QMap<QString, QString> m_TCP_infor;
    emit m_send_information(m_TCP_infor);
    connect(&m_TCP_information,&information::m_send_information,this,&newtemplate::m_new_lab_template);
    m_TCP_information.exec();
}
