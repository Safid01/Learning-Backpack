#include<stdio.h>

int main() {
    char ch;
    printf("Enter an alphabet :");
    scanf("%c", &ch);

    if (ch >='A' && ch <='Z') {
        printf("Upper case");
    }
    else if (ch >='a' && ch <='z') {
        printf("Lower case");
    }
    else {
        printf("Not an alphabet");
    }

    return 0;
}