#include <iostream>
#include <string>

using namespace std;

class People{
private:
    string name;

public:
    void SetName(string name){
        this->name = name;
    }

    string GetName(){
        return name;
    }
};

class Student : public People{
private:
    string group;

public:
    void SetGroup(string group){
        this->group = group;
    }

    string GetGroup(){
        return group;
    }
};

class ProgressStudent : public Student{
private:
    int mark;

public:
    void SetMark(int mark){
        this->mark = mark;
    }

    int GetMark(){
        return mark;
    }
};

class Teacher : public People{
private:
    string subject;

public:

    void SetSub(string subject){
        this->subject = subject;
    }

    string GetSub(){
        return subject;
    }
};

int main(){

    Teacher Teacher;
    Teacher.SetName("Hramova Tatiana Victorovna");
    Teacher.SetSub("Math");

    cout << "Teacher - ";
    cout << Teacher.GetName() << "\t" << "subject - " << Teacher.GetSub();

    cout << "-----------------------------------------------" << endl << endl;

    Student Student;
    Student.SetName("Varaksin Ivan Aleksandrovich");
    Student.SetGroup("IP-213");

    //Можно дописать










}
