// Числа, входящие в массив не более одного раза.

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	int i, n = 0, size;

	cout << "Type in size (>= 1): ";
	cin >> size;

	int *a = new int[size];

	for (i = 0; i < size; i++) {
		cout << "Type in an element: ";
		cin >> a[i];

	}
	cout << endl;

	for (i = 0; i < size; i++) {
		cout << a[i] << " ";
	}

	for (i = 0; i < size; i++) {
		for (int k = 0; k < size; k++) {
			if (a[i] == a[k]) {
				n++;
				if (n > 1) {
					cout << a[i] << " ";
					break;
				}
			}
		}
	}

	delete[] a;
	return 0;
}



