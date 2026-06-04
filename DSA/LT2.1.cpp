#include <iostream>
using namespace std;

int main() {
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int sum = 0, count = 0;

    cout << "Odd-indexed Elements: ";
    for(int i=1; i<10; i=i+2) {
        cout << arr[i] << " ";
        sum += arr [i];
        count += 1;
    }

    float avg = sum/count;

    cout << "\nSum: " << sum << endl;
    cout << "Average: " << avg << endl;

    if(sum % 2 == 0)
        cout << "Sum is Even" << endl;
    else
        cout << "Sum id Odd" << endl;

    return 0;
}