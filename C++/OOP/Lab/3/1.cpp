// 1. Инициализация матрицы с помощью:
// a. Конструктора по умолчанию для инициализации матрицы размерности 0
// b. Конструктора, принимающего одно целочисленное значение, для инициализации
// единичной квадратной матрицы указанной размерности. Единичная матрица — квадратная
// матрица, элементы главной диагонали которой равны единице, а остальные равны нулю.
// c. Конструктора, принимающего размерность матрицы, для инициализации матрицы
// указанной размерности.
// 3. Ввод значений матрицы с клавиатуры
// 4. Заполнение матрицы случайными числами
// 5 Вывод матрицы на экран.
// 6. Подсчет суммы элементов матрицы с выводом на экран (сумма сохраняется в
// соответствующем поле класса)
// 7. В деструкторе - корректное очищение динамической памяти (удаление матрицы)


// Вывести int** arr = new int* [size]; , чтоб он был в зоне видимости деструктора

#include <iostream>
#include <ctime>

using namespace std;

class Matrix{
private:
    int row, col;
    int size;
    //int sizeNull = 0;
    int Sum;
    int** arr;

public:

    void SetSize(int size){
        this->size = size;
    }

    void SetRow(int row){
        this->row = row;
    }

    void SetCol(int col){
        this->col = col;
    }

    Matrix(){
        int** arr = new int* [size];

        for (int i = 0; i < size; i++){
            arr[i] = new int [size];
        }
        cout << "Создана матрица размерностью 0" << endl;
    }

    Matrix(int size){
        int** arr = new int* [size];

        for (int i = 0; i < size; i++){
            arr[i] = new int [size];
        }
        for (int i = 0; i < size; i++){
            for (int j = 0; j < size; j++){
                arr[i][j] = 0;
            }
        }
        int step = 1;
        for (int i = 0; i < size; i++){
            for (int j = 0; j < size; j += step){
                arr[i][j] = 1;
            }
        }
    }

    Matrix(int row, int col){
        int **arr = new int* [row];

        for (int i = 0; i < row; i++){
            arr[i] = new int [col];
        }
        for (int i = 0; i < row; i++){
            for (int j = 0; j < col; j++){
                arr[i][j] = rand() % 100;
            }
        }
    }

    void Print(){
        for (int i = 0; i < row; i++){
            for (int j = 0; j < col; j++){
                cout << ' ' << arr[i][j];
            }
            cout << endl;
        }
        cout << endl;
    }

    void SumEl(){
        for (int i = 0; i < row; i++){
            for (int j = 0; j < col; j++){
                Sum += arr[i][j];
            }
        }
    }

    ~Matrix(){
        for (int i = 0; i < row; i++){
            delete[] arr[i];
        }
        delete[] arr;
    }


};

int main(){

    srand(time(NULL));

    int size;
    int row, col;








}
