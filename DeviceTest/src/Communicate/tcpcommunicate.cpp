#include "tcpcommunicate.h"

tcpcommunicate::tcpcommunicate(QObject *parent)
    : QObject{parent}
{
    qDebug() << "tcpcommunicate is created in: " << QThread::currentThread();

}

void tcpcommunicate::ConnectServer(unsigned short port, QString ip)
{
    qDebug() << "ConnectServer runs in: " << QThread::currentThread();
    m_t = new QTcpSocket(this);
    m_t->connectToHost(QHostAddress(ip),port);
    if (!m_t->waitForConnected()) {
        qDebug() << "无法连接到服务器：" << m_t->errorString();
    }
    connect(m_t,&QTcpSocket::connected,this,&tcpcommunicate::connectOK);
    connect(m_t,&QTcpSocket::disconnected,this,[=](){
        m_t->close();
    });

    connect(m_t, &QTcpSocket::readyRead, this,[=]() {
        // 读取服务器发送的数据
        QVector<float> m_tcp_communcation_data;
        QByteArray data = m_t->readAll();
        int numChannels = data.size() / 4;
//        qDebug() << "导联数：" << numChannels;
            for (int i = 0; i < numChannels; ++i) {
            float channelData;
            memcpy(&channelData, data.data() + i * sizeof(float), sizeof(float));
            m_tcp_communcation_data.push_back(channelData);
//            qDebug() << "导联" << i+1 << "数据：" << channelData;
        }
        emit sig_recv_ch_data(m_tcp_communcation_data);
//        emit sig_recv_ch_data_raw(m_tcp_communcation_data);
    });

}


