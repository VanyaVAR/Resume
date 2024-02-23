#include <iostream>
#include <string>

using namespace std;

class Numbers{
public:
    int x = 5;
    int y = 6;
    void Print(){
        cout << "public: " << endl;

        cout << x << endl;
        cout << y << endl;

        cout << "--------------------" << endl;

        cout << "private: " << endl;

        cout << value_1 << endl;
        cout << value_2 << endl;

        cout << "--------------------" << endl;

        cout << "Функция из модификатора private:" << endl << endl;

        Print_private();

    }
private:
    int value_1 = 100;
    int value_2 = 512;
    void Print_private(){
        cout << "Print_private:" << endl;

        cout << value_1 << endl;
        cout << value_2 << endl;
    }
};

int main(){

    Numbers Rand;

    Rand.Print();

}
