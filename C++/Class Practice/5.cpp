#include <iostream>
using namespace std;

class Rectangle {
    int length, breadth;
public:
    Rectangle(int l, int b) { // Constructor
        length = l;
        breadth = b;
    }
    int Area() { // Member function
          int area = length * breadth;
        return area;
    }
};
int main() {
    Rectangle r1(4, 5), r2(5, 8);
    cout << "Area 1: " << r1.Area() << endl;
    cout << "Area 2: " << r2.Area() << endl;
    return 0;
}