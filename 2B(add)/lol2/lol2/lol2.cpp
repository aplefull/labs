// Найти число, наиболее часто встречающееся в массиве.
#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	int i, n, temp = 0, size, max, buff;
	bool repeat = false;
	cout << "Type in size (>= 1): ";
	cin >> size;

	int *a = new int[size];

	for (i = 0; i < size; i++) {
		cout << "Type in an element: ";
		cin >> a[i];

	}

	for (i = 0; i < size; i++) {
		n = 0;
		for (int k = 0; k < size; k++) {
			//это смерть просто будет сейчас
			if (a[i] == a[k]) {
				n++;
			}
		}
		n--;

		if (n >= temp && n != 0) {
			if (n == temp && a[i] != max) {
				repeat = true;
				buff = n;
			}

			temp = n;
			max = a[i];
			
		}
	}

	for (i = 0; i < size; i++) {
		cout << a[i] << " ";
	}

	if (repeat == true && buff >= temp) {
		cout << endl << "More than one elemnet has maximal number of repetitions. " << endl;
		delete[] a;
		return 1;
	}

	else {

		if (temp == 0) {
			cout << endl << "There are no repeating elements." << endl;
			delete[] a;
			return 1;
		}

		else {
			cout << endl << "Most repeating element is " << max << " (" << temp + 1 << " times)." << endl;
		}
	}
	delete[] a;
	return 0;
}

