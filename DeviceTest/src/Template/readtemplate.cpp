#include "readtemplate.h"
#include "ui_readtemplate.h"

#include <QVBoxLayout>


readtemplate::readtemplate(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::readtemplate)
{
    ui->setupUi(this);
    QVBoxLayout* layout = new QVBoxLayout(this);
    setLayout(layout);

}

readtemplate::~readtemplate()
{
    delete ui;
}
void readtemplate::m_showtemplate(QMap<QString, QPoint> m_template_position_infos, QMap<QString, QString> communication_info)
{
    m_communication_info = communication_info;
    QStringList keys = m_template_position_infos.keys();
    for (int i = 0; i < keys.size(); ++i) {
        QString key = keys.at(i);
        QLabel *m_lab_module = new QLabel(this);
        m_lab_module->setFixedSize(100,100);
        m_lab_module->setText(key);
        m_lab_module->setStyleSheet("background-color: white; border: 1px solid black; padding: 5px;");
        m_lab_module->setAlignment(Qt::AlignCenter);
//        m_lab_module->move(mapFromGlobal(m_template_position_infos.value(key)));
        m_lab_module->move(m_template_position_infos.value(key));
    }
}

void readtemplate::revChartData(ChartSettingData chart_Data)
{
    m_chart_setting_data = chart_Data;
}

void readtemplate::revFilterData(QMap<QString, double> filter_inf)
{
    m_filter_inf = filter_inf;
}

void readtemplate::on_m_btn_operation_clicked()
{
    displayplot * m_displayplot = new displayplot(m_communication_info);
    m_displayplot->revCurrentChartData(m_chart_setting_data);
    m_displayplot->revCurrent_Filter_inf(m_filter_inf);
    m_displayplot->show();
}

