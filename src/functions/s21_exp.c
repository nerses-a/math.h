#include "../s21_math.h"

// возвращает значение e, возведенное в заданную степень
long double s21_exp(double x) {
  long double i = 1.0;
  long double term = 1.0;
  long double res = 1.0;
  int sign = 0;
  if (x < 0) {
    x *= -1;
    sign = 1;
  }
  while (s21_fabs(term) > S21_PRECISION) {
    term = term * (x / i);
    res += term;
    i += 1.0;
    if (res > S21_DBL_MAX) {
      res = S21_INFINITY;
      break;
    }
  }
  if (sign == 1) {
    if (res > S21_DBL_MAX)
      res = 0;
    else
      res = 1.0 / res;
  }
  return res > S21_DBL_MAX ? S21_INFINITY : res;
}