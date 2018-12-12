// Обратный порядок
#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	int temp, size, n;
	bool repeat = false;
	cout << "Type in size (>= 1): ";
	cin >> size;

	int *a = new int[size];

	cout << "Type in elements: ";
	for (int i = 0; i < size; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < size / 2; i++) {
		temp = a[size - 1 - i];
		a[size - 1 - i] = a[i];
		a[i] = temp;
	}

	for (int i = 0; i < size; i++) {
		cout << a[i] << " ";
	}
	delete[] a;
	return 0;
}