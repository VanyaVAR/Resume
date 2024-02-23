/* template (с англ. шаблон) нужны для упращения перегрузки функции (Объединение
 * функций)*/

#include <iostream>

using namespace std;

template <typename T>
T Sum_1(T value_1, T value_2)
{
    cout << value_1 + value_2 << endl;
}

template <typename T1, typename T2>
void Sum_2(T1 value_3, T2 value_4)
{
    cout << value_3 + value_4 << endl;
}

//Такую функцию можно и сделать не void, а Т1 или Т2 и она будет выводить либо int'вое значение либо double
//Смотря какое число введешь

int main()
{
    Sum_1(5,8);
    Sum_1(2.4,6.1);
    Sum_2(9.3, 4);
    Sum_2(6, 3.9);
    Sum_2(9,9);
    Sum_2(3.4,5.7);
}
