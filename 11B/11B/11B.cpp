// insertion sort
#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	int size, temp;
	cout << "size: ";
	cin >> size;
	int *a = new int[size];

	for (int i = 0; i < size; i++)
	{
		cin >> a[i];
	}

	for (int i = 1; i < size; i++)
	{
		if (a[i] < a[i - 1])
		{
			for (int j = i - 1; j >= 0; j--)
			{
				if (a[i] > a[j])
				{
					temp = a[i];
					for (int k = i; k - 1 > j; k--)
					{
						a[k] = a[k - 1];
					}
					a[j + 1] = temp;
					break;
				}

				if (j == 0)
				{
					temp = a[i];
					for (int k = i; k - 1 >= j; k--)
					{
						a[k] = a[k - 1];
					}
					a[j] = temp;
					break;
				}
			}
		}
	}

	for (int i = 0; i < size; i++)
	{
		cout << a[i] << " ";
	}

	delete[] a;
    return 0;
}

