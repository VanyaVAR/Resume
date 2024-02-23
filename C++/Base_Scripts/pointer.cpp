#include <iostream>
#include <ctime>

using namespace std;

int main(){
    const int SIZE = 5;
    int arr[SIZE];
    srand(time(NULL));

    cout << "Mассив \t";
    for (int i = 0; i < SIZE; i++){
        arr[i] = rand() % 100;
    }

    //Вывод
    for (int i = 0; i < SIZE; i++){
        cout << ' ' << arr[i];
    }

    cout << endl;

    int* p;
    p = &arr[0];
    *p = 228;
    cout << "Новый массив\t";
    for (int i = 0; i < SIZE; i++){
        cout << ' ' << arr[i];
    }


}
