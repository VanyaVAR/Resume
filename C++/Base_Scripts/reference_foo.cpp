#include <iostream>

using namespace std;

int Value_Error(int a){
    a = 1;
}

// int Value_True(int a){
//     a = 1;
//     return 1;
// }

int Reference(int &a){
    a = 1;
}

int Pointer(int *a){
    *a = 1;
}

int main(){

    int value = 202;
    cout << "value = " << value << endl;

    Value_Error(value);
    cout << "Value_Error = " << value << endl;

    // Value_True(value);
    // cout << "Value_True = " << value << endl;

    Reference(value);
    cout << "Reference = " << value << endl;

    Pointer(&value);
    cout << "Pointer = " << value << endl;


}
