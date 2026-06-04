#include <iostream>
using namespace std;

int main() {
    int n1, n2;
    char op;
    cout<<"Input 2 numbers:"<<endl;
    cin>>n1>>n2;
    cout<<"Input an operator:"<<endl;
    cin>>op;

    
    switch (op)
    {
    case '+':
        cout<<n1+n2<<endl;
        break;
    case '-':
        cout<<n1-n2<<endl;
        break;
    case '*':
        cout<<n1*n2<<endl;
        break;
    case '/':
        cout<<n1/n2<<endl;
        break;
    case '%':
        cout<<n1%n2<<endl;
        break;
    default:
        cout<<"Try another operator"<<endl;
        break;
    }

    return 0;
}