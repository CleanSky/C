#include <stdio.h>
#include <stdlib.h>

#define PI 3.14

double get_Circle_Area(double radius);

int main()
{
    double radius = 0;

    printf("Please input the radius of the circle: ");
    scanf("%lf", &radius);

    printf("The area of radius %lf is: %lf", radius, get_Circle_Area(radius));

    return 0;
}

double get_Circle_Area(double radius) {
    return PI * radius * radius;
}
