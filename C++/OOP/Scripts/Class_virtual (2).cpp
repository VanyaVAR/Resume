#include <iostream>
#include <string>

using namespace std;

class Person{
protected:
    string name;

public:

    Person(string _name) : name(_name){}

    virtual void GetInfo(){
        cout << "Name : "<< name << endl;
    }

};

class Student : public Person{
private:
    string group;

public: 

    Student(string _group, const string& name) : group(_group), Person(name){}

    void GetInfo() override {
        cout << "Student" << endl;
        Person::GetInfo();
        cout << "Group: " << group << endl << endl;
    }
};

class Teacher : public Person{
private:
    string object;

public:

    Teacher(string _object, const string &name) : object(_object), Person(name) {}

    void GetInfo() override{
        cout << "Teacher" << endl;
        Person::GetInfo();
        cout << "Object: " << object << endl;
    }
};

int main(){

    // string name;
    // cout << "Name: " << "\t";
    // cin >> name; cout << endl;

    // Person people(name);
    
    // Student student("IP-213", name);
    // Teacher teacher("Math", name);


    string name2;
    cout << "Name: " << "\t";
    cin >> name2; cout << endl;

    Person *people2 = new Person(name2);
    //people2 -> GetInfo();
    
    Student student2("IP-213", name2);
    Teacher teacher2("Math", name2);

    Person *pstudent = &student2;
    pstudent -> GetInfo();

    Person *pteacher = &teacher2;
    pteacher -> GetInfo();
}