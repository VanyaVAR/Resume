#include <iostream>
#include <string>

using namespace std;


class Size;

class Input{
public:
    void InputSize(Size &House);
};

class Size{
    friend Input; // // // // // // // // // //
private:
    double lenght;
    double height;

public:
    Size(double lenght, double height){
        this -> lenght = lenght;
        this -> height = height;
    }
};

void Input::InputSize(Size &House){
    cout << "Что вы хотите узнать? Длину или Высоту? l/h" << "\t";
    string choice;
    cin >> choice;
    cout << endl;

    if (choice == "l"){
        cout << "Длинна - " << House.lenght << endl;
    }
    if (choice == "h"){
        cout << "Высота - " << House.height << endl;
    }
    if (choice != "h" && choice != "l"){
        cout << "error" << endl;
    }
}

int main(){

    Size House(7.95, 6.5);

    Input input;
    input.InputSize(House);
}
