#include <iostream>
#include <string>

using namespace std;

//class Human;
class Apple;

class Human{
public:
    void ShowApple(Apple &apple);
};

class Apple{
private:
    double weight;
    string color;

public:
    Apple(double weight, string color){

        this -> weight = weight;
        this -> color = color;
    }

    friend void Human::ShowApple(Apple &apple);
};

void Human::ShowApple(Apple &apple){
    cout << "weight = " << apple.weight << endl;
    cout << "color = " << apple.color << endl;
}

int main(){

    Apple apple(0.76, "red");

    Human human;
    human.ShowApple(apple);
}
