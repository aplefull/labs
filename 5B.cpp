// Определить кол-во особых элементов матрицы, считая элемент особым, если он меньше суммы остальных эллементов соответствующей строки.
#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	int rows, columns, x, sum, k = 0;

	cout << "Type in number of rows and columns: " << endl;
	cin >> rows >> columns;

	int **a = new int*[rows]; 

	cout << "Type in elements:" << endl;

	for (int i = 0; i < rows; i++) {
		a[i] = new int[columns];

		for (int j = 0; j < columns; j++) {
			cin >> x;
			a[i][j] = x;
		}
	}  

	//вывод матрицы
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

	cout << endl << "Number of \"special\" elements: " << k << endl;

	for (int i = 0; i < rows; i++) {
		delete[] a[i];
	}

	delete[] a;
    return 0;
}

