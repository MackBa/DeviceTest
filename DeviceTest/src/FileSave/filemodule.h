#ifndef FILEMODULE_H
#define FILEMODULE_H

#include <QDialog>
#include <QFileDialog>
#include <QMap>
#include <QMessageBox>
namespace Ui {
class filemodule;
}

class filemodule : public QDialog
{
    Q_OBJECT

public:
    explicit filemodule(QWidget *parent = nullptr);
    ~filemodule();
public:
    void m_rev_information_line(QMap<QString, QString> m_rev_settings_information);

private slots:
    void on_m_btn_selectpath_clicked();

    void on_m_btn_sure_clicked();

    void on_m_btn_return_clicked();

    void on_m_btn_deletemodule_clicked();
signals:
    void m_delete_module();
    void m_send_information(QMap<QString, QString>);

private:
    Ui::filemodule *ui;
    QMap<QString, QString> m_settings_information;
};

#endif // FILEMODULE_H
