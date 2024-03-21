#ifndef FILTERBANK_H
#define FILTERBANK_H
#include "filter.h"

template<typename value_type>
class FilterBank
{
public:
    FilterBank();
public:
    //添加滤波器
    void AddFilter(Filter<double> filter);
    void AddFilter(int Order, const double* B, const double* A, bool enable = false);
    void AddFilter(int Order, const std::vector<double>& B, const std::vector<double>& A, bool enable = false);
    //滤波
    double DoFilter(const value_type& data);
    //定长滤波
    std::vector<double> DoFilter(const std::vector<value_type>& data);
    std::vector<double> DoFilter(const value_type* data, int size);
    //滤波器个数
    unsigned int GetFilterNum();
    //清空滤波器组
    void clear();
    std::vector<Filter<double>> m_filter_bank;
};


template<typename value_type>
inline FilterBank<value_type>::FilterBank()
{
}

template<typename value_type>
inline void FilterBank<value_type>::AddFilter(Filter<double> filter)
{
    m_filter_bank.push_back(filter);
}

template<typename value_type>
inline void FilterBank<value_type>::AddFilter(int Order, const double* B, const double* A, bool enable)
{
    Filter<double> tmp_filter(Order, B, A, enable);
    AddFilter(tmp_filter);
}

template<typename value_type>
inline void FilterBank<value_type>::AddFilter(int Order, const std::vector<double>& B, const std::vector<double>& A, bool enable)
{
    Filter<double> tmp_filter(Order, B, A, enable);
    AddFilter(tmp_filter);
}

template<typename value_type>
inline double FilterBank<value_type>::DoFilter(const value_type& data)
{
    double ret_data = data;
    for (auto iter = m_filter_bank.begin(); iter != m_filter_bank.end(); iter++)
    {
        ret_data = iter->DoFilter(ret_data);
    }
    return ret_data;
}

template<typename value_type>
inline std::vector<double> FilterBank<value_type>::DoFilter(const std::vector<value_type>& data)
{
    std::vector<double> ret_data(data.begin(), data.end());
    for (auto iter = m_filter_bank.begin(); iter != m_filter_bank.end(); iter++)
    {
        ret_data = iter->DoFilter(ret_data);
    }
    return ret_data;
}

template<typename value_type>
inline std::vector<double> FilterBank<value_type>::DoFilter(const value_type* data, int size)
{
    std::vector<double> ret_data(data, data + size);
    for (auto iter = m_filter_bank.begin(); iter != m_filter_bank.end(); iter++)
    {
        ret_data = iter->DoFilter(ret_data);
    }
    return ret_data;
}

template<typename value_type>
inline unsigned int FilterBank<value_type>::GetFilterNum()
{
    return m_filter_bank.size();
}

template<typename value_type>
inline void FilterBank<value_type>::clear()
{
    m_filter_bank.clear();
}


#endif // FILTERBANK_H
