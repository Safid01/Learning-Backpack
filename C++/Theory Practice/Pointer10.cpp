#include <iostream>
using namespace std;
int main()
{
int a = 10, *pa, ra;
pa = &a;
ra = *pa;
cout << "a=" << ra;
return 0;
}