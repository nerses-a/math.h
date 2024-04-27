#ifndef S21_MATH
#define S21_MATH

#define S21_ABS(x) ((x) < 0 ? -(x) : (x))

#define S21_IS_NAN(x) (x != x)
#define S21_IS_INF(x) (x == -S21_INFINITY || x == S21_INFINITY)
#define s21_NOT_INTEGER(exp) ((exp - (long)exp) != 0)
#define s21_INTEGER_AND_ODD(exp) \
  ((exp - (long)exp == 0) && ((long)exp % 2) != 0)
#define s21_INTEGER_AND_EVEN(exp) \
  ((exp - (long)exp == 0) && ((long)exp % 2) == 0)

#define S21_PRECISION 1e-16
#define S21_MAX_ITERATIONS 1000

#define S21_NAN (0.0 / 0.0)
#define S21_INFINITY (1.0 / 0.0)

#define S21_M_PI 3.14159265358979323846
#define S21_M_PI_2 1.57079632679489661923
#define S21_M_PI_4 0.78539816339744827899
#define S21_M_E 2.7182818284590452354

#define S21_FLT_MAX 3.40282346638528859811704183484516925e+38F
#define S21_DBL_MAX ((double)1.79769313486231570814527423731704357e+308L)
#define S21_LDBL_MAX 1.18973149535723176502126385303097021e+4932L

int s21_abs(int x);
long double s21_asin(double x);
long double s21_acos(double x);
long double s21_atan(double x);
long double s21_ceil(double x);

long double s21_fabs(double x);
long double s21_floor(double x);
long double s21_fmod(double x, double y);
long double s21_cos(double x);
long double s21_exp(double x);

long double s21_log(double x);
long double s21_pow_exp_int(double base, int exp);
long double s21_pow(double base, double exp);
long double s21_sin(double x);
long double s21_sqrt(double x);
long double s21_tan(double x);

#endif
