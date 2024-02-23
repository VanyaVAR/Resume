#include <iostream>
#include <string>

using namespace std;

class Apple{
private:
    int weight;
    string color;

public:

    static int Count_AmontApple; // Объявление статической переменной

    Apple(int weight, string color){
        this->weight = weight;
        this->color = color;

        Count_AmontApple ++; // Подсчет яблок
    }
    void Print(){
        cout << "weight = " << weight << "\t" << "color - " << color << endl;
    }
};

int Apple::Count_AmontApple = 0; // Инициализация статической переменной

int main(){

    Apple FirstApple(150, "red");
    FirstApple.Print();
    cout << "Количество яблок на данном этапе: " << FirstApple.Count_AmontApple << endl << endl;

    Apple SecondApple(120, "green");
    SecondApple.Print();
    cout << "Количество яблок на данном этапе: " << FirstApple.Count_AmontApple << endl << endl;

    Apple FirdApple(100, "yellow");
    FirdApple.Print();
    cout << "Количество яблок на данном этапе: " << FirstApple.Count_AmontApple << endl << endl;

}
