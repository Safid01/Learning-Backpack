#include<stdio.h>
#include<math.h>
int sum(int a, int b);

int main() {
    int a, b;
    printf("Enter the number :");
    scanf("%d", &a);
    printf("Enter the power of the number :");
    scanf("%d", &b);
    
    printf("%f", pow(a, b));
    
    return 0;
}