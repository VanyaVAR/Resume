#include <iostream>

using namespace std;

int main(){

    int size = 10;
    int *arr = new int [size];
    int *first_p = arr;
    int *last_p = &arr[size];// ссылается на след. элемент после массива. Так делать можно

    cout << "Колличество эл-тов динамического массива = " <<last_p - first_p;
    delete[] arr;
}
