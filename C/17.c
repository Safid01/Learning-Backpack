#include<stdio.h>
#include<math.h>

float squareArea(float side);
float circleArea(float rad);
float rectArea(float a, float b);

int main() {
    float side, rad, a, b;
    printf("Enter the SIDE of a SQUARE :");
    scanf("%f", &side);
    printf("Enter the RADIUS of a CIRCLE :");
    scanf("%f", &rad);
    printf("Enter the LENTH of a RECTANGLE :");
    scanf("%f", &a);
    printf("Enter the WIDTH of a RECTANGLE :");
    scanf("%f", &b);

    printf("Area of the Square is :%f\n", squareArea(side));
    printf("Area of the Circle is :%f\n", circleArea(rad));
    printf("Area of the Rectangle is :%f\n", rectArea(a, b));
    
    return 0;
}

float squareArea(float side) {
    return side * side;
}
float circleArea(float rad) {
    return 3.14 * rad * rad;
}
float rectArea(float a, float b) {
    return a * b;
}