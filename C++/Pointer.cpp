#include <iostream>
using namespace std;

int main() {
    int a1=5, a2=10;
    int *p, *p1, *p2;
    p1=&a1;
    p2=&a2;
    *p=4;
    *p2=*p;
    *p1=*p;
    cout<<&p1<<endl;
    cout<<*p2<<endl;
    cout<<*p1<<endl;
    cout<<p1<<endl;

    return 0;
}
