#include <iostream>
#include <ctime>

using namespace std;

class MyClass{
private:
    int* array;
    int Size;

public:
    MyClass(int size){
        this -> Size = size;
        this -> array = new int [size];

        for (int i = 0; i < size; i++){
            array[i] = rand() % 15;
        }
        cout << "Вызван конструктор" << endl;
    }

    MyClass(const MyClass &other){          //В параметр передаем костантное значение типа MyClass по ссылке
        this -> Size = other.Size;          //Присваиваем переменной Size в данном конструкторе значение переменной Size из другого коструктора (из которого копируем)
        this -> array = new int [other.Size];

        for (int i = 0; i < other.Size; i++){
            this -> array[i] = other.array[i];      //Присваиваем в массив данного конструктора значения из массива копируемого конструктора
        }
        cout << "Вызван конструктор копирования" << endl;
    }

    void Print(int size){
        for (int i = 0; i < size; i++){
            cout << ' ' << array[i];
        }
        cout << endl;
    }

    ~MyClass(){
        delete[] array;         //Деструктор вызывается после завершения программы
    }
};

int main(){

    int size;
    cout << "Введите размер массива: ";
    cin >> size;

    MyClass First(size);
    First.Print(size);

    MyClass Second(First);
    Second.Print(size);
}
