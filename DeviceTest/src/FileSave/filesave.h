#ifndef FILESAVE_H
#define FILESAVE_H

#include <QObject>
#include <QString>
#include <QDir>
#include <QDateTime>
#include <QFile>
#include <QByteArray>
#include "BDFHeader.h"
#include "ConstData.h"

static const std::string SubjectIdentification = "subject id";
static const std::string RecordingIdentification = "Luo device";
static const unsigned int NumberOfChannels = 8;
static const std::vector<std::string> LabelsOfChannels = { "ch1", "ch2", "ch3", "ch4", "ch5", "ch6", "ch7", "ch8" };
static const std::vector<std::string> TransducerType = { "EEG", "EEG", "EEG", "EEG", "EEG", "EEG", "EEG", "EEG" };
static const std::vector<std::string> PhysicalDimension = { "uV", "uV", "uV", "uV", "uV", "uV", "uV", "uV" };
static const std::vector<int> PhysicalMinimum = { -375000, -375000, -375000, -375000, -375000, -375000, -375000, -375000 };
static const std::vector<int> PhysicalMaximum = { 375000, 375000, 375000, 375000, 375000, 375000, 375000, 375000 };
static const std::vector<int> DigitalMinimum = { -8388608, -8388608, -8388608, -8388608, -8388608, -8388608, -8388608, -8388608 };
static const std::vector<int> DigitalMaximum = { 8388607, 8388607, 8388607, 8388607, 8388607, 8388607, 8388607, 8388607 };
static const std::vector<std::string> Prefiltering = { "", "", "", "", "", "", "", "" };

class FileSave : public QObject
{
    Q_OBJECT
public:
    explicit FileSave(QObject* parent = nullptr);
    ~FileSave();

public:
    void SetFileSavingPath(QString path);
    void StartRecord(const int& freq);
    void StopRecord();
public slots:
//    void SaveData(QVector<float> data);
    void SaveData(QByteArray data);

private:
    QString m_root_path = "./LuoData";
//    QFile m_qfile[TOTAL_CH_NUM];
    int m_freq;
    BDFHeader* m_bdf_header = nullptr;
    QFile m_file_write;
    QByteArray* m_buffer = nullptr;
    int m_already_record_time = 0;
private:
    void flush();

signals:
};

#endif // FILESAVE_H
