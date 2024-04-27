#include "../s21_math.h"

long double s21_cos(double x) {
  long double res = 0.0;
  if (x == -S21_INFINITY || x == S21_INFINITY || S21_IS_NAN(x))
    res = S21_NAN;
  else if (x == 0) {
    res = 1;
  } else if (x < 0)
    res = s21_cos(-x);
  else if (x > S21_M_PI * 2) {
    res = s21_cos(s21_fmod(x, 2 * S21_M_PI));
  } else {
    long double term = 1;
    res = 1;
    for (int i = 1; s21_fabs(term) > S21_PRECISION; i++) {
      term = term * (-x) * x / (2 * i * (2 * i - 1));
      res += term;
    }
  }
  return res;
}
