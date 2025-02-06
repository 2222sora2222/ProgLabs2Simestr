#include <iostream>
#include <cmath>
using namespace std;

class Complex {
public:
    double real, imag;

    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imag - other.imag);
    }

    Complex operator*(const Complex& other) const {
        return Complex(real * other.real - imag * other.imag, real * other.imag + imag * other.real);
    }

    void print() const {
        cout << "(" << real << ", " << imag << ")" << endl;
    }
};

class ComplexVector {
    Complex components[3];
public:
    ComplexVector(Complex c1, Complex c2, Complex c3) {
        components[0] = c1;
        components[1] = c2;
        components[2] = c3;
    }

    ComplexVector cross(const ComplexVector& other) const {
        Complex c1 = components[1] * other.components[2] - components[2] * other.components[1];
        Complex c2 = components[2] * other.components[0] - components[0] * other.components[2];
        Complex c3 = components[0] * other.components[1] - components[1] * other.components[0];
        return ComplexVector(c1, c2, c3);
    }

    void print() const {
        for (int i = 0; i < 3; ++i) {
            components[i].print();
        }
    }
};

int main() {
    Complex c1(1, 2), c2(3, 4), c3(5, 6);
    ComplexVector v1(c1, c2, c3);
    ComplexVector v2(c3, c2, c1);
    ComplexVector v3 = v1.cross(v2);
    v3.print();
    return 0;
}   