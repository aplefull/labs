// Удалить все элементы, стоящие до элемента с максимальным значением.
#include "stdafx.h"
#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
	int size, i, max, maxind = 0;
		cout << "Type in size of an array (>=2): ";
		cin >> size;

	int *a = new int[size];

	for (i = 0; i < size; i++) {
		cout << "Type in value: ";
		cin >> a[i];
	}

	max = a[0];
	for (i = 1; i < size; i++) {
		if (max < a[i]) {
			max = a[i];
			maxind = i;
		}
	}
	
	if (a[0] == max) {
		cout << "The first element is the largest." << endl;
		delete[] a;
		return 1;
	}
	
	else

	for (int k = maxind - 1; k >= 0; k--) {

		for (i = k; i < size - 1; i++) {
			a[i] = a[i + 1];
		}

	}

	for (i = 0; i < size - maxind; i++) {
		cout << a[i] << " ";
	}

	cout << endl;

	delete[] a;
    return 0;
}

