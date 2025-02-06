
#include <iostream>
#include <cmath>
using namespace std;

struct Complex {
    double r; // Модуль
    double theta; // Аргумент

    Complex(double r = 0, double theta = 0) : r(r), theta(theta) {}

    Complex add(const Complex& other) const {
        double x1 = r * cos(theta);
        double y1 = r * sin(theta);
        double x2 = other.r * cos(other.theta);
        double y2 = other.r * sin(other.theta);
        double x = x1 + x2;
        double y = y1 + y2;
        return Complex(sqrt(x * x + y * y), atan2(y, x));
    }

    Complex subtract(const Complex& other) const {
        double x1 = r * cos(theta);
        double y1 = r * sin(theta);
        double x2 = other.r * cos(other.theta);
        double y2 = other.r * sin(other.theta);
        double x = x1 - x2;
        double y = y1 - y2;
        return Complex(sqrt(x * x + y * y), atan2(y, x));
    }

    Complex multiply(const Complex& other) const {
        return Complex(r * other.r, theta + other.theta);
    }

    Complex divide(const Complex& other) const {
        return Complex(r / other.r, theta - other.theta);
    }

    void print() const {
        cout << "r = " << r << ", theta = " << theta << endl;
    }
};

int main() {
    Complex c1(5, M_PI / 4);
    Complex c2(3, M_PI / 6);

    Complex sum = c1.add(c2);
    Complex diff = c1.subtract(c2);
    Complex prod = c1.multiply(c2);
    Complex quot = c1.divide(c2);

    cout << "Сумма: "; sum.print();
    cout << "Разность: "; diff.print();
    cout << "Произведение: "; prod.print();
    cout << "Частное: "; quot.print();

    return 0;
}