#include <iostream>

using namespace std;

int Sum_1(int* pa)
{
    (*pa)++;
}

void Sum_2(int* val_1, int* val_2, int* val_3)
{
    *val_1 = 809;
    (*val_2)++;
    (*val_3)--;
}

int main()
{
    int a = 0;
    cout << a << endl;

    Sum_1(&a);
    cout << a << endl;

    cout << endl;

    int value_1 = 1, value_2 = 5, value_3 = 9;
    cout << "value_1 = " << value_1 << endl;
    cout << "value_2 = " << value_2 << endl;
    cout << "value_3 = " << value_3 << endl;

    Sum_2(&value_1, &value_2, &value_3);
    cout << endl;

    cout << "value_1 = " << value_1 << endl;
    cout << "value_2 = " << value_2 << endl;
    cout << "value_3 = " << value_3 << endl;
}
