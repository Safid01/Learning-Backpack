#include <iostream>
using namespace std;
 
int main()
{
    for(int i=1; i<=20; i++) {
        
        if (i%2!=0)
        cout<<i<<"\t";
    }
    int i=1;
    while(i<=20) i++ {
        
        if (i%2==0)
        cout<<i<<"\t";
    }
    return 0;
}