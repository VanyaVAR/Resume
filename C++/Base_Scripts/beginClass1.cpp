#include <iostream>
#include <string>

using namespace std;

class Human{
    public:
        int age;
        string name;
        float weight;

};

void Print(Human secondHuman){

    cout << secondHuman.name << endl;
    cout << secondHuman.age << " лет" << endl;
    cout << secondHuman.weight << " кг" << endl;

}

int main(){

    Human firstHuman;  // firstHuman - это объект класса
    firstHuman.age = 19;
    firstHuman.name = "Ivan Varaksin";
    firstHuman.weight = 78.5;

    cout << firstHuman.name << endl;
    cout << firstHuman.age << " лет" << endl;
    cout <<firstHuman.weight << " кг" << endl;

    cout <<"-----------------------" << endl;

    Human secondHuman;
    secondHuman.age = 30;
    secondHuman.name = "Dmitriy";
    secondHuman.weight = 70;

    void Print(class Human secondHuman);
}
