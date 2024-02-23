#include <iostream>
#include <ctime>

using namespace std;

int main(){
    srand(time(NULL));
    const int ROW = 3;
    const int COL = 4;

    cout << "Arr_One :" << endl;
    int Arr_One [ROW][COL] { {2,32,1,65}, {8,45,842,54}, {123,53,6,7} };
    for (int i = 0; i < ROW; i++){
        for (int j = 0; j < COL; j++){
            cout << ' ' << Arr_One[i][j];
        }
        cout << endl;
    }

    cout << endl;

    //Другой способ инициализации двумерного массива
    cout << "Arr_Two :" << endl;
    int Arr_Two [ROW][COL]{
        {2,32,1,65},
        {8,45,842,54},
        {123,53,6,7}
    };
    for (int i = 0; i < ROW; i++){
        for (int j = 0; j < COL; j++){
            cout << ' ' << Arr_Two[i][j];
        }
        cout << endl;
    }

    cout << endl;

    //Заполнение двумeрного массива случайными числами
    cout << "Arr_Three :" << endl;
    int Arr_Three[ROW][COL];
    for (int i = 0; i < ROW; i++){
        for (int j = 0; j < COL; j++){
            Arr_Three[i][j] = rand() % 100;
        }
    }
    for (int i = 0; i < ROW; i++){
        for (int j = 0; j < COL; j++){
            cout << ' ' << Arr_Three[i][j];
        }
        cout << endl;
    }
}
