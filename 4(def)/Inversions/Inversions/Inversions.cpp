//Кол-во инверсий.
#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	int size, n = 0;

	cout << "Type in size of an array: ";
	cin >> size;

	int* a = new int[size];

	cout << "Type all elements: ";
	for (int i = 0; i < size; i++) {
		cin >> a[i];
	}


	for (int i = 0; i < size; i++) {

		for (int j = i + 1; j < size; j++){

			if (a[i] > a[j]) {
				n++;
			}

		}
	}

	cout << "Answ: " << n << endl;
	delete[] a;
	return 0;
}

