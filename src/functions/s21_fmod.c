#include "../s21_math.h"

// остаток операции деления с плавающей точкой
long double s21_fmod(double x, double y) {
  long double res = 0.0;
  long double div_res = x / y;
  if (x == S21_INFINITY || x == -S21_INFINITY || y == 0 || S21_IS_NAN(y) ||
      S21_IS_NAN(x)) {
    res = S21_NAN;
  } else if (x == 0) {
    res = 0.0;
  } else if ((y == S21_INFINITY || y == -S21_INFINITY)) {
    res = x;
  } else if ((x > 0 && x < y) || (x < 0 && x > y)) {
    res = x;
  } else if (div_res > 0) {
    res = x - y * s21_floor(div_res);
  } else if (div_res < 0) {
    res = x - y * (s21_ceil(div_res));
  }
  return res;
}
