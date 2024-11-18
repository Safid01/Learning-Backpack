#include<iostream>
using namespace std;

int main () {
    char str[]={'S','a','f','i','d'};
    int n = sizeof(str)/sizeof(str[0]);
    for (int i=0; i<n; i++)
     {
        cout<<str[i];
     }
     cout<<endl;
     cout<<str<<endl;
     
     char str1[] = "Safid Hasan";
     cout<<str1<<endl;
return 0;

}