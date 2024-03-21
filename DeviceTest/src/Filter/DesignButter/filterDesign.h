#ifndef FILTERDESIGN_H
#define FILTERDESIGN_H

#include "src/DesignButter.h"
#include <vector>

enum FilterType
{
    Highpass = 0,
    Lowpass,
    Bandstop,
    Bandpass
};

std::vector<double> GenFilterParam(const int order, const double Fs, const double Fc[2], FilterType type);

#endif
