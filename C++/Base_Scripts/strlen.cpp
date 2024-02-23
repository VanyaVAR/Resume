#include <cstring>
#include <iostream>
#include <string>
#include <ctime>

using namespace std;

int main(){
    srand(time(NULL));
    int size = rand() % 100;

    char* str = new char[size];

    for (int i = 0; i < size; i++){
        str[i] = rand();
    }

    for (int i = 0; i < size; i++){
        cout << str[i];
    }

    cout << endl;

    int lenght = strlen(str);
    cout << lenght << endl;

    delete[] str;
    str = nullptr;
}
