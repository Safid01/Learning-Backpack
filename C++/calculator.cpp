#include<iostream>
#include<cmath>
using namespace std;

int main() {

    float value1, value2;
    char operation;
    cout<<"Type your expression:"<<endl;
    cin>>value1>>operation>>value2;

    if (operation == '+')
        cout<<"Addition:"<<value1+value2<<endl;
    else if (operation == '-')
        cout<<"Subtraction:"<<value1-value2<<endl;
    else if (operation == '*')
        cout<<"Multiplication:"<<value1*value2<<endl;
    else if (operation == '/')
        cout<<"Division:"<<value1/value2<<endl;
    else if (operation == '%')
        cout<<"Remainder:"<<(int)value1%(int)value2<<endl;
    else if (operation == '^')
        cout<<"Power:"<<pow(value1,value2)<<endl;
    else 
        cout<<"Invalid Operator"<<endl;

        return 0;
}