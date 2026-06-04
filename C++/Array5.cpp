#include<iostream>
using namespace std;

int main () {
    int n=8;
    int arr[8]={15,5,10,3,2,1,70,9};
    int MaxNum = -99999;
    for(int i=0; i<n; i++) 
    {
        if (MaxNum<arr[i])
        {
            MaxNum=arr[i];
        }
    }
    cout<<"Maximum value among the Array elements: "<<MaxNum<<endl;
return 0;

}