// Число, наиболее часто встречающееся в массиве.

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	int size, k1 = 0, k2 = 0, num;
	
	cout << "Type in size: ";
	cin >> size;

	int* a = new int[size];

	//ввод
	cout << "type in all elements: ";
	for (int i = 0; i < size; i++){
		cin >> a[i];
	}

	//вывод
	for (int i = 0; i < size; i++) {
		cout << a[i] << " ";
	}
	
	for (int i = 0; i < size - 1; i++) {

		for (int  j = i + 1; j < size; j++){

			if (a[i] == a[j]) {
				k1++;
			}
		}

		if (k1 > k2) {
			k2 = k1;
			num = a[i];
		}

		else if (k1 == k2) {

			cout << endl << "more than 1 element has max number of repetitions" << endl;
			delete[] a;
			return 1;

		}

		k1 = 0;
	}

	cout << endl << num << " " << k2 + 1 << " times" << endl;
	delete[] a;
    return 0;
}

