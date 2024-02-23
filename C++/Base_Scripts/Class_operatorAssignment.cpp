#include <iostream>

using namespace std;

class MyClass{
private:
    int Size;
    int* arr;
public:
    MyClass(int size){
        this -> Size = size;
        this -> arr = new int [size];

        for (int i = 0; i < size; i++){
            arr[i] = i;
        }
    }

    void operator = (const MyClass &other){

    }

    ~MyClass(){
        delete[] arr;
    }
};

int main(){

    MyClass first(10);
}
