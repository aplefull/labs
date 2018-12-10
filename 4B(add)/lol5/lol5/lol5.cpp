#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	int minIndex = 0, maxIndex = 0, size, n = 0, k = 0;

	cout << "Type in size of an array: ";
	cin >> size;
	int* a = new int[size];

	//ввод
	for (int i = 0; i < size; i++){
		cout << "Type in an element: ";
		cin >> a[i];
	}

	//вывод
	for (int i = 0; i < size; i++){
		cout << a[i] << " ";
	}
	cout << endl;

	for (int i = 1; i < size; i++){

		if (a[maxIndex] < a[i]) {
			maxIndex = i;
		}

		if (a[minIndex] > a[i]) {
			minIndex = i;
		}
	}

	//Проверяем, один ли max/min элемент
	for (int i = 0; i < size; i++) {

		if (a[i] == a[minIndex]) {
			k++;
		}

		if (a[i] == a[maxIndex]) {
			n++;
		}
	}

	if (k > 1) {
		cout << "There are more than 1 min element." << endl;
		k = 0;
	}

	else {
		//удаление min
		for (int i = minIndex; i < size - 1; i++) {
			a[i] = a[i + 1];
		}

		if (minIndex < maxIndex) {
			maxIndex--;
		}
	}

	if (n > 1) {
		cout << "There are more than 1 max element." << endl;
		n = 0;
	}

	else {
		//удаление max
		for (int i = maxIndex; i < size - 1; i++) {
			a[i] = a[i + 1];
		}
	}

	//вывод
	for (int i = 0; i < size - n - k; i++) {
		cout << a[i] << " ";
	}
	cout << endl;

	delete[] a;
    return 0;
}