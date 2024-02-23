#include <iostream>
#include <ctime>

using namespace std;

int main(){
    srand(time(NULL));
    const int SIZE = 10;
    int arr[SIZE];

    for (int i = 0; i < SIZE; i++){
        arr[i] = rand() % 100;
    }

    cout << "Массив" << endl;
    for (int i = 0; i < SIZE; i++){
        cout << ' ' << arr[i];
    }

    cout << endl;
    int min = arr[0];
    int max = arr[0];

    //Нахождение минимума массива
    for (int i = 1; i < SIZE; i++){
        if (min > arr[i]) min = arr[i];
    }
    cout << "Минимум: " << min << endl;

    //Нахождение максимума массива
    for (int i = 1; i < SIZE; i++){
        if (max < arr[i]) max = arr[i];
    }
    cout << "Максимум: " << max << endl;

    //Нахождение максимума массива
    for (int i = 0; i < SIZE; i++){
        if (max < arr[i]){
            max = arr[i];
        }
    }
    cout << "Максимум 2 : " << max;
}
