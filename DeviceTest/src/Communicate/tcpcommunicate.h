#ifndef TCPCOMMUNICATE_H
#define TCPCOMMUNICATE_H

#include <QObject>
#include <QTcpSocket>
#include <QThread>

class tcpcommunicate : public QObject
{
    Q_OBJECT
public:
    explicit tcpcommunicate(QObject *parent = nullptr);

public:
    void ConnectServer(unsigned short port, QString ip);
signals:
    void connectOK();
    void sig_recv_ch_data(QVector<float>);
    void sig_recv_ch_data_raw(QByteArray);

private:
    QTcpSocket * m_t;
    QThread *m_thread;
//    QVector<float> m_tcp_communcation_data;
};

#endif // TCPCOMMUNICATE_H
