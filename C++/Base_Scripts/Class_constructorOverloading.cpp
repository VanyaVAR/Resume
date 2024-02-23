#include <iostream>

using namespace std;

class Number{
private:
    int x;
    int y;

public:
    Number(){
        x = 0;
        y = 0;
    }

    Number(int valueX, int valueY){
        x = valueX;
        y = valueY;
    }

    Number(int valueX, bool random){
        x = valueX;
        random ? y = 1 : y = 0;
    }

    void Print(){
        cout << "x = " << x << "\t" << "y = " << y << endl << "---------------------------------" << endl;
    }
};

int main(){

    Number a;
    a.Print();

    Number b(6,10);
    b.Print();

    Number c(123, true);
    c.Print();

    Number d(321, false);
    d.Print();

}
