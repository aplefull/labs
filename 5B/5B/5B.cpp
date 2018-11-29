#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	int rows, columns, x, sum, k = 0;
	cout << "Введите кол-во строк и столбцов через пробел." << endl;
	cin >> rows >> columns;
	int **a = new int*[rows]; 

	cout << "Введите элементы массива." << endl;

	for (int i = 0; i < rows; i++) {
		a[i] = new int[columns];

		for (int j = 0; j < columns; j++) {
			cin >> x;
			a[i][j] = x;
		}
	}  


	for (int i = 0; i < rows; i++) {
		cout << endl;
		for (int j = 0; j < columns; j++) {
			cout << a[i][j] << " ";
		}
	} 
	cout << endl;

	for (int i = 0; i < rows; i++) {
		sum = 0;

		for (int j = 0; j < columns; j++) {
			sum += a[i][j];
		}

		for (int j = 0; j < columns; j++) {

			if (a[i][j] < sum - a[i][j]) {
				k++;
			}
		}
	}
	cout << "Кол-во особых элементов: " << k << endl;
	for (int i = 0; i < rows; i++) {
		delete[] a[i];
	}
	delete[] a;

    return 0;
}

