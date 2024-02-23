#include <iostream>
#include <string>

using namespace std;

class A{
public:
    A(){
        cout << "Вызов конструктора A" << endl;
    }

    ~A(){
        cout << "Вызов деструктора A" << endl;
    }
};

class B : public A{
public:
    B(){
        cout << "Вызов конструктора В" << endl;
    }

    ~B(){
        cout << "Вызов деструктора В" << endl;
    }
};

class C : public B{
public:
    C(){
        cout << "Вызов конструктора С" << endl;
    }

    ~C(){
        cout << "Вызов деструктора С" << endl;
    }
};

int main(){

    cout << "Создан объект А" << endl;
    A a;
    cout << endl;

    cout << "Создан объект B" << endl;
    B b;
    cout << endl;

    cout << "Создан объект C" << endl;
    C c;
    cout << endl;

    cout << endl;

    cout << "Порядок вызова деструкторов:" << endl;
}
