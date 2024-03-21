#ifndef FILTERWORK_H
#define FILTERWORK_H

#include <QObject>
#include "filterbank.h"
#include "ConstData.h"
#include "DesignButter/filterDesign.h"

namespace _FilterLowpass
{
    enum FilterLowpass
    {
        fc15 = 0,
        fc30,
        fc55,
        fc70,
        fc100
    };
};
namespace _FilterHighpass
{
    enum FilterHighpass
    {
        fc0_3 = 0,
        fc0_5,
        fc1,
        fc3
    };
}
namespace _FilterNotch
{
    enum FilterNotch
    {
        fc50 = 0,
        fc60
    };
}
namespace _FilterHighpassImpen
{
    enum FilterHighpassImpen
    {
        fc50 = 0,
        fc100,
        fc150,
        fc200
    };
}
using namespace _FilterLowpass;
using namespace _FilterHighpass;
using namespace _FilterNotch;
using namespace _FilterHighpassImpen;

class filterWork : public QObject
{
    Q_OBJECT
public:
    explicit filterWork(int ChNum, QObject* parent = nullptr);
    void SetSamplingFreq(SamplingFreq samp_freq);
    void DoFilter(QVector<float> data);

private:
    SamplingFreq m_freq_type = Freq1000;
    int m_ch_num = TOTAL_CH_NUM;
    bool m_is_filter_on = false;
    QVector<FilterBank<float>> m_vect_filterBank;

public:
    void OnFilterEnabled(bool enable);
    void OnFilterLowPassEnalbed(bool enable);
    void OnFilterHighPassEnabled(bool enable);
    void OnFilterNotchEnabled(bool enable);
    void OnFilterHighPassImpenEnabled(bool enable);

//    void OnFilterLowPassChanged(int index);
//    void OnFilterHighPassChanged(int index);
//    void OnFilterNotchChanged(int index);
//    void OnFilterHighPassImpenChanged(int index);

    void OnFilterChanged(const int index, const int order, const QVector<double> Fc, FilterType type);

signals:
    void sig_Filter_output(QVector<float>);
};

#endif // FILTERWORK_H
