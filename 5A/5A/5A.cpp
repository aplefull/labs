//Вывести кол-во нечётных (по значению) элементов в каждом столбце.
#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	int k, a[5][5];
	
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cout << "Type in element: ";
			cin >> k;
			a[i][j] = k;
		}
	}

	cout << endl;

	// Вывод матрицы.
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}

	for (int j = 0; j < 5; j++) {
		k = 0;
		for (int i = 0; i < 5; i++) {
			if (a[i][j] % 2 != 0) {
				k++;
			}
		}
		cout << "In column number " << j + 1 << " there are " << k << " odd elements." << endl;
	}

    return 0;
}

