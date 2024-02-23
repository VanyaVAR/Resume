#include <iostream>

using namespace std;

class A{
public:
    A(){
        cout << "A()" << endl;
    }
    virtual ~A(){
        cout << "~A()" << endl;
    }
};

class B : public A{
public:
    B(){
        cout << "B()" << endl;
    }
    ~B() override {
        cout << "~B()" << endl;
    }
};

int main(){

    // A a;
    // B b;

    cout << "A* pa = new B" << endl;
    A* pa = new B;
    delete pa;
    cout << "-----------" << endl;
    cout << "B* pb = new B" << endl;
    B* pb = new B;
    delete pb;
    cout << "-----------" << endl;
    cout << "A* ppa = new A" << endl;
    A* ppa = new A;
    delete ppa;

}