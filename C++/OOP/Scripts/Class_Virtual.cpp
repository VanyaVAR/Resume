#include <iostream>
#include <string>

using namespace std;

class Human{
private:
    string name;
    string surname;

public:
    void Set_Name(string name){
        this -> name = name;
    }

    void Set_Surname(string surname){
        this -> surname = surname;
    }
    virtual void Get_Info(){
        cout << name << ' ' << surname << endl;
    }
};

class Student : public Human{
private:
    int age;
    string mark;

public:

    void Set_Age(int age){
        this -> age = age;
    }

    void Get_Info() override{
        Human::Get_Info();
        cout << "Age: " << endl;

    }
};

class Instructor : public Human{
private:
    string car;

public:
    void Get_Info() override{
        Human::Get_Info();
    }
};

class TheoryStudent : public Student{
private:


public:
    void Get_Info() override{
        Human::Get_Info();
    }
};

class PracticStudent : public Student{
private:

public:
    void Get_Info() override{
        Human::Get_Info();
    }
};

int main(){


}