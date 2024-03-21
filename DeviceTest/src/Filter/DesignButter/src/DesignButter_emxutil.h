/*
 * File: DesignButter_emxutil.h
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 26-Mar-2023 11:59:42
 */

#ifndef DESIGNBUTTER_EMXUTIL_H
#define DESIGNBUTTER_EMXUTIL_H

/* Include Files */
#include "DesignButter_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
extern void emxEnsureCapacity_creal_T(emxArray_creal_T *emxArray, int oldNumel);

extern void emxEnsureCapacity_int8_T(emxArray_int8_T *emxArray, int oldNumel);

extern void emxEnsureCapacity_real_T(emxArray_real_T *emxArray, int oldNumel);

extern void emxFree_creal_T(emxArray_creal_T **pEmxArray);

extern void emxFree_int8_T(emxArray_int8_T **pEmxArray);

extern void emxFree_real_T(emxArray_real_T **pEmxArray);

extern void emxInit_creal_T(emxArray_creal_T **pEmxArray, int numDimensions);

extern void emxInit_int8_T(emxArray_int8_T **pEmxArray, int numDimensions);

extern void emxInit_real_T(emxArray_real_T **pEmxArray, int numDimensions);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for DesignButter_emxutil.h
 *
 * [EOF]
 */
