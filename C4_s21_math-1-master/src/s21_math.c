#include "s21_math.h"

#define SMALL_V (0.00000000000000000001)

int s21_abs(int x) {
  if (x < 0) x *= -1;
  return x;
}

long double power(double base, int exponent) {
  long double result = 1;
  for (int i = 0; i < exponent; i++) result *= base;

  return result;
}

/* Belleror |*/
long double s21_asin(double x) {
  long double result = 0;
  if (x > -1 && x < 1) {
    for (int i = 0; i < S21_APPR; i++) {
      result += (factorial(2 * i) * power(x, 2 * i + 1)) /
                (power(2, (2 * i)) * power(factorial(i), 2) * (2 * i + 1));
    }
  } else if ((x >= 1 - 0.00000001 && x <= 1 + 0.00000001) || (x == -1))
    result = S21_PI / (2 * x);
  else
    result = -S21_NAN;
  return result;
}

long double s21_sin(double x) {
  long double result = 0;
  if ((s21_fabs(x) == S21_INF) || (!(x >= 0) && !(x < 0))) {
    result = S21_NAN;
  } else {
    for (; x < -2 * S21_PI || 2 * S21_PI < x;) {
      if (x > 2 * S21_PI)
        x -= 2 * S21_PI;
      else
        x += 2 * S21_PI;
    }
    for (int i = 0; i < 150; i++) {
      result += power(-1, i) * power(x, 2 * i + 1) / factorial(2 * i + 1);
    }
  }
  return result;
}

long double s21_sqrt(double x) {
  long double result = s21_pow(x, 0.5);
  if (x < 0) result = S21_NAN;
  if (x == 0) result = 0;
  return result;
}

long double s21_fmod(double x, double y) {
  if (y <= SMALL_V && y >= -SMALL_V) {
    x = S21_NAN;
  } else {
    double absY = s21_fabs(y);
    while (x >= absY) x = x - absY;
  }
  return x;
}

long double s21_log(double x) {
  long double result = 0;
  if (x < 0)
    result = S21_NAN;
  else if (x == 0)
    result = -S21_INF;
  else {
    double guess = x - 1.0;
    while (s21_fabs(x - s21_exp(result)) > S21_EPSILON) {
      result = guess + (x - s21_exp(guess)) / s21_exp(guess);
      guess = result;
    }
  }
  return result;
}

/* Helgaann */
long double s21_cos(double x) {
  long double res = S21_NAN;
  if (x != S21_INF_POS || x != S21_INF_NEG || !S21_IS_NAN(x))
    res = s21_sin(S21_PI / 2 - x);
  return res;
}

long double s21_acos(double x) {
  if (S21_IS_NAN(x) || S21_IS_INF(x) || x > 1.0 || x < -1.0) {
    x = S21_NAN;
  } else if (x == 1) {
    x = 0;
  } else if (x == -1) {
    x = S21_PI;
  } else {
    x = S21_PI / 2.0 - s21_asin(x);
  }
  return x;
}

long double s21_floor(double x) {
  if (S21_IS_NAN(x))
    return S21_NAN;
  else if (S21_IS_INF(x)) {
    if (x > 0) {
      return S21_INF_POS;
    } else
      return S21_INF_NEG;
  } else {
    long long int res = x;
    if (x < 0 && x != res) {
      res = res - 1;
    }
    return res;
  }
}

long double s21_pow(double base, double exp) {
  long double result;
  int is_neg_exp = 0;

  if (exp == S21_INF_NEG) {
    if (base > 1) {
      result = 0;
    } else if ((base == 1) || (base == -1)) {
      result = 1;
    } else if ((base < 1) && (base > 0)) {
      result = S21_INF_POS;
    } else if ((base > -1) && (base < 0)) {
      result = S21_INF_POS;
    } else {
      result = 0;
    }
  } else if (exp == S21_INF_POS) {
    if (base > 1) {
      result = S21_INF_POS;
    } else if ((base == 1) || (base == -1)) {
      result = 1;
    } else if ((base < 1) && (base > 0)) {
      result = 0;
    } else {
      result = S21_INF_POS;
    }
  }

  else if (((base < 0) && (exp != (long int)exp)) ||
           ((base != base) && (exp != exp))) {
    result = S21_NAN;
  } else {
    if (exp < -S21_EPSILON) {
      is_neg_exp = 1;
      exp = (double)s21_fabs(exp);
    }

    if (exp < S21_EPSILON) {
      result = 1;
    } else {
      long int natural_exp = s21_floor(exp);
      double rest_exp = exp - s21_floor(exp);
      result = 1;
      for (int i = 0; i < natural_exp; i++) {
        result *= (long double)base;
      }

      if (rest_exp > S21_EPSILON) {
        result *= s21_exp(rest_exp * s21_log(base));
      }
      if (is_neg_exp) {
        result = 1. / result;
      }
    }
  }
  return result;
}

/* Bernicew */
long double s21_atan(double x) {
  long double res = 0;

  if (x != S21_INF_POS && x != S21_INF_NEG && !S21_IS_NAN(x) && x != 1 &&
      x != -1) {
    int is_in_range = (x > -1 && x < 1);
    res = is_in_range ? x : 1.0 / x;
    for (int i = 1; i < 7000; i++) {
      double a = s21_pow_int(-1, i);
      double b = s21_pow_int(x, (1 + 2 * i) * (is_in_range ? 1 : -1));
      double c = 1 + 2 * i;
      res += a * b / c;
    }

    if (!is_in_range) res = (S21_PI * s21_fabs(x) / (2 * x)) - res;
  }
  if (x == S21_INF_POS) res = S21_PI / 2;
  if (x == S21_INF_NEG) res = -S21_PI / 2;
  if (S21_IS_NAN(x)) res = x;
  if (x == 1) res = 0.785398163;
  if (x == -1) res = -0.785398163;
  return res;
}
long double s21_tan(double x) {
  long double res = 0;
  if (s21_fabs((double)s21_cos(x)) < S21_EPSILON)
    res = S21_INF;
  else
    res = s21_sin(x) / s21_cos(x);
  return res;
}
long double s21_ceil(double x) {
  long double res;
  if (!S21_IS_NAN(x) && !S21_IS_INF(x)) {
    int int_part = (int)x;
    int_part += (x > 0 && (x - int_part));
    res = int_part;
    if (res == 0 && x < 0) res = -res;
  } else
    res = x;
  return res;
}
long double s21_exp(double x) {  // 2134326431.3245342 = inf
  double result = 1.0;
  if (x != S21_INF_NEG) {
    double term = 1.0;
    for (int i = 1; i < S21_APPR;
         i++) {  // Выполняем несколько итераций для достижения приемлемой
                 // точности (может потребоваться больше)
      term *= x / i;
      result += term;
    }
  } else
    result = 0;
  return result;
}
long double s21_fabs(double x) {
  if (x < 0) x *= -1;
  return (long double)x;
}
//кусок для тангеса

long double factorial(int x) {
  long double res = 1;
  for (int i = 1; i <= x; i++) res = res * i;
  return res;
}
//для арктангенса
long double s21_pow_int(double base, long long int exp) {
  long double result = 1;
  int sign = (exp > 0);
  exp *= sign ? 1 : -1;
  for (long long int i = 0; i < exp; i++)
    result = sign ? result * base : result / base;
  return result;
}
