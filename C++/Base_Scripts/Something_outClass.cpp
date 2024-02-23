#include <iostream>

using namespace std;

class MyClass{
private:
    int x;
    int y;
    int z;

public:
    MyClass(int x, int y, int z);

    void Print();
};

MyClass::MyClass(int x, int y, int z){
    this->x = x;
    this->y = y;
    this->z = z;
}

void MyClass::Print(){
    cout << x << "\t" << y << "\t" << z << endl;
}

int main(){

    MyClass Value(5,6,2);
    Value.Print();
}
