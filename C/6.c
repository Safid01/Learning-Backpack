#include<stdio.h>

int main(){
    int marks;
    printf("Enter your mark :");
    scanf("%d", &marks);

    if(marks >=0 && marks <33) {
        printf("Fail");
    }
    else if (marks >= 33 && marks <=100) {
        printf("Pass");    
    }
    else {printf ("Wrong input");
    }

    return 0;
}