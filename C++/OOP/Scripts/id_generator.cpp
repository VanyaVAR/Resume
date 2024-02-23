//Люди одинаковые, а id разные

#include <iostream>
#include <string>

using namespace std;

class People{
private:
    string Name;
    string Surname;
    int age;
    int id;

public:

    static int Counter;

    People(string Name, string Surname, int age){
        this->Name = Name;
        this->Surname = Surname;
        this->age = age;

        Counter ++;
        id = Counter;
    }

    void Print(){
        cout << "id = " << id << endl << endl;
        cout << "Name: " << Name << endl << "Surname: " << Surname << endl << "Age: " << age << endl;
        cout <<"-------------------------------------------------------------------" << endl;
    }

};

int People::Counter = 0;

int main(){

    string Name, Surname;
    int age;

    cout << "Enter Name: " << "\t";
    cin >> Name;
    cout << endl;
    cout << "Enter Surname: " << "\t";
    cin >> Surname;
    cout << endl;
    cout << "Enter Age: " << "\t";
    cin >> age;
    cout << endl;

    People First(Name, Surname, age);
    First.Print();

    People Second(Name, Surname, age);
    Second.Print();

    People Fird(Name, Surname, age);

    //First.Print();
    //Second.Print();
    Fird.Print();

}
