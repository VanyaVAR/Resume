#include <ctime>
#include <iostream>

using namespace std;

int main()
{
    const int SIZE = 5;
    int arr[SIZE];
    srand(time(NULL));

    cout << "Обычное заполнение массива \t";
    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand() % 100;
    }
    //Вывод
    cout << "arr = [";
    for (int i = 0; i < SIZE; i++) {
        cout << " " << arr[i];
    }
    cout << " ]";

    cout << endl;
    cout << endl;

    cout << "Массив с циклом коллекции \t";
    for (int& i : arr) {
        i = rand() % 100;
    }
    //Вывод
    cout << "arr = [";
    for (int i = 0; i < SIZE; i++) {
        cout << " " << arr[i];
    }
    cout << " ]";
}
