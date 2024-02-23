#include <iostream>
#include <string>

using namespace std;

class Apple{
private:
    string color;
    int weight;
    int id;
    static int Counter;

public:
    Apple(string color, int weight){
        this -> color = color;
        this -> weight = weight;

        Counter ++;
        id = Counter;
    }

    void Print(){
        cout << "color - " << color << endl;
        cout << "weight = " << weight << endl;
    }

    int GetId(){
        return id;
    }
};

int Apple::Counter = 0;

int main(){

    Apple Green("green", 250);
    Apple Red("red", 200);

    Green.Print();
    Red.Print();

    cout << "id GREEN = " << Green.GetId() << "\t";
    cout << "id RED = " << Red.GetId();
}
