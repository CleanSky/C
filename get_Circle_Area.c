#include <stdio.h>
#include <stdlib.h>

#define PI 3.14
const double pi = 3.1415926;

double get_Circle_Area1(double radius);
double get_Circle_Area2(double radius);

int main()
{
    double radius = 0;

    printf("Please input the radius of the circle: ");
    scanf("%lf", &radius);

    printf("The area of radius %lf is: %lf\n", radius, get_Circle_Area1(radius));
    printf("The area of radius %lf is: %lf\n", radius, get_Circle_Area2(radius));

    return 0;
}

//宏定义PI
double get_Circle_Area1(double radius) {
    return PI * radius * radius;
}

//const常量定义PI
double get_Circle_Area2(double radius) {
    return pi * radius * radius;
}
