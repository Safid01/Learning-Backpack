#include<iostream>

using namespace std;

int main() {

double l, b;
cout<<"Enter the length:";
cin>>l;
cout<<"Enter the breadth:";
cin>>b;
if (l == b) {
    cout<<"This is a square";
}
else {
    cout<<"This is a rectangle";
}
return 0;

}