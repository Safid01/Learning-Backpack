#include<stdio.h>

int sum(int n);

int main() {
    int n;
    printf ("Enter the Number :");
    scanf ("%d", &n);

    int result = sum(n);
    printf("Sum is : %d", result);
    return 0;
}
//recursive function
int sum(int n) {
    if (n == 1) {       //Base case [Must include]
        return 1;
    }
    int tsum1 = sum(n-1);
    int tsum = tsum1 + n;
    return tsum;
}