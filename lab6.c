#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES 
#include <stdio.h>
#include <locale.h>
#include <math.h>

int check_leap_year(int yeas);
double calculate_F(double x);
int get_water_state(float temp);
int check_inside(float x, float y);

int main(void) {
    setlocale(LC_ALL, ".UTF-8");

    int yeas;
    printf("   Задача 1    \nВведите год: ");
    scanf("%d", &yeas);
    printf("год %d %s\n\n", yeas, check_leap_year(yeas) ? "високосный" : "не високосный");

    double x;
    printf("   Задача 2   \nВведите значение x: ");
    scanf("%lf", &x);
    printf("Результат: F(x) = %lf (вычислено по %s формуле)\n\n",
        calculate_F(x),
        (x >= 0.0 && x <= 1.0) ? "первой" : "второй");

    float temperature;
    printf("    Задание 3    \nВведите температуру воды (°C): ");
    scanf("%f", &temperature);
    int state = get_water_state(temperature);
    printf("Состояние воды: %s\n\n",
        (state == 1) ? "лед" :
        (state == 2) ? "жидкое" : "пар");

    float point_x, point_y;
    printf("    Домашнее задание    \nВведите координаты точки (x, y) через пробел: ");
    scanf("%f %f", &point_x, &point_y);
    printf("Точка (%.2f, %.2f) %s заштрихованной области.\n",
        point_x, point_y,
        check_inside(point_x, point_y) ? "принадлежит" : "НЕ принадлежит");

    return 0;
}

int check_leap_year(int yeas) {
    return ((yeas % 4 == 0 && yeas % 100 != 0) || (yeas % 400 == 0));
}

double calculate_F(double x) {
    return (x >= 0.0 && x <= 1.0) ? (x * x - x) : (x * x - sin(M_PI * x * x));
}

int get_water_state(float temp) {
    return (temp <= 0.0f) ? 1 : ((temp < 100.0f) ? 2 : 3);
}

int check_inside(float x, float y) {
    float distance_sq = x * x + y * y;
    return (x >= 0.0f && distance_sq >= 1.0f && distance_sq <= 9.0f);
}