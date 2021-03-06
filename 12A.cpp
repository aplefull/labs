#include "stdafx.h"
#include <iostream>

using namespace std;

int linearSearch(int*, int, int);

int main()
{
	int size, item;
	cout << "size: ";
	cin >> size;

	cout << "Type in array elements: ";
	int *a = new int[size];
	for (int i = 0; i < size; i++)
	{
		cin >> a[i];
	}

	cout << "item to search for: ";
	cin >> item;

	cout << linearSearch(a, size, item) << endl;

	delete[] a;
	return 0;
}

int linearSearch(int *a, int size, int item)
{
	for (int i = 0; i < size; i++)
	{
		if (a[i] == item)
		{
			return item;
		}
	}

	return -1;
}
