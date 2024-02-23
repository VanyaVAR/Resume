#include <iostream>
#include <string>

using namespace std;

class A{
private:
    string msg;

public:
    A() : msg("empty A msg"){

    }

    A(string msg){
        this->msg = msg;
    }

    void Print(){
        cout << msg << endl;
    }
};

class B : public A{
public:
    B() : A("new AB empty msg"){

    }

};

class C : public A{
public:
    C(){

    }
};

int main(){

    cout << "Вызов пустого А" << endl;
    A a1;
    a1.Print();
    cout << endl;

    cout << "Вызов непустого А" << endl;
    A a2("Not empty A");
    a2.Print();
    cout << endl;

    cout << "Вызов пустого В" << endl;
    B b;
    b.Print();
    cout << endl;

    cout << "Вызов пустого C" << endl;
    C c;
    c.Print();
}
