#include<iostream>
using namespace std;

int main () {
    int n=8;
     int arr[8]={15,5,10,3,2,1,7,9};
     cout<<"Printed the Array element: "<<endl;
     for (int i=0; i<n; i++)
     {
        cout<<"Input for index - "<<i<<": ";
        cin>>arr[i];
     }
        cout<<"Printed the Array element: "<<endl;
     for (int i=0; i<8; i++)
     {
        cout<<arr[i]<<"  ";
     }
     
return 0;

}