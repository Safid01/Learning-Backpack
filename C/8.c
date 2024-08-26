#include<stdio.h>

int main(){
    char ch;
    printf("Enter your character :");
    scanf("%c", &ch);

    int i='a';
    do {
        printf("%c\n", i);
        i++;
    }
    while(i <= ch);

    return 0;
}