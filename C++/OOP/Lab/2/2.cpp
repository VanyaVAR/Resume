#include <iostream>
#include <ctime>

using namespace std;

void printMatrix(int** matrix, int v, int N) {
	for (int j = 0; j < N; j++) {
		cout << matrix[v][j] << " ";
	}
	cout << endl;
}

void genRandMatrix(int N, int maxValue, int k) {
	int** matrix = new int* [k];
	int v = 0;
	for (int i = 0; i < k; i++) {
		matrix[i] = new int[N];
		for (int j = 0; j < N; j++) {
			matrix[i][j] = rand() % maxValue + 1;
		}
		printMatrix(matrix, v, N);
		delete[]matrix[i];
		N = rand() % 20 + 1;
		v++;
	}
	delete[]matrix;
}

int main() {
	srand(time(NULL));
	int k = rand() % 10 + 1;
	int N = rand() % 20 + 1;
	int maxValue = 100;
	genRandMatrix(N, maxValue, k);
}
