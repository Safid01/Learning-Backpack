#include <iostream>
using namespace std;

class Area {
    int length, breadth;
public:
    void setDim(int l, int b) {
        length = l;
        breadth = b;
    }
    int getArea() {
        int area = length * breadth;
        return area;
    }
};
int main() {
    Area a;
    int l, b;
    cout << "Enter length: ";
    cin >> l;
    cout << "Enter breadth: ";
    cin >> b;
    a.setDim(l, b);
    cout << "Area: " << a.getArea() << endl;
    return 0;
}