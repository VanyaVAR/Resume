// указатели на функцию

#include <iostream>

using namespace std;

int swap(int *x, int *y){
    int i = *x;
    *x = *y;
    *y = i;
}

int main(){
    int(*p_swap)(int *x, int *y) = swap;  //Это указатель на функцию. Сначала указывается тип функции (int) потом название указателя, параметры и через равно адресс функции (адрес функции это её название)
    int x = 500;
    int y = 222;

    p_swap(&x, &y);

    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
}
