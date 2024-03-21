#ifndef FILTERMODULE_H
#define FILTERMODULE_H

#include <QDialog>
#include <QMap>
#include <QMessageBox>
#include "src/Filter/DesignButter/filterDesign.h"
namespace Ui {
class filtermodule;
}

class filtermodule : public QDialog
{
    Q_OBJECT

public:
    explicit filtermodule(QWidget *parent = nullptr);
    ~filtermodule();
public:
    void m_rev_information_line(QMap<QString, QString> m_rev_settings_information);
private slots:
    void on_m_btn_sure_clicked();

    void on_m_btn_return_clicked();

    void on_m_btn_deletemodule_clicked();

    void on_m_listWidget_lowpass_currentTextChanged(const QString &currentText);

    void on_m_listWidget_highpass_currentTextChanged(const QString &currentText);

    void on_m_listWidget_notch_currentTextChanged(const QString &currentText);

    void on_m_listWidget_highpass_impen_currentTextChanged(const QString &currentText);
    void on_m_btn_lowpass_clicked(bool checked);

    void on_m_btn_highpass_clicked(bool checked);

    void on_m_btn_notch_clicked(bool checked);

    void on_m_btn_highpass_impen_clicked(bool checked);
signals:
    void m_delete_module();

    void sig_Filter_lowpass_enabled(bool enable);
    void sig_Filter_highpass_enabled(bool enable);
    void sig_Filter_notch_enabled(bool enable);
    void sig_Filter_highpass_impen_enabled(bool enable);

    void sig_Filter_Changed(const int index, const int order, const QVector<double> Fc, FilterType type);
    void m_send_information(QMap<QString, QString>);
    void m_filtermodule_send_filter_inf(QMap<QString,double>);
private:
    Ui::filtermodule *ui;

private:
    int m_filter_order = 2;
    QMap<QString, QString> m_settings_information;
    QMap<QString,double> m_filter_inf;
};

#endif // FILTERMODULE_H
