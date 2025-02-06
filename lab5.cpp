/***Четвертая задача:** Транспонирование матрицы, реализованной как двумерный динамический массив. 
 * Транспонирование — это замена строк на столбцы. Для динамического массива нужно правильно выделить и освободить память. 
 * Создать новую матрицу, где строки исходной становятся столбцами новой.*/
#include <iostream>
using namespace std;

int** transpose(int** matrix, int rows, int cols) {
    int** transposed = new int*[cols];
    for (int i = 0; i < cols; ++i) {
        transposed[i] = new int[rows];
        for (int j = 0; j < rows; ++j) {
            transposed[i][j] = matrix[j][i];
        }
    }
    return transposed;
}

int main() {
    int rows, cols;
    cout << "Введите количество строк и столбцов: ";
    cin >> rows >> cols;
    
    // Создание исходной матрицы
    int** matrix = new int*[rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new int[cols];
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = i * cols + j + 1; // Пример заполнения
        }
    }
    
    // Транспонирование
    int** transposed = transpose(matrix, rows, cols);
    
    // Вывод транспонированной матрицы
    cout << "Транспонированная матрица:\n";
    for (int i = 0; i < cols; ++i) {
        for (int j = 0; j < rows; ++j) {
            cout << transposed[i][j] << " ";
        }
        cout << endl;
    }
    
    // Освобождение памяти
    for (int i = 0; i < rows; ++i) delete[] matrix[i];
    for (int i = 0; i < cols; ++i) delete[] transposed[i];
    delete[] matrix;
    delete[] transposed;
    
    return 0;
}