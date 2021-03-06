#/*
test1 7 2
test2 8 11
test3 8 6
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
#include <array>

using namespace std;

void CreateFile(FILE*);
int Menu();
void WriteToFile(FILE*);
void ReadFromFile(FILE*);
void Display(FILE*);
void ExportFile(FILE*);

struct seeds
{
	char name[100];
	int plantingMonth;
	int harvestingMonth;
};

void CreateFile(FILE*);
int Menu();
void WriteToFile(FILE*, seeds);
void ReadFromFile(FILE*, seeds*);
void Display(FILE*, seeds);
void ExportFile(FILE*, seeds);

void LinearSearch(FILE*, seeds*);
void BinarySearch(FILE*, seeds*);
void SelectionSort(FILE*, seeds []);

int main()
{
	FILE *fl = NULL;
	
	seeds ToFile = { " ", 0, 0 }, *FromFile = nullptr;

	while (true)
	{
		switch (Menu())
		{
		case 1: WriteToFile(fl, ToFile); break;
		case 2: ReadFromFile(fl, FromFile); break;
		case 3: Display(fl, ToFile); break;
		case 4: ExportFile(fl, ToFile); break;
		case 5: LinearSearch(fl, FromFile); break;
		case 6: BinarySearch(fl, FromFile); break;

		default: cout << "Type number from 1 to 6"; break;
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
	cout << "Select what to do: \n 1: Write to the file \n 2: Read from file \n 3: Display data \n 4: Export file \n 5: Linear search \n 6: Binary search" << endl;
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

void ReadFromFile(FILE* fl, seeds *FromFile) {

	fl = fopen("C:\\Users\\User\\Desktop\\test.txt", "rb");
	if (fl == NULL)
	{
		cout << "error" << endl;
		return;
	}

	int n = _filelength(_fileno(fl)) / sizeof(seeds);
	FromFile = new seeds[n];
	fread(FromFile, sizeof(seeds), n, fl);

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

void SelectionSort(FILE* fl, seeds FromFile[]) {

	int size = _filelength(_fileno(fl)) / sizeof(seeds);
	seeds temp;

	for (int i = 0; i < size - 1; i++)
	{
		int min_index = i;

		for (int k = i; k < size; k++) {

			if (FromFile[k].harvestingMonth < FromFile[min_index].harvestingMonth) {
				min_index = k;
			}

		}

		if (min_index != i)
		{
			temp = FromFile[i];
			FromFile[i] = FromFile[min_index];
			FromFile[min_index] = temp;
		}
	}
}