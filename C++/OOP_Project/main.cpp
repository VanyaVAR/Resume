#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int MAX_PERSONS = 100;

class Person {
protected:
    string name;
    string surname;
    int birthYear;

public:
    Person(const string& _name, const string& _surname, int _birthYear)
        : name(_name), surname(_surname), birthYear(_birthYear) {}

    virtual ~Person() {}

    virtual void displayInfo() const = 0;

    virtual void writeToFile(ofstream& file) const {
        file << name << " " << surname << " " << birthYear;
    }
};

class Instructor : public Person {
protected:
    string specialization;

public:
    Instructor(const string& _name, const string& _surname, int _birthYear, const string& _specialization)
        : Person(_name, _surname, _birthYear), specialization(_specialization) {}

    ~Instructor() {}

    void displayInfo() const override {
        cout << "Instructor: " << name << " " << surname << ", Birth Year: " << birthYear
             << ", Specialization: " << specialization << endl;
    }

    void writeToFile(ofstream& file) const override {
        Person::writeToFile(file);
        file << " " << specialization;
    }
};

class Student : public Person {
protected:
    string car ;

public:
    Student(const string& _name, const string& _surname, int _birthYear, const string& _car )
        : Person(_name, _surname, _birthYear), car (_car ) {}

    ~Student() {}

    void displayInfo() const override {
        cout << "Student: " << name << " " << surname << ", Birth Year: " << birthYear
             << ", Car  : " << car  << endl;
    }

    void writeToFile(ofstream& file) const override {
        Person::writeToFile(file);
        file << " " << car ;
    }
};

void readPersonsFromFile(const string& filename, Person** persons, int& count) {
    ifstream file(filename);

    if (!file.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        return;
    }

    string name, surname;
    int birthYear;
    string specializationOrCar ;

    while (file >> name >> surname >> birthYear >> specializationOrCar ) {
        if (filename.find("instructors") != string::npos) {
            persons[count++] = new Instructor(name, surname, birthYear, specializationOrCar );
        } else if (filename.find("students") != string::npos) {
            persons[count++] = new Student(name, surname, birthYear, specializationOrCar );
        }
    }

    file.close();
}

void writePersonToFile(const string& filename, const Person* person) {
    ofstream file(filename, ios::app);

    if (!file.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        return;
    }

    person->writeToFile(file);
    file << endl;
    file.close();
}

int main() {
    Person* persons[MAX_PERSONS];
    int personCount = 0;

    cout << "Menu:\n1. Read persons from file\n2. Add a new person\n0. Exit\n";

    int choice;
    cin >> choice;

    if (choice == 1) {
        readPersonsFromFile("instructors.txt", persons, personCount);
        readPersonsFromFile("students.txt", persons, personCount);

        for (int i = 0; i < personCount; ++i) {
            persons[i]->displayInfo();
            delete persons[i];
        }
    }
    if (choice == 2) {
        cout << "Enter person details:" << endl;
        string name, surname;
        int birthYear;
        cout << "Name: ";
        cin >> name;
        cout << "Surname: ";
        cin >> surname;
        cout << "Birth Year: ";
        cin >> birthYear;

        cout << "Choose person type:\n1. Instructor\n2. Student\n";
        int personType;
        cin >> personType;

        if (personType == 1) {
            string specialization;
            cout << "Specialization: ";
            cin >> specialization;
            Instructor newInstructor(name, surname, birthYear, specialization);
            writePersonToFile("instructors.txt", &newInstructor);
        }
        if (personType == 2) {
            string car ;
            cout << "Car: ";
            cin >> car ;
            Student newStudent(name, surname, birthYear, car );
            writePersonToFile("students.txt", &newStudent);
        } else {
            cout << "Invalid choice\n";
        }
    }

    return 0;
}
