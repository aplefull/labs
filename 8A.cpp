#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	struct crops
	{
		char name[100];
		int monthPlant, monthPlant2, monthHarvest;
	};
	crops *seed;

	int size;
	cout << "Amount of different seeds: ";
	cin >> size;

	seed = new crops[size];

	for (int i = 0; i < size; i++)
	{
		cout << "Type in seed name, first month, 2nd month, harvest month: ";
		cin >> seed[i].name;
		cin >> seed[i].monthPlant;
		cin >> seed[i].monthPlant2;
		cin >> seed[i].monthHarvest;
	}

	for (int i = 0; i < size; i++)
	{
		if (seed[i].monthPlant2 == 3) {
			cout << "Plants, which have to be planted in March: " << seed[i].name << endl;
		}
	}

	delete[] seed;
	return 0;
}

