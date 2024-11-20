#include <iostream>
using namespace std;

int main() {
    int nums[] = {5, 8, 3, 1, 6};

    for (int i = 0; i < 5; i++) {
        for (int j = i; j < 5; j++) {
            cout << nums[j] << " ";
        }
        cout << endl;
    }

    return 0;
}
