#include <check.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "../s21_math.h"

// S21_ABS TEST
START_TEST(s21_abs_test) {
  ck_assert_int_eq(s21_abs(3), abs(3));
  ck_assert_int_eq(s21_abs(-3), abs(-3));
  ck_assert_int_eq(s21_abs((int)INFINITY), abs((int)INFINITY));
  ck_assert_int_eq(s21_abs((int)NAN), abs((int)NAN));
  ck_assert_int_eq(s21_abs((int)-INFINITY), abs((int)-INFINITY));

  for (int x = -1000; x < 1000; x += 100) {
    ck_assert_int_eq(abs(x), s21_abs(x));
  }
}

// S21_ASIN TEST
START_TEST(s21_asin_test) {
  for (double x = -1.0; x <= 1.0; x += 0.01) {
    ck_assert_ldouble_eq_tol(asin(x), s21_asin(x), 1e-6);
  }
  ck_assert_ldouble_nan(s21_asin(-1.5));
  ck_assert_ldouble_nan(s21_asin(1.5));
  ck_assert_ldouble_eq(s21_asin(0), +0);
  ck_assert_ldouble_eq_tol(s21_asin(1), asin(1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_asin(-1.0), asin(-1.0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_asin(0), asin(0), 1e-6);
  ck_assert_ldouble_nan(s21_asin(NAN));
  ck_assert_ldouble_nan(s21_asin(INFINITY));
  ck_assert_ldouble_nan(s21_asin(-INFINITY));
  ck_assert_ldouble_nan(s21_asin(S21_DBL_MAX));
  ck_assert_ldouble_eq_tol(s21_asin(-0.45781), asin(-0.45781), 1e-6);
}
END_TEST

// S21_ACOS TEST
START_TEST(s21_acos_test) {
  for (double x = -1.0; x <= 1.0; x += 0.01) {
    ck_assert_ldouble_eq_tol(acos(x), s21_acos(x), 1e-6);
  }
  ck_assert_ldouble_nan(s21_acos(-1.5));
  ck_assert_ldouble_nan(s21_acos(1.5));
  ck_assert_ldouble_eq(s21_acos(1), 0);
  ck_assert_ldouble_eq_tol(s21_acos(1), acos(1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_acos(0), acos(0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_acos(-1), acos(-1), 1e-6);
  ck_assert_ldouble_nan(s21_acos(NAN));
  ck_assert_ldouble_nan(s21_acos(INFINITY));
  ck_assert_ldouble_nan(s21_acos(-INFINITY));
  ck_assert_ldouble_nan(s21_acos(S21_DBL_MAX));
  ck_assert_ldouble_eq_tol(s21_acos(-0.45781), acos(-0.45781), 1e-6);
}
END_TEST

// S21_ATAN TEST

START_TEST(s21_atan_test) {
  for (double x = -1000; x < 1000; x += 10.123) {
    ck_assert_ldouble_eq_tol(atan(x), s21_atan(x), 1e-6);
  }

  for (double x = -10; x < 10; x += 0.23) {
    ck_assert_ldouble_eq_tol(atan(x), s21_atan(x), 1e-6);
  }
  ck_assert_ldouble_nan(s21_atan(NAN));
  ck_assert_ldouble_eq_tol(s21_atan(-INFINITY), atan(-INFINITY), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(INFINITY), atan(INFINITY), 1e-6);
  ck_assert_ldouble_eq(s21_atan(-0), -0);
  ck_assert_ldouble_eq(s21_atan(+0), +0);
  ck_assert_ldouble_eq_tol(s21_atan(0), atan(0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(1), atan(1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(-1), atan(-1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(S21_DBL_MAX), atan(S21_DBL_MAX), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(-0.45781), atan(-0.45781), 1e-6);
}
END_TEST

// S21_CEIL TEST
START_TEST(s21_ceil_test) {
  ck_assert_ldouble_infinite(s21_ceil(INFINITY));
  ck_assert_ldouble_infinite(s21_ceil(-INFINITY));
  ck_assert_ldouble_eq(s21_ceil(-0.0), 0.0);
  ck_assert_ldouble_eq(s21_ceil(+0.0), 0.0);
  ck_assert_ldouble_eq_tol(s21_ceil(0), ceil(0), 1e-6);
  ck_assert_ldouble_nan(s21_ceil(NAN));
  ck_assert_ldouble_eq_tol(s21_ceil(S21_DBL_MAX), ceil(S21_DBL_MAX), 1e-6);
  ck_assert_ldouble_eq_tol(s21_ceil(1e-19), ceil(1e-19), 1e-6);

  for (double x = -100; x < 100; x += 0.123) {
    ck_assert_ldouble_eq(ceil(x), s21_ceil(x));
  }
}
END_TEST

// S21_LOG TEST
START_TEST(test_log_1) {
  for (double x = 0.1; x < 1000; x += 1.23456) {
    long double s21_log_result = s21_log(x);
    long double log_result = log(x);
    ck_assert_ldouble_eq_tol(s21_log_result, log_result, 1e-6);
  }
}
END_TEST

START_TEST(test_log_2) {
  for (double x = 1000; x < 100000; x += 1234.56) {
    long double s21_log_result = s21_log(x);
    long double log_result = log(x);
    ck_assert_ldouble_eq_tol(s21_log_result, log_result, 1e-6);
  }
}
END_TEST

START_TEST(test_log_3) {
  ck_assert_ldouble_eq_tol(s21_log(0.1234), log(0.1234), 1e-6);
  ck_assert_ldouble_eq_tol(s21_log(S21_M_E), log(S21_M_E), 1e-6);

  ck_assert_ldouble_eq(s21_log(INFINITY), log(INFINITY));
  ck_assert_ldouble_eq(s21_log(0), log(0));

  ck_assert_ldouble_nan(s21_log(-1));
  ck_assert_ldouble_nan(log(-1));
  ck_assert_ldouble_nan(s21_log(-1000));
  ck_assert_ldouble_nan(log(-1000));
  ck_assert_ldouble_nan(s21_log(-INFINITY));
  ck_assert_ldouble_nan(log(-INFINITY));
  ck_assert_ldouble_nan(s21_log(-NAN));
  ck_assert_ldouble_nan(log(-NAN));

  ck_assert_ldouble_infinite(s21_log(INFINITY));
  ck_assert_ldouble_nan(s21_log(-1));

  ck_assert_ldouble_infinite(s21_log(0));
  ck_assert_ldouble_eq_tol(s21_log(1), log(1), 1e-6);
}
END_TEST

START_TEST(test_log_4) {
  for (double x = 1; x < 100; x += 0.50) {
    double log_res = log(x);
    long double s21_log_res = s21_log(x);
    ck_assert_ldouble_eq_tol((long double)log_res, s21_log_res, 1e-6);
  }
}
END_TEST

START_TEST(test_pow_1) {
  for (double x = -20.0; x <= 20.0; x += 0.123456) {
    for (double y = -1.0; y <= 1.0; y += 0.12345) {
      long double s21_pow_result = s21_pow(x, y);
      long double pow_result = pow(x, y);

      ck_assert(isnan(s21_pow_result) == isnan(pow_result));
      ck_assert(isinf(s21_pow_result) == isinf(pow_result));

      if (!isnan(pow_result) && !isinf(pow_result)) {
        ck_assert_ldouble_eq_tol(s21_pow_result, pow_result, 1e-6);
      }
    }
  }
}
END_TEST

START_TEST(test_pow_2) {
  for (double x = -20.0; x <= 20.0; x += 1.23456) {
    for (double y = -8.0; y <= 8.0; y += 0.12345) {
      long double s21_pow_result = s21_pow(x, y);
      long double pow_result = pow(x, y);

      ck_assert(isnan(s21_pow_result) == isnan(pow_result));
      ck_assert(isinf(s21_pow_result) == isinf(pow_result));

      if (!isnan(pow_result) && !isinf(pow_result)) {
        ck_assert_ldouble_eq_tol(s21_pow_result, pow_result, 1e-6);
      }
    }
  }
}
END_TEST

START_TEST(test_pow_3) {
  ck_assert_ldouble_eq(pow(1, 0), s21_pow(1, 0));
  ck_assert_ldouble_eq(pow(-1, 3), s21_pow(-1, 3));
  ck_assert_ldouble_eq(pow(-1, 4), s21_pow(-1, 4));
  ck_assert_ldouble_eq(pow(0, 0), s21_pow(0, 0));
  ck_assert_ldouble_eq(pow(0, -1), s21_pow(0, -1));
  ck_assert_ldouble_eq(pow(0, 1), s21_pow(0, 1));

  ck_assert_ldouble_eq(pow(INFINITY, 0), s21_pow(INFINITY, 0));
  ck_assert_ldouble_eq(pow(INFINITY, -1), s21_pow(INFINITY, -1));
  ck_assert_ldouble_eq(pow(-1, -INFINITY), s21_pow(-1, -INFINITY));
  ck_assert_ldouble_eq(pow(0, INFINITY), s21_pow(0, INFINITY));
  ck_assert_ldouble_nan(s21_pow(0, NAN));
  ck_assert_ldouble_nan(s21_pow(-7.0, 0.5));
  ck_assert_ldouble_eq(pow(NAN, 0), s21_pow(NAN, 0));

  ck_assert_ldouble_nan(s21_pow(NAN, NAN));
  ck_assert_ldouble_eq(pow(INFINITY, INFINITY), s21_pow(INFINITY, INFINITY));
  ck_assert_ldouble_eq(pow(INFINITY, -INFINITY), s21_pow(INFINITY, -INFINITY));
  ck_assert_ldouble_eq(pow(-INFINITY, INFINITY), s21_pow(-INFINITY, INFINITY));
  ck_assert_ldouble_eq(pow(-INFINITY, -INFINITY),
                       s21_pow(-INFINITY, -INFINITY));
  ck_assert_ldouble_eq(pow(1, -INFINITY), s21_pow(1, -INFINITY));
  ck_assert_ldouble_eq(pow(1, NAN), s21_pow(1, NAN));
  ck_assert_ldouble_nan(s21_pow(NAN, INFINITY));
  ck_assert_ldouble_nan(s21_pow(INFINITY, NAN));
  ck_assert_ldouble_nan(s21_pow(NAN, -INFINITY));
  ck_assert_ldouble_nan(s21_pow(-INFINITY, NAN));

  ck_assert_ldouble_eq(pow(2, INFINITY), s21_pow(2, INFINITY));
  ck_assert_ldouble_eq(pow(0.5, INFINITY), s21_pow(0.5, INFINITY));
  ck_assert_ldouble_eq(pow(-2, INFINITY), s21_pow(-2, INFINITY));
  ck_assert_ldouble_eq(pow(2, -INFINITY), s21_pow(2, -INFINITY));
  ck_assert_ldouble_eq(pow(0.5, -INFINITY), s21_pow(0.5, -INFINITY));
  ck_assert_ldouble_eq(pow(-2, -INFINITY), s21_pow(-2, -INFINITY));
}

END_TEST

START_TEST(test_sin_1) {
  for (double x = -1000; x < 1000; x += 0.123456) {
    long double s21_sin_result = s21_sin(x);
    long double sin_result = sin(x);
    ck_assert_ldouble_eq_tol(s21_sin_result, sin_result, 1e-6);
  }
}
END_TEST

START_TEST(test_sin_2) {
  for (double x = -10000000; x < 10000000; x += 123.456) {
    long double s21_sin_result = s21_sin(x);
    long double sin_result = sin(x);
    ck_assert_ldouble_eq_tol(s21_sin_result, sin_result, 1e-6);
  }
}
END_TEST

START_TEST(test_sin_3) {
  ck_assert_ldouble_eq_tol(s21_sin(0), sin(0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(0.5 * S21_M_PI), sin(0.5 * S21_M_PI), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(S21_M_PI), sin(S21_M_PI), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(1.5 * S21_M_PI), sin(1.5 * S21_M_PI), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(2 * S21_M_PI), sin(2 * S21_M_PI), 1e-6);

  ck_assert_ldouble_eq_tol(s21_sin(1e-6), sin(1e-6), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(1e-19), sin(1e-19), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(1e+10), sin(1e+10), 1e-6);

  ck_assert_ldouble_nan(s21_sin(INFINITY));
  ck_assert_ldouble_nan(sin(INFINITY));
  ck_assert_ldouble_nan(s21_sin(-INFINITY));
  ck_assert_ldouble_nan(sin(-INFINITY));
  ck_assert_ldouble_nan(s21_sin(NAN));
  ck_assert_ldouble_nan(sin(NAN));
}
END_TEST

START_TEST(test_cos_1) {
  for (double x = -1000; x < 1000; x += 0.123456) {
    long double s21_cos_result = s21_cos(x);
    long double cos_result = cos(x);
    ck_assert_ldouble_eq_tol(s21_cos_result, cos_result, 1e-6);
  }
}
END_TEST

START_TEST(test_cos_2) {
  for (double x = -10000000; x < 10000000; x += 123.456) {
    long double s21_cos_result = s21_cos(x);
    long double cos_result = cos(x);
    ck_assert_ldouble_eq_tol(s21_cos_result, cos_result, 1e-6);
  }
}
END_TEST

START_TEST(test_cos_3) {
  ck_assert_ldouble_eq_tol(s21_cos(0), cos(0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(0.5 * S21_M_PI), cos(0.5 * S21_M_PI), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(S21_M_PI), cos(S21_M_PI), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(1.5 * S21_M_PI), cos(1.5 * S21_M_PI), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(2 * S21_M_PI), cos(2 * S21_M_PI), 1e-6);

  ck_assert_ldouble_eq_tol(s21_cos(1e-6), cos(1e-6), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(1e-19), cos(1e-19), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(1e+10), cos(1e+10), 1e-6);

  ck_assert_ldouble_nan(s21_cos(INFINITY));
  ck_assert_ldouble_nan(cos(INFINITY));
  ck_assert_ldouble_nan(s21_cos(-INFINITY));
  ck_assert_ldouble_nan(cos(-INFINITY));
  ck_assert_ldouble_nan(s21_cos(NAN));
  ck_assert_ldouble_nan(cos(NAN));
}
END_TEST

START_TEST(test_cos) {
  for (double x = -1000000; x < 1000000; x += 123.456) {
    long double cos_res = cos(x);
    long double s21_cos_res = s21_cos(x);
    ck_assert_ldouble_eq_tol(cos_res, s21_cos_res, 1e-6);
  }

  ck_assert_ldouble_nan(s21_cos(NAN));
  ck_assert_ldouble_nan(s21_cos(-INFINITY));
  ck_assert_ldouble_nan(s21_cos(INFINITY));
  ck_assert_ldouble_eq_tol(s21_cos(0), cos(0), 1e-6);

  ck_assert_ldouble_eq_tol(s21_cos(S21_M_PI), cos(S21_M_PI), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(S21_M_PI / 2), cos(S21_M_PI / 2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(1e-6), cos(1e-6), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(1e-19), cos(1e-19), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(1e+10), cos(1e+10), 1e-6);
}
END_TEST

START_TEST(test_sqrt_1) {
  for (double x = 0; x < 10000; x += 0.123456) {
    long double s21_sqrt_result = s21_sqrt(x);
    long double sqrt_result = sqrt(x);
    ck_assert_ldouble_eq_tol(s21_sqrt_result, sqrt_result, 1e-6);
  }
}
END_TEST

START_TEST(test_sqrt_2) {
  for (double x = 1000; x < 10000000; x += 123.456) {
    long double s21_sqrt_result = s21_sqrt(x);
    long double sqrt_result = sqrt(x);
    ck_assert_ldouble_eq_tol(s21_sqrt_result, sqrt_result, 1e-6);
  }
}
END_TEST

START_TEST(test_sqrt_3) {
  ck_assert_ldouble_eq_tol(s21_sqrt(0), sqrt(0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sqrt(1e-6), sqrt(1e-6), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sqrt(1e-19), sqrt(1e-19), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sqrt(1e+10), sqrt(1e+10), 1e-6);
  ck_assert_ldouble_eq(s21_sqrt(INFINITY), sqrt(INFINITY));

  ck_assert_ldouble_nan(s21_sqrt(-1));
  ck_assert_ldouble_nan(sqrt(-1));
  ck_assert_ldouble_nan(s21_sqrt(-0.5));
  ck_assert_ldouble_nan(sqrt(-0.5));
  ck_assert_ldouble_nan(s21_sqrt(-10));
  ck_assert_ldouble_nan(sqrt(-10));
  ck_assert_ldouble_nan(s21_sqrt(-INFINITY));
  ck_assert_ldouble_nan(sqrt(-INFINITY));
  ck_assert_ldouble_nan(s21_sqrt(NAN));
  ck_assert_ldouble_nan(sqrt(NAN));
}
END_TEST

START_TEST(test_tan_1) {
  for (double x = -100; x < 100; x += 0.123456) {
    long double s21_tan_result = s21_tan(x);
    long double tan_result = tan(x);
    ck_assert_ldouble_eq_tol(s21_tan_result, tan_result, 1e-6);
  }
}
END_TEST

START_TEST(test_tan_2) {
  for (double x = -10000; x < 10000; x += 123.456) {
    long double s21_tan_result = s21_tan(x);
    long double tan_result = tan(x);
    ck_assert_ldouble_eq_tol(s21_tan_result, tan_result, 1e-6);
  }
}
END_TEST

START_TEST(test_tan_3) {
  ck_assert_ldouble_eq_tol(s21_tan(0), tan(0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(0.5 * S21_M_PI), tan(0.5 * S21_M_PI), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(S21_M_PI), tan(S21_M_PI), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(-0.5 * S21_M_PI), tan(-0.5 * S21_M_PI),
                           1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(2 * S21_M_PI), tan(2 * S21_M_PI), 1e-6);

  ck_assert_ldouble_eq_tol(s21_tan(1e-6), tan(1e-6), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(1e-19), tan(1e-19), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(1e+10), tan(1e+10), 1e-6);

  ck_assert_ldouble_nan(s21_tan(INFINITY));
  ck_assert_ldouble_nan(tan(INFINITY));
  ck_assert_ldouble_nan(s21_tan(-INFINITY));
  ck_assert_ldouble_nan(tan(-INFINITY));
  ck_assert_ldouble_nan(s21_tan(NAN));
  ck_assert_ldouble_nan(tan(NAN));
}
END_TEST

START_TEST(test_s21_exp) {
  for (double x = -20; x < 300.0; x += 1.123) {
    long double exp_res = exp(x);
    long double s21_exp_res = s21_exp(x);
    if (exp_res < 1e10)
      ck_assert_ldouble_eq_tol(exp_res, s21_exp_res, 1e-6);
    else
      ck_assert_ldouble_lt(fabsl(exp_res - s21_exp_res) / fabsl(s21_exp_res),
                           1e-15);
  }

  for (double x = -1; x < 1; x += 1e-3) {
    long double exp_res = exp(x);
    long double s21_exp_res = s21_exp(x);
    ck_assert_ldouble_eq_tol(exp_res, s21_exp_res, 1e-6);
  }

  ck_assert_ldouble_nan(s21_exp(NAN));
  ck_assert_ldouble_infinite(s21_exp(INFINITY));
  ck_assert_ldouble_eq_tol(s21_exp(-INFINITY), exp(-INFINITY), 1e-6);
  ck_assert_ldouble_infinite(s21_exp(S21_DBL_MAX));
  ck_assert_ldouble_eq_tol(s21_exp(0), exp(0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_exp(1), exp(1), 1e-6);
  ck_assert_ldouble_nan(s21_exp(S21_NAN));
  ck_assert_ldouble_infinite(s21_exp(710));
  ck_assert_ldouble_eq_tol(exp(-13.54), s21_exp(-13.54), 1e-6);
  ck_assert_ldouble_eq_tol(exp(13.54), s21_exp(13.54), 1e-6);
  ck_assert_ldouble_eq_tol(exp(-0.54), s21_exp(-0.54), 1e-6);
}
END_TEST

START_TEST(test_s21_fabs) {
  ck_assert_ldouble_infinite(s21_fabs(INFINITY));
  ck_assert_ldouble_infinite(s21_fabs(-INFINITY));
  ck_assert_ldouble_eq(s21_fabs(-0.0), 0.0);
  ck_assert_ldouble_eq(s21_fabs(+0.0), 0.0);
  ck_assert_ldouble_nan(s21_fabs(NAN));

  for (double x = -100; x < 100; x += 10.123) {
    long double fabs_res = (long double)fabs(x);
    long double s21_fabs_res = s21_fabs(x);
    ck_assert_ldouble_eq(fabs_res, s21_fabs_res);
  }
}
END_TEST

START_TEST(test_s21_floor_1) {
  ck_assert_ldouble_infinite(s21_floor(INFINITY));
  ck_assert_ldouble_infinite(s21_floor(-INFINITY));
  ck_assert_ldouble_eq(s21_floor(-0.0), 0.0);
  ck_assert_ldouble_eq(s21_floor(+0.0), 0.0);
  ck_assert_ldouble_nan(s21_floor(NAN));

  for (double x = -100; x < 100; x += 0.123) {
    long double floor_res = (long double)floor(x);
    long double s21_floor_res = s21_floor(x);
    ck_assert_ldouble_eq(floor_res, s21_floor_res);
  }
}
END_TEST

START_TEST(test_s21_floor_2) {
  double x = S21_FLT_MAX;
  long double floor_res = (long double)floor(x);
  long double s21_floor_res = s21_floor(x);
  ck_assert_ldouble_eq(floor_res, s21_floor_res);
}
END_TEST

START_TEST(test_s21_floor_3) {
  double x = x = 1e-19;
  long double floor_res = (long double)floor(x);
  long double s21_floor_res = s21_floor(x);
  ck_assert_ldouble_eq(floor_res, s21_floor_res);
}
END_TEST

START_TEST(test_s21_fmod_1) {
  for (double x = -100.123, y = -90.45; x < 100.163; x += 10.5, y += 0.35) {
    long double fmod_res = (long double)fmod(x, y);
    long double s21_fmod_res = s21_fmod(x, y);
    ck_assert_ldouble_eq(fmod_res, s21_fmod_res);
  }
}
END_TEST

START_TEST(test_s21_fmod_2) {
  // x=INFINITY
  ck_assert_ldouble_nan(s21_fmod(INFINITY, -0.123));
  ck_assert_ldouble_nan(s21_fmod(-INFINITY, -0.123));
  ck_assert_ldouble_nan(s21_fmod(INFINITY, NAN));
  ck_assert_ldouble_nan(s21_fmod(-INFINITY, NAN));
  ck_assert_ldouble_nan(s21_fmod(INFINITY, INFINITY));
  ck_assert_ldouble_nan(s21_fmod(-INFINITY, INFINITY));
  ck_assert_ldouble_nan(s21_fmod(INFINITY, 0.0));
  ck_assert_ldouble_nan(s21_fmod(-INFINITY, 0.0));
}
END_TEST

START_TEST(test_s21_fmod_3) {
  // y=0
  ck_assert_ldouble_nan(s21_fmod(-0.123, -0.0));
  ck_assert_ldouble_nan(s21_fmod(-0.123, 0.0));
  ck_assert_ldouble_nan(s21_fmod(INFINITY, 0.0));
  ck_assert_ldouble_nan(s21_fmod(INFINITY, -0.0));
  ck_assert_ldouble_nan(s21_fmod(NAN, 0.0));
  ck_assert_ldouble_nan(s21_fmod(NAN, -0.0));
  ck_assert_ldouble_nan(s21_fmod(0.0, 0.0));
}
END_TEST

START_TEST(test_s21_fmod_4) {
  // x=NAN
  ck_assert_ldouble_nan(s21_fmod(NAN, -0.123));
  ck_assert_ldouble_nan(s21_fmod(NAN, INFINITY));
  ck_assert_ldouble_nan(s21_fmod(NAN, -INFINITY));
  ck_assert_ldouble_nan(s21_fmod(NAN, NAN));
  ck_assert_ldouble_nan(s21_fmod(NAN, 0.0));
}
END_TEST

START_TEST(test_s21_fmod_5) {
  // y=NAN
  ck_assert_ldouble_nan(s21_fmod(-0.123, NAN));
  ck_assert_ldouble_nan(s21_fmod(INFINITY, NAN));
  ck_assert_ldouble_nan(s21_fmod(-INFINITY, NAN));
  ck_assert_ldouble_nan(s21_fmod(NAN, NAN));
  ck_assert_ldouble_nan(s21_fmod(0.0, NAN));
}
END_TEST

START_TEST(test_s21_fmod_6) {
  // x=0, y!=NAN
  ck_assert_ldouble_eq(s21_fmod(-0.0, -0.123), fmod(-0.0, -0.123));
  ck_assert_ldouble_eq(s21_fmod(-0.0, INFINITY), fmod(-0.0, INFINITY));
}
END_TEST

START_TEST(test_s21_fmod_7) {
  // x!=INFINITY,y=INFINITY
  ck_assert_ldouble_eq(s21_fmod(0.123, INFINITY), fmod(0.123, INFINITY));
  ck_assert_ldouble_eq(s21_fmod(1e-6, INFINITY), fmod(1e-6, INFINITY));
  ck_assert_ldouble_eq(s21_fmod(1e+35, INFINITY), fmod(1e+35, INFINITY));
}
END_TEST

START_TEST(test_s21_fmod_8) {
  // res=0
  ck_assert_ldouble_eq((long double)fmod(-1.23, -2), s21_fmod(-1.23, -2));
  ck_assert_ldouble_eq((long double)fmod(500, 600.1), s21_fmod(500, 600.1));
}
END_TEST

START_TEST(test_some_cases) {
  ck_assert_ldouble_infinite(pow(-0, -0.3));
  ck_assert_ldouble_infinite(s21_pow(-0, -0.3));

  ck_assert_ldouble_infinite(pow(0, -0.3));
  ck_assert_ldouble_infinite(s21_pow(0, -0.3));

  ck_assert_ldouble_infinite(pow(-INFINITY, 4.3));
  ck_assert_ldouble_infinite(s21_pow(-INFINITY, 4.3));

  ck_assert_ldouble_infinite(pow(INFINITY, 1.1));
  ck_assert_ldouble_infinite(s21_pow(INFINITY, 1.1));

  ck_assert_ldouble_eq_tol(s21_pow(-INFINITY, -0.4), pow(-INFINITY, -0.4),
                           0.000001);

  ck_assert_ldouble_eq_tol(s21_pow(-INFINITY, -5), pow(-INFINITY, -5),
                           0.000001);

  ck_assert_ldouble_eq_tol(s21_pow(-1, INFINITY), pow(-1, INFINITY), 0.000001);
  ck_assert_ldouble_eq_tol(s21_pow(-1, -INFINITY), pow(-1, -INFINITY),
                           0.000001);
}
END_TEST

int main(void) {
  Suite *s;
  TCase *tc_core;
  SRunner *sr;

  s = suite_create("s21_math");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, s21_abs_test);
  tcase_add_test(tc_core, s21_asin_test);
  tcase_add_test(tc_core, s21_acos_test);
  tcase_add_test(tc_core, s21_atan_test);
  tcase_add_test(tc_core, s21_ceil_test);

  tcase_add_test(tc_core, test_pow_1);
  tcase_add_test(tc_core, test_pow_2);
  tcase_add_test(tc_core, test_pow_3);

  tcase_add_test(tc_core, test_sin_1);
  tcase_add_test(tc_core, test_sin_2);
  tcase_add_test(tc_core, test_sin_3);

  tcase_add_test(tc_core, test_cos);
  tcase_add_test(tc_core, test_cos_1);
  tcase_add_test(tc_core, test_cos_2);
  tcase_add_test(tc_core, test_cos_3);

  tcase_add_test(tc_core, test_tan_1);
  tcase_add_test(tc_core, test_tan_2);
  tcase_add_test(tc_core, test_tan_3);

  tcase_add_test(tc_core, test_sqrt_1);
  tcase_add_test(tc_core, test_sqrt_2);
  tcase_add_test(tc_core, test_sqrt_3);

  tcase_add_test(tc_core, test_log_1);
  tcase_add_test(tc_core, test_log_2);
  tcase_add_test(tc_core, test_log_3);
  tcase_add_test(tc_core, test_log_4);

  tcase_add_test(tc_core, test_s21_exp);
  tcase_add_test(tc_core, test_s21_fabs);
  tcase_add_test(tc_core, test_s21_floor_1);
  tcase_add_test(tc_core, test_s21_floor_2);
  tcase_add_test(tc_core, test_s21_floor_3);
  tcase_add_test(tc_core, test_s21_fmod_1);
  tcase_add_test(tc_core, test_s21_fmod_2);
  tcase_add_test(tc_core, test_s21_fmod_3);
  tcase_add_test(tc_core, test_s21_fmod_4);
  tcase_add_test(tc_core, test_s21_fmod_5);
  tcase_add_test(tc_core, test_s21_fmod_6);
  tcase_add_test(tc_core, test_s21_fmod_7);
  tcase_add_test(tc_core, test_s21_fmod_8);

  tcase_add_test(tc_core, test_some_cases);

  suite_add_tcase(s, tc_core);

  sr = srunner_create(s);
  srunner_run_all(sr, CK_NORMAL);
  int number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
