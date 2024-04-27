#include "../s21_math.h"

// возвращает ближайшее целое число, не превышающее заданное значение
long double s21_floor(double x) {
  long double result = (long long int)x;
  if ((x == S21_INFINITY || x == -S21_INFINITY) || S21_IS_NAN(x))
    result = x;
  else if (x <= -S21_FLT_MAX || x >= S21_FLT_MAX) {
    result = x;
  } else if (x < 0. && s21_fabs(x - result) > 0.)
    result -= 1;
  return result;
}