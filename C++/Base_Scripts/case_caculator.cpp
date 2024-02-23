#include <iostream>

using namespace std;

int main()
{
    int a, b, res, test;
    cout << "Введите число а: ";
    cin >> a;
    cout << "Введите число b: ";
    cin >> b;
    cout << "Укажите дествие, которое хотите сделать над числами:" << endl <<
         "1. Сложение" << endl <<
         "2. Вычитание" << endl <<
         "3. Умножение" << endl <<
         "4. Деление" << endl;
    int c;
    cin >> c;
    switch (c) {
    case 1: {
        res = a + b;
        break;
    }

    case 2: {
        res = a - b;
        break;
    }
    case 4: {
        res = a / b;
        break;
    }
    case 3: {
        res = a * b;
        break;
    }
    default:{
        cout << "Я не знаю данного действия" << endl;
        test = 0;
    }
    }
    if (test != 0){
        cout << "Ответ: " << " " << res;
    }
}
