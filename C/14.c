#include<stdio.h>
void salam();
void bonjour();

int main(){
    printf("Enter b if you are Bangladeshi:");
    char ch;
    scanf("%c", &ch);

    if (ch == 'b') {
        salam();
    } else {
        bonjour();
    }

    return 0;
}

void salam(){
    printf("Assalamu Alaikum");
}

void bonjour() {
    printf("Bonjour");
}

