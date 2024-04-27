#include "../s21_math.h"

// вычисляет абсолютное значение числа с плавающей точкой
long double s21_fabs(double x) {
  long double res = (long double)x;
  if (S21_IS_NAN(x))
    res = S21_NAN;
  else if (res == S21_INFINITY || res == -S21_INFINITY)
    res = S21_INFINITY;
  else
    res = res < 0 ? -res : res;
  return res;
}