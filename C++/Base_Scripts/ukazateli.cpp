#include <iostream>

using namespace std;

int Change(int* pa, int* pb) // меняет местами значения
{
    int temp = *pa;
    *pa = *pb;
    *pb = temp;
}

int main()
{
    // для Change
    int a = 5;
    int b = 6;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    cout << "После выполнения функции" << endl;

    Change(&a, &b);
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    // Конец
    cout << "\n";
    cout << "\n";

    // Массивы и указатели
    cout << "Массивы" << endl;

    const int SIZE = 5;
    int arr[SIZE] = {2, 1, 43, 6, 3};
    cout << "arr = {";
    for (int i = 0; i < SIZE; i++) {
        cout << ' ' << arr[i];
    }
    cout << "}" << endl;
    cout << "Первый элемент массива = " << ' ' << arr[0] << endl;
    int* pArr = arr;
    cout << "Массив через указатель \t";
    for (int i = 0; i < SIZE; i++) {
        cout << ' ' << *(pArr + i);
    }
    cout << "\n";
    cout << "Первый элемент массива через указатель = " << *pArr << endl;
    cout << "Второй элемент массива через указатель = " << *(pArr + 1) << endl;

    // Конец
}
