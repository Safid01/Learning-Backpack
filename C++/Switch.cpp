#include<iostream>
#include<cmath>
using namespace std;

int main() {

    char choice;
    cin>>choice;
    switch (choice) {
        case 'Y' :
           cout << "Yes";
           break;
        case 'M' :
           cout << "Maybe";
           break;
        case 'N' :
           cout << "No";
           break;
    }

        return 0;
}