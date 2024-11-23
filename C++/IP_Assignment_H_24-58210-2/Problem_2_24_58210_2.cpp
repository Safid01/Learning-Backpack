#include <iostream>
using namespace std;

int main() {
    char ch;
    cout << "Enter an Alphabet: ";
    cin >> ch;
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
    switch (ch)
    {
    case 'a':
    case 'A':
        cout << ch << " is a Vowel." << endl;
        break;
    case 'e':
    case 'E':
        cout << ch << " is a Vowel." << endl;
        break;
    case 'i':
    case 'I':
        cout << ch << " is a Vowel." << endl;
        break;
    case 'o':
    case 'O':
        cout << ch << " is a Vowel." << endl;
        break;
    case 'u':
    case 'U':
        cout << ch << " is a Vowel." << endl;
        break;
    default:
        cout << ch << " is a Consonant." << endl;
        break;
    }
} else {
    cout << ch << " is not a character." << endl;
}

    return 0;
}