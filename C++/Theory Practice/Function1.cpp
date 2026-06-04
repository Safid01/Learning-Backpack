#include <iostream>
using namespace std;
 
int sum(int x, int y){
    cout<<"1"<<endl;
    return x+y;
}
int sum(double x, int y){
    cout<<"2"<<endl;
    return x+y;
}
double sum(double x, double y){
    cout<<"3"<<endl;
    return x+y;
}
 
int main() {
    cout<<sum(3,5);
    cout<<sum(3.7,5.8);
    return 0;
}