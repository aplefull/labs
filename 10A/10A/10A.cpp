#include "stdafx.h"
#include <iostream>

using namespace std;

int FindMax(int a[], int end);

int main()
{
	cout << "size: ";
	int size, maxInd;
	cin >> size;

	int *a = new int[size];

	cout << "array: ";
	for (int i = 0; i < size; i++)
	{
		cin >> a[i];
	}

	for (int i = 1; i < size; i++)
	{
		maxInd = 0;
		if (a[maxInd] < a[i])
		{
			maxInd = i;
		}
	}

	cout << FindMax(a, size - 1);

    return 0;
}

int FindMax(int a[], int end) {

	int max;

	if (end == 0)
	{
		return a[0];
	}

	if (a[end] > )
	{

	}

	else
	{
		FindMax(a, end - 1);
	}

	return max;
}

