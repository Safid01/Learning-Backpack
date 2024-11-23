#include <iostream>
using namespace std;

int main() {
    int nums[] = {5, 8, 2, 1, 0};

    for (int i = 0; i < 5; i++) {
        for (int j = i; j < 5; j++) {
            cout << nums[j] << " ";
        }
        cout << endl;
    }

    return 0;
}