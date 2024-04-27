#include "../s21_math.h"

long double s21_atan(double x) {
  long double result = x;
  if (x != x)
    result = S21_NAN;
  else if (x == 0.0)
    result = 0.0;
  else if (x == 1.0)
    result = S21_M_PI_4;
  else if (x == -1.0)
    result = -S21_M_PI_4;
  else if (x == -S21_INFINITY)
    result = -S21_M_PI_2;
  else if (x == S21_INFINITY)
    result = S21_M_PI_2;
  else if (x > 1)
    result = S21_M_PI_2 - s21_atan(1 / x);
  else if (x < -1)
    result = -S21_M_PI_2 - s21_atan(1 / x);
  else {
    long double term = x;
    for (int n = 1; s21_fabs(term) > S21_PRECISION; n++) {
      term *= (-1) * x * x;
      result += term / (2 * n + 1);
    }
  }
  return result;
}
