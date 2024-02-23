/*Создать одномерный динамический массив типа int, заполнить его случайными
числами, вывести на экран. Размер массива необходимо хранить в первом элементе
массива. */
#include <ctime>
#include <iostream>

using namespace std;

int* genRandArray(int size, int maxValue)
{
    int *arr = new int [size];
    arr[0] = size;

    for (int i = 1; i <= size; i++){
        arr[i] = rand() % maxValue;
    }
    return arr;
}

 void print(int* arr)
{
    int SIZE = arr[0];
    cout << SIZE << ": ";
    for (int i = 1; i <= SIZE; i++){
    cout << ' ' << arr[i];
    }
}

int main()
{
    srand(time(NULL));
    int size = rand() % 10;

    int maxValue = 100;
    int* arr = genRandArray(size, maxValue);
    // int SIZE = sizeof(arr);
    // cout << SIZE << endl;
    // for (int i = 0; i < size; i++){
    //     cout << ' ' << arr[i];
    // }
    print(arr);
    delete[] arr;
    arr = nullptr;

}
