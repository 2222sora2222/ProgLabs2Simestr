#include <iostream>
#include <cmath>
using namespace std;
/*2 задача:** Вычисление среднеквадратичного значения массива. 
Формула дана. Нужно создать массив, заполнить его, затем вычислить сумму квадратов элементов,
 разделить на количество и взять квадратный корень. Здесь важно правильно обработать ввод массива или его генерацию..*/
int main() {
    double V, alpha, gamma, m, t_total, dt;
    cout << "Введите начальную скорость (V): ";
    cin >> V;
    cout << "Введите угол (alpha в градусах): ";
    cin >> alpha;
    alpha = alpha * M_PI / 180.0; // Переводим в радианы
    cout << "Введите коэффициент сопротивления (gamma): ";
    cin >> gamma;
    cout << "Введите массу (m): ";
    cin >> m;
    cout << "Введите общее время (t_total): ";
    cin >> t_total;
    cout << "Введите шаг времени (dt): ";
    cin >> dt;

    double k = gamma / m;
    double x = 0, y = 0;
    double v = V * cos(alpha); // Начальная горизонтальная скорость
    double u = V * sin(alpha); // Начальная вертикальная скорость

    for (double t = 0; t <= t_total; t += dt) {
        // Дискретная модель
        double x_next = x + v * dt;
        double y_next = y + u * dt;
        double v_next = v - k * v * dt;
        double u_next = u - 9.81 * dt - k * u * dt;

        // Точное решение для сравнения
        double x_exact = (V * cos(alpha) / k) * (1 - exp(-k * t));
        double y_exact = (9.81/k + V * sin(alpha)) / k * (1 - exp(-k * t)) - (9.81 * t)/k;

        cout << "Время: " << t << endl;
        cout << "Дискретная модель: x=" << x << ", y=" << y << endl;
        cout << "Точное решение:    x=" << x_exact << ", y=" << y_exact << endl << endl;

        // Обновляем значения
        x = x_next;
        y = y_next;
        v = v_next;
        u = u_next;
    }
    return 0;
}