
#include "stdafx.h"
#include <iostream>
#include <io.h>
#include <stdio.h>

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

seeds ToFile, *FromFile;


int main()
{
	FILE *fl = NULL;

	while (true)
	{
		switch (Menu())
		{
		case 1: WriteToFile(fl); break;
		case 2: ReadFromFile(fl); break;
		case 3: Display(fl); break;
		case 4: ExportFile(fl); break;

		default: cout << "Are you retarded or something?"; break;
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

void WriteToFile(FILE* fl) {

	fl = fopen("C:\\Users\\User\\Desktop\\test.txt","wb");
	if (fl == NULL)
	{
		cout << "error" << endl;
		return;
	}

	int n;
	cout << "number of seeds(<=10): ";
	cin >> n;

	cout << "name, planting month, harvesting month: " << endl;

	for (int i = 0; i < n; i++)
	{
		cin >> ToFile.name >> ToFile.plantingMonth >> ToFile.harvestingMonth;
		fwrite(&ToFile, sizeof(seeds), 1, fl);
	}

	fclose(fl);
}

void ReadFromFile(FILE* fl) {

	fl = fopen("C:\\Users\\User\\Desktop\\test.txt", "rb");
	if (fl == NULL)
	{
		cout << "error" << endl;
		return;
	}

	int n = _filelength(_fileno(fl)) / sizeof(seeds);
	FromFile = new seeds[n];
	fread(FromFile, sizeof(seeds), n, fl);

	delete FromFile;
	fclose(fl);
}

void Display(FILE* fl) {

	fl = fopen("C:\\Users\\User\\Desktop\\test.txt", "rb");
	if (fl == NULL)
	{
		cout << "error" << endl;
		return;
	}

	int n = _filelength(_fileno(fl)) / sizeof(seeds);
	FromFile = new seeds[n];
	fread(FromFile, sizeof(seeds), n, fl);

	for (int i = 0; i < n; i++)
	{
		cout << "name: " << FromFile[i].name << endl << "planting month: " << FromFile[i].plantingMonth << endl << "harvesting month:" << FromFile[i].harvestingMonth << endl << endl;
	}

	delete FromFile;
	fclose(fl);
}

void ExportFile(FILE* fl) {

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


	FILE* Export = fopen("C:\\Users\\User\\Desktop\\export.txt", "wb");
    if (Export == NULL)
	{
		cout << "error" << endl;
		return;
	}

	//сортировка
	for (int j = 0; j < n - 1; j++)
	{
		for (int i = 0; i < n - i; i++)
		{
			seeds t;
			if (FromFile[i].harvestingMonth > FromFile[i + 1].harvestingMonth) {
				t = FromFile[i];
				FromFile[i] = FromFile[i + 1];
				FromFile[i + 1] = t;
			}
		}
	}

	//экспорт
	for (int i = 0; i < n; i++)
	{

		if (FromFile[i].plantingMonth == 8)
		{
			fprintf(Export, "name: %s | planting month: %d | harvesting month: %d\n", FromFile[i].name, FromFile[i].plantingMonth, FromFile[i].harvestingMonth);
		}
	}

	delete FromFile;
	fclose(Export);
}
