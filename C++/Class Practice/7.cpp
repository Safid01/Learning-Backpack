#include <iostream>
using namespace std;

class Area {
private:
    int length, breadth;
public:
    Area(int l, int b) {
        length = l;
        breadth = b;
    }
    int returnArea() {
        int area = length * breadth;
        return area;
    }
};
int main() {
    int l, b;
    cout << "Enter length: ";
    cin >> l;
    cout << "Enter breadth: ";
    cin >> b;
    Area a(l, b);
    cout << "Area: " << a.returnArea() << endl;
    return 0;
}