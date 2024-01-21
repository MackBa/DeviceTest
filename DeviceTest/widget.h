#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "newtemplate.h"
#include "readtemplate.h"
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_m_btn_newTemplate_clicked();

    void on_m_btn_readTemplate_clicked();

private:
    Ui::Widget *ui;
    QMap<QString, QPoint> m_template_position_infos;
    QMap<QString, QMap<QString, QString>> m_template_setting_infos;
    bool m_is_newtemplate = false;

};
#endif // WIDGET_H
