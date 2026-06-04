#include <iostream>
using namespace std;

int main() {
    int arr[8] = {1,5,6,2,3,4,7,8};

    int min = arr[0];
    int max = arr[0];

    for (int i=0; i<8; i++) {
        if (arr[i]<min)
            min = arr[i];
        if (arr[i]>max)
            max = arr[i];
    }

    cout << "Smallest: " << min << endl;
    cout << "Largest: " << max << endl;

    return 0;
}