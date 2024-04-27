#include "../s21_math.h"

long double s21_sqrt(double x) {
  // Проверки входного аргумента
  if (x < 0 || S21_IS_NAN(x))
    return S21_NAN;
  else if (x == S21_INFINITY)
    return S21_INFINITY;

  // Находим квадратный корень методом Ньютона (метод касательных)

  // Начальное приближение
  long double sqrt_res = 1.0;

  // Приближаемся, пока не достигнем необходимой точности или пока не будет
  // выполнено очень много итераций
  for (int i = 0; S21_ABS(sqrt_res * sqrt_res - x) > S21_PRECISION &&
                  i < S21_MAX_ITERATIONS;
       ++i) {
    sqrt_res = 0.5 * (sqrt_res + x / sqrt_res);
  }

  return sqrt_res;
}
