#include<iostream>
using namespace std;

int main () {
    int n=8;
    int arr[8]={15,5,10,3,2,1,70,9};
    int sum = 0;
    for(int i=0; i<n; i++) 
    {
        sum = sum+arr[i];
    }
    cout<<"\nSum of the Array elements: "<<sum<<endl;
return 0;

}