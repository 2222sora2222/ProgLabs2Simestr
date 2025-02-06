#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

class Qn {
    vector<double> a, b;
public:
    Qn(const vector<double>& a, const vector<double>& b) : a(a), b(b) {}

    double evaluate(double x) const {
        double result = 0;
        for (size_t k = 0; k < a.size(); ++k) {
            result += a[k] * sin(k * x) + b[k] * cos(k * x);
        }
        return result;
    }

    Qn derivative(int order) const {
        vector<double> da = a, db = b;
        for (int i = 0; i < order; ++i) {
            for (size_t k = 0; k < da.size(); ++k) {
                double temp = da[k];
                da[k] = k * db[k];
                db[k] = -k * temp;
            }
        }
        return Qn(da, db);
    }
};

int main() {
    vector<double> a = {0, 1, 0}; // Пример коэффициентов
    vector<double> b = {1, 0, 1};
    Qn qn(a, b);
    double x = M_PI / 4;
    cout << "Qn(x) = " << qn.evaluate(x) << endl;
    Qn dqn = qn.derivative(1);
    cout << "dQn(x)/dx = " << dqn.evaluate(x) << endl;
    return 0;
}