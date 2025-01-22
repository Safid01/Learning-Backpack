#include<iostream>
using namespace std;

int main () {
    int n=8;
    int arr[8]={15,5,10,3,2,1,70,9};
    int num;
    cout<<"Odd number: ";
    for(int i=0; i<n; i++) 
    {
        if (arr[i] % 2 != 0) {
        cout<<arr[i]<<" ";
    }
  } 
return 0;
}