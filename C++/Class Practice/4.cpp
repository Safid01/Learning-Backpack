#include <iostream>
using namespace std;

class Triangle {
    private:
        int a, b, c;
    public:
        Triangle(int x, int y, int z){ // Constructor
            a = x;
            b = y;
            c = z;
        }
        void prntareaperimeter() {
            int area = (a*b)/2;
            int perimeter = a+b+c;
            cout << "Area: " << area << ", Perimeter: " << perimeter << endl;
        }
};
int main() {
    Triangle t(3, 4, 5);
    t.prntareaperimeter();
    return 0;
}