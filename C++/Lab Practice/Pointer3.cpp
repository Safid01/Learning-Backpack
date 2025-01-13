#include<iostream>
using namespace std;

int main () {
   /* int num[5];
    int *ip;
    ip = num;
    *ip = 11;
    ip++;
    *ip = 22;
    ip = &num[2];
    *ip = 33;
    ip = num+3;
    *ip = 44;
    ip = num;
    *(ip+4) = 55;
    for (int i=0; i<5; i++) {
        cout << num[i] << " ";
    } */

   /* int arr[5];
    int *p;
    p = arr;
    for (int i = 0; i < 5; i++) {
        cin >> *p;
        p++;
    }
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    } */

   int num2 [10];
   int *cp;
   cp = num2;
   *cp = 11;
   for (int i = 0; i < 10; i++) {
    cp++;
    *cp = *(cp-1)+ 11;
   }
   for (int i = 0; i < 10; i++) {
        cout << num2[i] << " ";
    }

return 0;
}