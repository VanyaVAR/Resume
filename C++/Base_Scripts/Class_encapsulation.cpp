#include <iostream>
#include <ctime>

using namespace std;

class Coffee{
private:
    bool CheckError(){
        int check = rand() % 20;
        if (check <= 15)
            return true;
        if (check > 15)
            return false;
    }

public:
    void Start(){
        CheckError() ? cout << "Работает" : cout << "Ошибка";
    }

};

int main(){

    srand(time(NULL));

    Coffee Nescafe;
    Nescafe.Start();
}
