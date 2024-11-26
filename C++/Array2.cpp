#include<iostream>
using namespace std;

int main () {
    int n=8;
     int arr[8];
     for (int i=0; i<n; i++)
     {
        cout<<"Input for index - "<<i<<": ";
        cin>>arr[i];
     }
        cout<<"Printed the Array element: ";
     for (int i=0; i<8; i++)
     {
        cout<<arr[i]<<"  ";
     }
     
return 0;

}