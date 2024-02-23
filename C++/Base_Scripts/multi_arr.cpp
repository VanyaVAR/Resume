#include <iostream>
#include <ctime>

using namespace std;

int main(){

    srand(time(NULL));

    const int FIRST_VALUE = 5;
    const int SECOND_VALUE = 5;
    const int FIRD_VALUE = 5;

    int multi_arr [FIRST_VALUE][SECOND_VALUE][FIRD_VALUE];

    for (int i = 0; i < FIRST_VALUE; i++){
        for (int j = 0; j < SECOND_VALUE; j++) {
            for (int k = 0; k < FIRD_VALUE; k++){
                multi_arr[i][j][k] = rand() % 100;
            }
        }
    }

    for (int i = 0; i < FIRST_VALUE; i++){
        for (int j = 0; j < SECOND_VALUE; j++) {
            for (int k = 0; k < FIRD_VALUE; k++){
                cout << ' ' << multi_arr[i][j][k]; 
            }
            cout << endl;
        }
        cout << endl;
    }
}