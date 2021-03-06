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

void selectionSort(int a[], int size) {

	for (int i = 0; i < size - 1; i++) {

		int min_index = i;

		for (int k = i; k < size; k++) {

			if (a[k] < a[min_index]) {
				min_index = k;
			}

		}

		swap(a, min_index, i);
	}
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

	selectionSort(a, size);

	cout << endl << "sorted array: ";
	for (int i = 0; i < size; i++)
	{
		cout << a[i] << " ";
	}

	delete[] a;
	return 0;
}

