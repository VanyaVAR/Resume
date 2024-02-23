// добавление и удаление элементов из динамического массива

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

//ДОБАВЛЕНИЕ ЭЛЕМНТА В КОНЕЦ. *&arr - это указатель на ссылку. Для работы с массивом из main, а не с новым сделанным в этой функции. &size, тк нам нужно //поменять значение size в main через эту функцию
int push_back(int *&arr, int &size, int value){
    int* NewArr = new int [size + 1];   // size + 1, потому что новый массив будет больше на 1 элемент
    for (int i = 0; i < size; i++){
        NewArr[i] = arr[i];
    }
    NewArr[size] = value;   // [size], потому что size = 5, а новый массив размером в 6 элеметов
    size++;

    delete[] arr;

    arr = NewArr;
}

// УДАЛЕНИЕ ЭЛЕМЕНТА В КОНЦЕ
int pop_back(int *&arr, int &size, int value){
    int* newarr = new int [size - 1];
    for (int i = 0; i < size-1; i++){
        newarr[i] = arr[i];
    }

    size--;

    delete[] arr;
    arr = newarr;
}

int main(){

    int size = 5;
    int* arr = new int [size];

    cout << "Исходный массив" << endl;
    genArray(arr, size);
    printArray(arr, size);

    cout << endl << "Добавление элемента в конец:" << endl;

    push_back(arr, size, 55);
    printArray(arr, size);

    cout << endl << "Удаление последнего элемента с конца:" << endl;

    pop_back(arr, size, 0);
    printArray(arr, size);




    delete[] arr;
}
