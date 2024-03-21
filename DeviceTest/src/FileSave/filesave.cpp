#include "filesave.h"

FileSave::FileSave(QObject* parent)
    : QObject{parent}
{
}

FileSave::~FileSave()
{
    StopRecord();
}

void FileSave::SetFileSavingPath(QString path)
{
    m_root_path = path;
}

void FileSave::StartRecord(const int& freq)
{
    assert(m_bdf_header == nullptr);
    assert(m_buffer == nullptr);
    m_freq = freq;
    std::vector<int> NumberOfSamplesInEachDataRecord;
    for(int i = 0; i < NumberOfChannels; i++)
    {
        NumberOfSamplesInEachDataRecord.push_back(freq);
    }
    m_buffer = new QByteArray();
    m_buffer->resize(NumberOfChannels * freq * 3);
    memset(m_buffer->data(), 0, NumberOfChannels * m_freq * 3);
    m_already_record_time = 0;

    //创建保存文件夹
    static QDir dir;
    QString current_file_path = m_root_path + "/" + QDateTime::currentDateTime().toString("yyyy-MM-dd hh.mm.ss");
    if(!dir.exists(current_file_path))
    {
        dir.mkpath(current_file_path);
    }
    QString _file_name = current_file_path + "/data.bdf";
    m_bdf_header = new BDFHeader(BDFFileMode::OUT, _file_name.toStdString());

    m_bdf_header->WriteBDFHeader(
        SubjectIdentification,
        RecordingIdentification,
        NumberOfChannels,
        LabelsOfChannels,
        TransducerType,
        PhysicalDimension,
        PhysicalMinimum,
        PhysicalMaximum,
        DigitalMinimum,
        DigitalMaximum,
        Prefiltering,
        NumberOfSamplesInEachDataRecord);

    m_file_write.setFileName(_file_name);
    m_file_write.open( QIODevice :: WriteOnly | QIODevice::Append);
}

void FileSave::StopRecord()
{
    if(m_file_write.isOpen())
    {
        m_file_write.close();
    }
    if(m_bdf_header != nullptr)
    {
        m_bdf_header->FinishBDFDataWrite(m_already_record_time);
        delete m_bdf_header;
        m_bdf_header = nullptr;
    }
    if(m_buffer != nullptr)
    {
        delete m_buffer;
        m_buffer = nullptr;
    }


//    for(int i = 0; i < TOTAL_CH_NUM; i++)
//    {
//        if(m_qfile[i].isOpen())
//        {
//            m_qfile[i].close();
//        }
    //    }
}

void FileSave::SaveData(QByteArray data)
{
    // 0 ~ m_freq-1
    static int _current_index = 0;
    for(int i = 0; i < NumberOfChannels; i++)
    {
        memcpy(m_buffer->data() + i * m_freq * 3 + _current_index * 3, data.data() + i * 3, 3);
    }
    _current_index++;
    if(_current_index == m_freq)
    {
        flush();
        _current_index = 0;
        m_already_record_time++;
    }
}

//void FileSave::SaveData(QVector<float> data)
//{
//    static QByteArray _write_data("", sizeof(float));

////    for(int i = 0; i < data.size(); i++)
////    {
////        if(m_qfile[i].isOpen())
////        {
////            memcpy(_write_data.data(), &data[i], sizeof(float));
////            m_qfile[i].write(_write_data);
////        }
////    }

//}

void FileSave::flush()
{
    m_file_write.write(*m_buffer);
    memset(m_buffer->data(), 0, NumberOfChannels * m_freq * 3);
}
