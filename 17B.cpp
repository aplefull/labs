#include "stdafx.h"
#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

struct product {
	char name[100];
	int cost;
	int date;
};

void add(product inf, int m, product *H)
{
	int i = inf.cost % m;

	if (H[i].cost != -1) {
		int p = 0;

		while (H[i].cost != -1)
		{
			i = i + p * p;
			if (i == m)
				i = 0;

			p++;
		}
	}
	H[i] = inf;
}

int search(int inf, int m, product H[]) {
	int i = abs(inf % m);
	int p = 0;

	while (H[i].cost != -1)
	{
		if (H[i].cost == inf)
			return i;

		i = i + p * p;
		if (i > m)
			i = 0;
	}

	return -1;
}


int main()
{
	int n = 8;
	product a[7];

	cout << "array of structs: " << endl;
	for (int i = 0; i < n; i++) {
		cout << "enter name, price and date: " << endl;
		cin >> a[i].name;
		cin >> a[i].cost;
		cin >> a[i].date;
	}

	int m = 15;
	product H[15];

	for (int i = 0; i < m; i++)
		H[i].cost = -1;
	for (int i = 0; i < n; i++)
		add(a[i], m, H);

	int item = 0, res;
	cout << "array: " << endl;

	for (int i = 0; i < 8; i++) {
		cout << a[i].name << " | " << a[i].cost << " | " << a[i].date << endl;
	}

	cout << "hash-table: " << endl;

	for (int i = 0; i < 15; i++) {

		if (H[i].cost == -1) {
			cout << H[i].cost << endl;
		}

		else {
			cout << "cost: " << H[i].cost << endl << "name: " << H[i].name << endl << "date: " << H[i].date << endl;
		}
	}

	while (item != -1) {

		cout << "item to search for: ";
		cin >> item;
		res = search(item, m, H);

		if (res == -1)
			cout << "there is no such element" << endl;

		else 
			cout << "result: " << endl << H[res].name << endl << H[res].cost << endl << H[res].date << endl;
		
	}
	return 0;
}

