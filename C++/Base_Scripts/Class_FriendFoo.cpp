#include <iostream>
#include <string>

using namespace std;

class Point{

private:
    int x;
    int y;
    int z;

public:
    Point(){

    }

    int GetX(){
        return x;
    }
    int GetY(){
        return y;
    }
    int GetZ(){
        return z;
    }

    void SetX(int x){
        this -> x = x;
    }
    void SetY(int y){
        this -> y = y;
    }
    void SetZ(int z){
        this -> z = z;
    }

    void Print(){
        cout << "***Ваши данные:" << endl;
        cout << "***" << "\t" << "x = " << x << "\t" << "y = " << y << "\t" << "z = " << z << "\t" << "***" << endl;
    }

    friend void ChangeX(Point &First);  //Говорим классу, что эти функции могут иметь доступ к приветным переменным класса
    friend void ChangeY(Point &First);
    friend void ChangeZ(Point &First);
};

void ChangeX(Point &First){
    cout << "***Введите измененную переменную X" << "\t";
    cout << "x = ";
    int valueX;
    cin >> valueX;
    First.x = valueX;
    cout << endl;
}

void ChangeY(Point &First){
    cout << "***Введите измененную переменную Y" << "\t";
    cout << "y = ";
    int valueY;
    cin >> valueY;
    First.y = valueY;
    cout << endl;
}

void ChangeZ(Point &First){
    cout << "***Введите измененную переменную Z" << "\t";
    cout << "z = ";
    int valueZ;
    cin >> valueZ;
    First.z = valueZ;
    cout << endl;
}

int main(){

    Point First;
    int x, y, z;

    cout << "***Установите точки на осях!" << endl;
    cout << "x = ";
    cin >> x;
    First.SetX(x);
    cout << endl;

    cout << "y = ";
    cin >> y;
    First.SetY(y);
    cout << endl;

    cout << "z = ";
    cin >> z;
    First.SetZ(z);
    cout << endl;

    First.Print();
    cout << endl;

    cout << "***Хотите поменять данные? y/n" << "\t";
    string choice;
    cin >> choice;

    if (choice == "y"){

        cout << "Сколько переменных вы хотите поменять?" << "\t";
        int value;
        cin >> value;
        cout << endl;

        for(int i = 0; i < value; i++){

            cout << "***Выберите действие:" << endl;
            cout << "* (1) Поменять X" << endl;
            cout << "* (2) Поменять Y" << endl;
            cout << "* (3) Поменять Z" << endl;

            cout << "Ответ: ";
            int change;
            cin >> change;
            cout << endl;

            switch(change){
            case 1: {
                ChangeX(First);
                break;
            }
            case 2: {
                ChangeY(First);
                break;
            }
            case 3: {
                ChangeZ(First);
                break;
            }
            default: {
                cout << "Не пон" << endl;
            }
            }

        }
    }
    else{
        return 0;
    }


    First.Print();



}
