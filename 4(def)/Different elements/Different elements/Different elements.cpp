//Кол-во различных элементов в массиве
#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	int size, n = 0, temp;

	cout << "Type in size of an array: ";
	cin >> size;

	int* a = new int[size];

	//ввод
	cout << "Type all elements: ";
	for (int i = 0; i < size; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < size - n; i++){

		for (int j = i + 1; j < size - n; j++){

			if (a[i] == a[j]) {
				n++;
				temp = a[size - 1];
				a[size - 1] = a[j];
				a[j] = temp;
				j--;
			}
		}
	}

	cout << "answ: " << size - n << endl;

	delete[] a;
	return 0;
}

