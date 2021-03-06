/*
test1 7 2
test2 8 11
test3 8 46
test4 8 1
test5 8 10
test6 8 0
test7 8 10
test8 8 5
*/


#include "stdafx.h"
#include <iostream>
#include <io.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;


struct seeds
{
	char name[100];
	int plantingMonth;
	int harvestingMonth;
};

void CreateFile(FILE*);
int Menu();
void WriteToFile(FILE*, seeds);
void Display(FILE*, seeds);
void ExportFile(FILE*, seeds);
void DisplayFromStruct(FILE*, seeds*);

void QuickSort(seeds[], int , int );
void SelectionSort(FILE* , seeds[]);

void LinearSearch(FILE*, seeds*);
void BinarySearch(FILE*, seeds*);

int main()
{
	FILE *fl = NULL;

	seeds ToFile = { " ", 0, 0 }, *FromFile = nullptr;

	while (true)
	{
		switch (Menu())
		{
		case 1: WriteToFile(fl, ToFile); break;
		case 2: Display(fl, ToFile); break;
		case 3: ExportFile(fl, ToFile); break;
		case 4: DisplayFromStruct(fl, FromFile); break;
		case 5: LinearSearch(fl, FromFile); break;
		case 6: BinarySearch(fl, FromFile); break;

		default: cout << "Choose num from 1 to 6"; break;
		}

		break;
	}

	return 0;
}

void CreateFile(FILE* fl)
{
	fl = fopen("C:\\Users\\User\\Desktop\\test.txt", "wb");

	if (fl == NULL)
	{
		cout << "error" << endl;
		return;
	}

	fclose(fl);
}

int Menu() {
	int x;
	cout << "Select what to do: \n 1: Write to the file \n 2: Display data \n 3: Export file \n 4: Sort and display \n 5: Linear search \n 6: Binary search" << endl;
	cin >> x;
	return x;
}

void WriteToFile(FILE* fl, seeds ToFile) {

	fl = fopen("C:\\Users\\User\\Desktop\\test.txt", "wb");
	if (fl == NULL)
	{
		cout << "error" << endl;
		return;
	}

	int n;
	cout << "number of seeds: ";
	cin >> n;

	cout << "name, planting month, harvesting month: " << endl;

	for (int i = 0; i < n; i++)
	{
		cin >> ToFile.name >> ToFile.plantingMonth >> ToFile.harvestingMonth;
		fwrite(&ToFile, sizeof(seeds), 1, fl);
	}

	fclose(fl);
}

void Display(FILE* fl, seeds ToFile) {

	fl = fopen("C:\\Users\\User\\Desktop\\test.txt", "rb");
	if (fl == NULL)
	{
		cout << "error" << endl;
		return;
	}

	int n = _filelength(_fileno(fl)) / sizeof(seeds);

	for (int i = 0; i < n; i++)
	{
		fread(&ToFile, sizeof(seeds), 1, fl);
		printf("name: %s | planting month: %d | harvesting month: %d\n", ToFile.name, ToFile.plantingMonth, ToFile.harvestingMonth);
	}

	fclose(fl);
}

void ExportFile(FILE* fl, seeds ToFile) {

	fl = fopen("C:\\Users\\User\\Desktop\\test.txt", "rb");
	if (fl == NULL)
	{
		cout << "error" << endl;
		return;
	}

	int n = _filelength(_fileno(fl)) / sizeof(seeds);

	FILE* Export = fopen("C:\\Users\\User\\Desktop\\export.txt", "wb");
	if (Export == NULL)
	{
		cout << "error" << endl;
		return;
	}

	//экспорт
	for (int i = 0; i < n; i++)
	{
		fread(&ToFile, sizeof(seeds), 1, fl);
		fprintf(Export, "name: %s | planting month: %d | harvesting month: %d\n", ToFile.name, ToFile.plantingMonth, ToFile.harvestingMonth);
	}

	fclose(fl);
	fclose(Export);
}

void DisplayFromStruct(FILE *fl, seeds *a)
{
	fl = fopen("C:\\Users\\User\\Desktop\\test.txt", "rb");
	int n = _filelength(_fileno(fl)) / sizeof(seeds);
	a = new seeds[n];
	fread(a, sizeof(seeds), n, fl);
	

	QuickSort(a, 0, n - 1);
	//SelectionSort(fl, a);
	fclose(fl);

	for (int i = 0; i < n; i++)
	{
		printf("name: %s | planting month: %d | harvesting month: %d\n", a[i].name, a[i].plantingMonth, a[i].harvestingMonth);
	}
	
}


void SelectionSort(FILE* fl, seeds arr[]) {

	int size = _filelength(_fileno(fl)) / sizeof(seeds), min_index;
	seeds temp;

	for (int i = 0; i < size - 1; i++)
	{
		min_index = i;

		for (int k = i; k < size; k++) {

			if (arr[k].harvestingMonth < arr[min_index].harvestingMonth) {
				min_index = k;
			}

		}

		if (min_index != i)
		{
			temp = arr[i];
			arr[i] = arr[min_index];
			arr[min_index] = temp;
		}
	}
}

void QuickSort(seeds a[], int start, int end) {

	struct
	{
		int l;
		int r;
	} stack[20];

	int i, j, left, right, z = 0;
	seeds temp, pivot;

	stack[z].l = start; stack[z].r = end;

	while (z != -1)
	{
		left = stack[z].l; right = stack[z].r;
		z--;

		while (left < right)
		{
			i = left; j = right; pivot = a[(left + right) / 2];

			while (i <= j)
			{
				while (a[i].harvestingMonth < pivot.harvestingMonth)
				{
					i++;
				}

				while (a[j].harvestingMonth > pivot.harvestingMonth)
				{
					j--;
				}

				if (i <= j)
				{
					temp = a[i];
					a[i] = a[j];
					a[j] = temp;
					i++;
					j--;
				}
			}

			if ((j - left) < (right - i))
			{
				if (i < right)
				{
					z++;
					stack[z].l = i;
					stack[z].r = right;
				}

				right = j;
			}

			else
			{
				if (left < j)
				{
					z++;
					stack[z].l = left;
					stack[z].r = j;
				}

				left = i;
			}
		}
	}
}

void LinearSearch(FILE* fl, seeds* FromFile)
{
	fl = fopen("C:\\Users\\User\\Desktop\\test.txt", "rb");
	int size = _filelength(_fileno(fl)) / sizeof(seeds);
	FromFile = new seeds[size];
	fread(FromFile, sizeof(seeds), size, fl);
	fclose(fl);

	int item;
	cout << "item to serach for: ";
	cin >> item;

	for (int i = 0; i < size; i++)
	{
		if (FromFile[i].harvestingMonth == item)
		{
			cout << FromFile[i].name << endl;
			delete[] FromFile;
			return;
		}
	}
	delete[] FromFile;
	cout << "there is no such element" << endl;
}

void BinarySearch(FILE* fl, seeds* FromFile)
{
	fl = fopen("C:\\Users\\User\\Desktop\\test.txt", "rb");
	int size = _filelength(_fileno(fl)) / sizeof(seeds);
	FromFile = new seeds[size];
	fread(FromFile, sizeof(seeds), size, fl);
	SelectionSort(fl, FromFile);
	fclose(fl);

	int i = 0, j = size, median, item;
	cout << "item to serach for: ";
	cin >> item;

	while (i < j)
	{
		median = (i + j) / 2;
		if (FromFile[median].harvestingMonth < item)
		{
			i = median + 1;
		}

		else
		{
			j = median;
		}

		if (FromFile[median].harvestingMonth == item)
		{
			cout << FromFile[median].name << endl;
			delete[] FromFile;
			return;
		}
	}
	delete[] FromFile;
	cout << "there is no such element" << endl;
}