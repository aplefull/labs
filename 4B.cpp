// Удалить все элементы, стоящие до элемента с максимальным значением.
#include "stdafx.h"
#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
	int size, i, maxind = 0;
		cout << "Type in size of an array (>=2): ";
		cin >> size;

	int *a = new int[size];

	for (i = 0; i < size; i++) {
		cout << "Type in value: ";
		cin >> a[i];
	}


	for (i = 1; i < size; i++) {
		if (a[maxind] < a[i]) {
			maxind = i;
		}
	}
	
	if (a[0] == a[maxind]) {
		cout << "The first element is the largest." << endl;
		delete[] a;
		return 1;
	}
	
	else

		for (i = 0; i < size - maxind; i++) {
			a[i] = a[maxind + i];
		}

	for (i = 0; i < size - maxind; i++) {
		cout << a[i] << " ";
	}

	cout << endl;

	delete[] a;
    return 0;
}

