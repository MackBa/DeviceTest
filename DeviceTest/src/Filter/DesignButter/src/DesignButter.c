/*
 * File: DesignButter.c
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 26-Mar-2023 11:59:42
 */

/* Include Files */
#include "DesignButter.h"
#include "DesignButter_emxutil.h"
#include "DesignButter_types.h"
#include "rt_nonfinite.h"
#include "rt_defines.h"
#include "rt_nonfinite.h"
#include <float.h>
#include <math.h>
#include <string.h>

/* Variable Definitions */
static boolean_T isInitialized_DesignButter = false;

/* Function Declarations */
static void b_butter(double n, double Wn, double varargout_1_data[],
                     int varargout_1_size[2], double varargout_2_data[],
                     int varargout_2_size[2]);

static void b_buttzeros(double n, double Wn, const creal_T p_data[], int p_size,
                        creal_T z_data[], int *z_size, double *k);

static void b_lusolve(const emxArray_real_T *A, double B_data[],
                      const int *B_size);

static void b_mldivide(const emxArray_real_T *A, const emxArray_real_T *B,
                       emxArray_real_T *Y);

static void b_qrsolve(const emxArray_real_T *A, const emxArray_real_T *B,
                      emxArray_real_T *Y);

static void b_sqrt(creal_T *x);

static double b_xnrm2(int n, const double x[3]);

static void b_xzlartg(const creal_T f, const creal_T g, double *cs,
                      creal_T *sn);

static void bilinear(const emxArray_real_T *z, const double p_data[],
                     int p_size, const double k_data[], const int k_size[2],
                     double fs, emxArray_real_T *zd, double pd_data[],
                     int *pd_size, double kd_data[], int kd_size[2],
                     double *dd);

static void buttap(double n, creal_T p_data[], int *p_size, double *k);

static void butter(double n, double Wn, double varargout_1_data[],
                   int varargout_1_size[2], double varargout_2_data[],
                   int varargout_2_size[2]);

static void buttzeros(double n, double Wn, const creal_T p_data[], int p_size,
                      creal_T z_data[], int *z_size, double *k);

static void c_butter(double n, const double Wn[2], double varargout_1_data[],
                     int varargout_1_size[2], double varargout_2_data[],
                     int varargout_2_size[2]);

static void c_lusolve(const emxArray_real_T *A, double B_data[],
                      const int B_size[2]);

static boolean_T cplxpairv(creal_T x_data[], const int *x_size, double tol);

static void d_butter(double n, const double Wn[2], double varargout_1_data[],
                     int varargout_1_size[2], double varargout_2_data[],
                     int varargout_2_size[2]);

static void eig(const emxArray_real_T *A, creal_T V_data[], int *V_size);

static void eigHermitianStandard(const emxArray_real_T *A, double V_data[],
                                 int *V_size);

static int eml_dlahqr(emxArray_real_T *h);

static void inv(const emxArray_real_T *x, emxArray_real_T *y);

static void lp2bp(const emxArray_real_T *a, const double b_data[], int b_size,
                  const double c_data[], const int c_size[2], double d,
                  double wo, double bw, emxArray_real_T *at, double bt_data[],
                  int *bt_size, double ct_data[], int ct_size[2], double *dt);

static void lp2bs(const emxArray_real_T *a, const double b_data[], int b_size,
                  const double c_data[], const int c_size[2], double d,
                  double wo, double bw, emxArray_real_T *at, double bt_data[],
                  int *bt_size, double ct_data[], int ct_size[2], double *dt);

static void lp2hp(const emxArray_real_T *a, const double b_data[], int b_size,
                  const double c_data[], const int c_size[2], double d,
                  double wo, emxArray_real_T *at, double bt_data[],
                  int *bt_size, double ct_data[], int ct_size[2], double *dt);

static void lusolve(const emxArray_real_T *A, const emxArray_real_T *B,
                    emxArray_real_T *X);

static void mldivide(const emxArray_real_T *A, const double B_data[],
                     int B_size, double Y_data[], int *Y_size);

static void mrdiv(const double A_data[], const int A_size[2],
                  const emxArray_real_T *B, double Y_data[], int Y_size[2]);

static void qrpf(emxArray_real_T *A, int m, int n, double tau_data[],
                 int jpvt_data[]);

static void qrsolve(const emxArray_real_T *A, const double B_data[], int B_size,
                    double Y_data[], int *Y_size);

static int rankFromQR(const emxArray_real_T *A);

static double rt_atan2d_snf(double u0, double u1);

static double rt_hypotd_snf(double u0, double u1);

static double rt_powd_snf(double u0, double u1);

static double rt_remd_snf(double u0, double u1);

static void schur(emxArray_real_T *A, emxArray_real_T *V);

static void xdlanv2(double *a, double *b, double *c, double *d, double *rt1r,
                    double *rt1i, double *rt2r, double *rt2i, double *cs,
                    double *sn);

static void xgehrd(emxArray_real_T *a);

static void xgeqp3(emxArray_real_T *A, double tau_data[], int *tau_size,
                   int jpvt_data[], int jpvt_size[2]);

static void xgerc(int m, int n, double alpha1, int ix0, const double y_data[],
                  emxArray_real_T *A, int ia0, int lda);

static void xgetrf(int m, int n, emxArray_real_T *A, int lda, int ipiv_data[],
                   int ipiv_size[2]);

static double xnrm2(int n, const emxArray_real_T *x, int ix0);

static void xrot(int n, emxArray_real_T *x, int ix0, int incx, int iy0,
                 int incy, double c, double s);

static void xzgeev(const emxArray_real_T *A, int *info, creal_T alpha1_data[],
                   int *alpha1_size, creal_T beta1_data[], int *beta1_size);

static void xzgetrf(int m, int n, emxArray_real_T *A, int lda, int ipiv_data[],
                    int ipiv_size[2], int *info);

static void xzggbal(emxArray_creal_T *A, int *ilo, int *ihi, int rscale_data[],
                    int *rscale_size);

static void xzgghrd(int ilo, int ihi, emxArray_creal_T *A);

static void xzhgeqz(const emxArray_creal_T *A, int ilo, int ihi, int *info,
                    creal_T alpha1_data[], int *alpha1_size,
                    creal_T beta1_data[], int *beta1_size);

static double xzlarfg(int n, double *alpha1, emxArray_real_T *x, int ix0);

static void xzlartg(const creal_T f, const creal_T g, double *cs, creal_T *sn,
                    creal_T *r);

static void zp2ss(const creal_T p_data[], int p_size, double k,
                  emxArray_real_T *a, double b_data[], int *b_size,
                  double c_data[], int c_size[2], double *d);

/* Function Definitions */
/*
 * Arguments    : double n
 *                double Wn
 *                double varargout_1_data[]
 *                int varargout_1_size[2]
 *                double varargout_2_data[]
 *                int varargout_2_size[2]
 * Return Type  : void
 */
static void b_butter(double n, double Wn, double varargout_1_data[],
                     int varargout_1_size[2], double varargout_2_data[],
                     int varargout_2_size[2])
{
  emxArray_real_T *a;
  emxArray_real_T *ad;
  emxArray_real_T *wo;
  creal_T b_c_data[1003];
  creal_T x_data[1002];
  creal_T p_data[501];
  cint8_T z_data[500];
  double bd_data[1002];
  double cd_data[1002];
  double wo_data[1002];
  double b_data[501];
  double c_data[501];
  double b_d;
  double d;
  double d1;
  double im;
  double ks;
  int c_size[2];
  int cd_size[2];
  int b_size;
  int bd_size;
  int j;
  int k;
  int loop_ub;
  int x_size;
  signed char b_x_data[1000];
  boolean_T exitg1;
  boolean_T y;
  emxInit_real_T(&a, 2);
  emxInit_real_T(&wo, 2);
  buttap(n, p_data, &x_size, &ks);
  zp2ss(p_data, x_size, ks, a, b_data, &b_size, c_data, c_size, &d);
  ks = 4.0 * tan(3.1415926535897931 * Wn / 2.0);
  k = wo->size[0] * wo->size[1];
  wo->size[0] = a->size[0];
  wo->size[1] = a->size[1];
  emxEnsureCapacity_real_T(wo, k);
  loop_ub = a->size[0] * a->size[1];
  for (k = 0; k < loop_ub; k++) {
    wo->data[k] = ks * a->data[k];
  }
  emxFree_real_T(&a);
  for (k = 0; k < b_size; k++) {
    wo_data[k] = ks * b_data[k];
  }
  emxInit_real_T(&ad, 2);
  bilinear(wo, wo_data, b_size, c_data, c_size, d, ad, bd_data, &bd_size,
           cd_data, cd_size, &ks);
  eig(ad, x_data, &x_size);
  emxFree_real_T(&wo);
  emxFree_real_T(&ad);
  if (0 <= x_size - 1) {
    memcpy(&p_data[0], &x_data[0], x_size * sizeof(creal_T));
  }
  b_size = (int)n;
  for (k = 0; k < b_size; k++) {
    z_data[k].re = -1;
    z_data[k].im = 0;
  }
  for (k = 0; k < x_size; k++) {
    x_data[k].re = 1.0 - p_data[k].re;
    x_data[k].im = 0.0 - p_data[k].im;
  }
  if (x_size == 0) {
    ks = 1.0;
  } else {
    ks = x_data[0].re;
    im = x_data[0].im;
    for (k = 2; k <= x_size; k++) {
      b_d = x_data[k - 1].re;
      d1 = x_data[k - 1].im;
      d = ks * b_d - im * d1;
      im = ks * d1 + im * b_d;
      ks = d;
    }
  }
  im = ks / rt_powd_snf(2.0, n);
  for (k = 0; k < b_size; k++) {
    b_x_data[k] = z_data[k].im;
  }
  y = false;
  loop_ub = 1;
  exitg1 = false;
  while ((!exitg1) && (loop_ub <= (int)n)) {
    if (b_x_data[loop_ub - 1] == 0) {
      loop_ub++;
    } else {
      y = true;
      exitg1 = true;
    }
  }
  if (!y) {
    for (k = 0; k < b_size; k++) {
      z_data[k].re = -1;
      z_data[k].im = 0;
    }
  }
  bd_size = x_size + 1;
  b_c_data[0].re = 1.0;
  b_c_data[0].im = 0.0;
  for (j = 0; j < x_size; j++) {
    ks = -p_data[j].re;
    d = -p_data[j].im;
    b_d = b_c_data[j].im;
    d1 = b_c_data[j].re;
    b_c_data[j + 1].re = ks * d1 - d * b_d;
    b_c_data[j + 1].im = ks * b_d + d * d1;
    for (k = j + 1; k >= 2; k--) {
      b_d = p_data[j].re;
      d1 = p_data[j].im;
      d = b_d * b_c_data[k - 2].im + d1 * b_c_data[k - 2].re;
      b_c_data[k - 1].re -= b_d * b_c_data[k - 2].re - d1 * b_c_data[k - 2].im;
      b_c_data[k - 1].im -= d;
    }
  }
  varargout_2_size[0] = 1;
  varargout_2_size[1] = x_size + 1;
  for (k = 0; k < bd_size; k++) {
    varargout_2_data[k] = b_c_data[k].re;
  }
  bd_size = (int)n + 1;
  b_c_data[0].re = 1.0;
  b_c_data[0].im = 0.0;
  for (j = 0; j < b_size; j++) {
    loop_ub = z_data[j].im;
    b_d = b_c_data[j].im;
    d1 = b_c_data[j].re;
    b_c_data[j + 1].re = d1 - -(double)loop_ub * b_d;
    b_c_data[j + 1].im = b_d + -(double)loop_ub * d1;
    for (k = j + 1; k >= 2; k--) {
      ks = -b_c_data[k - 2].im + (double)loop_ub * b_c_data[k - 2].re;
      b_c_data[k - 1].re -=
          -b_c_data[k - 2].re - (double)loop_ub * b_c_data[k - 2].im;
      b_c_data[k - 1].im -= ks;
    }
  }
  loop_ub = x_size - (int)n;
  varargout_1_size[0] = 1;
  varargout_1_size[1] = (loop_ub + (int)n) + 1;
  if (0 <= loop_ub - 1) {
    memset(&varargout_1_data[0], 0, loop_ub * sizeof(double));
  }
  for (k = 0; k < bd_size; k++) {
    varargout_1_data[k + loop_ub] = im * b_c_data[k].re;
  }
}

/*
 * Arguments    : double n
 *                double Wn
 *                const creal_T p_data[]
 *                int p_size
 *                creal_T z_data[]
 *                int *z_size
 *                double *k
 * Return Type  : void
 */
static void b_buttzeros(double n, double Wn, const creal_T p_data[], int p_size,
                        creal_T z_data[], int *z_size, double *k)
{
  creal_T x_data[1002];
  double d;
  double im;
  double r;
  double y_re;
  double zWn_im;
  double zWn_re;
  double zWn_re_tmp;
  int i;
  int i1;
  int loop_ub;
  signed char b_x_data[1000];
  boolean_T exitg1;
  boolean_T y;
  *z_size = (int)n + (int)n;
  loop_ub = (int)n;
  for (i = 0; i < loop_ub; i++) {
    z_data[i].re = 1.0;
    z_data[i].im = 0.0;
  }
  loop_ub = (int)n;
  for (i = 0; i < loop_ub; i++) {
    i1 = i + (int)n;
    z_data[i1].re = -1.0;
    z_data[i1].im = 0.0;
  }
  zWn_re_tmp = 2.0 * rt_atan2d_snf(Wn, 4.0);
  zWn_re = zWn_re_tmp * 0.0;
  if (zWn_re_tmp == 0.0) {
    zWn_re = exp(zWn_re);
    zWn_im = 0.0;
  } else {
    r = exp(zWn_re / 2.0);
    zWn_re = r * (r * cos(zWn_re_tmp));
    zWn_im = r * (r * sin(zWn_re_tmp));
  }
  for (i = 0; i < p_size; i++) {
    x_data[i].re = zWn_re - p_data[i].re;
    x_data[i].im = zWn_im - p_data[i].im;
  }
  if (p_size == 0) {
    y_re = 1.0;
    im = 0.0;
  } else {
    y_re = x_data[0].re;
    im = x_data[0].im;
    for (loop_ub = 2; loop_ub <= p_size; loop_ub++) {
      r = x_data[loop_ub - 1].re;
      d = x_data[loop_ub - 1].im;
      zWn_re_tmp = y_re * r - im * d;
      im = y_re * d + im * r;
      y_re = zWn_re_tmp;
    }
  }
  for (i = 0; i < *z_size; i++) {
    x_data[i].re = zWn_re - z_data[i].re;
    x_data[i].im = zWn_im - z_data[i].im;
  }
  if (*z_size == 0) {
    zWn_re = 1.0;
    zWn_im = 0.0;
  } else {
    zWn_re = x_data[0].re;
    zWn_im = x_data[0].im;
    for (loop_ub = 2; loop_ub <= *z_size; loop_ub++) {
      r = x_data[loop_ub - 1].re;
      d = x_data[loop_ub - 1].im;
      zWn_re_tmp = zWn_re * r - zWn_im * d;
      zWn_im = zWn_re * d + zWn_im * r;
      zWn_re = zWn_re_tmp;
    }
  }
  if (zWn_im == 0.0) {
    if (im == 0.0) {
      *k = y_re / zWn_re;
    } else if (y_re == 0.0) {
      *k = 0.0;
    } else {
      *k = y_re / zWn_re;
    }
  } else if (zWn_re == 0.0) {
    if (y_re == 0.0) {
      *k = im / zWn_im;
    } else if (im == 0.0) {
      *k = 0.0;
    } else {
      *k = im / zWn_im;
    }
  } else {
    zWn_re_tmp = fabs(zWn_re);
    r = fabs(zWn_im);
    if (zWn_re_tmp > r) {
      zWn_re_tmp = zWn_im / zWn_re;
      *k = (y_re + zWn_re_tmp * im) / (zWn_re + zWn_re_tmp * zWn_im);
    } else if (r == zWn_re_tmp) {
      if (zWn_re > 0.0) {
        zWn_re = 0.5;
      } else {
        zWn_re = -0.5;
      }
      if (zWn_im > 0.0) {
        zWn_im = 0.5;
      } else {
        zWn_im = -0.5;
      }
      *k = (y_re * zWn_re + im * zWn_im) / zWn_re_tmp;
    } else {
      zWn_re_tmp = zWn_re / zWn_im;
      *k = (zWn_re_tmp * y_re + im) / (zWn_im + zWn_re_tmp * zWn_re);
    }
  }
  for (i = 0; i < *z_size; i++) {
    b_x_data[i] = (signed char)z_data[i].im;
  }
  y = false;
  loop_ub = 1;
  exitg1 = false;
  while ((!exitg1) && (loop_ub <= *z_size)) {
    if (b_x_data[loop_ub - 1] == 0) {
      loop_ub++;
    } else {
      y = true;
      exitg1 = true;
    }
  }
  if (!y) {
    for (i = 0; i < *z_size; i++) {
      z_data[i].im = 0.0;
    }
  }
}

/*
 * Arguments    : const emxArray_real_T *A
 *                double B_data[]
 *                const int *B_size
 * Return Type  : void
 */
static void b_lusolve(const emxArray_real_T *A, double B_data[],
                      const int *B_size)
{
  emxArray_real_T *b_A;
  double temp;
  int ipiv_data[1002];
  int ipiv_size[2];
  int LDA;
  int b_i;
  int i;
  int k;
  int kAcol;
  int n;
  emxInit_real_T(&b_A, 2);
  LDA = A->size[0];
  n = A->size[1];
  if (LDA < n) {
    n = LDA;
  }
  LDA = *B_size;
  if (LDA < n) {
    n = LDA;
  }
  i = b_A->size[0] * b_A->size[1];
  b_A->size[0] = A->size[0];
  b_A->size[1] = A->size[1];
  emxEnsureCapacity_real_T(b_A, i);
  LDA = A->size[0] * A->size[1];
  for (i = 0; i < LDA; i++) {
    b_A->data[i] = A->data[i];
  }
  xzgetrf(n, n, b_A, A->size[0], ipiv_data, ipiv_size, &LDA);
  LDA = b_A->size[0];
  for (b_i = 0; b_i <= n - 2; b_i++) {
    i = ipiv_data[b_i];
    if (i != b_i + 1) {
      temp = B_data[b_i];
      B_data[b_i] = B_data[i - 1];
      B_data[i - 1] = temp;
    }
  }
  for (k = 0; k < n; k++) {
    kAcol = LDA * k;
    if (B_data[k] != 0.0) {
      i = k + 2;
      for (b_i = i; b_i <= n; b_i++) {
        B_data[b_i - 1] -= B_data[k] * b_A->data[(b_i + kAcol) - 1];
      }
    }
  }
  for (k = n; k >= 1; k--) {
    kAcol = LDA * (k - 1);
    temp = B_data[k - 1];
    if (temp != 0.0) {
      B_data[k - 1] = temp / b_A->data[(k + kAcol) - 1];
      for (b_i = 0; b_i <= k - 2; b_i++) {
        B_data[b_i] -= B_data[k - 1] * b_A->data[b_i + kAcol];
      }
    }
  }
  emxFree_real_T(&b_A);
}

/*
 * Arguments    : const emxArray_real_T *A
 *                const emxArray_real_T *B
 *                emxArray_real_T *Y
 * Return Type  : void
 */
static void b_mldivide(const emxArray_real_T *A, const emxArray_real_T *B,
                       emxArray_real_T *Y)
{
  int i;
  int loop_ub;
  if ((A->size[0] == 0) || (A->size[1] == 0) ||
      ((B->size[0] == 0) || (B->size[1] == 0))) {
    i = Y->size[0] * Y->size[1];
    Y->size[0] = (short)A->size[1];
    Y->size[1] = (short)B->size[1];
    emxEnsureCapacity_real_T(Y, i);
    loop_ub = (short)A->size[1] * (short)B->size[1];
    for (i = 0; i < loop_ub; i++) {
      Y->data[i] = 0.0;
    }
  } else if (A->size[0] == A->size[1]) {
    lusolve(A, B, Y);
  } else {
    b_qrsolve(A, B, Y);
  }
}

/*
 * Arguments    : const emxArray_real_T *A
 *                const emxArray_real_T *B
 *                emxArray_real_T *Y
 * Return Type  : void
 */
static void b_qrsolve(const emxArray_real_T *A, const emxArray_real_T *B,
                      emxArray_real_T *Y)
{
  emxArray_real_T *b_A;
  emxArray_real_T *b_B;
  double tau_data[1002];
  double wj;
  int jpvt_data[1002];
  int jpvt_size[2];
  int b_i;
  int b_nb;
  int i;
  int k;
  int loop_ub;
  int m;
  int mn;
  int nb;
  int rankA;
  emxInit_real_T(&b_A, 2);
  i = b_A->size[0] * b_A->size[1];
  b_A->size[0] = A->size[0];
  b_A->size[1] = A->size[1];
  emxEnsureCapacity_real_T(b_A, i);
  loop_ub = A->size[0] * A->size[1];
  for (i = 0; i < loop_ub; i++) {
    b_A->data[i] = A->data[i];
  }
  emxInit_real_T(&b_B, 2);
  xgeqp3(b_A, tau_data, &loop_ub, jpvt_data, jpvt_size);
  i = b_B->size[0] * b_B->size[1];
  b_B->size[0] = B->size[0];
  b_B->size[1] = B->size[1];
  emxEnsureCapacity_real_T(b_B, i);
  loop_ub = B->size[0] * B->size[1];
  for (i = 0; i < loop_ub; i++) {
    b_B->data[i] = B->data[i];
  }
  rankA = rankFromQR(b_A);
  nb = B->size[1];
  i = Y->size[0] * Y->size[1];
  Y->size[0] = (short)b_A->size[1];
  Y->size[1] = (short)B->size[1];
  emxEnsureCapacity_real_T(Y, i);
  loop_ub = (short)b_A->size[1] * (short)B->size[1];
  for (i = 0; i < loop_ub; i++) {
    Y->data[i] = 0.0;
  }
  m = b_A->size[0];
  b_nb = B->size[1];
  loop_ub = b_A->size[0];
  mn = b_A->size[1];
  if (loop_ub < mn) {
    mn = loop_ub;
  }
  for (loop_ub = 0; loop_ub < mn; loop_ub++) {
    if (tau_data[loop_ub] != 0.0) {
      for (k = 0; k < b_nb; k++) {
        wj = b_B->data[loop_ub + b_B->size[0] * k];
        i = loop_ub + 2;
        for (b_i = i; b_i <= m; b_i++) {
          wj += b_A->data[(b_i + b_A->size[0] * loop_ub) - 1] *
                b_B->data[(b_i + b_B->size[0] * k) - 1];
        }
        wj *= tau_data[loop_ub];
        if (wj != 0.0) {
          b_B->data[loop_ub + b_B->size[0] * k] -= wj;
          for (b_i = i; b_i <= m; b_i++) {
            b_B->data[(b_i + b_B->size[0] * k) - 1] -=
                b_A->data[(b_i + b_A->size[0] * loop_ub) - 1] * wj;
          }
        }
      }
    }
  }
  for (k = 0; k < nb; k++) {
    for (b_i = 0; b_i < rankA; b_i++) {
      Y->data[(jpvt_data[b_i] + Y->size[0] * k) - 1] =
          b_B->data[b_i + b_B->size[0] * k];
    }
    for (loop_ub = rankA; loop_ub >= 1; loop_ub--) {
      i = jpvt_data[loop_ub - 1];
      Y->data[(i + Y->size[0] * k) - 1] /=
          b_A->data[(loop_ub + b_A->size[0] * (loop_ub - 1)) - 1];
      for (b_i = 0; b_i <= loop_ub - 2; b_i++) {
        Y->data[(jpvt_data[b_i] + Y->size[0] * k) - 1] -=
            Y->data[(jpvt_data[loop_ub - 1] + Y->size[0] * k) - 1] *
            b_A->data[b_i + b_A->size[0] * (loop_ub - 1)];
      }
    }
  }
  emxFree_real_T(&b_B);
  emxFree_real_T(&b_A);
}

/*
 * Arguments    : creal_T *x
 * Return Type  : void
 */
static void b_sqrt(creal_T *x)
{
  double absxi;
  double absxr;
  double xi;
  double xr;
  xr = x->re;
  xi = x->im;
  if (xi == 0.0) {
    if (xr < 0.0) {
      absxi = 0.0;
      xr = sqrt(-xr);
    } else {
      absxi = sqrt(xr);
      xr = 0.0;
    }
  } else if (xr == 0.0) {
    if (xi < 0.0) {
      absxi = sqrt(-xi / 2.0);
      xr = -absxi;
    } else {
      absxi = sqrt(xi / 2.0);
      xr = absxi;
    }
  } else if (rtIsNaN(xr)) {
    absxi = xr;
  } else if (rtIsNaN(xi)) {
    absxi = xi;
    xr = xi;
  } else if (rtIsInf(xi)) {
    absxi = fabs(xi);
    xr = xi;
  } else if (rtIsInf(xr)) {
    if (xr < 0.0) {
      absxi = 0.0;
      xr = xi * -xr;
    } else {
      absxi = xr;
      xr = 0.0;
    }
  } else {
    absxr = fabs(xr);
    absxi = fabs(xi);
    if ((absxr > 4.4942328371557893E+307) ||
        (absxi > 4.4942328371557893E+307)) {
      absxr *= 0.5;
      absxi = rt_hypotd_snf(absxr, absxi * 0.5);
      if (absxi > absxr) {
        absxi = sqrt(absxi) * sqrt(absxr / absxi + 1.0);
      } else {
        absxi = sqrt(absxi) * 1.4142135623730951;
      }
    } else {
      absxi = sqrt((rt_hypotd_snf(absxr, absxi) + absxr) * 0.5);
    }
    if (xr > 0.0) {
      xr = 0.5 * (xi / absxi);
    } else {
      if (xi < 0.0) {
        xr = -absxi;
      } else {
        xr = absxi;
      }
      absxi = 0.5 * (xi / xr);
    }
  }
  x->re = absxi;
  x->im = xr;
}

/*
 * Arguments    : int n
 *                const double x[3]
 * Return Type  : double
 */
static double b_xnrm2(int n, const double x[3])
{
  double absxk;
  double scale;
  double t;
  double y;
  y = 0.0;
  if (n >= 1) {
    if (n == 1) {
      y = fabs(x[1]);
    } else {
      scale = 3.3121686421112381E-170;
      absxk = fabs(x[1]);
      if (absxk > 3.3121686421112381E-170) {
        y = 1.0;
        scale = absxk;
      } else {
        t = absxk / 3.3121686421112381E-170;
        y = t * t;
      }
      absxk = fabs(x[2]);
      if (absxk > scale) {
        t = scale / absxk;
        y = y * t * t + 1.0;
        scale = absxk;
      } else {
        t = absxk / scale;
        y += t * t;
      }
      y = scale * sqrt(y);
    }
  }
  return y;
}

/*
 * Arguments    : const creal_T f
 *                const creal_T g
 *                double *cs
 *                creal_T *sn
 * Return Type  : void
 */
static void b_xzlartg(const creal_T f, const creal_T g, double *cs, creal_T *sn)
{
  double f2;
  double fs_im;
  double fs_re;
  double g2;
  double g2s;
  double gs_im;
  double gs_re;
  double scale;
  double scale_tmp;
  boolean_T guard1 = false;
  scale_tmp = fabs(f.re);
  f2 = fabs(f.im);
  if (f2 > scale_tmp) {
    scale_tmp = f2;
  }
  f2 = fabs(g.re);
  scale = fabs(g.im);
  if (scale > f2) {
    f2 = scale;
  }
  scale = scale_tmp;
  if (f2 > scale_tmp) {
    scale = f2;
  }
  fs_re = f.re;
  fs_im = f.im;
  gs_re = g.re;
  gs_im = g.im;
  guard1 = false;
  if (scale >= 7.4428285367870146E+137) {
    do {
      fs_re *= 1.3435752215134178E-138;
      fs_im *= 1.3435752215134178E-138;
      gs_re *= 1.3435752215134178E-138;
      gs_im *= 1.3435752215134178E-138;
      scale *= 1.3435752215134178E-138;
    } while (!(scale < 7.4428285367870146E+137));
    guard1 = true;
  } else if (scale <= 1.3435752215134178E-138) {
    if ((g.re == 0.0) && (g.im == 0.0)) {
      *cs = 1.0;
      sn->re = 0.0;
      sn->im = 0.0;
    } else {
      do {
        fs_re *= 7.4428285367870146E+137;
        fs_im *= 7.4428285367870146E+137;
        gs_re *= 7.4428285367870146E+137;
        gs_im *= 7.4428285367870146E+137;
        scale *= 7.4428285367870146E+137;
      } while (!(scale > 1.3435752215134178E-138));
      guard1 = true;
    }
  } else {
    guard1 = true;
  }
  if (guard1) {
    f2 = fs_re * fs_re + fs_im * fs_im;
    g2 = gs_re * gs_re + gs_im * gs_im;
    scale = g2;
    if (1.0 > g2) {
      scale = 1.0;
    }
    if (f2 <= scale * 2.0041683600089728E-292) {
      if ((f.re == 0.0) && (f.im == 0.0)) {
        *cs = 0.0;
        g2 = rt_hypotd_snf(gs_re, gs_im);
        sn->re = gs_re / g2;
        sn->im = -gs_im / g2;
      } else {
        g2s = sqrt(g2);
        *cs = rt_hypotd_snf(fs_re, fs_im) / g2s;
        if (scale_tmp > 1.0) {
          g2 = rt_hypotd_snf(f.re, f.im);
          fs_re = f.re / g2;
          fs_im = f.im / g2;
        } else {
          f2 = 7.4428285367870146E+137 * f.re;
          scale = 7.4428285367870146E+137 * f.im;
          g2 = rt_hypotd_snf(f2, scale);
          fs_re = f2 / g2;
          fs_im = scale / g2;
        }
        gs_re /= g2s;
        gs_im = -gs_im / g2s;
        sn->re = fs_re * gs_re - fs_im * gs_im;
        sn->im = fs_re * gs_im + fs_im * gs_re;
      }
    } else {
      scale = sqrt(g2 / f2 + 1.0);
      *cs = 1.0 / scale;
      g2 += f2;
      fs_re = scale * fs_re / g2;
      fs_im = scale * fs_im / g2;
      sn->re = fs_re * gs_re - fs_im * -gs_im;
      sn->im = fs_re * -gs_im + fs_im * gs_re;
    }
  }
}

/*
 * Arguments    : const emxArray_real_T *z
 *                const double p_data[]
 *                int p_size
 *                const double k_data[]
 *                const int k_size[2]
 *                double fs
 *                emxArray_real_T *zd
 *                double pd_data[]
 *                int *pd_size
 *                double kd_data[]
 *                int kd_size[2]
 *                double *dd
 * Return Type  : void
 */
static void bilinear(const emxArray_real_T *z, const double p_data[],
                     int p_size, const double k_data[], const int k_size[2],
                     double fs, emxArray_real_T *zd, double pd_data[],
                     int *pd_size, double kd_data[], int kd_size[2], double *dd)
{
  emxArray_int8_T *b_I;
  emxArray_real_T *c_I;
  emxArray_real_T *r;
  emxArray_real_T *t2;
  double tmp_data[1002];
  double b_d;
  int tmp_size[2];
  int d;
  int i;
  int loop_ub;
  emxInit_real_T(&r, 2);
  i = r->size[0] * r->size[1];
  r->size[0] = z->size[0];
  r->size[1] = z->size[1];
  emxEnsureCapacity_real_T(r, i);
  loop_ub = z->size[0] * z->size[1];
  for (i = 0; i < loop_ub; i++) {
    r->data[i] = z->data[i] * 0.5 / 2.0;
  }
  emxInit_real_T(&t2, 2);
  loop_ub = (short)z->size[0];
  d = (short)z->size[1];
  if (loop_ub < d) {
    d = loop_ub;
  }
  i = t2->size[0] * t2->size[1];
  t2->size[0] = (short)z->size[0];
  t2->size[1] = (short)z->size[1];
  emxEnsureCapacity_real_T(t2, i);
  loop_ub = (short)z->size[0] * (short)z->size[1];
  for (i = 0; i < loop_ub; i++) {
    t2->data[i] = 0.0;
  }
  if (d > 0) {
    for (loop_ub = 0; loop_ub < d; loop_ub++) {
      t2->data[loop_ub + t2->size[0] * loop_ub] = 1.0;
    }
  }
  loop_ub = t2->size[0] * t2->size[1];
  for (i = 0; i < loop_ub; i++) {
    t2->data[i] -= r->data[i];
  }
  emxInit_int8_T(&b_I, 2);
  loop_ub = (short)z->size[0];
  d = (short)z->size[1];
  if (loop_ub < d) {
    d = loop_ub;
  }
  i = b_I->size[0] * b_I->size[1];
  b_I->size[0] = (short)z->size[0];
  b_I->size[1] = (short)z->size[1];
  emxEnsureCapacity_int8_T(b_I, i);
  loop_ub = (short)z->size[0] * (short)z->size[1];
  for (i = 0; i < loop_ub; i++) {
    b_I->data[i] = 0;
  }
  if (d > 0) {
    for (loop_ub = 0; loop_ub < d; loop_ub++) {
      b_I->data[loop_ub + b_I->size[0] * loop_ub] = 1;
    }
  }
  emxInit_real_T(&c_I, 2);
  i = c_I->size[0] * c_I->size[1];
  c_I->size[0] = b_I->size[0];
  c_I->size[1] = b_I->size[1];
  emxEnsureCapacity_real_T(c_I, i);
  loop_ub = b_I->size[0] * b_I->size[1];
  for (i = 0; i < loop_ub; i++) {
    c_I->data[i] = (double)b_I->data[i] + r->data[i];
  }
  emxFree_int8_T(&b_I);
  emxFree_real_T(&r);
  b_mldivide(t2, c_I, zd);
  mldivide(t2, p_data, p_size, pd_data, pd_size);
  emxFree_real_T(&c_I);
  for (i = 0; i < *pd_size; i++) {
    pd_data[i] *= 0.70710678118654746;
  }
  tmp_size[0] = 1;
  tmp_size[1] = k_size[1];
  loop_ub = k_size[1];
  for (i = 0; i < loop_ub; i++) {
    tmp_data[i] = 0.70710678118654757 * k_data[i];
  }
  mrdiv(tmp_data, tmp_size, t2, kd_data, kd_size);
  mrdiv(k_data, k_size, t2, tmp_data, tmp_size);
  b_d = 0.0;
  loop_ub = tmp_size[1];
  emxFree_real_T(&t2);
  for (i = 0; i < loop_ub; i++) {
    b_d += tmp_data[i] * p_data[i];
  }
  *dd = b_d * 0.5 / 2.0 + fs;
}

/*
 * Arguments    : double n
 *                creal_T p_data[]
 *                int *p_size
 *                double *k
 * Return Type  : void
 */
static void buttap(double n, creal_T p_data[], int *p_size, double *k)
{
  creal_T x_data[1002];
  creal_T ptemp_data[250];
  double y_data[250];
  double d;
  double im;
  double r;
  double re;
  int loop_ub;
  int p_tmp;
  int y_size_idx_1;
  boolean_T guard1 = false;
  if (rtIsNaN(n - 1.0)) {
    y_size_idx_1 = 1;
    y_data[0] = rtNaN;
  } else if (n - 1.0 < 1.0) {
    y_size_idx_1 = 0;
  } else {
    loop_ub = (int)floor(((n - 1.0) - 1.0) / 2.0);
    y_size_idx_1 = loop_ub + 1;
    for (p_tmp = 0; p_tmp <= loop_ub; p_tmp++) {
      y_data[p_tmp] = 2.0 * (double)p_tmp + 1.0;
    }
  }
  d = 2.0 * n;
  for (p_tmp = 0; p_tmp < y_size_idx_1; p_tmp++) {
    r = 3.1415926535897931 * y_data[p_tmp] / d + 1.5707963267948966;
    ptemp_data[p_tmp].re = r * 0.0;
    ptemp_data[p_tmp].im = r;
  }
  for (loop_ub = 0; loop_ub < y_size_idx_1; loop_ub++) {
    d = ptemp_data[loop_ub].im;
    if (d == 0.0) {
      ptemp_data[loop_ub].re = exp(ptemp_data[loop_ub].re);
      ptemp_data[loop_ub].im = 0.0;
    } else {
      guard1 = false;
      if (rtIsInf(d)) {
        r = ptemp_data[loop_ub].re;
        if (rtIsInf(r) && (r < 0.0)) {
          ptemp_data[loop_ub].re = 0.0;
          ptemp_data[loop_ub].im = 0.0;
        } else {
          guard1 = true;
        }
      } else {
        guard1 = true;
      }
      if (guard1) {
        r = exp(ptemp_data[loop_ub].re / 2.0);
        ptemp_data[loop_ub].re = r * (r * cos(d));
        d = r * (r * sin(d));
        ptemp_data[loop_ub].im = d;
      }
    }
  }
  if (rtIsNaN(n) || rtIsInf(n)) {
    r = rtNaN;
  } else if (n == 0.0) {
    r = 0.0;
  } else {
    r = fmod(n, 2.0);
    if (r == 0.0) {
      r = 0.0;
    } else if (n < 0.0) {
      r += 2.0;
    }
  }
  if (r == 1.0) {
    loop_ub = y_size_idx_1 << 1;
    *p_size = loop_ub + 1;
    p_data[loop_ub].re = -1.0;
    p_data[loop_ub].im = 0.0;
  } else {
    *p_size = y_size_idx_1 << 1;
  }
  for (loop_ub = 0; loop_ub < y_size_idx_1; loop_ub++) {
    p_tmp = ((loop_ub + 1) << 1) - 1;
    p_data[p_tmp - 1] = ptemp_data[loop_ub];
    p_data[p_tmp].re = ptemp_data[loop_ub].re;
    p_data[p_tmp].im = -ptemp_data[loop_ub].im;
  }
  for (p_tmp = 0; p_tmp < *p_size; p_tmp++) {
    x_data[p_tmp].re = -p_data[p_tmp].re;
    x_data[p_tmp].im = -p_data[p_tmp].im;
  }
  if (*p_size == 0) {
    *k = 1.0;
  } else {
    *k = x_data[0].re;
    im = x_data[0].im;
    for (loop_ub = 2; loop_ub <= *p_size; loop_ub++) {
      d = x_data[loop_ub - 1].re;
      r = x_data[loop_ub - 1].im;
      re = *k * d - im * r;
      im = *k * r + im * d;
      *k = re;
    }
  }
}

/*
 * Arguments    : double n
 *                double Wn
 *                double varargout_1_data[]
 *                int varargout_1_size[2]
 *                double varargout_2_data[]
 *                int varargout_2_size[2]
 * Return Type  : void
 */
static void butter(double n, double Wn, double varargout_1_data[],
                   int varargout_1_size[2], double varargout_2_data[],
                   int varargout_2_size[2])
{
  emxArray_real_T *a;
  emxArray_real_T *ad;
  emxArray_real_T *b_ad;
  creal_T b_c_data[1003];
  creal_T x_data[1002];
  creal_T p_data[501];
  cuint8_T z_data[500];
  double b_bd_data[1002];
  double b_cd_data[1002];
  double b_data[501];
  double bd_data[501];
  double c_data[501];
  double cd_data[501];
  double b_d;
  double d;
  double d1;
  double dd;
  double ks;
  int c_size[2];
  int cd_size[2];
  int b_bd_size;
  int b_size;
  int bd_size;
  int j;
  int x_size;
  signed char z_im_tmp;
  emxInit_real_T(&a, 2);
  emxInit_real_T(&ad, 2);
  emxInit_real_T(&b_ad, 2);
  buttap(n, p_data, &x_size, &ks);
  zp2ss(p_data, x_size, ks, a, b_data, &b_size, c_data, c_size, &d);
  lp2hp(a, b_data, b_size, c_data, c_size, d,
        4.0 * tan(3.1415926535897931 * Wn / 2.0), ad, bd_data, &bd_size,
        cd_data, cd_size, &dd);
  bilinear(ad, bd_data, bd_size, cd_data, cd_size, dd, b_ad, b_bd_data,
           &b_bd_size, b_cd_data, c_size, &ks);
  eig(b_ad, x_data, &x_size);
  emxFree_real_T(&b_ad);
  emxFree_real_T(&ad);
  emxFree_real_T(&a);
  if (0 <= x_size - 1) {
    memcpy(&p_data[0], &x_data[0], x_size * sizeof(creal_T));
  }
  bd_size = (int)n;
  for (b_bd_size = 0; b_bd_size < x_size; b_bd_size++) {
    x_data[b_bd_size].re = p_data[b_bd_size].re + 1.0;
    x_data[b_bd_size].im = p_data[b_bd_size].im;
  }
  if (x_size == 0) {
    ks = 1.0;
  } else {
    ks = x_data[0].re;
    dd = x_data[0].im;
    for (b_bd_size = 2; b_bd_size <= x_size; b_bd_size++) {
      b_d = x_data[b_bd_size - 1].re;
      d1 = x_data[b_bd_size - 1].im;
      d = ks * b_d - dd * d1;
      dd = ks * d1 + dd * b_d;
      ks = d;
    }
  }
  dd = ks / rt_powd_snf(2.0, n);
  for (b_bd_size = 0; b_bd_size < bd_size; b_bd_size++) {
    z_data[b_bd_size].re = 1U;
    z_data[b_bd_size].im = 0U;
  }
  b_size = x_size + 1;
  b_c_data[0].re = 1.0;
  b_c_data[0].im = 0.0;
  for (j = 0; j < x_size; j++) {
    ks = -p_data[j].re;
    d = -p_data[j].im;
    b_d = b_c_data[j].im;
    d1 = b_c_data[j].re;
    b_c_data[j + 1].re = ks * d1 - d * b_d;
    b_c_data[j + 1].im = ks * b_d + d * d1;
    for (b_bd_size = j + 1; b_bd_size >= 2; b_bd_size--) {
      b_d = p_data[j].re;
      d1 = p_data[j].im;
      d = b_d * b_c_data[b_bd_size - 2].im + d1 * b_c_data[b_bd_size - 2].re;
      b_c_data[b_bd_size - 1].re -=
          b_d * b_c_data[b_bd_size - 2].re - d1 * b_c_data[b_bd_size - 2].im;
      b_c_data[b_bd_size - 1].im -= d;
    }
  }
  varargout_2_size[0] = 1;
  varargout_2_size[1] = x_size + 1;
  for (b_bd_size = 0; b_bd_size < b_size; b_bd_size++) {
    varargout_2_data[b_bd_size] = b_c_data[b_bd_size].re;
  }
  b_size = (int)n + 1;
  b_c_data[0].re = 1.0;
  b_c_data[0].im = 0.0;
  for (j = 0; j < bd_size; j++) {
    z_im_tmp = (signed char)z_data[j].im;
    b_d = b_c_data[j].im;
    d1 = b_c_data[j].re;
    b_c_data[j + 1].re = -d1 - -(double)z_im_tmp * b_d;
    b_c_data[j + 1].im = -b_d + -(double)z_im_tmp * d1;
    for (b_bd_size = j + 1; b_bd_size >= 2; b_bd_size--) {
      ks = b_c_data[b_bd_size - 2].im +
           (double)z_im_tmp * b_c_data[b_bd_size - 2].re;
      b_c_data[b_bd_size - 1].re -=
          b_c_data[b_bd_size - 2].re -
          (double)z_im_tmp * b_c_data[b_bd_size - 2].im;
      b_c_data[b_bd_size - 1].im -= ks;
    }
  }
  bd_size = x_size - (int)n;
  varargout_1_size[0] = 1;
  varargout_1_size[1] = (bd_size + (int)n) + 1;
  if (0 <= bd_size - 1) {
    memset(&varargout_1_data[0], 0, bd_size * sizeof(double));
  }
  for (b_bd_size = 0; b_bd_size < b_size; b_bd_size++) {
    varargout_1_data[b_bd_size + bd_size] = dd * b_c_data[b_bd_size].re;
  }
}

/*
 * Arguments    : double n
 *                double Wn
 *                const creal_T p_data[]
 *                int p_size
 *                creal_T z_data[]
 *                int *z_size
 *                double *k
 * Return Type  : void
 */
static void buttzeros(double n, double Wn, const creal_T p_data[], int p_size,
                      creal_T z_data[], int *z_size, double *k)
{
  creal_T x_data[1002];
  double tmp_data[1000];
  double y_data[1000];
  double b_im;
  double b_y_re;
  double d;
  double im;
  double r;
  double re;
  double y_re;
  int i;
  int loop_ub;
  int tmp_size_idx_1_tmp;
  int y_size_idx_1;
  boolean_T exitg1;
  boolean_T guard1 = false;
  boolean_T y;
  r = 2.0 * n - 1.0;
  if (rtIsNaN(r)) {
    y_size_idx_1 = 1;
    y_data[0] = rtNaN;
  } else if (r < 0.0) {
    y_size_idx_1 = 0;
  } else if (rtIsInf(r) && (0.0 == r)) {
    y_size_idx_1 = 1;
    y_data[0] = rtNaN;
  } else {
    loop_ub = (int)floor(r);
    y_size_idx_1 = loop_ub + 1;
    for (i = 0; i <= loop_ub; i++) {
      y_data[i] = i;
    }
  }
  tmp_size_idx_1_tmp = (short)y_size_idx_1;
  for (loop_ub = 0; loop_ub < tmp_size_idx_1_tmp; loop_ub++) {
    tmp_data[loop_ub] = rt_powd_snf(-1.0, y_data[loop_ub]);
  }
  r = 2.0 * rt_atan2d_snf(Wn, 4.0);
  y_re = r * 0.0;
  *z_size = (short)y_size_idx_1;
  for (i = 0; i < tmp_size_idx_1_tmp; i++) {
    d = tmp_data[i];
    z_data[i].re = d * y_re;
    z_data[i].im = d * r;
  }
  for (loop_ub = 0; loop_ub < tmp_size_idx_1_tmp; loop_ub++) {
    d = z_data[loop_ub].im;
    if (d == 0.0) {
      z_data[loop_ub].re = exp(z_data[loop_ub].re);
      z_data[loop_ub].im = 0.0;
    } else {
      guard1 = false;
      if (rtIsInf(d)) {
        r = z_data[loop_ub].re;
        if (rtIsInf(r) && (r < 0.0)) {
          z_data[loop_ub].re = 0.0;
          z_data[loop_ub].im = 0.0;
        } else {
          guard1 = true;
        }
      } else {
        guard1 = true;
      }
      if (guard1) {
        r = exp(z_data[loop_ub].re / 2.0);
        z_data[loop_ub].re = r * (r * cos(d));
        d = r * (r * sin(d));
        z_data[loop_ub].im = d;
      }
    }
  }
  for (i = 0; i < p_size; i++) {
    x_data[i].re = 1.0 - p_data[i].re;
    x_data[i].im = 0.0 - p_data[i].im;
  }
  if (p_size == 0) {
    y_re = 1.0;
    im = 0.0;
  } else {
    y_re = x_data[0].re;
    im = x_data[0].im;
    for (loop_ub = 2; loop_ub <= p_size; loop_ub++) {
      d = x_data[loop_ub - 1].re;
      r = x_data[loop_ub - 1].im;
      re = y_re * d - im * r;
      im = y_re * r + im * d;
      y_re = re;
    }
  }
  for (i = 0; i < tmp_size_idx_1_tmp; i++) {
    x_data[i].re = 1.0 - z_data[i].re;
    x_data[i].im = 0.0 - z_data[i].im;
  }
  if ((short)y_size_idx_1 == 0) {
    b_y_re = 1.0;
    b_im = 0.0;
  } else {
    b_y_re = x_data[0].re;
    b_im = x_data[0].im;
    for (loop_ub = 2; loop_ub <= tmp_size_idx_1_tmp; loop_ub++) {
      d = x_data[loop_ub - 1].re;
      r = x_data[loop_ub - 1].im;
      re = b_y_re * d - b_im * r;
      b_im = b_y_re * r + b_im * d;
      b_y_re = re;
    }
  }
  if (b_im == 0.0) {
    if (im == 0.0) {
      *k = y_re / b_y_re;
    } else if (y_re == 0.0) {
      *k = 0.0;
    } else {
      *k = y_re / b_y_re;
    }
  } else if (b_y_re == 0.0) {
    if (y_re == 0.0) {
      *k = im / b_im;
    } else if (im == 0.0) {
      *k = 0.0;
    } else {
      *k = im / b_im;
    }
  } else {
    r = fabs(b_y_re);
    re = fabs(b_im);
    if (r > re) {
      r = b_im / b_y_re;
      *k = (y_re + r * im) / (b_y_re + r * b_im);
    } else if (re == r) {
      if (b_y_re > 0.0) {
        b_y_re = 0.5;
      } else {
        b_y_re = -0.5;
      }
      if (b_im > 0.0) {
        b_im = 0.5;
      } else {
        b_im = -0.5;
      }
      *k = (y_re * b_y_re + im * b_im) / r;
    } else {
      r = b_y_re / b_im;
      *k = (r * y_re + im) / (b_im + r * b_y_re);
    }
  }
  for (i = 0; i < tmp_size_idx_1_tmp; i++) {
    y_data[i] = z_data[i].im;
  }
  y = false;
  loop_ub = 0;
  exitg1 = false;
  while ((!exitg1) && (loop_ub + 1 <= (short)y_size_idx_1)) {
    if ((y_data[loop_ub] == 0.0) || rtIsNaN(y_data[loop_ub])) {
      loop_ub++;
    } else {
      y = true;
      exitg1 = true;
    }
  }
  if (!y) {
    for (i = 0; i < tmp_size_idx_1_tmp; i++) {
      z_data[i].im = 0.0;
    }
  }
}

/*
 * Arguments    : double n
 *                const double Wn[2]
 *                double varargout_1_data[]
 *                int varargout_1_size[2]
 *                double varargout_2_data[]
 *                int varargout_2_size[2]
 * Return Type  : void
 */
static void c_butter(double n, const double Wn[2], double varargout_1_data[],
                     int varargout_1_size[2], double varargout_2_data[],
                     int varargout_2_size[2])
{
  emxArray_real_T *a;
  emxArray_real_T *ad;
  emxArray_real_T *b_ad;
  creal_T b_c_data[1003];
  creal_T p_data[1002];
  creal_T z_data[1000];
  creal_T ps_data[501];
  double b_bd_data[1002];
  double b_cd_data[1002];
  double bd_data[1002];
  double cd_data[1002];
  double b_data[501];
  double c_data[501];
  double Wn1;
  double d;
  double dd;
  double ks;
  double u_idx_0;
  double u_idx_1;
  int c_size[2];
  int cd_size[2];
  int b_size;
  int bd_size;
  int j;
  int k;
  int ps_size;
  emxInit_real_T(&a, 2);
  emxInit_real_T(&ad, 2);
  emxInit_real_T(&b_ad, 2);
  u_idx_0 = 4.0 * tan(3.1415926535897931 * Wn[0] / 2.0);
  u_idx_1 = 4.0 * tan(3.1415926535897931 * Wn[1] / 2.0);
  buttap(n, ps_data, &ps_size, &ks);
  zp2ss(ps_data, ps_size, ks, a, b_data, &b_size, c_data, c_size, &d);
  Wn1 = sqrt(u_idx_0 * u_idx_1);
  lp2bs(a, b_data, b_size, c_data, c_size, d, Wn1, u_idx_1 - u_idx_0, ad,
        bd_data, &ps_size, cd_data, cd_size, &dd);
  bilinear(ad, bd_data, ps_size, cd_data, cd_size, dd, b_ad, b_bd_data,
           &bd_size, b_cd_data, c_size, &ks);
  eig(b_ad, p_data, &ps_size);
  buttzeros(n, Wn1, p_data, ps_size, z_data, &b_size, &dd);
  bd_size = ps_size + 1;
  b_c_data[0].re = 1.0;
  b_c_data[0].im = 0.0;
  emxFree_real_T(&b_ad);
  emxFree_real_T(&ad);
  emxFree_real_T(&a);
  for (j = 0; j < ps_size; j++) {
    ks = -p_data[j].re;
    u_idx_0 = -p_data[j].im;
    u_idx_1 = b_c_data[j].im;
    d = b_c_data[j].re;
    b_c_data[j + 1].re = ks * d - u_idx_0 * u_idx_1;
    b_c_data[j + 1].im = ks * u_idx_1 + u_idx_0 * d;
    for (k = j + 1; k >= 2; k--) {
      u_idx_1 = p_data[j].re;
      d = p_data[j].im;
      u_idx_0 = u_idx_1 * b_c_data[k - 2].im + d * b_c_data[k - 2].re;
      b_c_data[k - 1].re -=
          u_idx_1 * b_c_data[k - 2].re - d * b_c_data[k - 2].im;
      b_c_data[k - 1].im -= u_idx_0;
    }
  }
  varargout_2_size[0] = 1;
  varargout_2_size[1] = ps_size + 1;
  for (j = 0; j < bd_size; j++) {
    varargout_2_data[j] = b_c_data[j].re;
  }
  bd_size = b_size + 1;
  b_c_data[0].re = 1.0;
  b_c_data[0].im = 0.0;
  for (j = 0; j < b_size; j++) {
    ks = -z_data[j].re;
    u_idx_0 = -z_data[j].im;
    u_idx_1 = b_c_data[j].im;
    d = b_c_data[j].re;
    b_c_data[j + 1].re = ks * d - u_idx_0 * u_idx_1;
    b_c_data[j + 1].im = ks * u_idx_1 + u_idx_0 * d;
    for (k = j + 1; k >= 2; k--) {
      u_idx_1 = z_data[j].re;
      d = z_data[j].im;
      u_idx_0 = u_idx_1 * b_c_data[k - 2].im + d * b_c_data[k - 2].re;
      b_c_data[k - 1].re -=
          u_idx_1 * b_c_data[k - 2].re - d * b_c_data[k - 2].im;
      b_c_data[k - 1].im -= u_idx_0;
    }
  }
  ps_size -= b_size;
  varargout_1_size[0] = 1;
  varargout_1_size[1] = (ps_size + b_size) + 1;
  if (0 <= ps_size - 1) {
    memset(&varargout_1_data[0], 0, ps_size * sizeof(double));
  }
  for (j = 0; j < bd_size; j++) {
    varargout_1_data[j + ps_size] = dd * b_c_data[j].re;
  }
}

/*
 * Arguments    : const emxArray_real_T *A
 *                double B_data[]
 *                const int B_size[2]
 * Return Type  : void
 */
static void c_lusolve(const emxArray_real_T *A, double B_data[],
                      const int B_size[2])
{
  emxArray_real_T *b_A;
  double temp;
  int ipiv_data[1002];
  int ipiv_size[2];
  int i;
  int i1;
  int j;
  int jAcol;
  int k;
  int n;
  emxInit_real_T(&b_A, 2);
  n = A->size[1];
  i = b_A->size[0] * b_A->size[1];
  b_A->size[0] = A->size[0];
  b_A->size[1] = A->size[1];
  emxEnsureCapacity_real_T(b_A, i);
  jAcol = A->size[0] * A->size[1];
  for (i = 0; i < jAcol; i++) {
    b_A->data[i] = A->data[i];
  }
  xzgetrf(A->size[1], A->size[1], b_A, A->size[1], ipiv_data, ipiv_size,
          &jAcol);
  if ((A->size[1] != 0) && (B_size[1] != 0)) {
    for (j = 0; j < n; j++) {
      jAcol = n * j;
      for (k = 0; k < j; k++) {
        i = k + jAcol;
        if (b_A->data[i] != 0.0) {
          B_data[j] -= b_A->data[i] * B_data[k];
        }
      }
      B_data[j] *= 1.0 / b_A->data[j + jAcol];
    }
  }
  if ((A->size[1] != 0) && (B_size[1] != 0)) {
    for (j = n; j >= 1; j--) {
      jAcol = n * (j - 1) - 1;
      i = j + 1;
      for (k = i; k <= n; k++) {
        i1 = k + jAcol;
        if (b_A->data[i1] != 0.0) {
          B_data[j - 1] -= b_A->data[i1] * B_data[k - 1];
        }
      }
    }
  }
  emxFree_real_T(&b_A);
  i = A->size[1] - 1;
  for (j = i; j >= 1; j--) {
    i1 = ipiv_data[j - 1];
    if (i1 != j) {
      temp = B_data[j - 1];
      B_data[j - 1] = B_data[i1 - 1];
      B_data[i1 - 1] = temp;
    }
  }
}

/*
 * Arguments    : creal_T x_data[]
 *                const int *x_size
 *                double tol
 * Return Type  : boolean_T
 */
static boolean_T cplxpairv(creal_T x_data[], const int *x_size, double tol)
{
  double absx_data[501];
  double zi_data[501];
  double zr_data[501];
  double absxk;
  int b_iwork_data[501];
  int idx_data[501];
  int iwork_data[501];
  int b_i;
  int b_k;
  int i;
  int i1;
  int i2;
  int j;
  int k;
  int kEnd;
  int n;
  int nc;
  int ng;
  int nr;
  int offset;
  int p;
  int pEnd;
  int q;
  int qEnd;
  boolean_T exitg1;
  boolean_T exitg2;
  boolean_T pairable;
  n = *x_size;
  i1 = *x_size;
  for (i = 0; i < *x_size; i++) {
    zr_data[i] = x_data[i].re;
  }
  nr = (short)i1;
  if (0 <= nr - 1) {
    memset(&idx_data[0], 0, nr * sizeof(int));
  }
  i = i1 - 1;
  for (k = 1; k <= i; k += 2) {
    absxk = zr_data[k];
    if ((zr_data[k - 1] <= absxk) || rtIsNaN(absxk)) {
      idx_data[k - 1] = k;
      idx_data[k] = k + 1;
    } else {
      idx_data[k - 1] = k + 1;
      idx_data[k] = k;
    }
  }
  if ((i1 & 1) != 0) {
    idx_data[i1 - 1] = i1;
  }
  b_i = 2;
  while (b_i < i1) {
    i2 = b_i << 1;
    j = 1;
    for (pEnd = b_i + 1; pEnd < i1 + 1; pEnd = qEnd + b_i) {
      p = j;
      q = pEnd - 1;
      qEnd = j + i2;
      if (qEnd > i1 + 1) {
        qEnd = i1 + 1;
      }
      k = 0;
      kEnd = qEnd - j;
      while (k + 1 <= kEnd) {
        absxk = zr_data[idx_data[q] - 1];
        i = idx_data[p - 1];
        if ((zr_data[i - 1] <= absxk) || rtIsNaN(absxk)) {
          iwork_data[k] = i;
          p++;
          if (p == pEnd) {
            while (q + 1 < qEnd) {
              k++;
              iwork_data[k] = idx_data[q];
              q++;
            }
          }
        } else {
          iwork_data[k] = idx_data[q];
          q++;
          if (q + 1 == qEnd) {
            while (p < pEnd) {
              k++;
              iwork_data[k] = idx_data[p - 1];
              p++;
            }
          }
        }
        k++;
      }
      for (k = 0; k < kEnd; k++) {
        idx_data[(j + k) - 1] = iwork_data[k];
      }
      j = qEnd;
    }
    b_i = i2;
  }
  nr = 0;
  nc = -1;
  for (k = 0; k < n; k++) {
    i = idx_data[k];
    absxk = rt_hypotd_snf(x_data[i - 1].re, x_data[i - 1].im);
    if (fabs(x_data[i - 1].im) <= tol * absxk) {
      nr++;
      i1 = n - nr;
      zr_data[i1] = x_data[i - 1].re;
      zi_data[i1] = 0.0;
      absx_data[k] = absxk;
    } else {
      nc++;
      zr_data[nc] = x_data[i - 1].re;
      zi_data[nc] = x_data[i - 1].im;
      absx_data[nc] = absxk;
    }
  }
  for (k = 0; k < nr; k++) {
    i = (nc + k) + 1;
    x_data[i].re = zr_data[(n - k) - 1];
    x_data[i].im = 0.0;
  }
  for (k = 0; k <= nc; k++) {
    x_data[k].re = zr_data[k];
    x_data[k].im = zi_data[k];
  }
  pairable = (((nc + 1) & 1) != 1);
  if (pairable) {
    k = 1;
    exitg1 = false;
    while ((!exitg1) && (k <= nc + 1)) {
      if (zr_data[k] - zr_data[k - 1] > tol * absx_data[k - 1]) {
        pairable = false;
        exitg1 = true;
      } else {
        k += 2;
      }
    }
  }
  if (pairable) {
    k = 1;
    exitg1 = false;
    while ((!exitg1) && (k < nc + 1)) {
      absxk = zr_data[k - 1];
      n = k;
      offset = k - 2;
      while ((k < nc + 1) && (zr_data[k] - absxk <= tol * absx_data[k - 1])) {
        k++;
      }
      ng = (k - n) + 1;
      nr = ng & 1;
      pairable = (nr == 0);
      if (!pairable) {
        exitg1 = true;
      } else {
        i = ng - 1;
        for (b_k = 1; b_k <= i; b_k += 2) {
          i1 = offset + b_k;
          absxk = zi_data[i1 + 1];
          if ((zi_data[i1] <= absxk) || rtIsNaN(absxk)) {
            idx_data[i1] = b_k;
            idx_data[i1 + 1] = b_k + 1;
          } else {
            idx_data[i1] = b_k + 1;
            idx_data[i1 + 1] = b_k;
          }
        }
        if (nr != 0) {
          idx_data[offset + ng] = ng;
        }
        b_i = 2;
        while (b_i < ng) {
          i2 = b_i << 1;
          j = 1;
          for (pEnd = b_i + 1; pEnd < ng + 1; pEnd = qEnd + b_i) {
            p = j;
            q = pEnd;
            qEnd = j + i2;
            if (qEnd > ng + 1) {
              qEnd = ng + 1;
            }
            b_k = 0;
            kEnd = qEnd - j;
            while (b_k + 1 <= kEnd) {
              nr = idx_data[offset + q];
              absxk = zi_data[offset + nr];
              i = idx_data[offset + p];
              if ((zi_data[offset + i] <= absxk) || rtIsNaN(absxk)) {
                b_iwork_data[b_k] = i;
                p++;
                if (p == pEnd) {
                  while (q < qEnd) {
                    b_k++;
                    b_iwork_data[b_k] = idx_data[offset + q];
                    q++;
                  }
                }
              } else {
                b_iwork_data[b_k] = nr;
                q++;
                if (q == qEnd) {
                  while (p < pEnd) {
                    b_k++;
                    b_iwork_data[b_k] = idx_data[offset + p];
                    p++;
                  }
                }
              }
              b_k++;
            }
            for (b_k = 0; b_k < kEnd; b_k++) {
              idx_data[(offset + j) + b_k] = b_iwork_data[b_k];
            }
            j = qEnd;
          }
          b_i = i2;
        }
        j = n;
        exitg2 = false;
        while ((!exitg2) && (j <= k)) {
          i1 = offset + idx_data[j - 1];
          if (fabs(zi_data[i1] +
                   zi_data[offset + idx_data[((k - j) + n) - 1]]) >
              tol * absx_data[i1]) {
            pairable = false;
            exitg2 = true;
          } else {
            j++;
          }
        }
        if (!pairable) {
          exitg1 = true;
        } else {
          nr = ng >> 1;
          for (j = 0; j < nr; j++) {
            i1 = offset + idx_data[(k - j) - 1];
            i = offset + ((j + 1) << 1);
            x_data[i - 1].re = zr_data[i1];
            x_data[i - 1].im = -zi_data[i1];
            x_data[i].re = zr_data[i1];
            x_data[i].im = zi_data[i1];
          }
          k++;
        }
      }
    }
  }
  return pairable;
}

/*
 * Arguments    : double n
 *                const double Wn[2]
 *                double varargout_1_data[]
 *                int varargout_1_size[2]
 *                double varargout_2_data[]
 *                int varargout_2_size[2]
 * Return Type  : void
 */
static void d_butter(double n, const double Wn[2], double varargout_1_data[],
                     int varargout_1_size[2], double varargout_2_data[],
                     int varargout_2_size[2])
{
  emxArray_real_T *a;
  emxArray_real_T *ad;
  emxArray_real_T *b_ad;
  creal_T b_c_data[1003];
  creal_T p_data[1002];
  creal_T z_data[1000];
  creal_T ps_data[501];
  double b_bd_data[1002];
  double b_cd_data[1002];
  double bd_data[1002];
  double cd_data[1002];
  double b_data[501];
  double c_data[501];
  double Wn1;
  double d;
  double dd;
  double ks;
  double u_idx_0;
  double u_idx_1;
  int c_size[2];
  int cd_size[2];
  int b_size;
  int bd_size;
  int j;
  int k;
  int ps_size;
  emxInit_real_T(&a, 2);
  emxInit_real_T(&ad, 2);
  emxInit_real_T(&b_ad, 2);
  u_idx_0 = 4.0 * tan(3.1415926535897931 * Wn[0] / 2.0);
  u_idx_1 = 4.0 * tan(3.1415926535897931 * Wn[1] / 2.0);
  buttap(n, ps_data, &ps_size, &ks);
  zp2ss(ps_data, ps_size, ks, a, b_data, &b_size, c_data, c_size, &d);
  Wn1 = sqrt(u_idx_0 * u_idx_1);
  lp2bp(a, b_data, b_size, c_data, c_size, d, Wn1, u_idx_1 - u_idx_0, ad,
        bd_data, &ps_size, cd_data, cd_size, &dd);
  bilinear(ad, bd_data, ps_size, cd_data, cd_size, dd, b_ad, b_bd_data,
           &bd_size, b_cd_data, c_size, &ks);
  eig(b_ad, p_data, &ps_size);
  b_buttzeros(n, Wn1, p_data, ps_size, z_data, &b_size, &dd);
  bd_size = ps_size + 1;
  b_c_data[0].re = 1.0;
  b_c_data[0].im = 0.0;
  emxFree_real_T(&b_ad);
  emxFree_real_T(&ad);
  emxFree_real_T(&a);
  for (j = 0; j < ps_size; j++) {
    ks = -p_data[j].re;
    u_idx_0 = -p_data[j].im;
    u_idx_1 = b_c_data[j].im;
    d = b_c_data[j].re;
    b_c_data[j + 1].re = ks * d - u_idx_0 * u_idx_1;
    b_c_data[j + 1].im = ks * u_idx_1 + u_idx_0 * d;
    for (k = j + 1; k >= 2; k--) {
      u_idx_1 = p_data[j].re;
      d = p_data[j].im;
      u_idx_0 = u_idx_1 * b_c_data[k - 2].im + d * b_c_data[k - 2].re;
      b_c_data[k - 1].re -=
          u_idx_1 * b_c_data[k - 2].re - d * b_c_data[k - 2].im;
      b_c_data[k - 1].im -= u_idx_0;
    }
  }
  varargout_2_size[0] = 1;
  varargout_2_size[1] = ps_size + 1;
  for (j = 0; j < bd_size; j++) {
    varargout_2_data[j] = b_c_data[j].re;
  }
  bd_size = b_size + 1;
  b_c_data[0].re = 1.0;
  b_c_data[0].im = 0.0;
  for (j = 0; j < b_size; j++) {
    ks = -z_data[j].re;
    u_idx_0 = -z_data[j].im;
    u_idx_1 = b_c_data[j].im;
    d = b_c_data[j].re;
    b_c_data[j + 1].re = ks * d - u_idx_0 * u_idx_1;
    b_c_data[j + 1].im = ks * u_idx_1 + u_idx_0 * d;
    for (k = j + 1; k >= 2; k--) {
      u_idx_1 = z_data[j].re;
      d = z_data[j].im;
      u_idx_0 = u_idx_1 * b_c_data[k - 2].im + d * b_c_data[k - 2].re;
      b_c_data[k - 1].re -=
          u_idx_1 * b_c_data[k - 2].re - d * b_c_data[k - 2].im;
      b_c_data[k - 1].im -= u_idx_0;
    }
  }
  ps_size -= b_size;
  varargout_1_size[0] = 1;
  varargout_1_size[1] = (ps_size + b_size) + 1;
  if (0 <= ps_size - 1) {
    memset(&varargout_1_data[0], 0, ps_size * sizeof(double));
  }
  for (j = 0; j < bd_size; j++) {
    varargout_1_data[j + ps_size] = dd * b_c_data[j].re;
  }
}

/*
 * Arguments    : const emxArray_real_T *A
 *                creal_T V_data[]
 *                int *V_size
 * Return Type  : void
 */
static void eig(const emxArray_real_T *A, creal_T V_data[], int *V_size)
{
  creal_T beta1_data[1002];
  double tmp_data[1002];
  double ai;
  double ar;
  double bi;
  double br;
  double brm;
  double im;
  double re;
  double s;
  int exitg1;
  int k;
  int nx;
  boolean_T exitg2;
  boolean_T p;
  *V_size = A->size[0];
  if ((A->size[0] != 0) && (A->size[1] != 0)) {
    nx = A->size[0] * A->size[1];
    p = true;
    for (k = 0; k < nx; k++) {
      if ((!p) || (rtIsInf(A->data[k]) || rtIsNaN(A->data[k]))) {
        p = false;
      }
    }
    if (!p) {
      *V_size = A->size[0];
      nx = A->size[0];
      for (k = 0; k < nx; k++) {
        V_data[k].re = rtNaN;
        V_data[k].im = 0.0;
      }
    } else {
      p = (A->size[0] == A->size[1]);
      if (p) {
        nx = 0;
        exitg2 = false;
        while ((!exitg2) && (nx <= A->size[1] - 1)) {
          k = 0;
          do {
            exitg1 = 0;
            if (k <= nx) {
              if (!(A->data[k + A->size[0] * nx] ==
                    A->data[nx + A->size[0] * k])) {
                p = false;
                exitg1 = 1;
              } else {
                k++;
              }
            } else {
              nx++;
              exitg1 = 2;
            }
          } while (exitg1 == 0);
          if (exitg1 == 1) {
            exitg2 = true;
          }
        }
      }
      if (p) {
        eigHermitianStandard(A, tmp_data, V_size);
        for (k = 0; k < *V_size; k++) {
          V_data[k].re = tmp_data[k];
          V_data[k].im = 0.0;
        }
      } else {
        xzgeev(A, &nx, V_data, V_size, beta1_data, &k);
        for (k = 0; k < *V_size; k++) {
          ar = V_data[k].re;
          ai = V_data[k].im;
          br = beta1_data[k].re;
          bi = beta1_data[k].im;
          if (bi == 0.0) {
            if (ai == 0.0) {
              re = ar / br;
              im = 0.0;
            } else if (ar == 0.0) {
              re = 0.0;
              im = ai / br;
            } else {
              re = ar / br;
              im = ai / br;
            }
          } else if (br == 0.0) {
            if (ar == 0.0) {
              re = ai / bi;
              im = 0.0;
            } else if (ai == 0.0) {
              re = 0.0;
              im = -(ar / bi);
            } else {
              re = ai / bi;
              im = -(ar / bi);
            }
          } else {
            brm = fabs(br);
            im = fabs(bi);
            if (brm > im) {
              s = bi / br;
              im = br + s * bi;
              re = (ar + s * ai) / im;
              im = (ai - s * ar) / im;
            } else if (im == brm) {
              if (br > 0.0) {
                s = 0.5;
              } else {
                s = -0.5;
              }
              if (bi > 0.0) {
                im = 0.5;
              } else {
                im = -0.5;
              }
              re = (ar * s + ai * im) / brm;
              im = (ai * s - ar * im) / brm;
            } else {
              s = br / bi;
              im = bi + s * br;
              re = (s * ar + ai) / im;
              im = (s * ai - ar) / im;
            }
          }
          V_data[k].re = re;
          V_data[k].im = im;
        }
      }
    }
  }
}

/*
 * Arguments    : const emxArray_real_T *A
 *                double V_data[]
 *                int *V_size
 * Return Type  : void
 */
static void eigHermitianStandard(const emxArray_real_T *A, double V_data[],
                                 int *V_size)
{
  emxArray_real_T *T;
  emxArray_real_T *b_A;
  int k;
  int n;
  emxInit_real_T(&b_A, 2);
  k = b_A->size[0] * b_A->size[1];
  b_A->size[0] = A->size[0];
  b_A->size[1] = A->size[1];
  emxEnsureCapacity_real_T(b_A, k);
  n = A->size[0] * A->size[1] - 1;
  for (k = 0; k <= n; k++) {
    b_A->data[k] = A->data[k];
  }
  emxInit_real_T(&T, 2);
  schur(b_A, T);
  n = T->size[0];
  *V_size = T->size[0];
  emxFree_real_T(&b_A);
  for (k = 0; k < n; k++) {
    V_data[k] = T->data[k + T->size[0] * k];
  }
  emxFree_real_T(&T);
}

/*
 * Arguments    : emxArray_real_T *h
 * Return Type  : int
 */
static int eml_dlahqr(emxArray_real_T *h)
{
  double v[3];
  double SMLNUM;
  double aa;
  double ab;
  double ba;
  double bb;
  double d;
  double rt1r;
  double rt2r;
  double s;
  double tst;
  int L;
  int b_k;
  int c_k;
  int hoffset;
  int i;
  int info;
  int itmax;
  int its;
  int j;
  int k;
  int knt;
  int ldh;
  int m;
  int n;
  int nr;
  boolean_T exitg1;
  boolean_T exitg2;
  boolean_T exitg3;
  boolean_T goto150;
  n = h->size[0];
  ldh = h->size[0];
  info = 0;
  if ((n != 0) && (1 != n)) {
    v[0] = 0.0;
    v[1] = 0.0;
    v[2] = 0.0;
    for (j = 0; j <= n - 4; j++) {
      h->data[(j + h->size[0] * j) + 2] = 0.0;
      h->data[(j + h->size[0] * j) + 3] = 0.0;
    }
    if (1 <= n - 2) {
      h->data[(n + h->size[0] * (n - 3)) - 1] = 0.0;
    }
    if (10 > n) {
      hoffset = 10;
    } else {
      hoffset = n;
    }
    itmax = 30 * hoffset;
    SMLNUM = 2.2250738585072014E-308 * ((double)n / 2.2204460492503131E-16);
    i = n - 1;
    exitg1 = false;
    while ((!exitg1) && (i + 1 >= 1)) {
      L = 1;
      goto150 = false;
      its = 0;
      exitg2 = false;
      while ((!exitg2) && (its <= itmax)) {
        k = i;
        exitg3 = false;
        while ((!exitg3) && (k + 1 > L)) {
          ba = fabs(h->data[k + h->size[0] * (k - 1)]);
          if (ba <= SMLNUM) {
            exitg3 = true;
          } else {
            bb = fabs(h->data[k + h->size[0] * k]);
            tst = fabs(h->data[(k + h->size[0] * (k - 1)) - 1]) + bb;
            if (tst == 0.0) {
              if (k - 1 >= 1) {
                tst = fabs(h->data[(k + h->size[0] * (k - 2)) - 1]);
              }
              if (k + 2 <= n) {
                tst += fabs(h->data[(k + h->size[0] * k) + 1]);
              }
            }
            if (ba <= 2.2204460492503131E-16 * tst) {
              tst = fabs(h->data[(k + h->size[0] * k) - 1]);
              if (ba > tst) {
                ab = ba;
                ba = tst;
              } else {
                ab = tst;
              }
              tst = fabs(h->data[(k + h->size[0] * (k - 1)) - 1] -
                         h->data[k + h->size[0] * k]);
              if (bb > tst) {
                aa = bb;
                bb = tst;
              } else {
                aa = tst;
              }
              s = aa + ab;
              tst = 2.2204460492503131E-16 * (bb * (aa / s));
              if ((SMLNUM > tst) || rtIsNaN(tst)) {
                tst = SMLNUM;
              }
              if (ba * (ab / s) <= tst) {
                exitg3 = true;
              } else {
                k--;
              }
            } else {
              k--;
            }
          }
        }
        L = k + 1;
        if (k + 1 > 1) {
          h->data[k + h->size[0] * (k - 1)] = 0.0;
        }
        if (k + 1 >= i) {
          goto150 = true;
          exitg2 = true;
        } else {
          if (its == 10) {
            s = fabs(h->data[(k + h->size[0] * k) + 1]) +
                fabs(h->data[(k + h->size[0] * (k + 1)) + 2]);
            tst = 0.75 * s + h->data[k + h->size[0] * k];
            aa = -0.4375 * s;
            ab = s;
            ba = tst;
          } else if (its == 20) {
            s = fabs(h->data[i + h->size[0] * (i - 1)]) +
                fabs(h->data[(i + h->size[0] * (i - 2)) - 1]);
            tst = 0.75 * s + h->data[i + h->size[0] * i];
            aa = -0.4375 * s;
            ab = s;
            ba = tst;
          } else {
            tst = h->data[(i + h->size[0] * (i - 1)) - 1];
            ab = h->data[i + h->size[0] * (i - 1)];
            aa = h->data[(i + h->size[0] * i) - 1];
            ba = h->data[i + h->size[0] * i];
          }
          s = ((fabs(tst) + fabs(aa)) + fabs(ab)) + fabs(ba);
          if (s == 0.0) {
            rt1r = 0.0;
            aa = 0.0;
            rt2r = 0.0;
            ab = 0.0;
          } else {
            tst /= s;
            ab /= s;
            aa /= s;
            ba /= s;
            bb = (tst + ba) / 2.0;
            tst = (tst - bb) * (ba - bb) - aa * ab;
            aa = sqrt(fabs(tst));
            if (tst >= 0.0) {
              rt1r = bb * s;
              rt2r = rt1r;
              aa *= s;
              ab = -aa;
            } else {
              rt1r = bb + aa;
              rt2r = bb - aa;
              if (fabs(rt1r - ba) <= fabs(rt2r - ba)) {
                rt1r *= s;
                rt2r = rt1r;
              } else {
                rt2r *= s;
                rt1r = rt2r;
              }
              aa = 0.0;
              ab = 0.0;
            }
          }
          m = i - 1;
          exitg3 = false;
          while ((!exitg3) && (m >= k + 1)) {
            tst = h->data[m + h->size[0] * (m - 1)];
            bb = h->data[(m + h->size[0] * (m - 1)) - 1];
            ba = bb - rt2r;
            s = (fabs(ba) + fabs(ab)) + fabs(tst);
            tst /= s;
            v[0] = (tst * h->data[(m + h->size[0] * m) - 1] +
                    (bb - rt1r) * (ba / s)) -
                   aa * (ab / s);
            v[1] = tst * (((bb + h->data[m + h->size[0] * m]) - rt1r) - rt2r);
            v[2] = tst * h->data[(m + h->size[0] * m) + 1];
            s = (fabs(v[0]) + fabs(v[1])) + fabs(v[2]);
            v[0] /= s;
            v[1] /= s;
            v[2] /= s;
            if ((m == k + 1) ||
                (fabs(h->data[(m + h->size[0] * (m - 2)) - 1]) *
                     (fabs(v[1]) + fabs(v[2])) <=
                 2.2204460492503131E-16 * fabs(v[0]) *
                     ((fabs(h->data[(m + h->size[0] * (m - 2)) - 2]) +
                       fabs(bb)) +
                      fabs(h->data[m + h->size[0] * m])))) {
              exitg3 = true;
            } else {
              m--;
            }
          }
          for (c_k = m; c_k <= i; c_k++) {
            nr = (i - c_k) + 2;
            if (3 < nr) {
              nr = 3;
            }
            if (c_k > m) {
              hoffset = (c_k + ldh * (c_k - 2)) - 1;
              for (j = 0; j < nr; j++) {
                v[j] = h->data[j + hoffset];
              }
            }
            aa = v[0];
            bb = 0.0;
            if (nr > 0) {
              tst = b_xnrm2(nr - 1, v);
              if (tst != 0.0) {
                ab = rt_hypotd_snf(v[0], tst);
                if (v[0] >= 0.0) {
                  ab = -ab;
                }
                if (fabs(ab) < 1.0020841800044864E-292) {
                  knt = -1;
                  do {
                    knt++;
                    for (b_k = 2; b_k <= nr; b_k++) {
                      v[b_k - 1] *= 9.9792015476736E+291;
                    }
                    ab *= 9.9792015476736E+291;
                    aa *= 9.9792015476736E+291;
                  } while (!(fabs(ab) >= 1.0020841800044864E-292));
                  ab = rt_hypotd_snf(aa, b_xnrm2(nr - 1, v));
                  if (aa >= 0.0) {
                    ab = -ab;
                  }
                  bb = (ab - aa) / ab;
                  tst = 1.0 / (aa - ab);
                  for (b_k = 2; b_k <= nr; b_k++) {
                    v[b_k - 1] *= tst;
                  }
                  for (b_k = 0; b_k <= knt; b_k++) {
                    ab *= 1.0020841800044864E-292;
                  }
                  aa = ab;
                } else {
                  bb = (ab - v[0]) / ab;
                  tst = 1.0 / (v[0] - ab);
                  for (b_k = 2; b_k <= nr; b_k++) {
                    v[b_k - 1] *= tst;
                  }
                  aa = ab;
                }
              }
            }
            v[0] = aa;
            if (c_k > m) {
              h->data[(c_k + h->size[0] * (c_k - 2)) - 1] = aa;
              h->data[c_k + h->size[0] * (c_k - 2)] = 0.0;
              if (c_k < i) {
                h->data[(c_k + h->size[0] * (c_k - 2)) + 1] = 0.0;
              }
            } else if (m > k + 1) {
              h->data[(c_k + h->size[0] * (c_k - 2)) - 1] *= 1.0 - bb;
            }
            d = v[1];
            aa = bb * v[1];
            if (nr == 3) {
              s = v[2];
              tst = bb * v[2];
              for (j = c_k; j <= n; j++) {
                ab = (h->data[(c_k + h->size[0] * (j - 1)) - 1] +
                      d * h->data[c_k + h->size[0] * (j - 1)]) +
                     s * h->data[(c_k + h->size[0] * (j - 1)) + 1];
                h->data[(c_k + h->size[0] * (j - 1)) - 1] -= ab * bb;
                h->data[c_k + h->size[0] * (j - 1)] -= ab * aa;
                h->data[(c_k + h->size[0] * (j - 1)) + 1] -= ab * tst;
              }
              if (c_k + 3 < i + 1) {
                hoffset = c_k + 2;
              } else {
                hoffset = i;
              }
              for (j = 0; j <= hoffset; j++) {
                ab = (h->data[j + h->size[0] * (c_k - 1)] +
                      d * h->data[j + h->size[0] * c_k]) +
                     s * h->data[j + h->size[0] * (c_k + 1)];
                h->data[j + h->size[0] * (c_k - 1)] -= ab * bb;
                h->data[j + h->size[0] * c_k] -= ab * aa;
                h->data[j + h->size[0] * (c_k + 1)] -= ab * tst;
              }
            } else if (nr == 2) {
              for (j = c_k; j <= n; j++) {
                tst = h->data[(c_k + h->size[0] * (j - 1)) - 1];
                ab = tst + d * h->data[c_k + h->size[0] * (j - 1)];
                h->data[(c_k + h->size[0] * (j - 1)) - 1] = tst - ab * bb;
                h->data[c_k + h->size[0] * (j - 1)] -= ab * aa;
              }
              for (j = 0; j <= i; j++) {
                ab = h->data[j + h->size[0] * (c_k - 1)] +
                     d * h->data[j + h->size[0] * c_k];
                h->data[j + h->size[0] * (c_k - 1)] -= ab * bb;
                h->data[j + h->size[0] * c_k] -= ab * aa;
              }
            }
          }
          its++;
        }
      }
      if (!goto150) {
        info = i + 1;
        exitg1 = true;
      } else {
        if ((L != i + 1) && (L == i)) {
          d = h->data[(i + h->size[0] * i) - 1];
          s = h->data[i + h->size[0] * (i - 1)];
          tst = h->data[i + h->size[0] * i];
          xdlanv2(&h->data[(i + h->size[0] * (i - 1)) - 1], &d, &s, &tst, &aa,
                  &ab, &bb, &ba, &rt2r, &rt1r);
          h->data[(i + h->size[0] * i) - 1] = d;
          h->data[i + h->size[0] * (i - 1)] = s;
          h->data[i + h->size[0] * i] = tst;
          if (n > i + 1) {
            hoffset = (i + 1) * ldh;
            xrot((n - i) - 1, h, i + hoffset, ldh, (i + hoffset) + 1, ldh, rt2r,
                 rt1r);
          }
          if (i - 1 >= 1) {
            hoffset = (i - 1) * ldh;
            knt = i * ldh;
            for (k = 0; k <= i - 2; k++) {
              b_k = knt + k;
              j = hoffset + k;
              tst = rt2r * h->data[j] + rt1r * h->data[b_k];
              h->data[b_k] = rt2r * h->data[b_k] - rt1r * h->data[j];
              h->data[j] = tst;
            }
          }
        }
        i = L - 2;
      }
    }
  }
  return info;
}

/*
 * Arguments    : const emxArray_real_T *x
 *                emxArray_real_T *y
 * Return Type  : void
 */
static void inv(const emxArray_real_T *x, emxArray_real_T *y)
{
  emxArray_real_T *B;
  emxArray_real_T *b_x;
  int y_data[1002];
  int ipiv_data[501];
  int p_data[501];
  int ipiv_size[2];
  int b_i;
  int b_n;
  int i;
  int j;
  int k;
  int kAcol;
  int m;
  int n;
  int yk;
  if ((x->size[0] == 0) || (x->size[1] == 0)) {
    i = y->size[0] * y->size[1];
    y->size[0] = x->size[0];
    y->size[1] = x->size[1];
    emxEnsureCapacity_real_T(y, i);
    b_n = x->size[0] * x->size[1];
    for (i = 0; i < b_n; i++) {
      y->data[i] = x->data[i];
    }
  } else {
    n = x->size[0];
    i = y->size[0] * y->size[1];
    y->size[0] = x->size[0];
    y->size[1] = x->size[1];
    emxEnsureCapacity_real_T(y, i);
    b_n = x->size[0] * x->size[1];
    for (i = 0; i < b_n; i++) {
      y->data[i] = 0.0;
    }
    emxInit_real_T(&b_x, 2);
    i = b_x->size[0] * b_x->size[1];
    b_x->size[0] = x->size[0];
    b_x->size[1] = x->size[1];
    emxEnsureCapacity_real_T(b_x, i);
    b_n = x->size[0] * x->size[1];
    for (i = 0; i < b_n; i++) {
      b_x->data[i] = x->data[i];
    }
    xgetrf(x->size[0], x->size[0], b_x, x->size[0], ipiv_data, ipiv_size);
    b_n = x->size[0];
    kAcol = x->size[0];
    y_data[0] = 1;
    yk = 1;
    for (k = 2; k <= b_n; k++) {
      yk++;
      y_data[k - 1] = yk;
    }
    if (0 <= kAcol - 1) {
      memcpy(&p_data[0], &y_data[0], kAcol * sizeof(int));
    }
    i = ipiv_size[1];
    for (k = 0; k < i; k++) {
      yk = ipiv_data[k];
      if (yk > k + 1) {
        b_n = p_data[yk - 1];
        p_data[yk - 1] = p_data[k];
        p_data[k] = b_n;
      }
    }
    for (k = 0; k < n; k++) {
      i = p_data[k];
      y->data[k + y->size[0] * (i - 1)] = 1.0;
      for (j = k + 1; j <= n; j++) {
        if (y->data[(j + y->size[0] * (i - 1)) - 1] != 0.0) {
          yk = j + 1;
          for (b_i = yk; b_i <= n; b_i++) {
            y->data[(b_i + y->size[0] * (i - 1)) - 1] -=
                y->data[(j + y->size[0] * (i - 1)) - 1] *
                b_x->data[(b_i + b_x->size[0] * (j - 1)) - 1];
          }
        }
      }
    }
    emxInit_real_T(&B, 2);
    m = x->size[0];
    n = x->size[0];
    i = B->size[0] * B->size[1];
    B->size[0] = y->size[0];
    B->size[1] = y->size[1];
    emxEnsureCapacity_real_T(B, i);
    b_n = y->size[0] * y->size[1];
    for (i = 0; i < b_n; i++) {
      B->data[i] = y->data[i];
    }
    for (j = 0; j < n; j++) {
      b_n = x->size[0] * j - 1;
      for (k = m; k >= 1; k--) {
        kAcol = x->size[0] * (k - 1) - 1;
        i = k + b_n;
        if (B->data[i] != 0.0) {
          B->data[i] /= b_x->data[k + kAcol];
          for (b_i = 0; b_i <= k - 2; b_i++) {
            yk = (b_i + b_n) + 1;
            B->data[yk] -= B->data[i] * b_x->data[(b_i + kAcol) + 1];
          }
        }
      }
    }
    emxFree_real_T(&b_x);
    i = y->size[0] * y->size[1];
    y->size[0] = B->size[0];
    y->size[1] = B->size[1];
    emxEnsureCapacity_real_T(y, i);
    b_n = B->size[0] * B->size[1];
    for (i = 0; i < b_n; i++) {
      y->data[i] = B->data[i];
    }
    emxFree_real_T(&B);
  }
}

/*
 * Arguments    : const emxArray_real_T *a
 *                const double b_data[]
 *                int b_size
 *                const double c_data[]
 *                const int c_size[2]
 *                double d
 *                double wo
 *                double bw
 *                emxArray_real_T *at
 *                double bt_data[]
 *                int *bt_size
 *                double ct_data[]
 *                int ct_size[2]
 *                double *dt
 * Return Type  : void
 */
static void lp2bp(const emxArray_real_T *a, const double b_data[], int b_size,
                  const double c_data[], const int c_size[2], double d,
                  double wo, double bw, emxArray_real_T *at, double bt_data[],
                  int *bt_size, double ct_data[], int ct_size[2], double *dt)
{
  emxArray_int8_T *b_result;
  emxArray_int8_T *varargin_2;
  emxArray_real_T *result;
  emxArray_real_T *varargin_1;
  double q;
  int i;
  int i1;
  int k;
  int loop_ub_tmp;
  int m;
  short input_sizes_idx_1;
  short sizes_idx_1;
  boolean_T empty_non_axis_sizes;
  emxInit_real_T(&result, 2);
  emxInit_real_T(&varargin_1, 2);
  q = wo / bw;
  i = varargin_1->size[0] * varargin_1->size[1];
  varargin_1->size[0] = a->size[0];
  varargin_1->size[1] = a->size[1];
  emxEnsureCapacity_real_T(varargin_1, i);
  m = a->size[0] * a->size[1];
  for (i = 0; i < m; i++) {
    varargin_1->data[i] = a->data[i] / q;
  }
  emxInit_int8_T(&varargin_2, 2);
  m = c_size[1];
  i = varargin_2->size[0] * varargin_2->size[1];
  varargin_2->size[0] = c_size[1];
  varargin_2->size[1] = c_size[1];
  emxEnsureCapacity_int8_T(varargin_2, i);
  loop_ub_tmp = c_size[1] * c_size[1];
  for (i = 0; i < loop_ub_tmp; i++) {
    varargin_2->data[i] = 0;
  }
  if (c_size[1] > 0) {
    for (k = 0; k < m; k++) {
      varargin_2->data[k + varargin_2->size[0] * k] = 1;
    }
  }
  if ((varargin_1->size[0] != 0) && (varargin_1->size[1] != 0)) {
    k = varargin_1->size[0];
  } else if ((varargin_2->size[0] != 0) && (varargin_2->size[1] != 0)) {
    k = varargin_2->size[0];
  } else {
    k = varargin_1->size[0];
    if (varargin_2->size[0] > varargin_1->size[0]) {
      k = varargin_2->size[0];
    }
  }
  empty_non_axis_sizes = (k == 0);
  if (empty_non_axis_sizes ||
      ((varargin_1->size[0] != 0) && (varargin_1->size[1] != 0))) {
    input_sizes_idx_1 = (short)varargin_1->size[1];
  } else {
    input_sizes_idx_1 = 0;
  }
  if (empty_non_axis_sizes ||
      ((varargin_2->size[0] != 0) && (varargin_2->size[1] != 0))) {
    sizes_idx_1 = (short)varargin_2->size[1];
  } else {
    sizes_idx_1 = 0;
  }
  i = result->size[0] * result->size[1];
  result->size[0] = k;
  result->size[1] = input_sizes_idx_1 + sizes_idx_1;
  emxEnsureCapacity_real_T(result, i);
  m = input_sizes_idx_1;
  for (i = 0; i < m; i++) {
    for (i1 = 0; i1 < k; i1++) {
      result->data[i1 + result->size[0] * i] = varargin_1->data[i1 + k * i];
    }
  }
  m = sizes_idx_1;
  for (i = 0; i < m; i++) {
    for (i1 = 0; i1 < k; i1++) {
      result->data[i1 + result->size[0] * (i + input_sizes_idx_1)] =
          varargin_2->data[i1 + k * i];
    }
  }
  emxFree_int8_T(&varargin_2);
  emxInit_int8_T(&b_result, 2);
  m = c_size[1];
  i = varargin_1->size[0] * varargin_1->size[1];
  varargin_1->size[0] = c_size[1];
  varargin_1->size[1] = c_size[1];
  emxEnsureCapacity_real_T(varargin_1, i);
  for (i = 0; i < loop_ub_tmp; i++) {
    varargin_1->data[i] = 0.0;
  }
  if (c_size[1] > 0) {
    for (k = 0; k < m; k++) {
      varargin_1->data[k + varargin_1->size[0] * k] = 1.0;
    }
  }
  m = varargin_1->size[0] * varargin_1->size[1];
  for (i = 0; i < m; i++) {
    varargin_1->data[i] = -varargin_1->data[i];
  }
  if ((varargin_1->size[0] != 0) && (varargin_1->size[1] != 0)) {
    k = varargin_1->size[0];
  } else if (c_size[1] != 0) {
    k = c_size[1];
  } else {
    k = varargin_1->size[0];
  }
  empty_non_axis_sizes = (k == 0);
  if (empty_non_axis_sizes ||
      ((varargin_1->size[0] != 0) && (varargin_1->size[1] != 0))) {
    input_sizes_idx_1 = (short)varargin_1->size[1];
  } else {
    input_sizes_idx_1 = 0;
  }
  if (empty_non_axis_sizes || (c_size[1] != 0)) {
    sizes_idx_1 = (short)c_size[1];
  } else {
    sizes_idx_1 = 0;
  }
  i = b_result->size[0] * b_result->size[1];
  b_result->size[0] = k;
  b_result->size[1] = input_sizes_idx_1 + sizes_idx_1;
  emxEnsureCapacity_int8_T(b_result, i);
  m = input_sizes_idx_1;
  for (i = 0; i < m; i++) {
    for (i1 = 0; i1 < k; i1++) {
      b_result->data[i1 + b_result->size[0] * i] =
          (signed char)varargin_1->data[i1 + k * i];
    }
  }
  emxFree_real_T(&varargin_1);
  m = sizes_idx_1;
  for (i = 0; i < m; i++) {
    for (i1 = 0; i1 < k; i1++) {
      b_result->data[i1 + b_result->size[0] * (i + input_sizes_idx_1)] = 0;
    }
  }
  if ((result->size[0] != 0) && (result->size[1] != 0)) {
    k = result->size[1];
  } else if ((b_result->size[0] != 0) && (b_result->size[1] != 0)) {
    k = b_result->size[1];
  } else {
    k = result->size[1];
    if (b_result->size[1] > result->size[1]) {
      k = b_result->size[1];
    }
  }
  empty_non_axis_sizes = (k == 0);
  if (empty_non_axis_sizes ||
      ((result->size[0] != 0) && (result->size[1] != 0))) {
    input_sizes_idx_1 = (short)result->size[0];
  } else {
    input_sizes_idx_1 = 0;
  }
  if (empty_non_axis_sizes ||
      ((b_result->size[0] != 0) && (b_result->size[1] != 0))) {
    sizes_idx_1 = (short)b_result->size[0];
  } else {
    sizes_idx_1 = 0;
  }
  m = input_sizes_idx_1;
  loop_ub_tmp = sizes_idx_1;
  i = at->size[0] * at->size[1];
  at->size[0] = input_sizes_idx_1 + sizes_idx_1;
  at->size[1] = k;
  emxEnsureCapacity_real_T(at, i);
  for (i = 0; i < k; i++) {
    for (i1 = 0; i1 < m; i1++) {
      at->data[i1 + at->size[0] * i] =
          wo * result->data[i1 + input_sizes_idx_1 * i];
    }
  }
  emxFree_real_T(&result);
  for (i = 0; i < k; i++) {
    for (i1 = 0; i1 < loop_ub_tmp; i1++) {
      at->data[(i1 + input_sizes_idx_1) + at->size[0] * i] =
          wo * (double)b_result->data[i1 + sizes_idx_1 * i];
    }
  }
  emxFree_int8_T(&b_result);
  *bt_size = b_size + (short)c_size[1];
  for (i = 0; i < b_size; i++) {
    bt_data[i] = wo * (b_data[i] / q);
  }
  m = (short)c_size[1];
  for (i = 0; i < m; i++) {
    bt_data[i + b_size] = wo * 0.0;
  }
  ct_size[0] = 1;
  ct_size[1] = c_size[1] + c_size[1];
  m = c_size[1];
  if (0 <= m - 1) {
    memcpy(&ct_data[0], &c_data[0], m * sizeof(double));
  }
  m = c_size[1];
  if (0 <= m - 1) {
    memset(&ct_data[c_size[1]], 0,
           ((m + c_size[1]) - c_size[1]) * sizeof(double));
  }
  *dt = d;
}

/*
 * Arguments    : const emxArray_real_T *a
 *                const double b_data[]
 *                int b_size
 *                const double c_data[]
 *                const int c_size[2]
 *                double d
 *                double wo
 *                double bw
 *                emxArray_real_T *at
 *                double bt_data[]
 *                int *bt_size
 *                double ct_data[]
 *                int ct_size[2]
 *                double *dt
 * Return Type  : void
 */
static void lp2bs(const emxArray_real_T *a, const double b_data[], int b_size,
                  const double c_data[], const int c_size[2], double d,
                  double wo, double bw, emxArray_real_T *at, double bt_data[],
                  int *bt_size, double ct_data[], int ct_size[2], double *dt)
{
  emxArray_real_T *b_I;
  emxArray_real_T *b_y;
  emxArray_real_T *c_result;
  emxArray_real_T *result;
  emxArray_real_T *y;
  double tmp_data[1002];
  double a_tmp;
  int tmp_size[2];
  int b_result;
  int i;
  int i1;
  int loop_ub;
  int loop_ub_tmp;
  int m;
  short input_sizes_idx_1;
  short sizes_idx_0;
  short sizes_idx_1;
  boolean_T empty_non_axis_sizes;
  emxInit_real_T(&y, 2);
  emxInit_real_T(&b_I, 2);
  a_tmp = wo / (wo / bw);
  inv(a, b_I);
  i = y->size[0] * y->size[1];
  y->size[0] = b_I->size[0];
  y->size[1] = b_I->size[1];
  emxEnsureCapacity_real_T(y, i);
  loop_ub = b_I->size[0] * b_I->size[1];
  for (i = 0; i < loop_ub; i++) {
    y->data[i] = a_tmp * b_I->data[i];
  }
  emxInit_real_T(&b_y, 2);
  m = c_size[1];
  i = b_I->size[0] * b_I->size[1];
  b_I->size[0] = c_size[1];
  b_I->size[1] = c_size[1];
  emxEnsureCapacity_real_T(b_I, i);
  loop_ub_tmp = c_size[1] * c_size[1];
  for (i = 0; i < loop_ub_tmp; i++) {
    b_I->data[i] = 0.0;
  }
  if (c_size[1] > 0) {
    for (loop_ub = 0; loop_ub < m; loop_ub++) {
      b_I->data[loop_ub + b_I->size[0] * loop_ub] = 1.0;
    }
  }
  i = b_y->size[0] * b_y->size[1];
  b_y->size[0] = b_I->size[0];
  b_y->size[1] = b_I->size[1];
  emxEnsureCapacity_real_T(b_y, i);
  loop_ub = b_I->size[0] * b_I->size[1];
  for (i = 0; i < loop_ub; i++) {
    b_y->data[i] = wo * b_I->data[i];
  }
  emxInit_real_T(&result, 2);
  inv(a, b_I);
  sizes_idx_0 = (short)b_I->size[0];
  sizes_idx_1 = (short)b_I->size[1];
  m = c_size[1];
  i = b_I->size[0] * b_I->size[1];
  b_I->size[0] = c_size[1];
  b_I->size[1] = c_size[1];
  emxEnsureCapacity_real_T(b_I, i);
  for (i = 0; i < loop_ub_tmp; i++) {
    b_I->data[i] = 0.0;
  }
  if (c_size[1] > 0) {
    for (loop_ub = 0; loop_ub < m; loop_ub++) {
      b_I->data[loop_ub + b_I->size[0] * loop_ub] = 1.0;
    }
  }
  if ((sizes_idx_0 != 0) && (sizes_idx_1 != 0)) {
    b_result = y->size[0];
  } else if (((short)b_I->size[0] != 0) && ((short)b_I->size[1] != 0)) {
    b_result = b_y->size[0];
  } else {
    b_result = y->size[0];
    if (b_y->size[0] > y->size[0]) {
      b_result = b_y->size[0];
    }
  }
  empty_non_axis_sizes = (b_result == 0);
  if (empty_non_axis_sizes || ((sizes_idx_0 != 0) && (sizes_idx_1 != 0))) {
    input_sizes_idx_1 = (short)y->size[1];
  } else {
    input_sizes_idx_1 = 0;
  }
  if (empty_non_axis_sizes ||
      (((short)b_I->size[0] != 0) && ((short)b_I->size[1] != 0))) {
    sizes_idx_1 = (short)b_y->size[1];
  } else {
    sizes_idx_1 = 0;
  }
  i = result->size[0] * result->size[1];
  result->size[0] = b_result;
  result->size[1] = input_sizes_idx_1 + sizes_idx_1;
  emxEnsureCapacity_real_T(result, i);
  loop_ub = input_sizes_idx_1;
  for (i = 0; i < loop_ub; i++) {
    for (i1 = 0; i1 < b_result; i1++) {
      result->data[i1 + result->size[0] * i] = y->data[i1 + b_result * i];
    }
  }
  loop_ub = sizes_idx_1;
  for (i = 0; i < loop_ub; i++) {
    for (i1 = 0; i1 < b_result; i1++) {
      result->data[i1 + result->size[0] * (i + input_sizes_idx_1)] =
          b_y->data[i1 + b_result * i];
    }
  }
  emxFree_real_T(&b_y);
  m = c_size[1];
  i = b_I->size[0] * b_I->size[1];
  b_I->size[0] = c_size[1];
  b_I->size[1] = c_size[1];
  emxEnsureCapacity_real_T(b_I, i);
  for (i = 0; i < loop_ub_tmp; i++) {
    b_I->data[i] = 0.0;
  }
  if (c_size[1] > 0) {
    for (loop_ub = 0; loop_ub < m; loop_ub++) {
      b_I->data[loop_ub + b_I->size[0] * loop_ub] = 1.0;
    }
  }
  i = y->size[0] * y->size[1];
  y->size[0] = b_I->size[0];
  y->size[1] = b_I->size[1];
  emxEnsureCapacity_real_T(y, i);
  loop_ub = b_I->size[0] * b_I->size[1];
  for (i = 0; i < loop_ub; i++) {
    y->data[i] = -wo * b_I->data[i];
  }
  emxInit_real_T(&c_result, 2);
  m = c_size[1];
  i = b_I->size[0] * b_I->size[1];
  b_I->size[0] = c_size[1];
  b_I->size[1] = c_size[1];
  emxEnsureCapacity_real_T(b_I, i);
  for (i = 0; i < loop_ub_tmp; i++) {
    b_I->data[i] = 0.0;
  }
  if (c_size[1] > 0) {
    for (loop_ub = 0; loop_ub < m; loop_ub++) {
      b_I->data[loop_ub + b_I->size[0] * loop_ub] = 1.0;
    }
  }
  if (((short)b_I->size[0] != 0) && ((short)b_I->size[1] != 0)) {
    b_result = y->size[0];
  } else if (c_size[1] != 0) {
    b_result = c_size[1];
  } else {
    b_result = y->size[0];
  }
  empty_non_axis_sizes = (b_result == 0);
  if (empty_non_axis_sizes ||
      (((short)b_I->size[0] != 0) && ((short)b_I->size[1] != 0))) {
    input_sizes_idx_1 = (short)y->size[1];
  } else {
    input_sizes_idx_1 = 0;
  }
  emxFree_real_T(&b_I);
  if (empty_non_axis_sizes || (c_size[1] != 0)) {
    sizes_idx_1 = (short)c_size[1];
  } else {
    sizes_idx_1 = 0;
  }
  i = c_result->size[0] * c_result->size[1];
  c_result->size[0] = b_result;
  c_result->size[1] = input_sizes_idx_1 + sizes_idx_1;
  emxEnsureCapacity_real_T(c_result, i);
  loop_ub = input_sizes_idx_1;
  for (i = 0; i < loop_ub; i++) {
    for (i1 = 0; i1 < b_result; i1++) {
      c_result->data[i1 + c_result->size[0] * i] = y->data[i1 + b_result * i];
    }
  }
  emxFree_real_T(&y);
  loop_ub = sizes_idx_1;
  for (i = 0; i < loop_ub; i++) {
    for (i1 = 0; i1 < b_result; i1++) {
      c_result->data[i1 + c_result->size[0] * (i + input_sizes_idx_1)] = 0.0;
    }
  }
  if ((result->size[0] != 0) && (result->size[1] != 0)) {
    b_result = result->size[1];
  } else if ((c_result->size[0] != 0) && (c_result->size[1] != 0)) {
    b_result = c_result->size[1];
  } else {
    b_result = result->size[1];
    if (c_result->size[1] > result->size[1]) {
      b_result = c_result->size[1];
    }
  }
  empty_non_axis_sizes = (b_result == 0);
  if (empty_non_axis_sizes ||
      ((result->size[0] != 0) && (result->size[1] != 0))) {
    input_sizes_idx_1 = (short)result->size[0];
  } else {
    input_sizes_idx_1 = 0;
  }
  if (empty_non_axis_sizes ||
      ((c_result->size[0] != 0) && (c_result->size[1] != 0))) {
    sizes_idx_0 = (short)c_result->size[0];
  } else {
    sizes_idx_0 = 0;
  }
  m = input_sizes_idx_1;
  loop_ub = sizes_idx_0;
  i = at->size[0] * at->size[1];
  at->size[0] = input_sizes_idx_1 + sizes_idx_0;
  at->size[1] = b_result;
  emxEnsureCapacity_real_T(at, i);
  for (i = 0; i < b_result; i++) {
    for (i1 = 0; i1 < m; i1++) {
      at->data[i1 + at->size[0] * i] = result->data[i1 + input_sizes_idx_1 * i];
    }
  }
  emxFree_real_T(&result);
  for (i = 0; i < b_result; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      at->data[(i1 + input_sizes_idx_1) + at->size[0] * i] =
          c_result->data[i1 + sizes_idx_0 * i];
    }
  }
  emxFree_real_T(&c_result);
  mldivide(a, b_data, b_size, tmp_data, &m);
  *bt_size = m + c_size[1];
  for (i = 0; i < m; i++) {
    bt_data[i] = -(a_tmp * tmp_data[i]);
  }
  loop_ub = c_size[1];
  if (0 <= loop_ub - 1) {
    memset(&bt_data[m], 0, ((loop_ub + m) - m) * sizeof(double));
  }
  mrdiv(c_data, c_size, a, tmp_data, tmp_size);
  ct_size[0] = 1;
  ct_size[1] = tmp_size[1] + c_size[1];
  loop_ub = tmp_size[1];
  if (0 <= loop_ub - 1) {
    memcpy(&ct_data[0], &tmp_data[0], loop_ub * sizeof(double));
  }
  loop_ub = c_size[1];
  if (0 <= loop_ub - 1) {
    memset(&ct_data[tmp_size[1]], 0,
           ((loop_ub + tmp_size[1]) - tmp_size[1]) * sizeof(double));
  }
  if ((a->size[0] == 0) || (a->size[1] == 0)) {
    *dt = d;
  } else {
    mrdiv(c_data, c_size, a, tmp_data, tmp_size);
    a_tmp = 0.0;
    loop_ub = tmp_size[1];
    for (i = 0; i < loop_ub; i++) {
      a_tmp += tmp_data[i] * b_data[i];
    }
    *dt = d - a_tmp;
  }
}

/*
 * Arguments    : const emxArray_real_T *a
 *                const double b_data[]
 *                int b_size
 *                const double c_data[]
 *                const int c_size[2]
 *                double d
 *                double wo
 *                emxArray_real_T *at
 *                double bt_data[]
 *                int *bt_size
 *                double ct_data[]
 *                int ct_size[2]
 *                double *dt
 * Return Type  : void
 */
static void lp2hp(const emxArray_real_T *a, const double b_data[], int b_size,
                  const double c_data[], const int c_size[2], double d,
                  double wo, emxArray_real_T *at, double bt_data[],
                  int *bt_size, double ct_data[], int ct_size[2], double *dt)
{
  emxArray_real_T *b_a;
  double Y_data[1002];
  double b_c_data[1002];
  double Y;
  int b_Y_size[2];
  int Y_size;
  int i;
  int i1;
  int loop_ub;
  inv(a, at);
  loop_ub = at->size[0] * at->size[1];
  for (i = 0; i < loop_ub; i++) {
    at->data[i] *= wo;
  }
  if ((a->size[0] == 0) || (a->size[1] == 0) || (b_size == 0)) {
    Y_size = (short)a->size[1];
    loop_ub = (short)a->size[1];
    if (0 <= loop_ub - 1) {
      memset(&Y_data[0], 0, loop_ub * sizeof(double));
    }
  } else if (a->size[0] == a->size[1]) {
    Y_size = b_size;
    if (0 <= b_size - 1) {
      memcpy(&Y_data[0], &b_data[0], b_size * sizeof(double));
    }
    b_lusolve(a, Y_data, &Y_size);
  } else {
    qrsolve(a, b_data, b_size, Y_data, &Y_size);
  }
  *bt_size = Y_size;
  for (i = 0; i < Y_size; i++) {
    bt_data[i] = -wo * Y_data[i];
  }
  emxInit_real_T(&b_a, 2);
  if ((c_size[1] == 0) || ((a->size[0] == 0) || (a->size[1] == 0))) {
    b_Y_size[1] = (short)a->size[0];
    loop_ub = (short)a->size[0];
    if (0 <= loop_ub - 1) {
      memset(&b_c_data[0], 0, loop_ub * sizeof(double));
    }
  } else if (a->size[0] == a->size[1]) {
    b_Y_size[0] = 1;
    b_Y_size[1] = c_size[1];
    loop_ub = c_size[1];
    if (0 <= loop_ub - 1) {
      memcpy(&b_c_data[0], &c_data[0], loop_ub * sizeof(double));
    }
    c_lusolve(a, b_c_data, b_Y_size);
  } else {
    i = b_a->size[0] * b_a->size[1];
    b_a->size[0] = a->size[1];
    b_a->size[1] = a->size[0];
    emxEnsureCapacity_real_T(b_a, i);
    loop_ub = a->size[0];
    for (i = 0; i < loop_ub; i++) {
      Y_size = a->size[1];
      for (i1 = 0; i1 < Y_size; i1++) {
        b_a->data[i1 + b_a->size[0] * i] = a->data[i + a->size[0] * i1];
      }
    }
    loop_ub = c_size[1];
    if (0 <= loop_ub - 1) {
      memcpy(&b_c_data[0], &c_data[0], loop_ub * sizeof(double));
    }
    qrsolve(b_a, b_c_data, c_size[1], Y_data, &Y_size);
    b_Y_size[1] = Y_size;
    if (0 <= Y_size - 1) {
      memcpy(&b_c_data[0], &Y_data[0], Y_size * sizeof(double));
    }
  }
  ct_size[0] = 1;
  ct_size[1] = b_Y_size[1];
  loop_ub = b_Y_size[1];
  if (0 <= loop_ub - 1) {
    memcpy(&ct_data[0], &b_c_data[0], loop_ub * sizeof(double));
  }
  if ((a->size[0] == 0) || (a->size[1] == 0)) {
    *dt = d;
  } else {
    if (c_size[1] == 0) {
      b_Y_size[1] = (short)a->size[0];
      loop_ub = (short)a->size[0];
      if (0 <= loop_ub - 1) {
        memset(&b_c_data[0], 0, loop_ub * sizeof(double));
      }
    } else if (a->size[0] == a->size[1]) {
      b_Y_size[0] = 1;
      b_Y_size[1] = c_size[1];
      loop_ub = c_size[1];
      if (0 <= loop_ub - 1) {
        memcpy(&b_c_data[0], &c_data[0], loop_ub * sizeof(double));
      }
      c_lusolve(a, b_c_data, b_Y_size);
    } else {
      i = b_a->size[0] * b_a->size[1];
      b_a->size[0] = a->size[1];
      b_a->size[1] = a->size[0];
      emxEnsureCapacity_real_T(b_a, i);
      loop_ub = a->size[0];
      for (i = 0; i < loop_ub; i++) {
        Y_size = a->size[1];
        for (i1 = 0; i1 < Y_size; i1++) {
          b_a->data[i1 + b_a->size[0] * i] = a->data[i + a->size[0] * i1];
        }
      }
      loop_ub = c_size[1];
      if (0 <= loop_ub - 1) {
        memcpy(&b_c_data[0], &c_data[0], loop_ub * sizeof(double));
      }
      qrsolve(b_a, b_c_data, c_size[1], Y_data, &Y_size);
      b_Y_size[1] = Y_size;
      if (0 <= Y_size - 1) {
        memcpy(&b_c_data[0], &Y_data[0], Y_size * sizeof(double));
      }
    }
    Y = 0.0;
    loop_ub = b_Y_size[1];
    for (i = 0; i < loop_ub; i++) {
      Y += b_c_data[i] * b_data[i];
    }
    *dt = d - Y;
  }
  emxFree_real_T(&b_a);
}

/*
 * Arguments    : const emxArray_real_T *A
 *                const emxArray_real_T *B
 *                emxArray_real_T *X
 * Return Type  : void
 */
static void lusolve(const emxArray_real_T *A, const emxArray_real_T *B,
                    emxArray_real_T *X)
{
  emxArray_real_T *b_A;
  double temp;
  int ipiv_data[1002];
  int ipiv_size[2];
  int LDB;
  int b_i;
  int i;
  int i1;
  int i2;
  int j;
  int jBcol;
  int k;
  int kAcol;
  int n;
  int nrhs;
  i = X->size[0] * X->size[1];
  X->size[0] = B->size[0];
  X->size[1] = B->size[1];
  emxEnsureCapacity_real_T(X, i);
  LDB = B->size[0] * B->size[1];
  for (i = 0; i < LDB; i++) {
    X->data[i] = B->data[i];
  }
  emxInit_real_T(&b_A, 2);
  LDB = A->size[0];
  n = A->size[1];
  if (LDB < n) {
    n = LDB;
  }
  LDB = B->size[0];
  if (LDB < n) {
    n = LDB;
  }
  nrhs = B->size[1] - 1;
  i = b_A->size[0] * b_A->size[1];
  b_A->size[0] = A->size[0];
  b_A->size[1] = A->size[1];
  emxEnsureCapacity_real_T(b_A, i);
  LDB = A->size[0] * A->size[1];
  for (i = 0; i < LDB; i++) {
    b_A->data[i] = A->data[i];
  }
  xzgetrf(n, n, b_A, A->size[0], ipiv_data, ipiv_size, &LDB);
  LDB = B->size[0];
  for (b_i = 0; b_i <= n - 2; b_i++) {
    i = ipiv_data[b_i];
    if (i != b_i + 1) {
      for (j = 0; j <= nrhs; j++) {
        temp = X->data[b_i + X->size[0] * j];
        X->data[b_i + X->size[0] * j] = X->data[(i + X->size[0] * j) - 1];
        X->data[(i + X->size[0] * j) - 1] = temp;
      }
    }
  }
  if ((B->size[1] != 0) && ((X->size[0] != 0) && (X->size[1] != 0))) {
    for (j = 0; j <= nrhs; j++) {
      jBcol = LDB * j;
      for (k = 0; k < n; k++) {
        kAcol = b_A->size[0] * k;
        i = k + jBcol;
        if (X->data[i] != 0.0) {
          i1 = k + 2;
          for (b_i = i1; b_i <= n; b_i++) {
            i2 = (b_i + jBcol) - 1;
            X->data[i2] -= X->data[i] * b_A->data[(b_i + kAcol) - 1];
          }
        }
      }
    }
  }
  if ((B->size[1] != 0) && ((X->size[0] != 0) && (X->size[1] != 0))) {
    for (j = 0; j <= nrhs; j++) {
      jBcol = LDB * j - 1;
      for (k = n; k >= 1; k--) {
        kAcol = b_A->size[0] * (k - 1) - 1;
        i = k + jBcol;
        if (X->data[i] != 0.0) {
          X->data[i] /= b_A->data[k + kAcol];
          for (b_i = 0; b_i <= k - 2; b_i++) {
            i1 = (b_i + jBcol) + 1;
            X->data[i1] -= X->data[i] * b_A->data[(b_i + kAcol) + 1];
          }
        }
      }
    }
  }
  emxFree_real_T(&b_A);
}

/*
 * Arguments    : const emxArray_real_T *A
 *                const double B_data[]
 *                int B_size
 *                double Y_data[]
 *                int *Y_size
 * Return Type  : void
 */
static void mldivide(const emxArray_real_T *A, const double B_data[],
                     int B_size, double Y_data[], int *Y_size)
{
  int loop_ub;
  if ((A->size[0] == 0) || (A->size[1] == 0) || (B_size == 0)) {
    *Y_size = (short)A->size[1];
    loop_ub = (short)A->size[1];
    if (0 <= loop_ub - 1) {
      memset(&Y_data[0], 0, loop_ub * sizeof(double));
    }
  } else if (A->size[0] == A->size[1]) {
    *Y_size = B_size;
    if (0 <= B_size - 1) {
      memcpy(&Y_data[0], &B_data[0], B_size * sizeof(double));
    }
    b_lusolve(A, Y_data, Y_size);
  } else {
    qrsolve(A, B_data, B_size, Y_data, Y_size);
  }
}

/*
 * Arguments    : const double A_data[]
 *                const int A_size[2]
 *                const emxArray_real_T *B
 *                double Y_data[]
 *                int Y_size[2]
 * Return Type  : void
 */
static void mrdiv(const double A_data[], const int A_size[2],
                  const emxArray_real_T *B, double Y_data[], int Y_size[2])
{
  emxArray_real_T *b_B;
  double b_A_data[1002];
  double tmp_data[1002];
  int b_loop_ub;
  int i;
  int i1;
  int loop_ub;
  emxInit_real_T(&b_B, 2);
  if ((A_size[1] == 0) || ((B->size[0] == 0) || (B->size[1] == 0))) {
    Y_size[0] = 1;
    Y_size[1] = (short)B->size[0];
    loop_ub = (short)B->size[0];
    if (0 <= loop_ub - 1) {
      memset(&Y_data[0], 0, loop_ub * sizeof(double));
    }
  } else if (B->size[0] == B->size[1]) {
    Y_size[0] = 1;
    Y_size[1] = A_size[1];
    loop_ub = A_size[1];
    if (0 <= loop_ub - 1) {
      memcpy(&Y_data[0], &A_data[0], loop_ub * sizeof(double));
    }
    c_lusolve(B, Y_data, Y_size);
  } else {
    i = b_B->size[0] * b_B->size[1];
    b_B->size[0] = B->size[1];
    b_B->size[1] = B->size[0];
    emxEnsureCapacity_real_T(b_B, i);
    loop_ub = B->size[0];
    for (i = 0; i < loop_ub; i++) {
      b_loop_ub = B->size[1];
      for (i1 = 0; i1 < b_loop_ub; i1++) {
        b_B->data[i1 + b_B->size[0] * i] = B->data[i + B->size[0] * i1];
      }
    }
    loop_ub = A_size[1];
    if (0 <= loop_ub - 1) {
      memcpy(&b_A_data[0], &A_data[0], loop_ub * sizeof(double));
    }
    qrsolve(b_B, b_A_data, A_size[1], tmp_data, &loop_ub);
    Y_size[0] = 1;
    Y_size[1] = loop_ub;
    if (0 <= loop_ub - 1) {
      memcpy(&Y_data[0], &tmp_data[0], loop_ub * sizeof(double));
    }
  }
  emxFree_real_T(&b_B);
}

/*
 * Arguments    : emxArray_real_T *A
 *                int m
 *                int n
 *                double tau_data[]
 *                int jpvt_data[]
 * Return Type  : void
 */
static void qrpf(emxArray_real_T *A, int m, int n, double tau_data[],
                 int jpvt_data[])
{
  double vn1_data[1002];
  double vn2_data[1002];
  double work_data[1002];
  double s;
  double smax;
  double temp2;
  int b_i;
  int exitg1;
  int i;
  int ia;
  int ii;
  int ip1;
  int ix;
  int j;
  int lastc;
  int lastv;
  int ma;
  int minmn;
  int mmi;
  int nmi;
  int pvt;
  boolean_T exitg2;
  ma = A->size[0];
  if (m < n) {
    minmn = m;
  } else {
    minmn = n;
  }
  ix = A->size[1];
  if (0 <= ix - 1) {
    memset(&work_data[0], 0, ix * sizeof(double));
  }
  ix = A->size[1];
  if (0 <= ix - 1) {
    memset(&vn1_data[0], 0, ix * sizeof(double));
  }
  ix = A->size[1];
  if (0 <= ix - 1) {
    memset(&vn2_data[0], 0, ix * sizeof(double));
  }
  for (j = 0; j < n; j++) {
    smax = xnrm2(m, A, j * ma + 1);
    vn1_data[j] = smax;
    vn2_data[j] = smax;
  }
  for (i = 0; i < minmn; i++) {
    ip1 = i + 2;
    lastc = i * ma;
    ii = lastc + i;
    nmi = n - i;
    mmi = (m - i) - 1;
    if (nmi < 1) {
      ix = -1;
    } else {
      ix = 0;
      if (nmi > 1) {
        smax = fabs(vn1_data[i]);
        for (lastv = 2; lastv <= nmi; lastv++) {
          s = fabs(vn1_data[(i + lastv) - 1]);
          if (s > smax) {
            ix = lastv - 1;
            smax = s;
          }
        }
      }
    }
    pvt = i + ix;
    if (pvt + 1 != i + 1) {
      ix = pvt * ma;
      for (lastv = 0; lastv < m; lastv++) {
        j = ix + lastv;
        smax = A->data[j];
        b_i = lastc + lastv;
        A->data[j] = A->data[b_i];
        A->data[b_i] = smax;
      }
      ix = jpvt_data[pvt];
      jpvt_data[pvt] = jpvt_data[i];
      jpvt_data[i] = ix;
      vn1_data[pvt] = vn1_data[i];
      vn2_data[pvt] = vn2_data[i];
    }
    if (i + 1 < m) {
      smax = A->data[ii];
      tau_data[i] = xzlarfg(mmi + 1, &smax, A, ii + 2);
      A->data[ii] = smax;
    } else {
      tau_data[i] = 0.0;
    }
    if (i + 1 < n) {
      smax = A->data[ii];
      A->data[ii] = 1.0;
      pvt = (ii + ma) + 1;
      if (tau_data[i] != 0.0) {
        lastv = mmi + 1;
        ix = ii + mmi;
        while ((lastv > 0) && (A->data[ix] == 0.0)) {
          lastv--;
          ix--;
        }
        lastc = nmi - 1;
        exitg2 = false;
        while ((!exitg2) && (lastc > 0)) {
          ix = pvt + (lastc - 1) * ma;
          ia = ix;
          do {
            exitg1 = 0;
            if (ia <= (ix + lastv) - 1) {
              if (A->data[ia - 1] != 0.0) {
                exitg1 = 1;
              } else {
                ia++;
              }
            } else {
              lastc--;
              exitg1 = 2;
            }
          } while (exitg1 == 0);
          if (exitg1 == 1) {
            exitg2 = true;
          }
        }
      } else {
        lastv = 0;
        lastc = 0;
      }
      if (lastv > 0) {
        if (lastc != 0) {
          if (0 <= lastc - 1) {
            memset(&work_data[0], 0, lastc * sizeof(double));
          }
          j = 0;
          b_i = pvt + ma * (lastc - 1);
          for (nmi = pvt; ma < 0 ? nmi >= b_i : nmi <= b_i; nmi += ma) {
            s = 0.0;
            ix = (nmi + lastv) - 1;
            for (ia = nmi; ia <= ix; ia++) {
              s += A->data[ia - 1] * A->data[(ii + ia) - nmi];
            }
            work_data[j] += s;
            j++;
          }
        }
        xgerc(lastv, lastc, -tau_data[i], ii + 1, work_data, A, pvt, ma);
      }
      A->data[ii] = smax;
    }
    for (j = ip1; j <= n; j++) {
      ix = i + (j - 1) * ma;
      smax = vn1_data[j - 1];
      if (smax != 0.0) {
        s = fabs(A->data[ix]) / smax;
        s = 1.0 - s * s;
        if (s < 0.0) {
          s = 0.0;
        }
        temp2 = smax / vn2_data[j - 1];
        temp2 = s * (temp2 * temp2);
        if (temp2 <= 1.4901161193847656E-8) {
          if (i + 1 < m) {
            smax = xnrm2(mmi, A, ix + 2);
            vn1_data[j - 1] = smax;
            vn2_data[j - 1] = smax;
          } else {
            vn1_data[j - 1] = 0.0;
            vn2_data[j - 1] = 0.0;
          }
        } else {
          vn1_data[j - 1] = smax * sqrt(s);
        }
      }
    }
  }
}

/*
 * Arguments    : const emxArray_real_T *A
 *                const double B_data[]
 *                int B_size
 *                double Y_data[]
 *                int *Y_size
 * Return Type  : void
 */
static void qrsolve(const emxArray_real_T *A, const double B_data[], int B_size,
                    double Y_data[], int *Y_size)
{
  emxArray_real_T *b_A;
  double b_B_data[1002];
  double tau_data[1002];
  double wj;
  int jpvt_data[1002];
  int jpvt_size[2];
  int b_i;
  int i;
  int loop_ub;
  int m;
  int mn;
  int rankA;
  emxInit_real_T(&b_A, 2);
  i = b_A->size[0] * b_A->size[1];
  b_A->size[0] = A->size[0];
  b_A->size[1] = A->size[1];
  emxEnsureCapacity_real_T(b_A, i);
  loop_ub = A->size[0] * A->size[1];
  for (i = 0; i < loop_ub; i++) {
    b_A->data[i] = A->data[i];
  }
  xgeqp3(b_A, tau_data, &loop_ub, jpvt_data, jpvt_size);
  if (0 <= B_size - 1) {
    memcpy(&b_B_data[0], &B_data[0], B_size * sizeof(double));
  }
  rankA = rankFromQR(b_A);
  *Y_size = (short)b_A->size[1];
  loop_ub = (short)b_A->size[1];
  if (0 <= loop_ub - 1) {
    memset(&Y_data[0], 0, loop_ub * sizeof(double));
  }
  m = b_A->size[0];
  loop_ub = b_A->size[0];
  mn = b_A->size[1];
  if (loop_ub < mn) {
    mn = loop_ub;
  }
  for (loop_ub = 0; loop_ub < mn; loop_ub++) {
    if (tau_data[loop_ub] != 0.0) {
      wj = b_B_data[loop_ub];
      i = loop_ub + 2;
      for (b_i = i; b_i <= m; b_i++) {
        wj += b_A->data[(b_i + b_A->size[0] * loop_ub) - 1] * b_B_data[b_i - 1];
      }
      wj *= tau_data[loop_ub];
      if (wj != 0.0) {
        b_B_data[loop_ub] -= wj;
        for (b_i = i; b_i <= m; b_i++) {
          b_B_data[b_i - 1] -=
              b_A->data[(b_i + b_A->size[0] * loop_ub) - 1] * wj;
        }
      }
    }
  }
  for (b_i = 0; b_i < rankA; b_i++) {
    Y_data[jpvt_data[b_i] - 1] = b_B_data[b_i];
  }
  for (loop_ub = rankA; loop_ub >= 1; loop_ub--) {
    i = jpvt_data[loop_ub - 1];
    Y_data[i - 1] /= b_A->data[(loop_ub + b_A->size[0] * (loop_ub - 1)) - 1];
    for (b_i = 0; b_i <= loop_ub - 2; b_i++) {
      Y_data[jpvt_data[b_i] - 1] -=
          Y_data[jpvt_data[loop_ub - 1] - 1] *
          b_A->data[b_i + b_A->size[0] * (loop_ub - 1)];
    }
  }
  emxFree_real_T(&b_A);
}

/*
 * Arguments    : const emxArray_real_T *A
 * Return Type  : int
 */
static int rankFromQR(const emxArray_real_T *A)
{
  double tol;
  int maxmn;
  int minmn;
  int r;
  r = 0;
  if (A->size[0] < A->size[1]) {
    minmn = A->size[0];
    maxmn = A->size[1];
  } else {
    minmn = A->size[1];
    maxmn = A->size[0];
  }
  if (minmn > 0) {
    tol = 2.2204460492503131E-15 * (double)maxmn * fabs(A->data[0]);
    while ((r < minmn) && (!(fabs(A->data[r + A->size[0] * r]) <= tol))) {
      r++;
    }
  }
  return r;
}

/*
 * Arguments    : double u0
 *                double u1
 * Return Type  : double
 */
static double rt_atan2d_snf(double u0, double u1)
{
  double y;
  int b_u0;
  int b_u1;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = rtNaN;
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    if (u0 > 0.0) {
      b_u0 = 1;
    } else {
      b_u0 = -1;
    }
    if (u1 > 0.0) {
      b_u1 = 1;
    } else {
      b_u1 = -1;
    }
    y = atan2(b_u0, b_u1);
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = atan2(u0, u1);
  }
  return y;
}

/*
 * Arguments    : double u0
 *                double u1
 * Return Type  : double
 */
static double rt_hypotd_snf(double u0, double u1)
{
  double a;
  double y;
  a = fabs(u0);
  y = fabs(u1);
  if (a < y) {
    a /= y;
    y *= sqrt(a * a + 1.0);
  } else if (a > y) {
    y /= a;
    y = a * sqrt(y * y + 1.0);
  } else if (!rtIsNaN(y)) {
    y = a * 1.4142135623730951;
  }
  return y;
}

/*
 * Arguments    : double u0
 *                double u1
 * Return Type  : double
 */
static double rt_powd_snf(double u0, double u1)
{
  double d;
  double d1;
  double y;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = rtNaN;
  } else {
    d = fabs(u0);
    d1 = fabs(u1);
    if (rtIsInf(u1)) {
      if (d == 1.0) {
        y = 1.0;
      } else if (d > 1.0) {
        if (u1 > 0.0) {
          y = rtInf;
        } else {
          y = 0.0;
        }
      } else if (u1 > 0.0) {
        y = 0.0;
      } else {
        y = rtInf;
      }
    } else if (d1 == 0.0) {
      y = 1.0;
    } else if (d1 == 1.0) {
      if (u1 > 0.0) {
        y = u0;
      } else {
        y = 1.0 / u0;
      }
    } else if (u1 == 2.0) {
      y = u0 * u0;
    } else if ((u1 == 0.5) && (u0 >= 0.0)) {
      y = sqrt(u0);
    } else if ((u0 < 0.0) && (u1 > floor(u1))) {
      y = rtNaN;
    } else {
      y = pow(u0, u1);
    }
  }
  return y;
}

/*
 * Arguments    : double u0
 *                double u1
 * Return Type  : double
 */
static double rt_remd_snf(double u0, double u1)
{
  double b_u1;
  double y;
  if (rtIsNaN(u0) || rtIsNaN(u1) || rtIsInf(u0)) {
    y = rtNaN;
  } else if (rtIsInf(u1)) {
    y = u0;
  } else {
    if (u1 < 0.0) {
      b_u1 = ceil(u1);
    } else {
      b_u1 = floor(u1);
    }
    if ((u1 != 0.0) && (u1 != b_u1)) {
      b_u1 = fabs(u0 / u1);
      if (!(fabs(b_u1 - floor(b_u1 + 0.5)) > DBL_EPSILON * b_u1)) {
        y = 0.0 * u0;
      } else {
        y = fmod(u0, u1);
      }
    } else {
      y = fmod(u0, u1);
    }
  }
  return y;
}

/*
 * Arguments    : emxArray_real_T *A
 *                emxArray_real_T *V
 * Return Type  : void
 */
static void schur(emxArray_real_T *A, emxArray_real_T *V)
{
  int i;
  int istart;
  int j;
  int jend;
  int nx;
  boolean_T p;
  nx = A->size[0] * A->size[1];
  p = true;
  for (istart = 0; istart < nx; istart++) {
    if ((!p) || (rtIsInf(A->data[istart]) || rtIsNaN(A->data[istart]))) {
      p = false;
    }
  }
  if (!p) {
    istart = V->size[0] * V->size[1];
    V->size[0] = (short)A->size[0];
    V->size[1] = (short)A->size[1];
    emxEnsureCapacity_real_T(V, istart);
    nx = (short)A->size[0] * (short)A->size[1];
    for (istart = 0; istart < nx; istart++) {
      V->data[istart] = rtNaN;
    }
    nx = (short)A->size[0];
    if (((short)A->size[0] != 0) && ((short)A->size[1] != 0) &&
        (1 < (short)A->size[0])) {
      istart = 2;
      if ((short)A->size[0] - 2 < (short)A->size[1] - 1) {
        jend = (short)A->size[0] - 1;
      } else {
        jend = (short)A->size[1];
      }
      for (j = 0; j < jend; j++) {
        for (i = istart; i <= nx; i++) {
          V->data[(i + V->size[0] * j) - 1] = 0.0;
        }
        istart++;
      }
    }
  } else {
    xgehrd(A);
    istart = V->size[0] * V->size[1];
    V->size[0] = A->size[0];
    V->size[1] = A->size[1];
    emxEnsureCapacity_real_T(V, istart);
    nx = A->size[0] * A->size[1];
    for (istart = 0; istart < nx; istart++) {
      V->data[istart] = A->data[istart];
    }
    eml_dlahqr(V);
    nx = V->size[0];
    if ((V->size[0] != 0) && (V->size[1] != 0) && (3 < V->size[0])) {
      istart = 4;
      if (V->size[0] - 4 < V->size[1] - 1) {
        jend = V->size[0] - 3;
      } else {
        jend = V->size[1];
      }
      for (j = 0; j < jend; j++) {
        for (i = istart; i <= nx; i++) {
          V->data[(i + V->size[0] * j) - 1] = 0.0;
        }
        istart++;
      }
    }
  }
}

/*
 * Arguments    : double *a
 *                double *b
 *                double *c
 *                double *d
 *                double *rt1r
 *                double *rt1i
 *                double *rt2r
 *                double *rt2i
 *                double *cs
 *                double *sn
 * Return Type  : void
 */
static void xdlanv2(double *a, double *b, double *c, double *d, double *rt1r,
                    double *rt1i, double *rt2r, double *rt2i, double *cs,
                    double *sn)
{
  double bcmax;
  double bcmis;
  double p;
  double scale;
  double tau;
  double z;
  int b_b;
  int b_c;
  if (*c == 0.0) {
    *cs = 1.0;
    *sn = 0.0;
  } else if (*b == 0.0) {
    *cs = 0.0;
    *sn = 1.0;
    z = *d;
    *d = *a;
    *a = z;
    *b = -*c;
    *c = 0.0;
  } else {
    tau = *a - *d;
    if ((tau == 0.0) && ((*b < 0.0) != (*c < 0.0))) {
      *cs = 1.0;
      *sn = 0.0;
    } else {
      p = 0.5 * tau;
      scale = fabs(*b);
      bcmis = fabs(*c);
      if ((scale > bcmis) || rtIsNaN(bcmis)) {
        bcmax = scale;
      } else {
        bcmax = bcmis;
      }
      if ((scale < bcmis) || rtIsNaN(bcmis)) {
        bcmis = scale;
      }
      if (!(*b < 0.0)) {
        b_b = 1;
      } else {
        b_b = -1;
      }
      if (!(*c < 0.0)) {
        b_c = 1;
      } else {
        b_c = -1;
      }
      bcmis = bcmis * (double)b_b * (double)b_c;
      scale = fabs(p);
      if ((!(scale > bcmax)) && (!rtIsNaN(bcmax))) {
        scale = bcmax;
      }
      z = p / scale * p + bcmax / scale * bcmis;
      if (z >= 8.8817841970012523E-16) {
        *a = sqrt(scale) * sqrt(z);
        if (p < 0.0) {
          *a = -*a;
        }
        z = p + *a;
        *a = *d + z;
        *d -= bcmax / z * bcmis;
        tau = rt_hypotd_snf(*c, z);
        *cs = z / tau;
        *sn = *c / tau;
        *b -= *c;
        *c = 0.0;
      } else {
        scale = *b + *c;
        tau = rt_hypotd_snf(scale, tau);
        *cs = sqrt(0.5 * (fabs(scale) / tau + 1.0));
        if (!(scale < 0.0)) {
          b_b = 1;
        } else {
          b_b = -1;
        }
        *sn = -(p / (tau * *cs)) * (double)b_b;
        bcmax = *a * *cs + *b * *sn;
        bcmis = -*a * *sn + *b * *cs;
        z = *c * *cs + *d * *sn;
        scale = -*c * *sn + *d * *cs;
        *b = bcmis * *cs + scale * *sn;
        *c = -bcmax * *sn + z * *cs;
        z = 0.5 * ((bcmax * *cs + z * *sn) + (-bcmis * *sn + scale * *cs));
        *a = z;
        *d = z;
        if (*c != 0.0) {
          if (*b != 0.0) {
            if ((*b < 0.0) == (*c < 0.0)) {
              scale = sqrt(fabs(*b));
              bcmis = sqrt(fabs(*c));
              *a = scale * bcmis;
              if (!(*c < 0.0)) {
                p = *a;
              } else {
                p = -*a;
              }
              tau = 1.0 / sqrt(fabs(*b + *c));
              *a = z + p;
              *d = z - p;
              *b -= *c;
              *c = 0.0;
              bcmax = scale * tau;
              scale = bcmis * tau;
              z = *cs * bcmax - *sn * scale;
              *sn = *cs * scale + *sn * bcmax;
              *cs = z;
            }
          } else {
            *b = -*c;
            *c = 0.0;
            z = *cs;
            *cs = -*sn;
            *sn = z;
          }
        }
      }
    }
  }
  *rt1r = *a;
  *rt2r = *d;
  if (*c == 0.0) {
    *rt1i = 0.0;
    *rt2i = 0.0;
  } else {
    *rt1i = sqrt(fabs(*b)) * sqrt(fabs(*c));
    *rt2i = -*rt1i;
  }
}

/*
 * Arguments    : emxArray_real_T *a
 * Return Type  : void
 */
static void xgehrd(emxArray_real_T *a)
{
  double work_data[1002];
  double tau_data[1001];
  double alpha1;
  double temp;
  int b_i;
  int c_i;
  int exitg1;
  int i;
  int i1;
  int i2;
  int ia;
  int iac;
  int ic0;
  int in;
  int iv0_tmp;
  int lastc;
  int lastv;
  int n;
  int n_tmp_tmp;
  int work_tmp;
  short unnamed_idx_0;
  boolean_T exitg2;
  n = a->size[0];
  unnamed_idx_0 = (short)a->size[0];
  i = unnamed_idx_0;
  if (0 <= i - 1) {
    memset(&work_data[0], 0, i * sizeof(double));
  }
  b_i = a->size[0];
  for (c_i = 0; c_i <= b_i - 2; c_i++) {
    in = (c_i + 1) * n;
    alpha1 = a->data[(c_i + a->size[0] * c_i) + 1];
    i = c_i + 3;
    if (i >= n) {
      i = n;
    }
    temp = xzlarfg((n - c_i) - 1, &alpha1, a, i + c_i * n);
    tau_data[c_i] = temp;
    a->data[(c_i + a->size[0] * c_i) + 1] = 1.0;
    n_tmp_tmp = n - c_i;
    iv0_tmp = (c_i + c_i * n) + 2;
    ic0 = in + 1;
    if (temp != 0.0) {
      lastv = n_tmp_tmp - 2;
      i = (iv0_tmp + n_tmp_tmp) - 4;
      while ((lastv + 1 > 0) && (a->data[i + 1] == 0.0)) {
        lastv--;
        i--;
      }
      lastc = n;
      exitg2 = false;
      while ((!exitg2) && (lastc > 0)) {
        i = in + lastc;
        ia = i;
        do {
          exitg1 = 0;
          if ((n > 0) && (ia <= i + lastv * n)) {
            if (a->data[ia - 1] != 0.0) {
              exitg1 = 1;
            } else {
              ia += n;
            }
          } else {
            lastc--;
            exitg1 = 2;
          }
        } while (exitg1 == 0);
        if (exitg1 == 1) {
          exitg2 = true;
        }
      }
    } else {
      lastv = -1;
      lastc = 0;
    }
    if (lastv + 1 > 0) {
      if (lastc != 0) {
        if (0 <= lastc - 1) {
          memset(&work_data[0], 0, lastc * sizeof(double));
        }
        i = iv0_tmp - 1;
        i1 = (in + n * lastv) + 1;
        for (iac = ic0; n < 0 ? iac >= i1 : iac <= i1; iac += n) {
          i2 = (iac + lastc) - 1;
          for (ia = iac; ia <= i2; ia++) {
            work_tmp = ia - iac;
            work_data[work_tmp] += a->data[ia - 1] * a->data[i];
          }
          i++;
        }
      }
      if (!(-tau_data[c_i] == 0.0)) {
        i = in;
        for (work_tmp = 0; work_tmp <= lastv; work_tmp++) {
          i1 = (iv0_tmp + work_tmp) - 1;
          if (a->data[i1] != 0.0) {
            temp = a->data[i1] * -tau_data[c_i];
            i1 = i + 1;
            i2 = lastc + i;
            for (iac = i1; iac <= i2; iac++) {
              a->data[iac - 1] += work_data[(iac - i) - 1] * temp;
            }
          }
          i += n;
        }
      }
    }
    ic0 = (c_i + in) + 2;
    if (tau_data[c_i] != 0.0) {
      lastv = n_tmp_tmp - 1;
      i = (iv0_tmp + n_tmp_tmp) - 3;
      while ((lastv > 0) && (a->data[i] == 0.0)) {
        lastv--;
        i--;
      }
      lastc = n_tmp_tmp - 1;
      exitg2 = false;
      while ((!exitg2) && (lastc > 0)) {
        i = ic0 + (lastc - 1) * n;
        ia = i;
        do {
          exitg1 = 0;
          if (ia <= (i + lastv) - 1) {
            if (a->data[ia - 1] != 0.0) {
              exitg1 = 1;
            } else {
              ia++;
            }
          } else {
            lastc--;
            exitg1 = 2;
          }
        } while (exitg1 == 0);
        if (exitg1 == 1) {
          exitg2 = true;
        }
      }
    } else {
      lastv = 0;
      lastc = 0;
    }
    if (lastv > 0) {
      if (lastc != 0) {
        if (0 <= lastc - 1) {
          memset(&work_data[0], 0, lastc * sizeof(double));
        }
        i = 0;
        i1 = ic0 + n * (lastc - 1);
        for (iac = ic0; n < 0 ? iac >= i1 : iac <= i1; iac += n) {
          temp = 0.0;
          i2 = (iac + lastv) - 1;
          for (ia = iac; ia <= i2; ia++) {
            temp += a->data[ia - 1] * a->data[((iv0_tmp + ia) - iac) - 1];
          }
          work_data[i] += temp;
          i++;
        }
      }
      xgerc(lastv, lastc, -tau_data[c_i], iv0_tmp, work_data, a, ic0, n);
    }
    a->data[(c_i + a->size[0] * c_i) + 1] = alpha1;
  }
}

/*
 * Arguments    : emxArray_real_T *A
 *                double tau_data[]
 *                int *tau_size
 *                int jpvt_data[]
 *                int jpvt_size[2]
 * Return Type  : void
 */
static void xgeqp3(emxArray_real_T *A, double tau_data[], int *tau_size,
                   int jpvt_data[], int jpvt_size[2])
{
  int n;
  int u0;
  int u1;
  boolean_T guard1 = false;
  n = A->size[1] - 1;
  u0 = A->size[0];
  *tau_size = A->size[1];
  if (u0 < *tau_size) {
    *tau_size = u0;
  }
  if (0 <= *tau_size - 1) {
    memset(&tau_data[0], 0, *tau_size * sizeof(double));
  }
  guard1 = false;
  if ((A->size[0] == 0) || (A->size[1] == 0)) {
    guard1 = true;
  } else {
    u0 = A->size[0];
    u1 = A->size[1];
    if (u0 < u1) {
      u1 = u0;
    }
    if (u1 < 1) {
      guard1 = true;
    } else {
      jpvt_size[0] = 1;
      jpvt_size[1] = A->size[1];
      u0 = A->size[1];
      if (0 <= u0 - 1) {
        memset(&jpvt_data[0], 0, u0 * sizeof(int));
      }
      for (u0 = 0; u0 <= n; u0++) {
        jpvt_data[u0] = u0 + 1;
      }
      qrpf(A, A->size[0], A->size[1], tau_data, jpvt_data);
    }
  }
  if (guard1) {
    jpvt_size[0] = 1;
    jpvt_size[1] = A->size[1];
    u0 = A->size[1];
    if (0 <= u0 - 1) {
      memset(&jpvt_data[0], 0, u0 * sizeof(int));
    }
    for (u0 = 0; u0 <= n; u0++) {
      jpvt_data[u0] = u0 + 1;
    }
  }
}

/*
 * Arguments    : int m
 *                int n
 *                double alpha1
 *                int ix0
 *                const double y_data[]
 *                emxArray_real_T *A
 *                int ia0
 *                int lda
 * Return Type  : void
 */
static void xgerc(int m, int n, double alpha1, int ix0, const double y_data[],
                  emxArray_real_T *A, int ia0, int lda)
{
  double temp;
  int i;
  int ijA;
  int j;
  int jA;
  if (!(alpha1 == 0.0)) {
    jA = ia0;
    for (j = 0; j < n; j++) {
      if (y_data[j] != 0.0) {
        temp = y_data[j] * alpha1;
        i = m + jA;
        for (ijA = jA; ijA < i; ijA++) {
          A->data[ijA - 1] += A->data[((ix0 + ijA) - jA) - 1] * temp;
        }
      }
      jA += lda;
    }
  }
}

/*
 * Arguments    : int m
 *                int n
 *                emxArray_real_T *A
 *                int lda
 *                int ipiv_data[]
 *                int ipiv_size[2]
 * Return Type  : void
 */
static void xgetrf(int m, int n, emxArray_real_T *A, int lda, int ipiv_data[],
                   int ipiv_size[2])
{
  emxArray_real_T *b_A;
  int b_ipiv_data[1002];
  int b_ipiv_size[2];
  int b_loop_ub;
  int i;
  int i1;
  int loop_ub;
  emxInit_real_T(&b_A, 2);
  i = b_A->size[0] * b_A->size[1];
  b_A->size[0] = A->size[0];
  b_A->size[1] = A->size[1];
  emxEnsureCapacity_real_T(b_A, i);
  loop_ub = A->size[0] * A->size[1];
  for (i = 0; i < loop_ub; i++) {
    b_A->data[i] = A->data[i];
  }
  xzgetrf(m, n, b_A, lda, b_ipiv_data, b_ipiv_size, &loop_ub);
  i = A->size[0] * A->size[1];
  A->size[0] = b_A->size[0];
  A->size[1] = b_A->size[1];
  emxEnsureCapacity_real_T(A, i);
  loop_ub = b_A->size[1];
  for (i = 0; i < loop_ub; i++) {
    b_loop_ub = b_A->size[0];
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      A->data[i1 + A->size[0] * i] = b_A->data[i1 + b_A->size[0] * i];
    }
  }
  emxFree_real_T(&b_A);
  ipiv_size[0] = 1;
  ipiv_size[1] = b_ipiv_size[1];
  loop_ub = b_ipiv_size[1];
  if (0 <= loop_ub - 1) {
    memcpy(&ipiv_data[0], &b_ipiv_data[0], loop_ub * sizeof(int));
  }
}

/*
 * Arguments    : int n
 *                const emxArray_real_T *x
 *                int ix0
 * Return Type  : double
 */
static double xnrm2(int n, const emxArray_real_T *x, int ix0)
{
  double absxk;
  double scale;
  double t;
  double y;
  int k;
  int kend;
  y = 0.0;
  if (n >= 1) {
    if (n == 1) {
      y = fabs(x->data[ix0 - 1]);
    } else {
      scale = 3.3121686421112381E-170;
      kend = (ix0 + n) - 1;
      for (k = ix0; k <= kend; k++) {
        absxk = fabs(x->data[k - 1]);
        if (absxk > scale) {
          t = scale / absxk;
          y = y * t * t + 1.0;
          scale = absxk;
        } else {
          t = absxk / scale;
          y += t * t;
        }
      }
      y = scale * sqrt(y);
    }
  }
  return y;
}

/*
 * Arguments    : int n
 *                emxArray_real_T *x
 *                int ix0
 *                int incx
 *                int iy0
 *                int incy
 *                double c
 *                double s
 * Return Type  : void
 */
static void xrot(int n, emxArray_real_T *x, int ix0, int incx, int iy0,
                 int incy, double c, double s)
{
  double temp;
  int b_temp_tmp;
  int k;
  int temp_tmp;
  if (n >= 1) {
    for (k = 0; k < n; k++) {
      temp_tmp = (iy0 + k * incx) - 1;
      b_temp_tmp = (ix0 + k * incy) - 1;
      temp = c * x->data[b_temp_tmp] + s * x->data[temp_tmp];
      x->data[temp_tmp] = c * x->data[temp_tmp] - s * x->data[b_temp_tmp];
      x->data[b_temp_tmp] = temp;
    }
  }
}

/*
 * Arguments    : const emxArray_real_T *A
 *                int *info
 *                creal_T alpha1_data[]
 *                int *alpha1_size
 *                creal_T beta1_data[]
 *                int *beta1_size
 * Return Type  : void
 */
static void xzgeev(const emxArray_real_T *A, int *info, creal_T alpha1_data[],
                   int *alpha1_size, creal_T beta1_data[], int *beta1_size)
{
  emxArray_creal_T *At;
  double a;
  double absxk;
  double anrm;
  double cfrom1;
  double cfromc;
  double cto1;
  double ctoc;
  int rscale_data[1002];
  int ihi;
  int ilo;
  int loop_ub;
  boolean_T exitg1;
  boolean_T guard1 = false;
  boolean_T ilascl;
  boolean_T notdone;
  emxInit_creal_T(&At, 2);
  ilo = At->size[0] * At->size[1];
  At->size[0] = A->size[0];
  At->size[1] = A->size[1];
  emxEnsureCapacity_creal_T(At, ilo);
  loop_ub = A->size[0] * A->size[1];
  for (ilo = 0; ilo < loop_ub; ilo++) {
    At->data[ilo].re = A->data[ilo];
    At->data[ilo].im = 0.0;
  }
  *info = 0;
  *alpha1_size = At->size[0];
  loop_ub = At->size[0];
  if (0 <= loop_ub - 1) {
    memset(&alpha1_data[0], 0, loop_ub * sizeof(creal_T));
  }
  *beta1_size = At->size[0];
  loop_ub = At->size[0];
  if (0 <= loop_ub - 1) {
    memset(&beta1_data[0], 0, loop_ub * sizeof(creal_T));
  }
  if ((At->size[0] != 0) && (At->size[1] != 0)) {
    anrm = 0.0;
    loop_ub = 0;
    exitg1 = false;
    while ((!exitg1) && (loop_ub <= At->size[0] * At->size[1] - 1)) {
      absxk = rt_hypotd_snf(At->data[loop_ub].re, At->data[loop_ub].im);
      if (rtIsNaN(absxk)) {
        anrm = rtNaN;
        exitg1 = true;
      } else {
        if (absxk > anrm) {
          anrm = absxk;
        }
        loop_ub++;
      }
    }
    if (rtIsInf(anrm) || rtIsNaN(anrm)) {
      *alpha1_size = At->size[0];
      loop_ub = At->size[0];
      for (ilo = 0; ilo < loop_ub; ilo++) {
        alpha1_data[ilo].re = rtNaN;
        alpha1_data[ilo].im = 0.0;
      }
      *beta1_size = At->size[0];
      loop_ub = At->size[0];
      for (ilo = 0; ilo < loop_ub; ilo++) {
        beta1_data[ilo].re = rtNaN;
        beta1_data[ilo].im = 0.0;
      }
    } else {
      ilascl = false;
      absxk = anrm;
      guard1 = false;
      if ((anrm > 0.0) && (anrm < 6.7178761075670888E-139)) {
        absxk = 6.7178761075670888E-139;
        ilascl = true;
        guard1 = true;
      } else if (anrm > 1.4885657073574029E+138) {
        absxk = 1.4885657073574029E+138;
        ilascl = true;
        guard1 = true;
      }
      if (guard1) {
        cfromc = anrm;
        ctoc = absxk;
        notdone = true;
        while (notdone) {
          cfrom1 = cfromc * 2.0041683600089728E-292;
          cto1 = ctoc / 4.9896007738368E+291;
          if ((cfrom1 > ctoc) && (ctoc != 0.0)) {
            a = 2.0041683600089728E-292;
            cfromc = cfrom1;
          } else if (cto1 > cfromc) {
            a = 4.9896007738368E+291;
            ctoc = cto1;
          } else {
            a = ctoc / cfromc;
            notdone = false;
          }
          loop_ub = At->size[0] * At->size[1];
          for (ilo = 0; ilo < loop_ub; ilo++) {
            At->data[ilo].re *= a;
            At->data[ilo].im *= a;
          }
        }
      }
      xzggbal(At, &ilo, &ihi, rscale_data, &loop_ub);
      xzgghrd(ilo, ihi, At);
      xzhgeqz(At, ilo, ihi, info, alpha1_data, alpha1_size, beta1_data,
              beta1_size);
      if ((*info == 0) && ilascl) {
        notdone = true;
        while (notdone) {
          cfrom1 = absxk * 2.0041683600089728E-292;
          cto1 = anrm / 4.9896007738368E+291;
          if ((cfrom1 > anrm) && (anrm != 0.0)) {
            a = 2.0041683600089728E-292;
            absxk = cfrom1;
          } else if (cto1 > absxk) {
            a = 4.9896007738368E+291;
            anrm = cto1;
          } else {
            a = anrm / absxk;
            notdone = false;
          }
          for (ilo = 0; ilo < *alpha1_size; ilo++) {
            alpha1_data[ilo].re *= a;
            alpha1_data[ilo].im *= a;
          }
        }
      }
    }
  }
  emxFree_creal_T(&At);
}

/*
 * Arguments    : int m
 *                int n
 *                emxArray_real_T *A
 *                int lda
 *                int ipiv_data[]
 *                int ipiv_size[2]
 *                int *info
 * Return Type  : void
 */
static void xzgetrf(int m, int n, emxArray_real_T *A, int lda, int ipiv_data[],
                    int ipiv_size[2], int *info)
{
  double s;
  double smax;
  int b_n;
  int b_tmp;
  int i;
  int ipiv_tmp;
  int j;
  int jA;
  int jp1j;
  int k;
  int mmj;
  int u0;
  int yk;
  if (m < n) {
    yk = m;
  } else {
    yk = n;
  }
  if (yk < 1) {
    b_n = 0;
  } else {
    b_n = yk;
  }
  ipiv_size[0] = 1;
  ipiv_size[1] = b_n;
  if (b_n > 0) {
    ipiv_data[0] = 1;
    yk = 1;
    for (k = 2; k <= b_n; k++) {
      yk++;
      ipiv_data[k - 1] = yk;
    }
  }
  *info = 0;
  if ((m >= 1) && (n >= 1)) {
    u0 = m - 1;
    if (u0 >= n) {
      u0 = n;
    }
    for (j = 0; j < u0; j++) {
      mmj = m - j;
      b_tmp = j * (lda + 1);
      jp1j = b_tmp + 2;
      if (mmj < 1) {
        yk = -1;
      } else {
        yk = 0;
        if (mmj > 1) {
          smax = fabs(A->data[b_tmp]);
          for (k = 2; k <= mmj; k++) {
            s = fabs(A->data[(b_tmp + k) - 1]);
            if (s > smax) {
              yk = k - 1;
              smax = s;
            }
          }
        }
      }
      if (A->data[b_tmp + yk] != 0.0) {
        if (yk != 0) {
          ipiv_tmp = j + yk;
          ipiv_data[j] = ipiv_tmp + 1;
          for (k = 0; k < n; k++) {
            yk = k * lda;
            jA = j + yk;
            smax = A->data[jA];
            i = ipiv_tmp + yk;
            A->data[jA] = A->data[i];
            A->data[i] = smax;
          }
        }
        i = b_tmp + mmj;
        for (yk = jp1j; yk <= i; yk++) {
          A->data[yk - 1] /= A->data[b_tmp];
        }
      } else {
        *info = j + 1;
      }
      b_n = n - j;
      ipiv_tmp = b_tmp + lda;
      jA = ipiv_tmp;
      for (k = 0; k <= b_n - 2; k++) {
        yk = ipiv_tmp + k * lda;
        smax = A->data[yk];
        if (A->data[yk] != 0.0) {
          i = jA + 2;
          yk = mmj + jA;
          for (jp1j = i; jp1j <= yk; jp1j++) {
            A->data[jp1j - 1] += A->data[((b_tmp + jp1j) - jA) - 1] * -smax;
          }
        }
        jA += lda;
      }
    }
    if ((*info == 0) && (m <= n) &&
        (!(A->data[(m + A->size[0] * (m - 1)) - 1] != 0.0))) {
      *info = m;
    }
  }
}

/*
 * Arguments    : emxArray_creal_T *A
 *                int *ilo
 *                int *ihi
 *                int rscale_data[]
 *                int *rscale_size
 * Return Type  : void
 */
static void xzggbal(emxArray_creal_T *A, int *ilo, int *ihi, int rscale_data[],
                    int *rscale_size)
{
  double atmp_im;
  double atmp_re;
  int exitg1;
  int exitg2;
  int i;
  int ii;
  int j;
  int jj;
  int nzcount;
  boolean_T exitg3;
  boolean_T exitg4;
  boolean_T found;
  *rscale_size = A->size[0];
  nzcount = A->size[0];
  for (ii = 0; ii < nzcount; ii++) {
    rscale_data[ii] = 1;
  }
  *ilo = 1;
  *ihi = A->size[0];
  if (A->size[0] <= 1) {
    *ihi = 1;
  } else {
    do {
      exitg2 = 0;
      i = 0;
      j = 0;
      found = false;
      ii = *ihi;
      exitg3 = false;
      while ((!exitg3) && (ii > 0)) {
        nzcount = 0;
        i = ii;
        j = *ihi;
        jj = 0;
        exitg4 = false;
        while ((!exitg4) && (jj <= *ihi - 1)) {
          if ((A->data[(ii + A->size[0] * jj) - 1].re != 0.0) ||
              (A->data[(ii + A->size[0] * jj) - 1].im != 0.0) ||
              (ii == jj + 1)) {
            if (nzcount == 0) {
              j = jj + 1;
              nzcount = 1;
              jj++;
            } else {
              nzcount = 2;
              exitg4 = true;
            }
          } else {
            jj++;
          }
        }
        if (nzcount < 2) {
          found = true;
          exitg3 = true;
        } else {
          ii--;
        }
      }
      if (!found) {
        exitg2 = 2;
      } else {
        nzcount = A->size[0];
        if (i != *ihi) {
          for (ii = 1; ii <= nzcount; ii++) {
            atmp_re = A->data[(i + A->size[0] * (ii - 1)) - 1].re;
            atmp_im = A->data[(i + A->size[0] * (ii - 1)) - 1].im;
            A->data[(i + A->size[0] * (ii - 1)) - 1] =
                A->data[(*ihi + A->size[0] * (ii - 1)) - 1];
            A->data[(*ihi + A->size[0] * (ii - 1)) - 1].re = atmp_re;
            A->data[(*ihi + A->size[0] * (ii - 1)) - 1].im = atmp_im;
          }
        }
        if (j != *ihi) {
          for (ii = 0; ii < *ihi; ii++) {
            atmp_re = A->data[ii + A->size[0] * (j - 1)].re;
            atmp_im = A->data[ii + A->size[0] * (j - 1)].im;
            A->data[ii + A->size[0] * (j - 1)] =
                A->data[ii + A->size[0] * (*ihi - 1)];
            A->data[ii + A->size[0] * (*ihi - 1)].re = atmp_re;
            A->data[ii + A->size[0] * (*ihi - 1)].im = atmp_im;
          }
        }
        rscale_data[*ihi - 1] = j;
        (*ihi)--;
        if (*ihi == 1) {
          rscale_data[0] = 1;
          exitg2 = 1;
        }
      }
    } while (exitg2 == 0);
    if (exitg2 != 1) {
      do {
        exitg1 = 0;
        i = 0;
        j = 0;
        found = false;
        jj = *ilo;
        exitg3 = false;
        while ((!exitg3) && (jj <= *ihi)) {
          nzcount = 0;
          i = *ihi;
          j = jj;
          ii = *ilo;
          exitg4 = false;
          while ((!exitg4) && (ii <= *ihi)) {
            if ((A->data[(ii + A->size[0] * (jj - 1)) - 1].re != 0.0) ||
                (A->data[(ii + A->size[0] * (jj - 1)) - 1].im != 0.0) ||
                (ii == jj)) {
              if (nzcount == 0) {
                i = ii;
                nzcount = 1;
                ii++;
              } else {
                nzcount = 2;
                exitg4 = true;
              }
            } else {
              ii++;
            }
          }
          if (nzcount < 2) {
            found = true;
            exitg3 = true;
          } else {
            jj++;
          }
        }
        if (!found) {
          exitg1 = 1;
        } else {
          nzcount = A->size[0];
          if (i != *ilo) {
            for (ii = *ilo; ii <= nzcount; ii++) {
              atmp_re = A->data[(i + A->size[0] * (ii - 1)) - 1].re;
              atmp_im = A->data[(i + A->size[0] * (ii - 1)) - 1].im;
              A->data[(i + A->size[0] * (ii - 1)) - 1] =
                  A->data[(*ilo + A->size[0] * (ii - 1)) - 1];
              A->data[(*ilo + A->size[0] * (ii - 1)) - 1].re = atmp_re;
              A->data[(*ilo + A->size[0] * (ii - 1)) - 1].im = atmp_im;
            }
          }
          if (j != *ilo) {
            for (ii = 0; ii < *ihi; ii++) {
              atmp_re = A->data[ii + A->size[0] * (j - 1)].re;
              atmp_im = A->data[ii + A->size[0] * (j - 1)].im;
              A->data[ii + A->size[0] * (j - 1)] =
                  A->data[ii + A->size[0] * (*ilo - 1)];
              A->data[ii + A->size[0] * (*ilo - 1)].re = atmp_re;
              A->data[ii + A->size[0] * (*ilo - 1)].im = atmp_im;
            }
          }
          rscale_data[*ilo - 1] = j;
          (*ilo)++;
          if (*ilo == *ihi) {
            rscale_data[*ilo - 1] = *ilo;
            exitg1 = 1;
          }
        }
      } while (exitg1 == 0);
    }
  }
}

/*
 * Arguments    : int ilo
 *                int ihi
 *                emxArray_creal_T *A
 * Return Type  : void
 */
static void xzgghrd(int ilo, int ihi, emxArray_creal_T *A)
{
  creal_T s;
  double c;
  double d;
  double d1;
  double stemp_im;
  double stemp_re;
  int j;
  int jcol;
  int jcolp1;
  int jrow;
  int n;
  n = A->size[0];
  if ((A->size[0] > 1) && (ihi >= ilo + 2)) {
    for (jcol = ilo - 1; jcol + 1 < ihi - 1; jcol++) {
      jcolp1 = jcol + 2;
      for (jrow = ihi - 1; jrow + 1 > jcol + 2; jrow--) {
        xzlartg(A->data[(jrow + A->size[0] * jcol) - 1],
                A->data[jrow + A->size[0] * jcol], &c, &s,
                &A->data[(jrow + A->size[0] * jcol) - 1]);
        A->data[jrow + A->size[0] * jcol].re = 0.0;
        A->data[jrow + A->size[0] * jcol].im = 0.0;
        for (j = jcolp1; j <= n; j++) {
          stemp_re = c * A->data[(jrow + A->size[0] * (j - 1)) - 1].re +
                     (s.re * A->data[jrow + A->size[0] * (j - 1)].re -
                      s.im * A->data[jrow + A->size[0] * (j - 1)].im);
          stemp_im = c * A->data[(jrow + A->size[0] * (j - 1)) - 1].im +
                     (s.re * A->data[jrow + A->size[0] * (j - 1)].im +
                      s.im * A->data[jrow + A->size[0] * (j - 1)].re);
          d = A->data[(jrow + A->size[0] * (j - 1)) - 1].im;
          d1 = A->data[(jrow + A->size[0] * (j - 1)) - 1].re;
          A->data[jrow + A->size[0] * (j - 1)].re =
              c * A->data[jrow + A->size[0] * (j - 1)].re -
              (s.re * A->data[(jrow + A->size[0] * (j - 1)) - 1].re +
               s.im * A->data[(jrow + A->size[0] * (j - 1)) - 1].im);
          A->data[jrow + A->size[0] * (j - 1)].im =
              c * A->data[jrow + A->size[0] * (j - 1)].im -
              (s.re * d - s.im * d1);
          A->data[(jrow + A->size[0] * (j - 1)) - 1].re = stemp_re;
          A->data[(jrow + A->size[0] * (j - 1)) - 1].im = stemp_im;
        }
        s.re = -s.re;
        s.im = -s.im;
        for (j = 1; j <= ihi; j++) {
          stemp_re = c * A->data[(j + A->size[0] * jrow) - 1].re +
                     (s.re * A->data[(j + A->size[0] * (jrow - 1)) - 1].re -
                      s.im * A->data[(j + A->size[0] * (jrow - 1)) - 1].im);
          stemp_im = c * A->data[(j + A->size[0] * jrow) - 1].im +
                     (s.re * A->data[(j + A->size[0] * (jrow - 1)) - 1].im +
                      s.im * A->data[(j + A->size[0] * (jrow - 1)) - 1].re);
          d = A->data[(j + A->size[0] * jrow) - 1].im;
          d1 = A->data[(j + A->size[0] * jrow) - 1].re;
          A->data[(j + A->size[0] * (jrow - 1)) - 1].re =
              c * A->data[(j + A->size[0] * (jrow - 1)) - 1].re -
              (s.re * A->data[(j + A->size[0] * jrow) - 1].re +
               s.im * A->data[(j + A->size[0] * jrow) - 1].im);
          A->data[(j + A->size[0] * (jrow - 1)) - 1].im =
              c * A->data[(j + A->size[0] * (jrow - 1)) - 1].im -
              (s.re * d - s.im * d1);
          A->data[(j + A->size[0] * jrow) - 1].re = stemp_re;
          A->data[(j + A->size[0] * jrow) - 1].im = stemp_im;
        }
      }
    }
  }
}

/*
 * Arguments    : const emxArray_creal_T *A
 *                int ilo
 *                int ihi
 *                int *info
 *                creal_T alpha1_data[]
 *                int *alpha1_size
 *                creal_T beta1_data[]
 *                int *beta1_size
 * Return Type  : void
 */
static void xzhgeqz(const emxArray_creal_T *A, int ilo, int ihi, int *info,
                    creal_T alpha1_data[], int *alpha1_size,
                    creal_T beta1_data[], int *beta1_size)
{
  emxArray_creal_T *b_A;
  creal_T b_ascale;
  creal_T ctemp;
  creal_T shift;
  double ad22_im;
  double ad22_re;
  double anorm;
  double ascale;
  double b_atol;
  double bscale;
  double colscale;
  double colssq;
  double eshift_im;
  double eshift_re;
  double scale;
  double ssq;
  double t;
  double t1_im;
  double t1_im_tmp;
  double t1_re;
  int col;
  int exitg1;
  int iiter;
  int ilast;
  int ilastm;
  int ilastm1;
  int istart;
  int j;
  int jiter;
  int jp1;
  int n;
  int nm1;
  boolean_T b_guard1 = false;
  boolean_T exitg2;
  boolean_T failed;
  boolean_T goto60;
  boolean_T goto70;
  boolean_T goto90;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  boolean_T guard3 = false;
  emxInit_creal_T(&b_A, 2);
  istart = b_A->size[0] * b_A->size[1];
  b_A->size[0] = A->size[0];
  b_A->size[1] = A->size[1];
  emxEnsureCapacity_creal_T(b_A, istart);
  jp1 = A->size[0] * A->size[1];
  for (istart = 0; istart < jp1; istart++) {
    b_A->data[istart] = A->data[istart];
  }
  *info = 0;
  if ((A->size[0] == 1) && (A->size[1] == 1)) {
    ihi = 1;
  }
  n = A->size[0];
  *alpha1_size = A->size[0];
  jp1 = A->size[0];
  if (0 <= jp1 - 1) {
    memset(&alpha1_data[0], 0, jp1 * sizeof(creal_T));
  }
  *beta1_size = A->size[0];
  jp1 = A->size[0];
  for (istart = 0; istart < jp1; istart++) {
    beta1_data[istart].re = 1.0;
    beta1_data[istart].im = 0.0;
  }
  eshift_re = 0.0;
  eshift_im = 0.0;
  ctemp.re = 0.0;
  ctemp.im = 0.0;
  anorm = 0.0;
  if (ilo <= ihi) {
    scale = 3.3121686421112381E-170;
    ssq = 0.0;
    nm1 = ihi - ilo;
    for (j = 0; j <= nm1; j++) {
      colscale = 3.3121686421112381E-170;
      colssq = 0.0;
      col = (ilo + j) - 1;
      jp1 = j + 1;
      if (jp1 >= nm1) {
        jp1 = nm1;
      }
      istart = ilo + jp1;
      for (jp1 = ilo; jp1 <= istart; jp1++) {
        anorm = fabs(A->data[(jp1 + A->size[0] * col) - 1].re);
        if (anorm > colscale) {
          t = colscale / anorm;
          colssq = colssq * t * t + 1.0;
          colscale = anorm;
        } else {
          t = anorm / colscale;
          colssq += t * t;
        }
        anorm = fabs(A->data[(jp1 + A->size[0] * col) - 1].im);
        if (anorm > colscale) {
          t = colscale / anorm;
          colssq = colssq * t * t + 1.0;
          colscale = anorm;
        } else {
          t = anorm / colscale;
          colssq += t * t;
        }
      }
      if (scale >= colscale) {
        t = colscale / scale;
        ssq += t * t * colssq;
      } else {
        t = scale / colscale;
        ssq = colssq + t * t * ssq;
        scale = colscale;
      }
    }
    anorm = scale * sqrt(ssq);
  }
  t = 2.2204460492503131E-16 * anorm;
  b_atol = 2.2250738585072014E-308;
  if (t > 2.2250738585072014E-308) {
    b_atol = t;
  }
  t = 2.2250738585072014E-308;
  if (anorm > 2.2250738585072014E-308) {
    t = anorm;
  }
  ascale = 1.0 / t;
  bscale = 1.0 / sqrt(A->size[0]);
  failed = true;
  istart = ihi + 1;
  for (j = istart; j <= n; j++) {
    alpha1_data[j - 1] = A->data[(j + A->size[0] * (j - 1)) - 1];
  }
  guard1 = false;
  guard2 = false;
  if (ihi >= ilo) {
    n = ilo;
    istart = ilo;
    ilast = ihi - 1;
    ilastm1 = ihi - 2;
    ilastm = ihi;
    iiter = 0;
    goto60 = false;
    goto70 = false;
    goto90 = false;
    jiter = 0;
    do {
      exitg1 = 0;
      if (jiter <= 30 * ((ihi - ilo) + 1) - 1) {
        b_guard1 = false;
        if (ilast + 1 == ilo) {
          goto60 = true;
          b_guard1 = true;
        } else if (fabs(b_A->data[ilast + b_A->size[0] * ilastm1].re) +
                       fabs(b_A->data[ilast + b_A->size[0] * ilastm1].im) <=
                   b_atol) {
          b_A->data[ilast + b_A->size[0] * ilastm1].re = 0.0;
          b_A->data[ilast + b_A->size[0] * ilastm1].im = 0.0;
          goto60 = true;
          b_guard1 = true;
        } else {
          j = ilastm1;
          guard3 = false;
          exitg2 = false;
          while ((!exitg2) && (j + 1 >= ilo)) {
            if (j + 1 == ilo) {
              guard3 = true;
              exitg2 = true;
            } else if (fabs(b_A->data[j + b_A->size[0] * (j - 1)].re) +
                           fabs(b_A->data[j + b_A->size[0] * (j - 1)].im) <=
                       b_atol) {
              b_A->data[j + b_A->size[0] * (j - 1)].re = 0.0;
              b_A->data[j + b_A->size[0] * (j - 1)].im = 0.0;
              guard3 = true;
              exitg2 = true;
            } else {
              j--;
              guard3 = false;
            }
          }
          if (guard3) {
            n = j + 1;
            goto70 = true;
          }
          if (goto70) {
            b_guard1 = true;
          } else {
            for (istart = 0; istart < *alpha1_size; istart++) {
              alpha1_data[istart].re = rtNaN;
              alpha1_data[istart].im = 0.0;
            }
            for (istart = 0; istart < *beta1_size; istart++) {
              beta1_data[istart].re = rtNaN;
              beta1_data[istart].im = 0.0;
            }
            *info = 1;
            exitg1 = 1;
          }
        }
        if (b_guard1) {
          if (goto60) {
            goto60 = false;
            alpha1_data[ilast] = b_A->data[ilast + b_A->size[0] * ilast];
            ilast = ilastm1;
            ilastm1--;
            if (ilast + 1 < ilo) {
              failed = false;
              guard2 = true;
              exitg1 = 1;
            } else {
              iiter = 0;
              eshift_re = 0.0;
              eshift_im = 0.0;
              ilastm = ilast + 1;
              jiter++;
            }
          } else {
            if (goto70) {
              goto70 = false;
              iiter++;
              if (iiter - iiter / 10 * 10 != 0) {
                anorm = ascale * b_A->data[ilastm1 + b_A->size[0] * ilastm1].re;
                t = ascale * b_A->data[ilastm1 + b_A->size[0] * ilastm1].im;
                if (t == 0.0) {
                  shift.re = anorm / bscale;
                  shift.im = 0.0;
                } else if (anorm == 0.0) {
                  shift.re = 0.0;
                  shift.im = t / bscale;
                } else {
                  shift.re = anorm / bscale;
                  shift.im = t / bscale;
                }
                anorm = ascale * b_A->data[ilast + b_A->size[0] * ilast].re;
                t = ascale * b_A->data[ilast + b_A->size[0] * ilast].im;
                if (t == 0.0) {
                  ad22_re = anorm / bscale;
                  ad22_im = 0.0;
                } else if (anorm == 0.0) {
                  ad22_re = 0.0;
                  ad22_im = t / bscale;
                } else {
                  ad22_re = anorm / bscale;
                  ad22_im = t / bscale;
                }
                t1_re = 0.5 * (shift.re + ad22_re);
                t1_im = 0.5 * (shift.im + ad22_im);
                t1_im_tmp = t1_re * t1_im;
                anorm = ascale * b_A->data[ilastm1 + b_A->size[0] * ilast].re;
                t = ascale * b_A->data[ilastm1 + b_A->size[0] * ilast].im;
                if (t == 0.0) {
                  colscale = anorm / bscale;
                  colssq = 0.0;
                } else if (anorm == 0.0) {
                  colscale = 0.0;
                  colssq = t / bscale;
                } else {
                  colscale = anorm / bscale;
                  colssq = t / bscale;
                }
                anorm = ascale * b_A->data[ilast + b_A->size[0] * ilastm1].re;
                t = ascale * b_A->data[ilast + b_A->size[0] * ilastm1].im;
                if (t == 0.0) {
                  ssq = anorm / bscale;
                  anorm = 0.0;
                } else if (anorm == 0.0) {
                  ssq = 0.0;
                  anorm = t / bscale;
                } else {
                  ssq = anorm / bscale;
                  anorm = t / bscale;
                }
                t = shift.re * ad22_re - shift.im * ad22_im;
                scale = shift.re * ad22_im + shift.im * ad22_re;
                shift.re = ((t1_re * t1_re - t1_im * t1_im) +
                            (colscale * ssq - colssq * anorm)) -
                           t;
                shift.im = ((t1_im_tmp + t1_im_tmp) +
                            (colscale * anorm + colssq * ssq)) -
                           scale;
                b_sqrt(&shift);
                if ((t1_re - ad22_re) * shift.re +
                        (t1_im - ad22_im) * shift.im <=
                    0.0) {
                  shift.re += t1_re;
                  shift.im += t1_im;
                } else {
                  shift.re = t1_re - shift.re;
                  shift.im = t1_im - shift.im;
                }
              } else {
                anorm = ascale * b_A->data[ilast + b_A->size[0] * ilastm1].re;
                t = ascale * b_A->data[ilast + b_A->size[0] * ilastm1].im;
                if (t == 0.0) {
                  colscale = anorm / bscale;
                  colssq = 0.0;
                } else if (anorm == 0.0) {
                  colscale = 0.0;
                  colssq = t / bscale;
                } else {
                  colscale = anorm / bscale;
                  colssq = t / bscale;
                }
                eshift_re += colscale;
                eshift_im += colssq;
                shift.re = eshift_re;
                shift.im = eshift_im;
              }
              j = ilastm1;
              jp1 = ilastm1 + 1;
              exitg2 = false;
              while ((!exitg2) && (j + 1 > n)) {
                istart = j + 1;
                ctemp.re = ascale * b_A->data[j + b_A->size[0] * j].re -
                           shift.re * bscale;
                ctemp.im = ascale * b_A->data[j + b_A->size[0] * j].im -
                           shift.im * bscale;
                anorm = fabs(ctemp.re) + fabs(ctemp.im);
                t = ascale * (fabs(b_A->data[jp1 + b_A->size[0] * j].re) +
                              fabs(b_A->data[jp1 + b_A->size[0] * j].im));
                scale = anorm;
                if (t > anorm) {
                  scale = t;
                }
                if ((scale < 1.0) && (scale != 0.0)) {
                  anorm /= scale;
                  t /= scale;
                }
                if ((fabs(b_A->data[j + b_A->size[0] * (j - 1)].re) +
                     fabs(b_A->data[j + b_A->size[0] * (j - 1)].im)) *
                        t <=
                    anorm * b_atol) {
                  goto90 = true;
                  exitg2 = true;
                } else {
                  jp1 = j;
                  j--;
                }
              }
              if (!goto90) {
                istart = n;
                ctemp.re =
                    ascale * b_A->data[(n + b_A->size[0] * (n - 1)) - 1].re -
                    shift.re * bscale;
                ctemp.im =
                    ascale * b_A->data[(n + b_A->size[0] * (n - 1)) - 1].im -
                    shift.im * bscale;
              }
              goto90 = false;
              b_ascale.re =
                  ascale * b_A->data[istart + b_A->size[0] * (istart - 1)].re;
              b_ascale.im =
                  ascale * b_A->data[istart + b_A->size[0] * (istart - 1)].im;
              b_xzlartg(ctemp, b_ascale, &anorm, &shift);
              j = istart;
              nm1 = istart - 2;
              while (j < ilast + 1) {
                if (j > istart) {
                  xzlartg(b_A->data[(j + b_A->size[0] * nm1) - 1],
                          b_A->data[j + b_A->size[0] * nm1], &anorm, &shift,
                          &b_A->data[(j + b_A->size[0] * nm1) - 1]);
                  b_A->data[j + b_A->size[0] * nm1].re = 0.0;
                  b_A->data[j + b_A->size[0] * nm1].im = 0.0;
                }
                for (nm1 = j; nm1 <= ilastm; nm1++) {
                  ad22_re =
                      anorm * b_A->data[(j + b_A->size[0] * (nm1 - 1)) - 1].re +
                      (shift.re * b_A->data[j + b_A->size[0] * (nm1 - 1)].re -
                       shift.im * b_A->data[j + b_A->size[0] * (nm1 - 1)].im);
                  ad22_im =
                      anorm * b_A->data[(j + b_A->size[0] * (nm1 - 1)) - 1].im +
                      (shift.re * b_A->data[j + b_A->size[0] * (nm1 - 1)].im +
                       shift.im * b_A->data[j + b_A->size[0] * (nm1 - 1)].re);
                  t = b_A->data[(j + b_A->size[0] * (nm1 - 1)) - 1].re;
                  b_A->data[j + b_A->size[0] * (nm1 - 1)].re =
                      anorm * b_A->data[j + b_A->size[0] * (nm1 - 1)].re -
                      (shift.re *
                           b_A->data[(j + b_A->size[0] * (nm1 - 1)) - 1].re +
                       shift.im *
                           b_A->data[(j + b_A->size[0] * (nm1 - 1)) - 1].im);
                  b_A->data[j + b_A->size[0] * (nm1 - 1)].im =
                      anorm * b_A->data[j + b_A->size[0] * (nm1 - 1)].im -
                      (shift.re *
                           b_A->data[(j + b_A->size[0] * (nm1 - 1)) - 1].im -
                       shift.im * t);
                  b_A->data[(j + b_A->size[0] * (nm1 - 1)) - 1].re = ad22_re;
                  b_A->data[(j + b_A->size[0] * (nm1 - 1)) - 1].im = ad22_im;
                }
                shift.re = -shift.re;
                shift.im = -shift.im;
                nm1 = j;
                if (ilast + 1 < j + 2) {
                  nm1 = ilast - 1;
                }
                for (col = n; col <= nm1 + 2; col++) {
                  ad22_re =
                      anorm * b_A->data[(col + b_A->size[0] * j) - 1].re +
                      (shift.re *
                           b_A->data[(col + b_A->size[0] * (j - 1)) - 1].re -
                       shift.im *
                           b_A->data[(col + b_A->size[0] * (j - 1)) - 1].im);
                  ad22_im =
                      anorm * b_A->data[(col + b_A->size[0] * j) - 1].im +
                      (shift.re *
                           b_A->data[(col + b_A->size[0] * (j - 1)) - 1].im +
                       shift.im *
                           b_A->data[(col + b_A->size[0] * (j - 1)) - 1].re);
                  t = b_A->data[(col + b_A->size[0] * j) - 1].re;
                  b_A->data[(col + b_A->size[0] * (j - 1)) - 1].re =
                      anorm * b_A->data[(col + b_A->size[0] * (j - 1)) - 1].re -
                      (shift.re * b_A->data[(col + b_A->size[0] * j) - 1].re +
                       shift.im * b_A->data[(col + b_A->size[0] * j) - 1].im);
                  b_A->data[(col + b_A->size[0] * (j - 1)) - 1].im =
                      anorm * b_A->data[(col + b_A->size[0] * (j - 1)) - 1].im -
                      (shift.re * b_A->data[(col + b_A->size[0] * j) - 1].im -
                       shift.im * t);
                  b_A->data[(col + b_A->size[0] * j) - 1].re = ad22_re;
                  b_A->data[(col + b_A->size[0] * j) - 1].im = ad22_im;
                }
                nm1 = j - 1;
                j++;
              }
            }
            jiter++;
          }
        }
      } else {
        guard2 = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  } else {
    guard1 = true;
  }
  if (guard2) {
    if (failed) {
      *info = ilast + 1;
      for (jp1 = 0; jp1 <= ilast; jp1++) {
        alpha1_data[jp1].re = rtNaN;
        alpha1_data[jp1].im = 0.0;
        beta1_data[jp1].re = rtNaN;
        beta1_data[jp1].im = 0.0;
      }
    } else {
      guard1 = true;
    }
  }
  if (guard1) {
    for (j = 0; j <= ilo - 2; j++) {
      alpha1_data[j] = b_A->data[j + b_A->size[0] * j];
    }
  }
  emxFree_creal_T(&b_A);
}

/*
 * Arguments    : int n
 *                double *alpha1
 *                emxArray_real_T *x
 *                int ix0
 * Return Type  : double
 */
static double xzlarfg(int n, double *alpha1, emxArray_real_T *x, int ix0)
{
  double beta1;
  double tau;
  double xnorm;
  int i;
  int k;
  int knt;
  tau = 0.0;
  if (n > 0) {
    xnorm = xnrm2(n - 1, x, ix0);
    if (xnorm != 0.0) {
      beta1 = rt_hypotd_snf(*alpha1, xnorm);
      if (*alpha1 >= 0.0) {
        beta1 = -beta1;
      }
      if (fabs(beta1) < 1.0020841800044864E-292) {
        knt = -1;
        i = (ix0 + n) - 2;
        do {
          knt++;
          for (k = ix0; k <= i; k++) {
            x->data[k - 1] *= 9.9792015476736E+291;
          }
          beta1 *= 9.9792015476736E+291;
          *alpha1 *= 9.9792015476736E+291;
        } while (!(fabs(beta1) >= 1.0020841800044864E-292));
        beta1 = rt_hypotd_snf(*alpha1, xnrm2(n - 1, x, ix0));
        if (*alpha1 >= 0.0) {
          beta1 = -beta1;
        }
        tau = (beta1 - *alpha1) / beta1;
        xnorm = 1.0 / (*alpha1 - beta1);
        for (k = ix0; k <= i; k++) {
          x->data[k - 1] *= xnorm;
        }
        for (k = 0; k <= knt; k++) {
          beta1 *= 1.0020841800044864E-292;
        }
        *alpha1 = beta1;
      } else {
        tau = (beta1 - *alpha1) / beta1;
        xnorm = 1.0 / (*alpha1 - beta1);
        i = (ix0 + n) - 2;
        for (k = ix0; k <= i; k++) {
          x->data[k - 1] *= xnorm;
        }
        *alpha1 = beta1;
      }
    }
  }
  return tau;
}

/*
 * Arguments    : const creal_T f
 *                const creal_T g
 *                double *cs
 *                creal_T *sn
 *                creal_T *r
 * Return Type  : void
 */
static void xzlartg(const creal_T f, const creal_T g, double *cs, creal_T *sn,
                    creal_T *r)
{
  double f2;
  double f2s;
  double fs_im;
  double fs_re;
  double g2;
  double gs_im;
  double gs_re;
  double scale;
  double scale_tmp;
  int count;
  int rescaledir;
  boolean_T guard1 = false;
  scale_tmp = fabs(f.re);
  f2s = fabs(f.im);
  if (f2s > scale_tmp) {
    scale_tmp = f2s;
  }
  f2s = fabs(g.re);
  scale = fabs(g.im);
  if (scale > f2s) {
    f2s = scale;
  }
  scale = scale_tmp;
  if (f2s > scale_tmp) {
    scale = f2s;
  }
  fs_re = f.re;
  fs_im = f.im;
  gs_re = g.re;
  gs_im = g.im;
  count = -1;
  rescaledir = 0;
  guard1 = false;
  if (scale >= 7.4428285367870146E+137) {
    do {
      count++;
      fs_re *= 1.3435752215134178E-138;
      fs_im *= 1.3435752215134178E-138;
      gs_re *= 1.3435752215134178E-138;
      gs_im *= 1.3435752215134178E-138;
      scale *= 1.3435752215134178E-138;
    } while (!(scale < 7.4428285367870146E+137));
    rescaledir = 1;
    guard1 = true;
  } else if (scale <= 1.3435752215134178E-138) {
    if ((g.re == 0.0) && (g.im == 0.0)) {
      *cs = 1.0;
      sn->re = 0.0;
      sn->im = 0.0;
      *r = f;
    } else {
      do {
        count++;
        fs_re *= 7.4428285367870146E+137;
        fs_im *= 7.4428285367870146E+137;
        gs_re *= 7.4428285367870146E+137;
        gs_im *= 7.4428285367870146E+137;
        scale *= 7.4428285367870146E+137;
      } while (!(scale > 1.3435752215134178E-138));
      rescaledir = -1;
      guard1 = true;
    }
  } else {
    guard1 = true;
  }
  if (guard1) {
    f2 = fs_re * fs_re + fs_im * fs_im;
    g2 = gs_re * gs_re + gs_im * gs_im;
    scale = g2;
    if (1.0 > g2) {
      scale = 1.0;
    }
    if (f2 <= scale * 2.0041683600089728E-292) {
      if ((f.re == 0.0) && (f.im == 0.0)) {
        *cs = 0.0;
        r->re = rt_hypotd_snf(g.re, g.im);
        r->im = 0.0;
        f2 = rt_hypotd_snf(gs_re, gs_im);
        sn->re = gs_re / f2;
        sn->im = -gs_im / f2;
      } else {
        g2 = sqrt(g2);
        *cs = rt_hypotd_snf(fs_re, fs_im) / g2;
        if (scale_tmp > 1.0) {
          f2 = rt_hypotd_snf(f.re, f.im);
          fs_re = f.re / f2;
          fs_im = f.im / f2;
        } else {
          scale = 7.4428285367870146E+137 * f.re;
          f2s = 7.4428285367870146E+137 * f.im;
          f2 = rt_hypotd_snf(scale, f2s);
          fs_re = scale / f2;
          fs_im = f2s / f2;
        }
        gs_re /= g2;
        gs_im = -gs_im / g2;
        sn->re = fs_re * gs_re - fs_im * gs_im;
        sn->im = fs_re * gs_im + fs_im * gs_re;
        r->re = *cs * f.re + (sn->re * g.re - sn->im * g.im);
        r->im = *cs * f.im + (sn->re * g.im + sn->im * g.re);
      }
    } else {
      f2s = sqrt(g2 / f2 + 1.0);
      r->re = f2s * fs_re;
      r->im = f2s * fs_im;
      *cs = 1.0 / f2s;
      f2 += g2;
      f2s = r->re / f2;
      scale = r->im / f2;
      sn->re = f2s * gs_re - scale * -gs_im;
      sn->im = f2s * -gs_im + scale * gs_re;
      if (rescaledir > 0) {
        for (rescaledir = 0; rescaledir <= count; rescaledir++) {
          r->re *= 7.4428285367870146E+137;
          r->im *= 7.4428285367870146E+137;
        }
      } else if (rescaledir < 0) {
        for (rescaledir = 0; rescaledir <= count; rescaledir++) {
          r->re *= 1.3435752215134178E-138;
          r->im *= 1.3435752215134178E-138;
        }
      }
    }
  }
}

/*
 * Arguments    : const creal_T p_data[]
 *                int p_size
 *                double k
 *                emxArray_real_T *a
 *                double b_data[]
 *                int *b_size
 *                double c_data[]
 *                int c_size[2]
 *                double *d
 * Return Type  : void
 */
static void zp2ss(const creal_T p_data[], int p_size, double k,
                  emxArray_real_T *a, double b_data[], int *b_size,
                  double c_data[], int c_size[2], double *d)
{
  creal_T pf_data[501];
  creal_T vwork_data[501];
  creal_T c[3];
  creal_T x[2];
  double e_tmp_data[500];
  double a1[4];
  double b_a[4];
  double b1[2];
  double absxk;
  double scale;
  double t;
  double wn;
  int b_k;
  int dim;
  int i;
  int j;
  int np;
  int vlen;
  int vstride;
  boolean_T b_tmp_data[501];
  boolean_T c_tmp_data[501];
  boolean_T d_tmp_data[501];
  boolean_T tmp_data[501];
  boolean_T oddPoles;
  boolean_T paired;
  for (vstride = 0; vstride < p_size; vstride++) {
    tmp_data[vstride] = rtIsInf(p_data[vstride].re);
  }
  for (vstride = 0; vstride < p_size; vstride++) {
    b_tmp_data[vstride] = rtIsInf(p_data[vstride].im);
  }
  for (vstride = 0; vstride < p_size; vstride++) {
    c_tmp_data[vstride] = rtIsNaN(p_data[vstride].re);
  }
  for (vstride = 0; vstride < p_size; vstride++) {
    d_tmp_data[vstride] = rtIsNaN(p_data[vstride].im);
  }
  for (vstride = 0; vstride < p_size; vstride++) {
    tmp_data[vstride] = ((!tmp_data[vstride]) && (!b_tmp_data[vstride]) &&
                         ((!c_tmp_data[vstride]) && (!d_tmp_data[vstride])));
  }
  dim = p_size - 1;
  np = 0;
  vlen = 0;
  for (i = 0; i <= dim; i++) {
    if (tmp_data[i]) {
      np++;
      pf_data[vlen] = p_data[i];
      vlen++;
    }
  }
  dim = 2;
  if (np != 1) {
    dim = 1;
  }
  oddPoles = true;
  if (np != 0) {
    if (np == 1) {
      oddPoles = cplxpairv(pf_data, &np, 0.0);
    } else {
      if (dim <= 1) {
        vlen = np;
      } else {
        vlen = 1;
      }
      if (vlen != 1) {
        oddPoles = cplxpairv(pf_data, &np, 0.0);
      } else {
        if (dim <= 1) {
          i = np;
        } else {
          i = 1;
        }
        vlen = i - 1;
        vstride = 1;
        for (b_k = 0; b_k <= dim - 2; b_k++) {
          vstride *= np;
        }
        for (j = 0; j < vstride; j++) {
          for (b_k = 0; b_k <= vlen; b_k++) {
            vwork_data[b_k] = pf_data[j + b_k * vstride];
          }
          paired = cplxpairv(vwork_data, &i, 0.0);
          for (b_k = 0; b_k <= vlen; b_k++) {
            pf_data[j + b_k * vstride] = vwork_data[b_k];
          }
          if ((!oddPoles) || (!paired)) {
            oddPoles = false;
          }
        }
      }
    }
  }
  if (!oddPoles) {
    if (np == 0) {
      wn = 0.0;
    } else {
      wn = 0.0;
      if (np == 1) {
        wn = rt_hypotd_snf(pf_data[0].re, pf_data[0].im);
      } else {
        scale = 3.3121686421112381E-170;
        for (b_k = 0; b_k < np; b_k++) {
          absxk = fabs(pf_data[b_k].re);
          if (absxk > scale) {
            t = scale / absxk;
            wn = wn * t * t + 1.0;
            scale = absxk;
          } else {
            t = absxk / scale;
            wn += t * t;
          }
          absxk = fabs(pf_data[b_k].im);
          if (absxk > scale) {
            t = scale / absxk;
            wn = wn * t * t + 1.0;
            scale = absxk;
          } else {
            t = absxk / scale;
            wn += t * t;
          }
        }
        wn = scale * sqrt(wn);
      }
    }
    wn = 1.0E+6 * (double)np * wn * 2.2204460492503131E-16 +
         2.2204460492503131E-16;
    dim = 2;
    if (np != 1) {
      dim = 1;
    }
    if (np != 0) {
      if (np == 1) {
        cplxpairv(pf_data, &np, wn);
      } else {
        if (dim <= 1) {
          vlen = np;
        } else {
          vlen = 1;
        }
        if (vlen != 1) {
          cplxpairv(pf_data, &np, wn);
        } else {
          if (dim <= 1) {
            i = np;
          } else {
            i = 1;
          }
          vlen = i - 1;
          vstride = 1;
          for (b_k = 0; b_k <= dim - 2; b_k++) {
            vstride *= np;
          }
          for (j = 0; j < vstride; j++) {
            for (b_k = 0; b_k <= vlen; b_k++) {
              vwork_data[b_k] = pf_data[j + b_k * vstride];
            }
            cplxpairv(vwork_data, &i, wn);
            for (b_k = 0; b_k <= vlen; b_k++) {
              pf_data[j + b_k * vstride] = vwork_data[b_k];
            }
          }
        }
      }
    }
  }
  vstride = a->size[0] * a->size[1];
  a->size[0] = np;
  a->size[1] = np;
  emxEnsureCapacity_real_T(a, vstride);
  dim = np * np;
  for (vstride = 0; vstride < dim; vstride++) {
    a->data[vstride] = 0.0;
  }
  *b_size = np;
  c_size[0] = 1;
  c_size[1] = np;
  if (0 <= np - 1) {
    memset(&b_data[0], 0, np * sizeof(double));
    memset(&c_data[0], 0, np * sizeof(double));
  }
  *d = 1.0;
  oddPoles = false;
  if (rt_remd_snf(np, 2.0) != 0.0) {
    a->data[0] = pf_data[np - 1].re;
    b_data[0] = 1.0;
    c_data[0] = 1.0;
    *d = 0.0;
    np--;
    oddPoles = true;
  }
  for (i = 1; i < np; i += 2) {
    b1[0] = i;
    b1[1] = (double)i + 1.0;
    c[0].re = 1.0;
    c[0].im = 0.0;
    for (j = 0; j < 2; j++) {
      dim = (int)b1[j] - 1;
      x[j] = pf_data[dim];
      wn = -pf_data[dim].re;
      scale = -pf_data[dim].im;
      absxk = wn * c[j].im + scale * c[j].re;
      c[j + 1].re = wn * c[j].re - scale * c[j].im;
      c[j + 1].im = absxk;
      for (b_k = j + 1; b_k >= 2; b_k--) {
        wn = x[j].re;
        scale = x[j].im;
        c[1].re -= wn * c[0].re - scale * c[0].im;
        c[1].im -= wn * c[0].im + scale * c[0].re;
      }
    }
    x[0] = pf_data[i - 1];
    x[1] = pf_data[i];
    wn =
        sqrt(rt_hypotd_snf(x[0].re, x[0].im) * rt_hypotd_snf(x[1].re, x[1].im));
    if (wn == 0.0) {
      wn = 1.0;
    }
    absxk = 1.0 / wn;
    wn = (1.0 - -c[1].re * 0.0) / absxk;
    b_a[1] = wn;
    b_a[0] = -c[1].re - wn * 0.0;
    wn = (0.0 - -c[2].re * 0.0) / absxk;
    b_a[3] = wn;
    b_a[2] = -c[2].re - wn * 0.0;
    for (vstride = 0; vstride < 2; vstride++) {
      wn = b_a[vstride + 2];
      scale = b_a[vstride];
      a1[vstride] = scale + wn * 0.0;
      a1[vstride + 2] = scale * 0.0 + wn * absxk;
    }
    b1[1] = 0.0 / absxk;
    b1[0] = 1.0 - b1[1] * 0.0;
    if (oddPoles) {
      j = i - 1;
    } else {
      j = i - 2;
    }
    if (j == -1) {
      a->data[0] = a1[0];
      a->data[1] = a1[1];
      c_data[0] = 0.0;
      a->data[a->size[0]] = a1[2];
      a->data[a->size[0] + 1] = a1[3];
      c_data[1] = absxk;
    } else {
      for (vstride = 0; vstride <= j; vstride++) {
        a->data[((short)((short)j + 2) + a->size[0] * vstride) - 1] =
            b1[0] * c_data[vstride];
        a->data[((short)((short)((short)j + 1) + 2) + a->size[0] * vstride) -
                1] = b1[1] * c_data[vstride];
      }
      a->data[((short)((short)j + 2) +
               a->size[0] * ((short)((short)j + 2) - 1)) -
              1] = a1[0];
      a->data[((short)((short)((short)j + 1) + 2) +
               a->size[0] * ((short)((short)j + 2) - 1)) -
              1] = a1[1];
      a->data[((short)((short)j + 2) +
               a->size[0] * ((short)((short)((short)j + 1) + 2) - 1)) -
              1] = a1[2];
      a->data[((short)((short)((short)j + 1) + 2) +
               a->size[0] * ((short)((short)((short)j + 1) + 2) - 1)) -
              1] = a1[3];
      vlen = j + 1;
      for (vstride = 0; vstride <= j; vstride++) {
        e_tmp_data[vstride] = 0.0 * c_data[vstride];
      }
      if (0 <= vlen - 1) {
        memcpy(&c_data[0], &e_tmp_data[0], vlen * sizeof(double));
      }
      c_data[(short)((short)j + 2) - 1] = 0.0;
      c_data[(short)((short)((short)j + 1) + 2) - 1] = absxk;
    }
    b_data[j + 1] = b1[0] * *d;
    b_data[j + 2] = b1[1] * *d;
    *d = 0.0;
  }
  c_size[0] = 1;
  dim = c_size[1] - 1;
  for (vstride = 0; vstride <= dim; vstride++) {
    c_data[vstride] *= k;
  }
  *d *= k;
}

/*
 * Arguments    : double fs
 *                const double fc[2]
 *                double type
 *                double order
 *                double NUM_data[]
 *                int NUM_size[2]
 *                double DEN_data[]
 *                int DEN_size[2]
 * Return Type  : void
 */
void DesignButter(double fs, const double fc[2], double type, double order,
                  double NUM_data[], int NUM_size[2], double DEN_data[],
                  int DEN_size[2])
{
  static double c_NUM_data[2003];
  double c_DEN_data[1003];
  double b_NUM_data[1002];
  double b_DEN_data[502];
  double b_fc[2];
  double b_fs;
  int b_DEN_size[2];
  int b_NUM_size[2];
  int loop_ub;
  if (!isInitialized_DesignButter) {
    DesignButter_initialize();
  }
  /*  fs:采样率 */
  /*  fc:截止频率 */
  /*  type: 类型，0:高通；1：低通;2:带阻；3：带通 */
  /*  order: 阶数 */
  NUM_size[0] = 0;
  NUM_size[1] = 0;
  DEN_size[0] = 0;
  DEN_size[1] = 0;
  if (type == 0.0) {
    butter(order, fc[0] / (fs / 2.0), b_NUM_data, b_NUM_size, b_DEN_data,
           b_DEN_size);
    NUM_size[0] = 1;
    NUM_size[1] = b_NUM_size[1];
    loop_ub = b_NUM_size[1];
    if (0 <= loop_ub - 1) {
      memcpy(&NUM_data[0], &b_NUM_data[0], loop_ub * sizeof(double));
    }
    DEN_size[0] = 1;
    DEN_size[1] = b_DEN_size[1];
    loop_ub = b_DEN_size[1];
    if (0 <= loop_ub - 1) {
      memcpy(&DEN_data[0], &b_DEN_data[0], loop_ub * sizeof(double));
    }
  } else if (type == 1.0) {
    b_butter(order, fc[0] / (fs / 2.0), b_NUM_data, b_NUM_size, b_DEN_data,
             b_DEN_size);
    NUM_size[0] = 1;
    NUM_size[1] = b_NUM_size[1];
    loop_ub = b_NUM_size[1];
    if (0 <= loop_ub - 1) {
      memcpy(&NUM_data[0], &b_NUM_data[0], loop_ub * sizeof(double));
    }
    DEN_size[0] = 1;
    DEN_size[1] = b_DEN_size[1];
    loop_ub = b_DEN_size[1];
    if (0 <= loop_ub - 1) {
      memcpy(&DEN_data[0], &b_DEN_data[0], loop_ub * sizeof(double));
    }
  } else if (type == 2.0) {
    b_fs = fs / 2.0;
    b_fc[0] = fc[0] / b_fs;
    b_fc[1] = fc[1] / b_fs;
    c_butter(order / 2.0, b_fc, c_NUM_data, b_NUM_size, c_DEN_data, b_DEN_size);
    NUM_size[0] = 1;
    NUM_size[1] = b_NUM_size[1];
    loop_ub = b_NUM_size[1];
    if (0 <= loop_ub - 1) {
      memcpy(&NUM_data[0], &c_NUM_data[0], loop_ub * sizeof(double));
    }
    DEN_size[0] = 1;
    DEN_size[1] = b_DEN_size[1];
    loop_ub = b_DEN_size[1];
    if (0 <= loop_ub - 1) {
      memcpy(&DEN_data[0], &c_DEN_data[0], loop_ub * sizeof(double));
    }
  } else if (type == 3.0) {
    b_fs = fs / 2.0;
    b_fc[0] = fc[0] / b_fs;
    b_fc[1] = fc[1] / b_fs;
    d_butter(order / 2.0, b_fc, c_NUM_data, b_NUM_size, c_DEN_data, b_DEN_size);
    NUM_size[0] = 1;
    NUM_size[1] = b_NUM_size[1];
    loop_ub = b_NUM_size[1];
    if (0 <= loop_ub - 1) {
      memcpy(&NUM_data[0], &c_NUM_data[0], loop_ub * sizeof(double));
    }
    DEN_size[0] = 1;
    DEN_size[1] = b_DEN_size[1];
    loop_ub = b_DEN_size[1];
    if (0 <= loop_ub - 1) {
      memcpy(&DEN_data[0], &c_DEN_data[0], loop_ub * sizeof(double));
    }
  }
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void DesignButter_initialize(void)
{
  rt_InitInfAndNaN();
  isInitialized_DesignButter = true;
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void DesignButter_terminate(void)
{
  /* (no terminate code required) */
  isInitialized_DesignButter = false;
}

/*
 * File trailer for DesignButter.c
 *
 * [EOF]
 */
