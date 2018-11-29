// Отрицательные в начало, положительные - в конец. Сохранить взаимное расположение.

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	int i, n = 0, size, temp;

	cout << "Type in size (>= 1): ";
	cin >> size;

	int *a = new int[size];

	for (i = 0; i < size; i++) {
		cout << "Type in an element: ";
		cin >> a[i];

	}

	for (i = 0; i < size; i++) {
		cout << a[i] << " ";
	}

	cout << endl;

	for (i = 0; i < size; i++) {
		if (a[i] < 0) {
			n++;
		}

	}

	if (n == 0 || n == size) {

		for (i = 0; i < size; i++) {
			cout << a[i] << " ";
		}

		delete[] a;
		return 0;
	}

		for (i = size - 1; i >= 0; i--) {

			if (a[i] < 0 && n > 0) {
				n--;
				i++;
				for (int k = i - 1; k > 0; k--) {
					temp = a[k - 1];
					a[k - 1] = a[k];
					a[k] = temp;
				}
			}
		}

	for (i = 0; i < size; i++) {
		cout << a[i] << " ";
	}


	delete[] a;
	return 0;
}



