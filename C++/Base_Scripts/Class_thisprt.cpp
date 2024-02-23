#include <iostream>

using namespace std;

class Pointer{
private:
    int x = 0;
    int y = 0;

public:

    void SetX(int valuex){
        x = valuex
    }

    int GetX(){
        return x;
    }

    void SetY(int y){
        this->y = y;
    }

    int GetY(){
        return y;
    }
};

int main(){

    Pointer a;
    a.SetX(5);
    int A_x = a.GetX();

    a.SetY(999);
    int A_y = a.GetY();

    cout << "A_x = " << A_x << "\t" << "A_y = " <<A_y;

}
