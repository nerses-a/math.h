#include "../s21_math.h"

// Функция для возведения в целочисленную степень
long double s21_pow_exp_int(double base, int exp) {
  long double res = 1.0;

  if (exp > 0)
    for (int i = 0; i < exp; ++i) res *= base;

  else if (exp < 0)
    for (int i = 0; i > exp; --i) res /= base;

  return res;
}

long double s21_pow(double base, double exp) {
  // Проверки входных аргументов
  if (base == 1 || exp == 0)
    return 1;
  else if (S21_IS_NAN(base) || S21_IS_NAN(exp))
    return S21_NAN;
  else if (S21_IS_INF(exp) && base == -1)
    return 1;
  else if (exp < 0 && base == 0.0)
    return (1.0 / base);
  else if (S21_IS_INF(exp) && S21_ABS(base) > 1)
    return (exp == S21_INFINITY) ? S21_INFINITY : 0.0;
  else if (S21_IS_INF(exp) && S21_ABS(base) < 1)
    return (exp == S21_INFINITY) ? 0.0 : S21_INFINITY;
  else if ((base == -S21_INFINITY) && s21_INTEGER_AND_ODD(exp))
    return (exp < 0) ? -0.0 : base;
  else if (S21_IS_INF(base))
    return (exp < 0) ? 0.0 : S21_INFINITY;
  else if (base < 0 && s21_NOT_INTEGER(exp))
    return S21_NAN;
  else if (base == 0.0)
    return (s21_INTEGER_AND_EVEN(exp)) ? 0.0 : base;

  // Находим самую близкую целую точку
  int x_0 = (int)s21_floor(exp + 0.5);

  // Находим a^x_0
  long double a_x_0 = s21_pow_exp_int(base, x_0);
  long double add_0 = (exp - x_0) * s21_log(base);
  long double add = add_0 * a_x_0;
  // Первый член ряда
  long double res = a_x_0;

  // Добавляем другие члены ряда, пока не достигнем нужной точности
  for (int i = 2; S21_ABS(add) > S21_PRECISION; ++i) {
    res += add;
    add *= (add_0 / i);
  }

  return res > S21_DBL_MAX ? S21_INFINITY : res;
}
