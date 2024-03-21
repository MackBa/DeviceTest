#include "filterDesign.h"

std::vector<double> GenFilterParam(const int order, const double Fs, const double Fc[2], FilterType type)
{
    std::vector<double> ret_data;

    static double NUM_data[2003];
    double DEN_data[1003];
    int DEN_size[2];
    int NUM_size[2];

    DesignButter(Fs, Fc, type, order, NUM_data, NUM_size, DEN_data, DEN_size);


    ret_data.insert(ret_data.end(), NUM_data, NUM_data + order + 1);
    ret_data.insert(ret_data.end(), DEN_data, DEN_data + order + 1);

    return ret_data;
}
