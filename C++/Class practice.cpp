#include <iostream>
using namespace std;
int main() {
    double mark;
    cout<<"Enter the mark: ";
    cin>>mark;
    if(mark<=100 && mark>=90){
        cout<<"A+";
    }else if(mark>=85 && mark<90){
        cout<<"A";
    }else{
        cout<<"F";
    }
    return 0;
}