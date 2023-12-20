#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "baseclass.h"
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget,public BaseClass
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

public:
    void ReceiveData(const DataStruct& data) override;
    void SendData(const DataStruct& data) override;

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
