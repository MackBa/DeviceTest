/*
 * File: DesignButter.h
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 26-Mar-2023 11:59:42
 */

#ifndef DESIGNBUTTER_H
#define DESIGNBUTTER_H

/* Include Files */
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
extern void DesignButter(double fs, const double fc[2], double type,
                         double order, double NUM_data[], int NUM_size[2],
                         double DEN_data[], int DEN_size[2]);

extern void DesignButter_initialize(void);

extern void DesignButter_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for DesignButter.h
 *
 * [EOF]
 */
