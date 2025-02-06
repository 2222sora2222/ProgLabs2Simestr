#include <iostream>
#include <cmath>
using namespace std;

class EquationSolver {
public:
    static void solve(double a, double b, double c) {
        double R = sqrt(a * a + b * b);
        if (c > R) {
            cout << "Решений нет" << endl;
            return;
        }
        double alpha = atan2(b, a);
        double x1 = asin(c / R) - alpha;
        double x2 = M_PI - asin(c / R) - alpha;
        cout << "x1 = " << x1 << ", x2 = " << x2 << endl;
    }
};

int main() {
    double a, b, c;
    cout << "Введите a, b, c: ";
    cin >> a >> b >> c;
    EquationSolver::solve(a, b, c);
    return 0;
}