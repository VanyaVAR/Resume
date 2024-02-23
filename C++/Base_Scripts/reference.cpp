#include <iostream>

using namespace std;

int main(){
    int value = 4;
    int &val_ref = value;
    cout << "&val_ref = value;" << endl << endl;
    cout << val_ref << endl;
    cout << &val_ref << endl;

    cout << "-------------------------" << endl;

    val_ref ++;
    cout << "val_ref ++;" << endl << endl;
    cout << val_ref << endl;
    cout << &val_ref << endl;

    cout << "-------------------------" << endl;

    int *p_val = &val_ref;
    cout << "int *p_val = &val_ref;" << endl << endl;
    cout << p_val << endl;
    cout << *p_val << endl;

    cout << "-------------------------" << endl;

    *p_val ++;
    cout << "*p_val ++;" << endl << endl;
    cout << p_val << endl;
    cout << *p_val << "\t" << "Это мусор" <<endl;
    cout << value << endl;

    cout << "-------------------------" << endl;

    p_val ++;
    cout << "p_val ++;" << endl << endl;
    cout << p_val << endl;
    cout << *p_val << "\t" << "Это мусор" <<endl;

    cout << "-------------------------" << endl;
}
