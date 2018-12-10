// Найти кол-во и произведение отрицательных нечётных элементов.

#include "stdafx.h"
#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
	int x, product = 1, k = 0;
	int a[10];

	cout << "Type in elements" << endl;

	for (int i = 0; i < 10; i++) { 
		cin >> x;
		a[i] = x;
	}

	cout << endl;

	for (int i = 0; i < 10; i++) {
		if (a[i] < 0 && a[i] % 2 != 0) {
			product *= a[i];
			k++;
		}
	}
	if (k == 0) {
		cout << "There are no negative elements in an array." << endl;
	}
	else {
		cout << "Product: " << product << endl << "Number of elements: " << k << endl;
	}

    return 0;
}

