#include <iostream>
using namespace std;

int main() {
    int n=5;
    int nums[5];
    cout << "Enter 5 numbers: ";
    for (int i = 0; i < 5; i++) {
        cin >> nums[i];
    }
    int smallest, secondSmallest;
    int MaxNum = -99999;
    for (int i = 0; i < 5; i++) {
        if (nums[i] < smallest) {
            // Update secondSmallest before updating smallest
            secondSmallest = smallest;
            smallest = nums[i];
        } else if (nums[i] < secondSmallest) {
            // Update secondSmallest if smaller than current secondSmallest
            secondSmallest = nums[i];
        }
    }
    cout<<"Maximum value among the Array elements: "<<MaxNum<<endl;
    return 0;
}