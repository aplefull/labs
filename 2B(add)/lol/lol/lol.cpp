#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	int i, n, size;

	cout << "Type in size (>= 1): ";
	cin >> size;

	cout << "Type in array shift (>= 1): ";
	cin >> n;

	double *a = new double[size], temp;

	for (i = 0; i < size; i++) {
		cout << "Type in an element: ";
		cin >> a[i];

	}

	cout << endl;

	for (i = 0; i < size; i++) {
		cout << a[i] << " ";
	}

	cout << endl;

	for (int k = 1; k <= n; k++) {

		temp = a[size - 1];

		for (i = size - 1; i > 0; i--) {
			a[i] = a[i - 1];
		}

		a[0] = temp;
	}

	for (i = 0; i < size; i++) {
		cout << a[i] << " ";
	}

	delete[] a;
    return 0;
}

