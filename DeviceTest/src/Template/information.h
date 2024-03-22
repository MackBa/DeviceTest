#ifndef INFORMATION_H
#define INFORMATION_H

#include <QDialog>
#include <QMap>
#include <QMessageBox>
namespace Ui {
class information;
}

class information : public QDialog
{
    Q_OBJECT

public:
    explicit information(QWidget *parent = nullptr);
    ~information();

public:
    void m_rev_information_line(QMap<QString, QString> m_rev_settings_information);
private slots:
    void on_m_btn_sure_clicked();
    void on_m_btn_return_clicked();
    void on_m_btn_deletemodule_clicked();
signals:
    void m_send_information(QMap<QString, QString> m_settings_information);
    void m_delete_module();
private:
    Ui::information *ui;
};

#endif // INFORMATION_H
