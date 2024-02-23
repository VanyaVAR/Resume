#include <iostream>

#define SIZE 5  //макрос
#define DEBUG_1
#define DEBUG_2

using namespace std;

int main(){

    cout << "Пример макроса SIZE в качестве переменной" << endl;
    for (int i = 0; i < SIZE; i++){
        cout << ' ' <<i;
    }
    cout << endl;
    cout << "-----------------------------";
    cout << endl;

#ifdef DEBUG_1
    cout << "Макрос DEBUG_1 определен";
#endif

    cout << endl;
    cout << "-----------------------------";
    cout << endl;

#ifdef DEBUG_2
    cout << "Марос DEBUG_2 определен (пример с else)";
#else
    cout << "Макрос DEBUG_2 неопределен"
#endif
    cout << endl;
    cout << "-----------------------------";
    cout << endl;

#ifdef DEBUG_3
    cout << "Макрос DEBUG_3 определен";
#else
    cout << "Макрос DEBUG_3 неопределен";
#endif

    cout << endl;
    cout << "-----------------------------";
    cout << endl;

#ifndef DEBUG_3
    cout << "Макрос DEBUG_3 неопределен (пример с ifndef)";
#endif


}
