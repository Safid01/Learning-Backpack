#include<stdio.h>

float convtemp(float celcius);

int main() {
    float celcius;
    printf ("Enter the Celcius value :");
    scanf ("%f", &celcius);

    float far = convtemp(celcius);
    printf("Fahrenheit value is : %f", far);
    return 0;
}
//recursive function
float convtemp(float celcius) {
    float far = celcius * (9.0/5.0) + 32;
    return far;
}