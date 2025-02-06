#include <iostream>
#include <cmath>
using namespace std;

double factorial(int n) {
    double result = 1;
    for (int i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}

double sinSeries(double x, int terms = 10) {
    double result = 0;
    for (int n = 0; n < terms; ++n) {
        result += pow(-1, n) * pow(x, 2 * n + 1) / factorial(2 * n + 1);
    }
    return result;
}

int main() {
    double x;
    cout << "Введите x: ";
    cin >> x;
    cout << "sin(x) = " << sinSeries(x) << endl;
    return 0;
}