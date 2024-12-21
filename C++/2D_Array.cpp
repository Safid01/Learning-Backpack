#include <iostream>
using namespace std;

int main () {
    int nums [3] [3] = {{1,2,6}, {4,3,8}, {6,1,5}};
    cout << nums [1] [2];
    cout << endl;
    for (int i = 0; i < 3; i++) {
        for (int k = 0; k < 3; k++) {
            cout << nums [i] [k];
        }
        cout << endl;
    }
    return 0;
}