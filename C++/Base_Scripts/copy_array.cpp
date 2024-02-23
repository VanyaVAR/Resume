#include <iostream>
#include <cstdlib>

using namespace std;

int genArray(int* const arr, const int size){

    for (int i = 0; i < size; i++){
        arr[i] = rand() % 10;
    }
}

int printArray(int* const arr, const int size){

    for (int i = 0; i < size; i++){
        cout << ' ' << arr[i];
    }
}

int main(){
    int size = 10;
    int* arr = new int [size];
    int* copy_arr = new int [size];

    genArray(arr, size);
    cout << "arr = ";
    printArray(arr, size);
    cout << endl;
    genArray(copy_arr, size);
    cout << "copy_arr = ";
    printArray(copy_arr, size);

    cout << endl;

    /*cout << "Так выглядит неправильное копирование массива, которое приводит к утечке памяти :" << endl;
    copy_arr = arr;

    printArray(arr, size);
    cout << endl;
    printArray(copy_arr, size);*/

    cout << "Правильное копирование массива" << endl;

    delete[] copy_arr;

    copy_arr = new int [size];
    for (int i = 0; i < size; i++){
        copy_arr[i] = arr[i];
    }

    cout << "arr = ";
    printArray(arr, size);
    cout << endl;
    cout << "copy_arr = ";
    printArray(copy_arr, size);

    delete[] copy_arr;
    delete[] arr;
}
