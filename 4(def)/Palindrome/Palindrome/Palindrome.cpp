// Определить, является ли массив палиндромом.

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	int size;

	cout << "Type in size of an array: ";
	cin >> size;
	char* a = new char[size];

	//ввод
	cout << "Type in all elements: ";
	for (int i = 0; i < size; i++) {
		cin >> a[i];
	}

	//вывод
	for (int i = 0; i < size; i++) {
		cout << a[i] << " ";
	}

	cout << endl;

	for (int i = 0; i < size / 2; i++){

		if (a[i] != a[size - i - 1]) {
			cout << "Array is not a palindrome" << endl;
			delete[] a;
			return 0;
		}

	}

	cout << "Array is a palindrome" << endl;

	delete[] a;
	return 0;
}