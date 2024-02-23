#include <iostream>
#include <string>

using namespace std;

class Student{
    public:
        string name;
        string surname;
        int age;
        void Print(){
            cout << name << "\t";
            cout << surname << endl;
            cout << age << " лет" << endl;
        }
};

int main(){
    Student IT_Student;
    IT_Student.age = 19;
    IT_Student.name = "Alexey";
    IT_Student.surname = "Buharkin";

    IT_Student.Print();

}
