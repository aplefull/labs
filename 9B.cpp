
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
void ReadFromFile(FILE*, seeds*);
void Display(FILE*, seeds);
void ExportFile(FILE*, seeds);


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

		default: cout << "Choose num from 1 to 4"; break;
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
	cout << "Select what to do: \n 1: Write to the file \n 2: Read from file \n 3: Display data \n 4: Export file" << endl;
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

		if (ToFile.plantingMonth == 8)
		{
			fprintf(Export, "name: %s | planting month: %d | harvesting month: %d\n", ToFile.name, ToFile.plantingMonth, ToFile.harvestingMonth);
		}
	}

	fclose(fl);
	fclose(Export);
}
