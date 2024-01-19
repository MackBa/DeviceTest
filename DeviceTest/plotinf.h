#ifndef PLOTINF_H
#define PLOTINF_H

#include <QDialog>
#include <QObject>
#include <QMessageBox>
#include <QMap>
namespace Ui {
class plotinf;
}

class plotinf : public QDialog
{
    Q_OBJECT

public:
    explicit plotinf(QWidget *parent = nullptr);
    ~plotinf();
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
    Ui::plotinf *ui;
};

#endif // PLOTINF_H
