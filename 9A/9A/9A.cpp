//среднее значение положительных/отр. чисел

#include "stdafx.h"
#include<iostream>
#include <io.h>
#include <stdio.h>

using namespace std;

void WriteToFile(FILE*);
void ReadFromFile(FILE*);

int main()
{
	FILE *fl = NULL;

	WriteToFile(fl);
	ReadFromFile(fl);

	return 0;
}

void WriteToFile(FILE* fl) {

	fl = fopen("C:\\Users\\User\\Desktop\\test.txt", "wb");
	if (fl == NULL)
	{
		cout << "error" << endl;
		return;
	}

	cout << "Type in 10 numbers: " << endl;
	int t;
	for (int i = 0; i < 10; i++)
	{
		cin >> t;
		fwrite(&t, sizeof(t), 1, fl);
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

	fseek(fl, 0, SEEK_END);
	int size = ftell(fl);
	rewind(fl);

	int n = _filelength(_fileno(fl)) / sizeof(int);
	int* a = new int[n];
	fread(a, sizeof(int), n, fl);

	//считаем среднее значение положительных/отр. чисел
	int Neg = 0, Pos = 0, NegCounter = 0;

	for (int i = 0; i < 10; i++)
	{
		if (a[i] >= 0)
		{
			Pos += a[i];
		}

		else
		{
			Neg += a[i];
			NegCounter++;
		}

		cout << a[i] << ' ';
	}

	if (NegCounter == 0)
	{
		cout << endl << "there are no negative numbers" << endl << "positive med: " << Pos / 10. << endl;
	}

	if (NegCounter == 10)
	{
		cout << endl << "negative med: " << Neg / 10. << endl << "there are no positive numbers" << endl;
	}

	else
	{
		cout << endl << "negative med: " << Neg / static_cast <double> (NegCounter) << endl << "positive med: " << Pos / static_cast <double> (10 - NegCounter) << endl;
	}

	delete a;
	fclose(fl);
}