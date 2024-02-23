// деструктор нужен для очистки памяти после выполнения программы
#include <iostream>

using namespace std;

class MyClass{
private:
    int x;
    int y;

public:
    MyClass(){
        x = 2;
        y = 9;
        cout << "Вызван конструктор" << endl;
        cout << "x = " << x << "\t" << "y = " << y << endl;
    }
    ~MyClass(){
        cout << "Вызван деструктор";
    }
};

void Foo_MyClass(){
    cout << "Начало выполнения" << endl;
    MyClass a;
    cout << "Конец выполнения" << endl;
}

int main(){

    Foo_MyClass();


}
