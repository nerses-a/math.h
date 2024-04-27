#include "../s21_math.h"

long double s21_sin(double x) {
  // Проверка входного аргумента
  if (x == -S21_INFINITY || x == S21_INFINITY || S21_IS_NAN(x)) return S21_NAN;

  // Работаем в диапазоне x∈[−2π,2π), т.к. sin(x) периодическая функция
  x = s21_fmod(x, 2.0 * S21_M_PI);  // Период 2π

  // Находим через разложение в ряд Маклорена(в окрестности точки x = 0)
  // f(x) = sin(x) = x - x^3 / 3! + x^5 / 5! - x^7 / 7! ...

  // Первый член ряда
  long double sin_res = x;
  long double add = x;

  // Добавляем другие члены ряда, пока не достигнем нужной точности
  for (int i = 2; S21_ABS(add) > S21_PRECISION; i += 2) {
    add *= -(x * x) / (i * (i + 1));
    sin_res += add;
  }

  return sin_res;
}