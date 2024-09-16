#include <check.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "s21_math.h"

/* Продолжайте далее */

START_TEST(test_s21_abs_1) {
  ck_assert_int_eq(s21_abs(0), abs(0));
  ck_assert_int_eq(s21_abs(-5), abs(-5));
  ck_assert_int_eq(s21_abs(-100), abs(-100));
  ck_assert_int_eq(s21_abs(-1050), abs(-1050));
  ck_assert_int_eq(s21_abs(-10002), abs(-10002));
  ck_assert_int_eq(s21_abs(30), abs(-30));
}
END_TEST;

START_TEST(test_s21_abs_2) { ck_assert_int_eq(s21_abs('a'), abs('a')); }
END_TEST;

START_TEST(test_s21_fmod_1) {
  ck_assert_ldouble_eq_tol(s21_fmod(123.43, 21.2), fmod(123.43, 21.2),
                           S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_fmod(121233.99, 2154.1), fmod(121233.99, 2154.1),
                           S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_fmod(1212323.55, 271.2), fmod(1212323.55, 271.2),
                           S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_fmod(125453.55, 261.3), fmod(125453.55, 261.3),
                           S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_fmod(165623.55, 2561.4), fmod(165623.55, 2561.4),
                           S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_fmod(123.66, 28781.5), fmod(123.66, 28781.5),
                           S21_EPSILON);
  ck_assert(isnan(s21_fmod(123.77, 0)) && isnan(fmod(123.77, 0)));
  ck_assert_ldouble_eq_tol(s21_fmod(0.77, 28781.6), fmod(0.77, 28781.6),
                           S21_EPSILON);
}
END_TEST;

START_TEST(sin_test) {
  ck_assert_ldouble_eq_tol(s21_sin(0), sin(0), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_sin(1), sin(1), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_sin(S21_PI), sin(S21_PI), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_sin(S21_PI / 2), sin(S21_PI / 2), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_sin(S21_PI / 2), sinl(S21_PI / 2), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_sin(-S21_PI / 2), sin(-S21_PI / 2), S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_sin(3 * S21_PI / 2), sin(3 * S21_PI / 2),
                           S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_sin(-3 * S21_PI / 2), sin(-3 * S21_PI / 2),
                           S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_sin(5.1234567890123456), sin(5.1234567890123456),
                           S21_EPSILON);
  ck_assert_ldouble_eq_tol(s21_sin(3.1234567890123456), sin(3.1234567890123456),
                           S21_EPSILON);
  ck_assert_ldouble_nan(s21_sin(S21_NAN));
  ck_assert_ldouble_nan(sin(S21_NAN));
  for (double i = -10.0; i < 100; i += 0.1) {
    ck_assert_ldouble_eq_tol(s21_sin(i), sin(i), S21_EPSILON);
  }
}
END_TEST

START_TEST(test_s21_asin_1) {
  ck_assert_double_eq_tol(s21_asin(0.5), asinl(0.5), S21_EPSILON);
  ck_assert_double_eq_tol(s21_asin(0.3), asinl(0.3), S21_EPSILON);
  ck_assert_double_eq_tol(s21_asin(0.23333), asinl(0.23333), S21_EPSILON);
  ck_assert_double_eq_tol(s21_asin(1.0), asinl(1.0), S21_EPSILON);
  ck_assert_double_eq_tol(s21_asin(0), asinl(0), S21_EPSILON);
  ck_assert_double_eq_tol(s21_asin(-1), asinl(-1), S21_EPSILON);
  for (double i = -10.0; i < 100; i += 0.5) {
    // printf("%lf\n", i);
    if (isnan(s21_asin(i)))
      ck_assert(isnan(s21_asin(i)) && isnan(asin(i)));
    else
      ck_assert_ldouble_eq_tol(s21_asin(i), asin(i), S21_EPSILON);
  }
}
END_TEST

START_TEST(test_s21_asin_2) {
  double x = 1.5;
  ck_assert(isnan(s21_asin(x)) && isnan(asinl(x)));
  ck_assert(isnan(s21_asin(2)) && isnan(asinl(2)));
  ck_assert(isnan(s21_asin(-2)) && isnan(asinl(-2)));
}
END_TEST

START_TEST(test_s21_sqrt) {
  ck_assert_double_eq_tol(s21_sqrt(0.5), sqrt(0.5), S21_EPSILON);
  ck_assert_double_eq_tol(s21_sqrt(2), sqrt(2), S21_EPSILON);
  ck_assert_double_eq_tol(s21_sqrt(5), sqrt(5), S21_EPSILON);
  ck_assert_double_eq_tol(s21_sqrt(4), sqrt(4), S21_EPSILON);
  ck_assert_double_eq_tol(s21_sqrt(0), sqrt(0), S21_EPSILON);
  ck_assert_double_eq_tol(s21_sqrt(1), sqrt(1), S21_EPSILON);
  ck_assert_double_eq_tol(s21_sqrt(100), sqrt(100), S21_EPSILON);
}
END_TEST

START_TEST(test_s21_log) {
  ck_assert_double_eq_tol(s21_log(0.5), log(0.5), S21_EPSILON);
  ck_assert_double_eq_tol(s21_log(2.5), log(2.5), S21_EPSILON);
  ck_assert_double_eq_tol(s21_log(1), log(1), S21_EPSILON);
  ck_assert_double_eq_tol(s21_log(1111), log(1111), S21_EPSILON);
  ck_assert_double_eq_tol(s21_log(9), log(9), S21_EPSILON);
  ck_assert(isinf(s21_log(0)) && isinf(log(0)));
  ck_assert(isnan(s21_log(-1)) && isnan(log(-1)));
}
END_TEST
/* Продолжайте далее */
/*
TAN TEST
*/

START_TEST(s21_tan_test1) {
  ck_assert_double_eq_tol(s21_tan(69800), tan(69800), 0.000001);
}
END_TEST

START_TEST(s21_tan_test2) {
  ck_assert_double_eq_tol(s21_tan(-14.96), tan(-14.96), 0.000001);
}
END_TEST

START_TEST(s21_tan_test3) {
  ck_assert_double_nan(s21_tan(INFINITY));
  ck_assert_double_nan(tan(INFINITY));
}
END_TEST

START_TEST(s21_tan_test4) {
  ck_assert_double_nan(s21_tan(NAN));
  ck_assert_double_nan(tan(NAN));
}
END_TEST

START_TEST(s21_tan_test5) {
  ck_assert_double_nan(s21_tan(-INFINITY));
  ck_assert_double_nan(tan(-INFINITY));
}
END_TEST

START_TEST(s21_tan_test6) {
  ck_assert_double_eq_tol(s21_tan(0), tan(0), 0.000001);
}
END_TEST

START_TEST(s21_tan_test7) {
  ck_assert_double_eq_tol(s21_tan(S21_PI), tan(S21_PI), 0.000001);
}
END_TEST

/*

ATAN TEST

*/

START_TEST(s21_atan_test1) {
  long double arr[] = {14.96, -25.1235, 0.23464, 0, 1, -1};
  for (int i = 0; i < 6; i++)
    ck_assert_double_eq_tol(s21_atan(arr[i]), atan(arr[i]), 0.000001);
}
END_TEST

START_TEST(s21_atan_test2) {
  ck_assert_double_eq(s21_atan(INFINITY), atan(INFINITY));
}
END_TEST

START_TEST(s21_atan_test3) {
  ck_assert_double_nan(s21_atan(NAN));
  ck_assert_double_nan(atan(NAN));
}
END_TEST

START_TEST(s21_atan_test4) {
  ck_assert_double_eq(s21_atan(-INFINITY), atan(-INFINITY));
}
END_TEST

/*
CEIL TEST

*/

START_TEST(s21_ceil_test1) {
  ck_assert_double_eq_tol(s21_ceil(-0.1), ceil(-0.1), 0.000001);
}
END_TEST

START_TEST(s21_ceil_test2) {
  ck_assert_double_eq_tol(s21_ceil(-213.3), ceil(-213.3), 0.000001);
}
END_TEST

START_TEST(s21_ceil_test3) {
  ck_assert_double_eq(s21_ceil(INFINITY), ceil(INFINITY));
}
END_TEST

START_TEST(s21_ceil_test4) {
  ck_assert_double_nan(s21_ceil(NAN));
  ck_assert_double_nan(ceil(NAN));
}
END_TEST

START_TEST(s21_ceil_test5) {
  ck_assert_double_eq(s21_ceil(-INFINITY), ceil(-INFINITY));
}
END_TEST

START_TEST(s21_ceil_test6) {
  ck_assert_double_eq_tol(s21_ceil(50), ceil(50), 0.000001);
}
END_TEST

/*


EXP TEST

*/

START_TEST(s21_exp_test1) {
  ck_assert_double_eq(s21_exp(25048.369), exp(25048.369));
}
END_TEST

START_TEST(s21_exp_test2) {
  ck_assert_double_eq_tol(s21_exp(-14.96), exp(-14.96), 0.000001);
}
END_TEST

START_TEST(s21_exp_test3) {
  ck_assert_double_eq(s21_exp(INFINITY), exp(INFINITY));
}
END_TEST

START_TEST(s21_exp_test4) {
  ck_assert_double_nan(s21_exp(NAN));
  ck_assert_double_nan(exp(NAN));
}
END_TEST

START_TEST(s21_exp_test5) {
  ck_assert_double_eq(s21_exp(-INFINITY), exp(-INFINITY));
}
END_TEST

START_TEST(s21_exp_test6) {
  ck_assert_double_eq_tol(s21_exp(0), exp(0), 0.000001);
}
END_TEST

START_TEST(s21_exp_test7) {
  ck_assert_double_eq_tol(s21_exp(1), exp(1), 0.000001);
}
END_TEST

START_TEST(s21_exp_test8) {
  ck_assert_double_eq_tol(s21_exp(-1), exp(-1), 0.000001);
}
END_TEST

/*

FABS TEST

*/

START_TEST(s21_fabs_test1) {
  ck_assert_double_eq_tol(s21_fabs(568.36), fabs(568.36), 0.000001);
}
END_TEST

START_TEST(s21_fabs_test2) {
  ck_assert_double_eq_tol(s21_fabs(-14720.5689), fabs(-14720.5689), 0.000001);
}
END_TEST

START_TEST(s21_fabs_test3) {
  ck_assert_double_eq(s21_fabs(INFINITY), fabs(INFINITY));
}
END_TEST

START_TEST(s21_fabs_test4) {
  ck_assert_double_nan(s21_fabs(NAN));
  ck_assert_double_nan(fabs(NAN));
}
END_TEST

START_TEST(s21_fabs_test5) {
  ck_assert_double_eq(s21_fabs(-INFINITY), fabs(-INFINITY));
}
END_TEST

/*  POW TEST  */
START_TEST(s21_pow_test1) {
  long double a = 1.;
  long double exp = 1.;
  ck_assert_ldouble_eq_tol(s21_pow(a, exp), pow(a, exp), 0.000001);
}
END_TEST

START_TEST(s21_pow_test2) {
  long double a = 1234;
  long double exp = -4.3;
  ck_assert_ldouble_eq_tol(s21_pow(a, exp), pow(a, exp), 0.000001);
}
END_TEST

START_TEST(s21_pow_test3) {
  long double a = 0.0;
  long double exp = 0.5;
  ck_assert_ldouble_eq_tol(s21_pow(a, exp), pow(a, exp), 0.000001);
}
END_TEST

START_TEST(s21_pow_test4) {
  long double a = 0.0;
  long double exp = -2.0;
  ck_assert_ldouble_eq(s21_pow(a, exp), pow(a, exp));
}
END_TEST

START_TEST(s21_pow_test5) {
  long double a = 0.0;
  long double exp = 0.0;
  ck_assert_ldouble_eq_tol(s21_pow(a, exp), pow(a, exp), 0.000001);
}
END_TEST

START_TEST(s21_pow_test6) {
  long double a = 2134.0;
  long double exp = -1.0;
  ck_assert_ldouble_eq_tol(s21_pow(a, exp), pow(a, exp), 0.000001);
}
END_TEST

START_TEST(s21_pow_test7) {
  long double a = 2134326432.324534262346346;
  long double exp = -0.123567345643;
  for (a = 0.1; a < 300; a += 0.1) {
    ck_assert_ldouble_eq_tol(s21_pow(a, exp), pow(a, exp), 0.000001);
  }
}
END_TEST

START_TEST(s21_pow_test8) {
  long double a = S21_NAN;
  long double exp = S21_NAN;
  ck_assert(isnan(s21_pow(a, exp)) && isnan(pow(a, exp)));
  long double a2 = 2.33;
  for (long double exp = 0; exp < 5; exp += 1) {
    ck_assert_ldouble_eq_tol(s21_pow(a2, exp), pow(a2, exp), 0.000001);
  }
}
END_TEST

START_TEST(s21_pow_test9) {
  long double a = S21_INF_POS;
  long double exp = -1;
  ck_assert_ldouble_eq_tol(s21_pow(a, exp), pow(a, exp), 0.000001);
}
END_TEST

START_TEST(s21_pow_test10) {
  long double a = S21_INF_POS;
  long double exp = 1;
  ck_assert_ldouble_eq(s21_pow(a, exp), pow(a, exp));
}
END_TEST

START_TEST(s21_pow_test11) {
  long double a = S21_INF_NEG;
  long double exp = 1;
  ck_assert_ldouble_eq(s21_pow(a, exp), pow(a, exp));
}
END_TEST

START_TEST(s21_pow_test12) {
  long double a = 12424.234;
  long double exp = S21_INF_NEG;
  ck_assert_ldouble_eq_tol(s21_pow(a, exp), pow(a, exp), 0.000001);
}
END_TEST

START_TEST(s21_pow_test13) {
  long double a = -12424.234;
  long double exp = S21_INF_NEG;
  ck_assert_ldouble_eq_tol(s21_pow(a, exp), pow(a, exp), 0.000001);
}
END_TEST

START_TEST(s21_pow_test14) {
  long double a = -12424.234;
  long double exp = S21_INF_POS;
  ck_assert(isinf(s21_pow(a, exp)) && isinf(pow(a, exp)));
}
END_TEST

START_TEST(s21_pow_test15) {
  long double a = 3;
  long double exp = S21_INF_POS;
  ck_assert(isinf(s21_pow(a, exp)) && isinf(pow(a, exp)));
}
END_TEST

START_TEST(s21_pow_test16) {
  long double a = S21_INF_NEG;
  long double exp = S21_INF_NEG;
  ck_assert_ldouble_eq_tol(s21_pow(a, exp), pow(a, exp), 0.000001);
}
END_TEST

START_TEST(s21_pow_test17) {
  long double a = -1.;
  long double exp = 1.;
  ck_assert_ldouble_eq_tol(s21_pow(a, exp), pow(a, exp), 0.000001);
}
END_TEST

START_TEST(s21_pow_test18) {
  long double a = S21_INF_POS;
  long double exp = S21_INF_POS;
  ck_assert(isinf(s21_pow(a, exp)) && isinf(pow(a, exp)));
}
END_TEST

START_TEST(s21_pow_test19) {
  long double a = 15.;
  long double exp = 3.1415;
  ck_assert(s21_pow(a, exp) && pow(a, exp));
}
END_TEST

START_TEST(s21_pow_test20) {
  double a = 15.;
  double exp = 3.;
  ck_assert(s21_pow(a, exp) && pow(a, exp));
}
END_TEST

START_TEST(s21_pow_test21) {
  long double a = 15.;
  long double exp = 2.;
  ck_assert(s21_pow(a, exp) && pow(a, exp));
}
END_TEST

START_TEST(s21_pow_test22) {
  long double a = S21_INF_NEG;
  long double exp = -1;
  ck_assert_ldouble_eq_tol(s21_pow(a, exp), pow(a, exp), 0.000001);
}
END_TEST

START_TEST(s21_pow_test23) {
  long double a = 1.;
  long double exp = S21_INF_NEG;
  ck_assert_ldouble_eq_tol(s21_pow(a, exp), pow(a, exp), 0.000001);
}
END_TEST

START_TEST(s21_pow_test24) {
  long double a = -1.;
  long double exp = S21_INF_POS;
  ck_assert_ldouble_eq_tol(s21_pow(a, exp), pow(a, exp), 0.000001);
}
END_TEST

START_TEST(s21_pow_test25) {
  long double a = 0.4;
  long double exp = S21_INF_POS;
  ck_assert_ldouble_eq_tol(s21_pow(a, exp), pow(a, exp), 0.000001);
}
END_TEST

START_TEST(s21_pow_test26) {
  long double a = 0.9;
  long double exp = S21_INF_NEG;
  ck_assert_ldouble_eq(s21_pow(a, exp), pow(a, exp));
}
END_TEST

START_TEST(s21_pow_test27) {
  long double a = -0.9;
  long double exp = S21_INF_NEG;
  ck_assert_ldouble_eq(s21_pow(a, exp), pow(a, exp));
}
END_TEST

START_TEST(s21_pow_test28) {
  long double a = -0.5;
  long double exp = S21_NAN;
  ck_assert(s21_pow(a, exp) && pow(a, exp));
}
END_TEST

/*  COS TEST  */
START_TEST(s21_cos_test1) {
  ck_assert_ldouble_eq_tol(s21_cos(0), cos(0), 0.000001);
}
END_TEST

START_TEST(s21_cos_test2) {
  ck_assert_ldouble_eq_tol(s21_cos(1), cos(1), 0.000001);
}
END_TEST

START_TEST(s21_cos_test3) {
  ck_assert_ldouble_eq_tol(s21_cos(S21_PI + 0.2), cos(S21_PI + 0.2), 0.000001);
}
END_TEST

START_TEST(s21_cos_test4) {
  ck_assert_ldouble_eq_tol(s21_cos(S21_PI), cos(S21_PI), 0.000001);
}
END_TEST

START_TEST(s21_cos_test5) {
  ck_assert_ldouble_eq_tol(s21_cos(S21_PI / 2), cos(S21_PI / 2), 0.000001);
}
END_TEST

START_TEST(s21_cos_test6) {
  ck_assert_ldouble_eq_tol(s21_cos(-S21_PI / 2), cos(-S21_PI / 2), 0.000001);
}
END_TEST

START_TEST(s21_cos_test7) {
  ck_assert_ldouble_eq_tol(s21_cos(5.1234567890123456), cos(5.1234567890123456),
                           0.000001);
}
END_TEST

START_TEST(s21_cos_test8) {
  ck_assert_ldouble_nan(s21_cos(S21_INF_POS));
  ck_assert_ldouble_nan(cos(S21_INF_POS));
}
END_TEST

START_TEST(s21_cos_test9) {
  ck_assert_ldouble_nan(s21_cos(-S21_INF_POS));
  ck_assert_ldouble_nan(cos(-S21_INF_POS));
}
END_TEST

START_TEST(s21_cos_test10) {
  for (int i = -360; i <= 360; i++) {
    ck_assert_ldouble_eq_tol(s21_cos(i * S21_PI / 180), cos(i * S21_PI / 180),
                             0.000001);
  }
}
END_TEST

/*  ACOS TEST */
START_TEST(s21_acos_test1) {
  ck_assert_ldouble_eq_tol(s21_acos(0), acos(0), 0.000001);
}
END_TEST

START_TEST(s21_acos_test2) {
  ck_assert_ldouble_eq_tol(s21_acos(1), acos(1), 0.000001);
}
END_TEST

START_TEST(s21_acos_test3) {
  ck_assert_ldouble_eq_tol(s21_acos(-1), acos(-1), 0.000001);
}
END_TEST

START_TEST(s21_acos_test4) {
  ck_assert_ldouble_eq_tol(s21_acos(-0.7), acos(-0.7), 0.000001);
}
END_TEST

START_TEST(s21_acos_test5) {
  ck_assert_ldouble_eq_tol(s21_acos(0.0001), acos(0.0001), 0.000001);
}
END_TEST

START_TEST(s21_acos_test6) {
  ck_assert_ldouble_nan(s21_acos(-7.1234));
  ck_assert_ldouble_nan(acos(-7.1234));
}
END_TEST

START_TEST(s21_acos_test7) {
  ck_assert_ldouble_nan(s21_acos(7.12345678901234567));
  ck_assert_ldouble_nan(acos(7.12345678901234567));
}
END_TEST

START_TEST(s21_acos_test8) {
  ck_assert_ldouble_nan(s21_acos(S21_NAN));
  ck_assert_ldouble_nan(acos(S21_NAN));
}
END_TEST

START_TEST(s21_acos_test9) {
  ck_assert_ldouble_nan(s21_acos(S21_INF_POS));
  ck_assert_ldouble_nan(acos(S21_INF_POS));
}
END_TEST

START_TEST(s21_acos_test10) {
  ck_assert_ldouble_nan(s21_acos(-S21_INF_POS));
  ck_assert_ldouble_nan(acos(-S21_INF_POS));
}
END_TEST

/* FLOOR TEST  */
START_TEST(s21_floor_test1) {
  ck_assert_ldouble_eq_tol(s21_floor(0.0), floor(0.0), 0.000001);
}
END_TEST

START_TEST(s21_floor_test2) {
  ck_assert_ldouble_eq_tol(s21_floor(-0.0), floor(-0.0), 0.000001);
}
END_TEST

START_TEST(s21_floor_test3) {
  ck_assert_ldouble_eq_tol(s21_floor(0.000001), floor(0.000001), 0.000001);
}
END_TEST

START_TEST(s21_floor_test4) {
  ck_assert_ldouble_eq_tol(s21_floor(-0.000001), floor(-0.000001), 0.000001);
}
END_TEST

START_TEST(s21_floor_test5) {
  ck_assert_ldouble_eq_tol(s21_floor(-1.000001), floor(-1.000001), 0.000001);
}
END_TEST

START_TEST(s21_floor_test6) {
  ck_assert_ldouble_eq_tol(s21_floor(1.000001), floor(1.000001), 0.000001);
}
END_TEST

START_TEST(s21_floor_test7) {
  ck_assert_ldouble_eq_tol(s21_floor(1.), floor(1.), 0.000001);
}
END_TEST

START_TEST(s21_floor_test8) {
  ck_assert_ldouble_eq_tol(s21_floor(-1.), floor(-1.), 0.000001);
}
END_TEST

START_TEST(s21_floor_test9) {
  ck_assert_ldouble_eq_tol(s21_floor(1234567890.), floor(1234567890.),
                           0.000001);
}
END_TEST

START_TEST(s21_floor_test10) {
  ck_assert_ldouble_eq_tol(s21_floor(1234567890.123456),
                           floor(1234567890.123456), 0.000001);
}
END_TEST

START_TEST(s21_floor_test11) {
  ck_assert_ldouble_eq_tol(s21_floor(-1234567890.123456),
                           floor(-1234567890.123456), 0.000001);
}
END_TEST

START_TEST(s21_floor_test12) {
  ck_assert_ldouble_eq_tol(s21_floor(9999999999.999999),
                           floor(9999999999.999999), 0.000001);
}
END_TEST

START_TEST(s21_floor_test13) {
  ck_assert_ldouble_eq_tol(s21_floor(-9999999999.999999),
                           floor(-9999999999.999999), 0.000001);
}
END_TEST

START_TEST(s21_floor_test14) {
  ck_assert_ldouble_eq_tol(s21_floor(-9999999999999.99999999999),
                           floor(-9999999999999.99999999999), 0.000001);
}
END_TEST

START_TEST(s21_floor_test15) {
  ck_assert_ldouble_nan(s21_floor(NAN));
  ck_assert_ldouble_nan(floor(NAN));
}
END_TEST

START_TEST(s21_floor_test16) {
  ck_assert_ldouble_nan(s21_floor(-NAN));
  ck_assert_ldouble_nan(floor(-NAN));
}
END_TEST

START_TEST(s21_floor_test17) {
  ck_assert_ldouble_eq(s21_floor(INFINITY), floor(INFINITY));
}
END_TEST

START_TEST(s21_floor_test18) {
  ck_assert_ldouble_eq(s21_floor(-INFINITY), floor(-INFINITY));
}
END_TEST

START_TEST(s21_floor_test19) {
  ck_assert_ldouble_eq_tol(s21_floor(2.2250738585072014e-308),
                           floor(2.2250738585072014e-308), 0.000001);
}
END_TEST

/* End --- */
int main(void) {
  Suite *s = suite_create("s21_suite");
  TCase *tc = tcase_create("");

  tcase_add_test(tc, test_s21_abs_1);
  tcase_add_test(tc, test_s21_abs_2);
  /* Продолжайте далее */
  tcase_add_test(tc, test_s21_fmod_1);
  tcase_add_test(tc, sin_test);
  tcase_add_test(tc, test_s21_asin_1);
  tcase_add_test(tc, test_s21_asin_2);
  tcase_add_test(tc, test_s21_sqrt);
  tcase_add_test(tc, test_s21_log);

  tcase_add_test(tc, s21_tan_test1);
  tcase_add_test(tc, s21_tan_test2);
  tcase_add_test(tc, s21_tan_test3);
  tcase_add_test(tc, s21_tan_test4);
  tcase_add_test(tc, s21_tan_test5);
  tcase_add_test(tc, s21_tan_test6);
  tcase_add_test(tc, s21_tan_test7);

  tcase_add_test(tc, s21_atan_test1);
  tcase_add_test(tc, s21_atan_test2);
  tcase_add_test(tc, s21_atan_test3);
  tcase_add_test(tc, s21_atan_test4);

  tcase_add_test(tc, s21_ceil_test1);
  tcase_add_test(tc, s21_ceil_test2);
  tcase_add_test(tc, s21_ceil_test3);
  tcase_add_test(tc, s21_ceil_test4);
  tcase_add_test(tc, s21_ceil_test5);
  tcase_add_test(tc, s21_ceil_test6);

  tcase_add_test(tc, s21_exp_test1);
  tcase_add_test(tc, s21_exp_test2);
  tcase_add_test(tc, s21_exp_test3);
  tcase_add_test(tc, s21_exp_test4);
  tcase_add_test(tc, s21_exp_test5);
  tcase_add_test(tc, s21_exp_test6);
  tcase_add_test(tc, s21_exp_test7);
  tcase_add_test(tc, s21_exp_test8);

  tcase_add_test(tc, s21_fabs_test1);
  tcase_add_test(tc, s21_fabs_test2);
  tcase_add_test(tc, s21_fabs_test3);
  tcase_add_test(tc, s21_fabs_test4);
  tcase_add_test(tc, s21_fabs_test5);

  tcase_add_test(tc, s21_acos_test1);
  tcase_add_test(tc, s21_acos_test2);
  tcase_add_test(tc, s21_acos_test3);
  tcase_add_test(tc, s21_acos_test4);
  tcase_add_test(tc, s21_acos_test5);
  tcase_add_test(tc, s21_acos_test6);
  tcase_add_test(tc, s21_acos_test7);
  tcase_add_test(tc, s21_acos_test8);
  tcase_add_test(tc, s21_acos_test9);
  tcase_add_test(tc, s21_acos_test10);

  tcase_add_test(tc, s21_cos_test1);
  tcase_add_test(tc, s21_cos_test2);
  tcase_add_test(tc, s21_cos_test3);
  tcase_add_test(tc, s21_cos_test4);
  tcase_add_test(tc, s21_cos_test5);
  tcase_add_test(tc, s21_cos_test6);
  tcase_add_test(tc, s21_cos_test7);
  tcase_add_test(tc, s21_cos_test8);
  tcase_add_test(tc, s21_cos_test9);
  tcase_add_test(tc, s21_cos_test10);

  tcase_add_test(tc, s21_floor_test1);
  tcase_add_test(tc, s21_floor_test2);
  tcase_add_test(tc, s21_floor_test3);
  tcase_add_test(tc, s21_floor_test4);
  tcase_add_test(tc, s21_floor_test5);
  tcase_add_test(tc, s21_floor_test6);
  tcase_add_test(tc, s21_floor_test7);
  tcase_add_test(tc, s21_floor_test8);
  tcase_add_test(tc, s21_floor_test9);
  tcase_add_test(tc, s21_floor_test10);
  tcase_add_test(tc, s21_floor_test10);
  tcase_add_test(tc, s21_floor_test11);
  tcase_add_test(tc, s21_floor_test12);
  tcase_add_test(tc, s21_floor_test13);
  tcase_add_test(tc, s21_floor_test14);
  tcase_add_test(tc, s21_floor_test15);
  tcase_add_test(tc, s21_floor_test16);
  tcase_add_test(tc, s21_floor_test17);
  tcase_add_test(tc, s21_floor_test18);
  tcase_add_test(tc, s21_floor_test19);

  tcase_add_test(tc, s21_pow_test1);
  tcase_add_test(tc, s21_pow_test2);
  tcase_add_test(tc, s21_pow_test3);
  tcase_add_test(tc, s21_pow_test4);
  tcase_add_test(tc, s21_pow_test5);
  tcase_add_test(tc, s21_pow_test6);
  tcase_add_test(tc, s21_pow_test7);
  tcase_add_test(tc, s21_pow_test8);
  tcase_add_test(tc, s21_pow_test9);
  tcase_add_test(tc, s21_pow_test10);
  tcase_add_test(tc, s21_pow_test11);
  tcase_add_test(tc, s21_pow_test12);
  tcase_add_test(tc, s21_pow_test13);
  tcase_add_test(tc, s21_pow_test14);
  tcase_add_test(tc, s21_pow_test15);
  tcase_add_test(tc, s21_pow_test16);
  tcase_add_test(tc, s21_pow_test17);
  tcase_add_test(tc, s21_pow_test18);
  tcase_add_test(tc, s21_pow_test19);
  tcase_add_test(tc, s21_pow_test20);
  tcase_add_test(tc, s21_pow_test21);
  tcase_add_test(tc, s21_pow_test22);
  tcase_add_test(tc, s21_pow_test23);
  tcase_add_test(tc, s21_pow_test24);
  tcase_add_test(tc, s21_pow_test25);
  tcase_add_test(tc, s21_pow_test26);
  tcase_add_test(tc, s21_pow_test27);
  tcase_add_test(tc, s21_pow_test28);

  /* End --- */
  suite_add_tcase(s, tc);
  SRunner *sr;
  int number_failed = 0;

  sr = srunner_create(s);
  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (number_failed == 0) ? 0 : 1;
}
