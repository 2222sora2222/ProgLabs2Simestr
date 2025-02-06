/*4 задача:** Поиск экстремального элемента массива (максимума или минимума). 
 * Массив заполняется случайными числами. Нужно создать функцию, которая принимает массив и параметр, 
 * указывающий, искать максимум или минимум. 
 * Затем пройти по всем элементам, сравнивая их.*/
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int findExtreme(int arr[], int n, bool findMax) {
    if (n == 0) return -1; // Ошибка
    int extreme = arr[0];
    for (int i = 1; i < n; ++i) {
        if ((findMax && arr[i] > extreme) || (!findMax && arr[i] < extreme)) {
            extreme = arr[i];
        }
    }
    return extreme;
}

int main() {
    srand(time(0));
    int n;
    cout << "Введите размер массива: ";
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; ++i) {
        arr[i] = rand() % 100; // Числа от 0 до 99
    }
    bool choice;
    cout << "Найти максимум (1) или минимум (0)? ";
    cin >> choice;
    int result = findExtreme(arr, n, choice);
    cout << "Результат: " << result << endl;
    delete[] arr;
    return 0;
}