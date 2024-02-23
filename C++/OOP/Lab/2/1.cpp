#include <iostream>
#include <ctime>
using namespace std;

int** genRandMatrix(int size, int maxValue) {
	int** matrix = new int* [size];
	for (int i = 0; i < size; i++) {
		matrix[i] = new int[size];
		for (int j = 0; j < size; j++) {
			matrix[i][j] = rand() % maxValue + 1;
		}
	}
	return matrix;
}

int* rightmas(int* arr, int** matrix, int size) {
	if (size == 1)
	{
		arr[0] = matrix[0][0];
		return arr;
	}
	int row = 0;
	int col = size - 1;
	int k = 1;
	for (int i = 0; i < size * size; i += 1)
	{
		arr[i] = matrix[row][col];
		if ((row < size - 1) && (col == size - 1))
		{
			row = row - k + 1;
			col -= k;
			k += 1;
			continue;
		}
		if ((row < size - 1) && (col < size - 1))
		{
			row += 1;
			col += 1;
			continue;
		}
		if ((row == size - 1) && (col <= size - 1))
		{
			k -= 1;
			row = row - k + 1;
			col -= k;
			continue;
		}
	}
	return arr;
}

int* leftmas(int* arr, int** matrix, int size) {
	if (size == 1)
	{
		arr[0] = matrix[0][0];
		return arr;
	}
	int row = 0;
	int col = 0;
	int k = 1;
	for (int i = 0; i < size * size; i += 1)
	{
		arr[i] = matrix[row][col];
		if ((row < size - 1) && (col == 0))
		{
			row = row - k + 1;
			col += k;
			k += 1;
			continue;
		}
		if ((row < size - 1) && (col <= size - 1))
		{
			row += 1;
			col -= 1;
			continue;
		}
		if ((row == size - 1) && (col < size - 1))
		{
			k -= 1;
			row = row - k + 1;
			col += k;
			continue;
		}
	}
	return arr;
}

int* spiralmas(int* arr, int** matrix, int size) {
	if (size == 1)
	{
		arr[0] = matrix[0][0];
		return arr;
	}
	int centerOfSpiral = (size - 1) / 2;
	int col = centerOfSpiral, row = centerOfSpiral;
	arr[0] = matrix[row][col];
	int k = 0, e = 1;
	while (k != -1)
	{
		k += 1;
		for (int j = 0; j < k; j += 1, e += 1)
		{
			if (k == size)
			{
				k = -1;
				break;
			}
			if (k % 2 == 1)
			{
				col += 1;
			}
			else
			{
				col -= 1;
			}
			arr[e] = matrix[row][col];
		}
		for (int l = 0; l < k; l += 1, e += 1)
		{
			if (k == size)
			{
				k = -1;
				break;
			}
			if (k % 2 == 1)
			{
				row += 1;
			}
			else
			{
				row -= 1;
			}
			arr[e] = matrix[row][col];
		}
		if (k == -1)
		{
			break;
		}
	}
	for (int i = 0; i < size - 1; i += 1, e += 1)
	{
		if (size % 2 == 1)
		{
			col += 1;
		}
		else
		{
			col -= 1;
		}
		arr[e] = matrix[row][col];
	}
	return arr;
}

int* spiralleftmas(int* arr, int** matrix, int size) {
	if (size == 1)
	{
		arr[0] = matrix[0][0];
		return arr;
	}
	int row = 0, col = 0;
	arr[0] = matrix[row][col];
	int k = size, e = 1, m = 0;
	for (int i = 0; i < size - 1; i += 1, e += 1)
	{
		col += 1;
		arr[e] = matrix[row][col];
	}
	while (k != 1)
	{
		k -= 1;
		for (int i = 0; i < k; i += 1, e += 1)
		{
			if (m == 0)
			{
				row += 1;
			}
			else
			{
				row -= 1;
			}
			arr[e] = matrix[row][col];
		}
		for (int j = 0; j < k; j += 1, e += 1)
		{
			if (m == 0)
			{
				col -= 1;
			}
			else
			{
				col += 1;
			}
			arr[e] = matrix[row][col];
		}
		m = (m + 1) % 2;
	}
	return arr;
}

void printMatrix(int** matrix, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cout << ' ' << matrix[i][j];
		}
		cout << endl;
	}
}

void printmas(int* arr, int size) {
	for (int i = 0; i < size * size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

void deleteMatrix(int** matrix, int size, int* arr) {
	for (int i = 0; i < size; i++) {
		delete[]matrix[i];
	}
	delete[]matrix;
}

int main() {
	srand(time(NULL));
	int size = rand() % 5 + 1;
	cout << size << endl;
	int maxValue = 100;
	int** matrix = genRandMatrix(size, maxValue);
	printMatrix(matrix, size);
	int* arr = new int[size * size];
	rightmas(arr, matrix, size);
	printf("Array by right diagonals:\n");
	printmas(arr, size);
	printf("\n");
	leftmas(arr, matrix, size);
	printf("Array by left diagonals:\n");
	printmas(arr, size);
	printf("\n");
	spiralmas(arr, matrix, size);
	printf("Array by spiral of center diagonals:\n");
	printmas(arr, size);
	printf("\n");
	spiralleftmas(arr, matrix, size);
	printf("Array by spiral of left diagonals:\n");
	printmas(arr, size);
	deleteMatrix(matrix, size, arr);
}
