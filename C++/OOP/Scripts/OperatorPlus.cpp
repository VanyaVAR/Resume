#include <iostream>

using namespace std;

class Math{
private:
    int x;
    int y;

public:
    Math(){
        int x = 0;
        int y = 0;
    }

    Math(int x,int y){
        this->x = x;
        this->y = y;
    }

    Math operator + (const Math & other){
        Math temp;
        temp.x = this->x + other.x;
        temp.y = this->y + other.y;
        return temp;
    }

    void Print(){
        cout << "x = " << x << "\t" << "y = " << y << endl;
    }
};

int main(){

    cout << "A" << endl;
    Math a(4,7);
    a.Print();

    cout << endl;

    cout << "B" << endl;
    Math b(3,9);
    b.Print();

    cout << endl;

    cout << "C '+'" << endl;
    Math c;
    c = a + b;
    c.Print();

    cout << endl;

    cout << "D '+'" << endl;
    Math d;
    d = a.operator+(b);
    d.Print();

}
