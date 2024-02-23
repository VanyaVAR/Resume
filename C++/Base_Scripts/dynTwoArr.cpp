#include <iostream>
#include <ctime>

using namespace std;

int main(){
    srand(time(NULL));
    int row;
    int col;
    cout << "Введите колличество строк: ";
    cin >> row;
    cout << "Введите колличество столбцов: ";
    cin >> col;

    int **arr = new int* [row];

    for (int i = 0; i < row; i++){
        arr[i] = new int [col];
    }

    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            arr[i][j] = rand() % 20;
        }
    }

    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            cout << ' ' << arr[i][j];
        }
        cout << endl;
    }

    for (int i = 0; i < row; i++){
        delete[] arr[i];
    }
    delete[] arr;
}
