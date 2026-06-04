#include <iostream>
using namespace std;

class Volume {
    private:
        int length, breadth, height;
    public:
        Volume(int l, int b, int h) {
            length = l;
            breadth = b;
            height = h;
        }
        int calculate() {
            int volume = length * breadth * height;
            return volume;
        }
};
int main() {
    int l, b, h;
    cout << "Enter length: ";
    cin >> l;
    cout << "Enter breadth: ";
    cin >> b;
    cout << "Enter height: ";
    cin >> h;
    Volume box(l, b, h);
    cout << "Volume: " << box.calculate() << endl;
    return 0;
}