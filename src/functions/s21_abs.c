#include "../s21_math.h"

int s21_abs(int x) {
  int res = x;
  if (x < 0) {
    res = -x;
  }
  return res;
}
