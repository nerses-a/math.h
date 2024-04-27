#include "../s21_math.h"

long double s21_log(double x) {
  // Проверки входного аргумента
  if (x < 0 || S21_IS_NAN(x))
    return S21_NAN;
  else if (x == 0.0)
    return -S21_INFINITY;
  else if (x == S21_INFINITY)
    return S21_INFINITY;
  else if (x == S21_M_E)
    return 1.0;

  long double log_res = 0;

  // Находим через разложение в ряд Телора(в окрестности точки x = 1)
  // и делая замену на (x-1)/(x+1) получаем
  // f(x) = ln(x) = 2 * [(x-1)/(x+1) + (1/3) * ((x - 1)/(x + 1))^3 + ... ]

  // Первый член ряда
  double a_1 = (x - 1) / (x + 1);
  double a_1_pow_2 = a_1 * a_1;
  long double add = a_1;

  // Добавляем другие члены ряда, пока не достигнем нужной точности
  for (int i = 1; S21_ABS(add) > S21_PRECISION; i += 2) {
    log_res += add / i;
    add *= a_1_pow_2;
  }

  // Умножаем на 2, т.к. за ряд выносили 2
  log_res *= 2.0;

  return log_res;
}
