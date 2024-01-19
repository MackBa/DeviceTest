#ifndef READTEMPLATE_H
#define READTEMPLATE_H

#include <QWidget>
#include <QLabel>
#include <QMap>
#include <QPoint>
namespace Ui {
class readtemplate;
}

class readtemplate : public QWidget
{
    Q_OBJECT

public:
    explicit readtemplate(QWidget *parent = nullptr);
    ~readtemplate();
    void m_showtemplate(QMap<QString, QPoint> m_template_position_infos);
private:
    Ui::readtemplate *ui;
};

#endif // READTEMPLATE_H
