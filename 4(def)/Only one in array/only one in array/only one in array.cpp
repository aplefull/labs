// Числа, входящие в массив только 1 раз.

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	int size;
	bool NoRep = true, err = true;

	cout << "Type in size: ";
	cin >> size;

	int* a = new int[size];

	//ввод
	cout << "type in all elements: ";
	for (int i = 0; i < size; i++) {
		cin >> a[i];
	}

	//вывод
	for (int i = 0; i < size; i++) {
		cout << a[i] << " ";
	}

	cout << endl << "Numbers: ";

	for (int i = 0; i < size; i++){

		for (int j = 0; j < size; j++) {

			if (a[i] == a[j] && i != j) {
				NoRep = false;
				break;
			}
		}

		if (NoRep == true) {
			cout << a[i] << " ";
			err = false;
		}

		else
		NoRep = true;
	}

	if (err = true) {
		cout << "There are no non-repeating numbers." << endl;
		delete[] a;
		return 1;
	}

	cout << endl;

	delete[] a;
	return 0;
}

