#include <iostream>
#include <ctime>

using namespace std;

int main(){
    srand(time(NULL));
    int SIZE;
    cout << "Введите размер массива: ";
    cin >> SIZE;

    int *arr = new int [SIZE];

    for (int i = 0; i < SIZE; i++){
        arr[i] = rand() % 15;
    }

    for (int i = 0; i < SIZE; i++){
        cout << ' ' << arr[i];
    }

    delete [] arr;
}
