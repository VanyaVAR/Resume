#include <iostream>
#include <string>

using namespace std;

class Number{
private:
    int x;
    int y;
    string z;

public:
    int GetX(){
        return x;
    }

    void SetX(int valueX){
        x = valueX;
    }

    int GetY(){
        return y;
    }

    int GetDoubleY(){
        return y*2;
    }

    void SetY(int valueY){
        y = valueY;
    }

    string GetZ(){
        return z;
    }

    void SetZ(string valueZ){
        z = valueZ;
    }

    void PrintNumber(){
        cout << "x = " << x << "\t" << "y = " << y << endl;
    }

    void PrintString(){
        cout << z << endl;
    }


};

int main(){

    Number Value;
    Value.SetX(6);
    Value.SetY(15);
    Value.SetZ("Hello, it's value Z");

    Value.PrintNumber();
    Value.PrintString();

    int X, Y;
    string Z;

    X = Value.GetX();
    Y = Value.GetY();
    Z = Value.GetZ();

    cout << X << endl;
    cout << Y << endl;
    cout << Z << endl;

}
