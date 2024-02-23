#include <iostream>
#include <string>
#include <ctime>

using namespace std;

class Pixel{
public:

    Pixel(){
        r = g = b = 0;
    }

    Pixel(int r, int g, int b){
        this->r = r;
        this->g = g;
        this->b = b;
    }

    string GetInfo(){
        return "R=" + to_string(r) + ", G=" + to_string(g) + ", B=" + to_string(b);
    }

private:
    int r;
    int g;
    int b;
};

int main(){

    srand(time(NULL));

    const int SIZE = 5;
    int size = rand() % 30;

    // Статический массив объектов
    Pixel static_arr[SIZE];
    cout << "Статические Массив" << endl;

    //cout << static_arr[0].GetInfo();   //Обращаемся к нулевому элементу массива

    for (int i = 0; i < SIZE; i++){     // С помощью цикла проходимся по всем элементам массива
        cout << static_arr[i].GetInfo() << endl;
    }

    cout << endl;

    static_arr[3] = Pixel(3,6,9);      // Меняем значение элемента 
    cout << static_arr[3].GetInfo() << endl << endl; 

    // Динамический массив объектов
    cout << "Динамический Массив" << endl;
    Pixel *dyn_arr = new Pixel[size];
    dyn_arr[0] = Pixel(6,3,1);
    dyn_arr[1] = Pixel(8,4,2);

    cout << dyn_arr[0].GetInfo() << " " << dyn_arr[1].GetInfo() << endl;

    //Заполнение массива объектами с рандомными значениями
    for (int i = 0; i < size; i++){
        dyn_arr[i] = Pixel((rand()%50),(rand()%50),(rand()%50));
    }

    //Вывод
    for (int i = 0; i < size; i++){
        cout << dyn_arr[i].GetInfo() << endl;
    }

}