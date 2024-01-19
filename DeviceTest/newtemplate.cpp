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
    for (int i = 0; i < m_labels.size(); ++i) {
        QLabel *m_but_label = m_labels[i];
        m_template_position_infos[m_but_label->text()] = m_but_label->pos();

    }
    emit m_newtemplate_close(m_template_position_infos);
    event->accept();
}

void newtemplate::m_new_lab_template(QMap<QString, QString> m_information)
{
    m_rev_information = m_information;
    //标签
    MyTemplate *m_lab_module = new MyTemplate(this);
    m_lab_module->setFixedSize(100,100);
    QString text =m_rev_information.value("inf1_1");
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
    m_labels_setting_infos.insert(m_rev_information.value("inf1_1"),m_rev_information);
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
    if (m_labels_setting_infos.contains(labelText)) {
        if(labelText == "绘图")
        {
            plotinf m_information(this);
            connect(this,&newtemplate::m_send_information,&m_information,&plotinf::m_rev_information_line);
            connect(&m_information,&plotinf::m_delete_module,this,[=](){
                m_but_label->close();
            });
            connect(&m_information,&plotinf::m_send_information,this,[=](QMap<QString,QString> m_information){
                QStringList keys = m_labels_setting_infos.keys();
                for (int i = 0; i < keys.size(); ++i) {
                    QString key = keys.at(i);
                    if(key == labelText){
                        key = m_information.value("inf1_1");
                        m_labels_setting_infos[key] = m_information;
                    }
                }
                m_but_label->setText(m_information.value("inf1_1"));
            });
            emit m_send_information(m_labels_setting_infos[labelText]);
            m_information.exec();
        }else{
            information m_information(this);
            connect(this,&newtemplate::m_send_information,&m_information,&information::m_rev_information_line);
            connect(&m_information,&information::m_delete_module,this,[=](){
                m_but_label->close();
            });
            connect(&m_information,&information::m_send_information,this,[=](QMap<QString,QString> m_information){
                QStringList keys = m_labels_setting_infos.keys();
                for (int i = 0; i < keys.size(); ++i) {
                    QString key = keys.at(i);
                    if(key == labelText){
                        key = m_information.value("inf1_1");
                        m_labels_setting_infos[key] = m_information;
                    }
                }
                m_but_label->setText(m_information.value("inf1_1"));
            });
            emit m_send_information(m_labels_setting_infos[labelText]);
            m_information.exec();
        }
    }
}

void newtemplate::m_delete_template(QString m_delete_inf_text)
{

}

void newtemplate::m_communication_TCP_template()
{
    information m_TCP_information(this);
    connect(this,&newtemplate::m_send_information,&m_TCP_information,&information::m_rev_information_line);
    QMap<QString, QString> m_TCP_infor;
    m_TCP_infor["inf1_1"] = "通信";
    m_TCP_infor["inf2_1"] = "通信方式";
    m_TCP_infor["inf2_2"] = "TCP";
    m_TCP_infor["inf3_1"] = "ip地址";
    m_TCP_infor["inf3_2"] = "127.0.0.1";
    m_TCP_infor["inf4_1"] = "端口号";
    m_TCP_infor["inf4_2"] = "8888";
    emit m_send_information(m_TCP_infor);
    connect(&m_TCP_information,&information::m_send_information,this,&newtemplate::m_new_lab_template);
    m_TCP_information.exec();
}

void newtemplate::m_communication_UDP_template()
{

}

void newtemplate::m_communication_serialport_template()
{

}


void newtemplate::m_filter_template()
{

}

void newtemplate::m_save_template()
{
    information m_TCP_information(this);
    connect(this,&newtemplate::m_send_information,&m_TCP_information,&information::m_rev_information_line);
    QMap<QString, QString> m_TCP_infor;
    m_TCP_infor["inf1_1"] = "保存";
    m_TCP_infor["inf2_1"] = "保存路径";
    emit m_send_information(m_TCP_infor);
    connect(&m_TCP_information,&information::m_send_information,this,&newtemplate::m_new_lab_template);
    m_TCP_information.exec();
}

void newtemplate::m_plot_template()
{
    plotinf m_plot_information(this);
    connect(this,&newtemplate::m_send_information,&m_plot_information,&plotinf::m_rev_information_line);
    QMap<QString, QString> m_TCP_infor;
    m_TCP_infor["inf1_1"] = "绘图";
    m_TCP_infor["inf2_1"] = "Y轴上线/uV";
    m_TCP_infor["inf2_2"] = "50.00";
    m_TCP_infor["inf3_1"] = "Y轴下线/uV";
    m_TCP_infor["inf3_2"] = "-50.00";
    m_TCP_infor["inf4_1"] = "X轴范围/uV";
    m_TCP_infor["inf4_2"] = "5.00";
    emit m_send_information(m_TCP_infor);
    connect(&m_plot_information,&plotinf::m_send_information,this,&newtemplate::m_new_lab_template);
    m_plot_information.exec();
}

void newtemplate::m_impedance_template()
{

}

void newtemplate::m_other_template()
{
    information m_TCP_information(this);
    connect(this,&newtemplate::m_send_information,&m_TCP_information,&information::m_rev_information_line);
    QMap<QString, QString> m_TCP_infor;
    emit m_send_information(m_TCP_infor);
    connect(&m_TCP_information,&information::m_send_information,this,&newtemplate::m_new_lab_template);
    m_TCP_information.exec();
}