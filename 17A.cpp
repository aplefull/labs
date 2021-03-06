#include "stdafx.h"
#include <iostream>
#include <math.h>

using namespace std;

void add(int data, int m, int *H) {
	int i = data % m;
	if (H[i] != -1)
	{
		while (H[i] != -1) 
		{
			i++;
			if (i == m) i = 0;
			
		}
	}

	H[i] = data;
}

int search(int data, int m, int H[]) {
	int i = abs(data  % m);
	while (H[i] != 1)
	{
		if (H[i] == data) return i;
		i++;
		if (i >= m)
		{
			i = 0;
		}
	}
	return -1;
}

int main()
{
	int n = 11, m = 15, i;
	int arr[11], H[15];

	cout << "elements(11): " << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	for (int i = 0; i < m; i++)
	{
		H[i] = -1;
	}

	for (int i = 0; i < n; i++)
	{
		add(arr[i], m, H);
	}

	int item = 0, res;

	cout << "item to search for: " << endl;

	while (item != -1)
	{
		cin >> item;
		res = search(item, m, H);
		if (res == -1)
		{
			cout << "there is no such element" << endl;
		}
		else
		{
			cout << "original array: " << endl;
			for (int i = 0; i < n; i++)
			{
				cout << arr[i] << " ";
			}

			cout << endl << "hash: " << endl;
			for (int i = 0; i < m; i++)
			{
				cout << H[i] << " ";
			}

			cout << endl << "result: " << H[res] << endl;
		}
	}

    return 0;
}

