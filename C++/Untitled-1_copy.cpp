#include <iostream>
using namespace std;

int main() {

    int N;
    int ratings[20];

    cout << "Enter number of customer ratings (N <= 20): ";
    cin >> N;

    cout << "Enter " << N << " ratings:\n";
    for (int i = 0; i < N; i++)
        cin >> ratings[i];

    cout << "\nAll Ratings: ";
    for (int i = 0; i < N; i++)
        cout << ratings[i] << " ";
    cout << "\n";

    int target, index = -1;
    cout << "\nEnter rating to search: ";
    cin >> target;

    for (int i = 0; i < N; i++) {
        if (ratings[i] == target) {
            index = i;
            break;
        }
    }

    if (index != -1)
        cout << target << " Found at index " << index << ".\n";
    else
        cout << target << " Not found.\n";

    int maxRating = ratings[0];
    for (int i = 1; i < N; i++) {
        if (ratings[i] > maxRating)
            maxRating = ratings[i];
    }

    cout << "Highest Rating: " << maxRating << "\n";

    return 0;
}