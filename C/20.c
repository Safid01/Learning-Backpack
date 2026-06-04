#include<stdio.h>

int fib(int n);

int main() {
    int n;
    printf ("Enter the 'n'th number of fibonacci sequence: ");
    scanf ("%d", &n);
    
    int ffib = fib(n);
    printf ("The %dth value of fibonacci sequence is : %d", n, ffib);

    return 0;
}

int fib(int n) {
    if(n == 0) {
        return 0;
    }
    if(n == 1) { 
        return 1;
    }

    int fibNM1 = fib(n-1);
    int fibNM2 = fib(n-2);
    int fibN = fibNM1 + fibNM2;

    return fibN;
}