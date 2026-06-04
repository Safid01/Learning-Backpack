#include <iostream>
using namespace std;

class Triangle {
    public:
        void prntareaperimeter(int a, int b, int c) { //Member function
            int area = (a*b)/2;
            int perimeter = a+b+c;
            cout << "Area: " << area << ", Perimeter: " << perimeter << endl;
        }
};
int main() {
    Triangle t;
    t.prntareaperimeter(3, 4, 5);
    return 0;
}