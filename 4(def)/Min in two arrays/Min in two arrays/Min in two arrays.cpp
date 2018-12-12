// Наименьший элемент среди массива a, который не входит в массив b.

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	int sizeA, sizeB, minIndex, temp, k = 1;
	bool done = false;

	cout << "Type in size of an array a: ";
	cin >> sizeA;
	int* a = new int[sizeA];

	//ввод1
	cout << "Type in all elements: ";
	for (int i = 0; i < sizeA; i++) {
		cin >> a[i];
	}

	cout << "Type in size of an array b: ";
	cin >> sizeB;
	int* b = new int[sizeB];

	//ввод2
	cout << "Type in all elements: ";
	for (int i = 0; i < sizeB; i++) {
		cin >> b[i];
	}

	//вывод
	for (int i = 0; i < sizeA; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < sizeB; i++) {
		cout << b[i] << " ";
	}

	do{
		if (sizeA - k + 1 == 1) {
			cout << endl << "There are no such elements" << endl;
			delete[] a;
			delete[] b;
			return 1;
		}

		minIndex = 0;
		for (int i = 0; i < sizeA - k + 1; i++) {
			if (a[minIndex] > a[i]) {
				minIndex = i;
			}
		}

		for (int i = 0; i < sizeB; i++) {

			if (a[minIndex] == b[i]) {

				temp = a[sizeA - k];
				a[sizeA - k] = a[minIndex];
				a[minIndex] = temp;
				k++;

				break;
			}

			else {

				if (i == sizeB - 1) {
					done = true;
				}
			}
		}
	}

	while (done == false);

	cout << endl << a[minIndex] << endl;

	delete[] a;
	return 0;
}