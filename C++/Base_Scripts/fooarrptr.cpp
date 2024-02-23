// массив указателей на функцию

#include <iostream>

using namespace std;

void swap(int *x, int *y){
    int i = *x;
    *x = *y;
    *y = i;
}

void do_plus(int *x, int *y){
    *x += *y;
}

void do_minus(int *x, int *y){
    *y -= *x;
}

int main(){
    void (*actions[])(int *, int *) = {swap, do_plus, do_minus};
    int x = 300;
    int y = 555;

    cout << "Начальные значения переменных x = " << x << "и y = " << y << endl;
    cout << endl;

    actions[0](&x, &y);
    cout << "Swap\t" << "x = " << x << ' '<< "y = " << y;

    cout << endl;

    actions[1](&x, &y);
    cout << "do_plus\t" << "x = " << x << ' '<< "y = " << y;

    cout << endl;

    actions[2](&x, &y);
    cout << "do_minus\t" << "x = " << x << ' '<< "y = " << y;
}
