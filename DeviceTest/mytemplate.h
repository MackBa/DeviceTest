#ifndef MYTEMPLATE_H
#define MYTEMPLATE_H

#include <QLabel>
#include <QMouseEvent>
class MyTemplate : public QLabel
{
    Q_OBJECT
public:
    explicit MyTemplate(QWidget *parent = nullptr);

signals:
protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event)override;
private:
    QPoint m_offset;
    struct m_label_infs
    {
        int x;
        int y;
        QString text;
    };


};

#endif // MYTEMPLATE_H
