#ifndef TCPMODULE_H
#define TCPMODULE_H

#include <QDialog>
#include <QHostAddress>
#include <QNetworkInterface>
namespace Ui {
class tcpmodule;
}

class tcpmodule : public QDialog
{
    Q_OBJECT

public:
    explicit tcpmodule(QWidget *parent = nullptr);
    ~tcpmodule();
public:
    void m_rev_information_line(QMap<QString, QString> m_rev_settings_information);
private slots:
    void on_m_btn_sure_clicked();

    void on_m_btn_return_clicked();

    void on_m_btn_deletemodule_clicked();
signals:
    void m_delete_module();
    void m_send_information(QMap<QString, QString>);
private:
    Ui::tcpmodule *ui;
    QMap<QString, QString> m_settings_information;
};

#endif // TCPMODULE_H
