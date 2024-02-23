/*Матрица А имеет размерность 10x20. В матрице поменять местами
1-ю и 2-ю строки, 3-ю и 4-ю строки, …., 9-ю и 10-ю строки. */

#include <iostream>
#include <ctime>

using namespace std;

int main(){
    srand(time(NULL));

    const int ROW = 4;
    const int COL = 4;
    int arr [ROW][COL];
    int change [ROW];

    for (int i = 0; i < ROW; i++){
        for (int j = 0; j < COL; j++){
            arr[i][j] = rand() % 100;
        }
    }
    cout << "Первый массив" << endl;
    for (int i = 0; i < ROW; i++){
        for (int j = 0; j < COL; j++){
            cout << ' ' << arr[i][j];
        }
        cout << endl;
    }

    cout << endl;

    for (int i = 0; i < ROW; i = i + 2){
        for (int j = 0; j < COL; j++){
            change[j] = arr[i][j];
            arr[i][j] = arr[i+1][j];
            arr[i+1][j] = change[j];
        }

    }
    for (int i = 0; i < ROW; i++){
        for (int j = 0; j < COL; j++){
            cout << ' ' << arr[i][j];
        }
        cout << endl;
    }
}
