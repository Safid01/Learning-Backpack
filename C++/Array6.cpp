#include<iostream>
using namespace std;

int main () {
    int n=8;
    int arr[8]={15,5,10,3,2,1,70,9};
    int num;
    for(int i=0; i<n; i++) 
    {
        if (arr[i] % 2 != 0) {
        cout<<"Odd number: "<<arr[i]<<endl;
    }
    
    }
    
return 0;

}