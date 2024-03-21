#include "filterwork.h"
#include <QDebug>

#include "DesignButter/filterDesign.h"
filterWork::filterWork(int ChNum, QObject* parent)
    : QObject{parent}
{
    m_ch_num = ChNum;

    m_vect_filterBank.resize(ChNum);
    for(int i = 0; i < ChNum; i++)
    {
        m_vect_filterBank[i].m_filter_bank.resize(4);
    }
}

void filterWork::SetSamplingFreq(SamplingFreq samp_freq)
{
    qDebug()<<"滤波设置了波特率";
    m_freq_type = samp_freq;
}

void filterWork::DoFilter(QVector<float> data)
{
    if(m_is_filter_on)
    {

        QVector<float> ret_data;
        for(int i = 0; i < m_ch_num; i++)
        {
            ret_data.push_back(m_vect_filterBank[i].DoFilter(data[i]));
        }
        emit sig_Filter_output(ret_data);
    }
    else
    {
        emit sig_Filter_output(data);
    }
}

void filterWork::OnFilterEnabled(bool enable)
{
    m_is_filter_on = enable;
}

void filterWork::OnFilterLowPassEnalbed(bool enable)
{
    for(auto iter = m_vect_filterBank.begin(); iter != m_vect_filterBank.end(); iter++)
    {
        iter->m_filter_bank[0].SetEnabled(enable);
    }
}

void filterWork::OnFilterHighPassEnabled(bool enable)
{
    for(auto iter = m_vect_filterBank.begin(); iter != m_vect_filterBank.end(); iter++)
    {
        iter->m_filter_bank[1].SetEnabled(enable);
    }
}

void filterWork::OnFilterNotchEnabled(bool enable)
{
    for(auto iter = m_vect_filterBank.begin(); iter != m_vect_filterBank.end(); iter++)
    {
        iter->m_filter_bank[2].SetEnabled(enable);
    }
}

void filterWork::OnFilterHighPassImpenEnabled(bool enable)
{
    for(auto iter = m_vect_filterBank.begin(); iter != m_vect_filterBank.end(); iter++)
    {
        iter->m_filter_bank[3].SetEnabled(enable);
    }
}

void filterWork::OnFilterChanged(const int index, const int order, const QVector<double> Fc, FilterType type)
{
    qDebug()<<"滤波低启动了";
//    qDebug() << index << '\t' << order << "\t" << Fc[0] << ":" << Fc[1] << "\t" << type;
    std::vector<double> _filter_data = GenFilterParam(order, m_freq_type, Fc.data(), type);
    std::vector<double> _NUM(_filter_data.begin(), _filter_data.begin() + order + 1);
    std::vector<double> _DEN( _filter_data.begin() + order + 1, _filter_data.end());
    for(auto iter = m_vect_filterBank.begin(); iter != m_vect_filterBank.end(); iter++)
    {
        bool _old_enabled = iter->m_filter_bank[index].isEnable();
        iter->m_filter_bank[index] = Filter<double>(order, _NUM, _DEN);
        iter->m_filter_bank[index].SetEnabled(_old_enabled);
    }
}
