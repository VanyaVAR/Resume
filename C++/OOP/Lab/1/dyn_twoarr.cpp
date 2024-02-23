/*Создать двумерный динамический массив типа int, заполнить его случайными числами,
вывести на экран. Размер каждого одномерного массива – произвольный (матрица не
обязана быть прямоугольной). Количество строк матрицы хранить в отдельной
переменной в main.
Функции, реализованные в первом задании, рекомендуется использовать во втором.*/

#include <iostream>
//#include <ctime>

using namespace std;

int** genRandMatrix(int size, int maxValue){
    int** matrix = new int* [size];
    for (int i = 0; i < size; i++){
        int size_row = rand() % 10;
        matrix[i] = new int [size_row];
        matrix[i][0] = size_row;
        for (int j = 1; j < size_row; j++){
            matrix[i][j] = rand() % maxValue;
        }
    }
    return matrix;
}

void print(int** matrix){

    for (int i = 0; matrix[i] != nullptr; i++){
        cout << ' ' << *matrix[i] << ":";
        int *p_row = matrix[i];
        int size_row = p_row[0];
        for (int j = 0; j < size_row; j++){
            cout << ' ' << matrix[i + 1][j];
        }
        cout << endl;
    }
}

int main(){
    srand(time(NULL));
    int size = rand() % 10;
    int maxValue = 100;
    int** matrix = genRandMatrix(size, maxValue);
    int count = 0;
    for(int i = 0; i < size - 1; i++){
        count++;
    }
    cout << count << endl;
    print(matrix);

    for (int i = 0; i < size; i++){

        delete[] matrix[i];
    }
    delete[] matrix;

}
