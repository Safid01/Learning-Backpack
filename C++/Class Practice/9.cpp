#include <iostream>
using namespace std;

class Complex {
public:
    float real, imag;
    Complex(float r, float i){
        real = r;
        imag = i;
    }
    static Complex add(Complex a, Complex b) {
        return Complex(a.real + b.real, a.imag + b.imag);
    }
    static Complex subtract(Complex a, Complex b) {
        return Complex(a.real - b.real, a.imag - b.imag);
    }
    static Complex multiply(Complex a, Complex b) {
        return Complex(a.real*b.real - a.imag*b.imag, a.real*b.imag + a.imag*b.real);
    }
    void print() {
        cout << real << " + " << imag << "i" << endl;
    }
};
int main() {
    float r1, i1, r2, i2;
    cout << "Enter first complex (real imaginary): ";
    cin >> r1 >> i1;
    cout << "Enter second complex (real imaginary): ";
    cin >> r2 >> i2;
    
    Complex c1(r1, i1), c2(r2, i2);
    
    cout << "Sum: ";
    Complex::add(c1, c2).print();
    cout << "Difference: ";
    Complex::subtract(c1, c2).print();
    cout << "Product: ";
    Complex::multiply(c1, c2).print();
    return 0;
}