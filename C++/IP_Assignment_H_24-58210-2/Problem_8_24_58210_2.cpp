#include <iostream>
using namespace std;

int main() {
    int id[5] = {5, 8, 3, 1, 6};
    int n = sizeof(id) / sizeof(id[0]);
    for (int i = 0; i < n; i++) {
        int limit = id[i];
        for (int j = 1; j <= limit; j++) {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}