#include <iostream>
using namespace std;
int main()
{
int track[] = { 10, 20, 30, 40 }, *striker;
striker = track;
track[1] += 30;
cout << "Striker>" << *striker << " ";
*striker -= 10;
striker++;
cout << "Next@" << *striker << " ";
striker += 2;
cout << "Last@" << *striker << " ";
cout << "Reset To" << track[0] << " ";
return 0;
}