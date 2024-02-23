#include <iostream>

using namespace std;

class Number{
private:
    int x;
    int y;

public:
    Number(int valueX, int valueY){         //конструктор класса
        x = valueX;
        y = valueY;
    }

    void Print(){
        cout << "x = " << x << "\t" << "y = " << y << endl;
    }
};

int main(){

    Number a(5,1);      //указываем значения для конструктора
    a.Print();
}
