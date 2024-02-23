#include <iostream>

using namespace std;

int main(){
    int value_1, value_2;
    cout << "Введите value_1: ";
    cin >> value_1;

    /*if (value_1 > 10){
        cout << "value_1 больше 10";
    }
    else{
        cout << "value_1 меньше 10";

    }*/

    // Можно записать в одну строчку "?" - это if, а ":" - это else

    value_1 > 10 ? cout << "value_1 больше 10" : cout << "value_1 меньше 10";

    cout << endl;

    cout << "Введите value_2: ";
    cin >>value_2;

    /*if (value_2 > 10){
        cout << "value_2 больше 10";
    }
    else{
        if(value_2 < 10){
            cout << "value_2 меньше 10";
        }
        else{
            cout << "value_2 равно 10";
        }
    }*/

    value_2 > 10 ? cout << "value_2 больше 10" : value_2 < 10 ? cout << "value_2 меньше 10" : cout << "value_2 равно 10";



}
