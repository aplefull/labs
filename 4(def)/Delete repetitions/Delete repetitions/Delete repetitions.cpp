//Удалить повторный вхождения символов.
#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	int size, n = 0;

	cout << "Type in size of an array: ";
	cin >> size;

	int* a = new int[size];

	//ввод
	cout << "Type all elements: ";
	for (int i = 0; i < size; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < size - n; i++){

		for (int j = i + 1; j < size - n; j++) {

			if (a[i] == a[j]) {

				for (int k = j; k < size - 1; k++) {
					a[k] = a[k + 1];
				}
				n++;
				j--;
			}
		}
	}

	//вывод
	for (int i = 0; i < size - n; i++) {
		cout << a[i] << " ";
	}

	delete[] a;
	return 0;
}

