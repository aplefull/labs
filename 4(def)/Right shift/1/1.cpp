//Циклический сдвиг вправо.
#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	int size, n, temp;

	cout << "Type in size of an array: ";
	cin >> size;

	int* a = new int[size];

	cout << "Type all elements: ";
	for (int i = 0; i < size; i++){
		cin >> a[i];
	}

	cout << "n: ";
	cin >> n;

	for (int j = 0; j < n; j++) {
		temp = a[size - 1];
		for (int i = size - 1; i > 0; i--) {
			a[i] = a[i - 1];
		}
		a[0] = temp;
	}

	for (int i = 0; i < size; i++) {
		cout << a[i] << " ";
	}

	delete[] a;
    return 0;
}

