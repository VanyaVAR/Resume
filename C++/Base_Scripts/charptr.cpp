#include <ctime>
#include <iostream>

using namespace std;

void Print_1(char* arr, int SIZE)
{
    for (int i = 0; i < SIZE; i++) {
        cout << ' ' << arr[i];
    }
}

void Print_2(char* q, int SIZE)
{
    for (int i = 0; i < SIZE; i++) {
        cout << ' ' << q[-i];
    }
}

int main()
{
    srand(time(NULL));
    const int SIZE = rand() % 20;
    char arr[SIZE];
    char* p;
    char* q;

    p = arr;
    p[0] = 'A';
    q = &arr[SIZE - 1];

    // Цикл для кодировки следующего элемента в массиве
    // Без него выведится только первая буква А
    while (p != q) {
        p++;
        *p = p[-1] + 1;
    }

    Print_1(arr, SIZE);
    cout << endl;
    Print_2(q, SIZE);
}
