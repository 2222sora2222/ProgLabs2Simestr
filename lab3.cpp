#include <iostream>
#include <cmath>
using namespace std;
/*3 задача:** Вычисление среднеквадратичного значения массива. Формула дана.
 Нужно создать массив, заполнить его, затем вычислить сумму квадратов элементов, 
 разделить на количество и взять квадратный корень. Здесь важно правильно обработать ввод массива или его генерацию. .*/
double rms(double arr[], int n) {
    if (n == 0) return 0.0;
    double sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += arr[i] * arr[i];
    }
    return sqrt(sum / n);
}

int main() {
    int n;
    cout << "Введите количество элементов: ";
    cin >> n;
    double *arr = new double[n];
    for (int i = 0; i < n; ++i) {
        cout << "Элемент " << i+1 << ": ";
        cin >> arr[i];
    }
    cout << "Среднеквадратичное значение: " << rms(arr, n) << endl;
    delete[] arr;
    return 0;
}