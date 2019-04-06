// selection sort
#include "stdafx.h"
#include <iostream>

using namespace std;

void swap(int a[], int first_index, int second_index) {
	int temp;
	temp = a[second_index];
	a[second_index] = a[first_index];
	a[first_index] = temp;
}

int main()
{
	int size;
	cout << "size: ";
	cin >> size;
	int *a = new int[size];

	cout << "Type in numbers: ";
	for (int i = 0; i < size; i++)
	{
		cin >> a[i];
	}

	for (int i = 0; i < size - 1; i++) {

		int min_index = i;

		for (int k = i; k < size; k++) {

			if (a[k] < a[min_index]) {
				min_index = k;
			}

		}

		swap(a, min_index, i);
	}

	cout << endl << "sorted array: ";
	for (int i = 0; i < size; i++)
	{
		cout << a[i] << " ";
	}

	delete[] a;
	return 0;
}

