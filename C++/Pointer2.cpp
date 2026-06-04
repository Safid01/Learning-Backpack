#include<iostream>
using namespace std;

int main () {
    int *p;
    int arr[] = {10, 20, 30, 40, 50};
    p = arr;
    for (int i=0; i<5; i++) {
        cout << *p << " ";
        p++;
    }
    cout << endl;
    int *q;
    q = &arr[4];
    for (int i=0; i<5; i++) {
        cout << *q << " ";
        q--;
    }
    return 0;
}