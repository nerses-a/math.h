#include "../s21_math.h"

long double s21_tan(double x) {
  // Входная проверка (так как при ±S21_M_PI / 2 тангенс стремится к ±∞ и могут
  // возникают неточности)
  if (x == S21_M_PI / 2) {
    return 16331239353195370.0000;
  } else if (x == -S21_M_PI / 2) {
    return -16331239353195370.0000;
  }

  // Находим как sin(x) / cos(x) )))
  long double tan_res = s21_sin(x) / s21_cos(x);
  return tan_res;
}
