#include <iostream>

using namespace std;

template <typename T1, typename T2>
void Change(T1 &val_1, T2 &val_2){
    T1 a = val_1;
    val_1 = val_2;
    val_2 = a;
}

int main(){

    int val_1 = 1, val_2 = 3;
    // cin << val_1;
    // cin << val_2;
    cout << "До" << endl;
    cout << val_1 << endl;
    cout << val_2 << endl << endl;

    Change(val_1, val_2);
    cout << "После" << endl;
    cout << val_1 << endl;
    cout << val_2 << endl;

}
