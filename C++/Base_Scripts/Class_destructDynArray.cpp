#include <ctime>
#include <iostream>

using namespace std;

class Array {
private:
  int *arr;

public:
  Array(int size) {
    arr = new int[size];
    for (int i = 0; i < size; i++) {
      arr[i] = rand() % 15;
    }
  }

  ~Array() { delete[] arr; }

  void Print(int size) {
    for (int i = 0; i < size; i++) {
      cout << ' ' << arr[i];
    }
  }
};

int main() {

  srand(time(NULL));
  int size;
  cout << "Введите размер массива" << endl;
  cin >> size;

  Array firstArr(size);
  firstArr.Print(size);
}
