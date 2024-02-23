#include <ctime>
#include <iostream>

using namespace std;

int main()
{
    srand(time(NULL));
    const int SIZE = 5;
    int arr[SIZE];

    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand() % 15;
    }
    for (int i = 0; i < SIZE; i++) {
        cout << ' ' << arr[i];
    }

    cout << endl;

    int* pArr;
    pArr = arr;
    cout << " pArr = arr  =  " << pArr << endl;
    // pArr = &arr;  Не работает
    pArr = &arr[0];
    cout << " pArr = &arr[0]  =  " << pArr << endl;
    //*pArr = arr;  Не работает
    //*pArr = &arr;  Не работает
    *pArr = arr[0];
    cout << " *pArr = arr [0]  =  " << pArr << endl;
    cout << " *pArr = arr [0]  =  " << *pArr << endl;
}
