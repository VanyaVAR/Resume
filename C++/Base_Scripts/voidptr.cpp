#include <iostream>

using namespace std;

int main(){
    int a = 8;
    char b = 'F';
    double f = 3.52;

    void* pointer;
    pointer = &a;

    //cout << *pointer; выведет ошибку

    cout << *(int* )pointer << endl;

    pointer = &b;
    cout << *(char* )pointer << endl;

    pointer = &f;
    cout << *(double* )pointer << endl;

}
