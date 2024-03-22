#include "mytemplate.h"

MyTemplate::MyTemplate(QWidget *parent)
    : QLabel{parent}
{
    setMouseTracking(true);
}
void MyTemplate::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        m_offset = event->pos();
    }
    QLabel::mousePressEvent(event);
}

void MyTemplate::mouseMoveEvent(QMouseEvent *event)
{
    if (event->buttons() & Qt::LeftButton) {
        QPoint newPos = event->pos() - m_offset;
        move(mapToParent(newPos));
    }
    QLabel::mouseMoveEvent(event);
}

void MyTemplate::mouseReleaseEvent(QMouseEvent *event)
{

    QLabel::mouseReleaseEvent(event);
}
