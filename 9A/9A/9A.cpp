//среднее значение положительных/отр. чисел

#include "stdafx.h"
#include<iostream>
#include <io.h>
#include <stdio.h>
#include <ctime>
#include <string.h>

using namespace std;

int main()
{
	int num, len;
	char a[100] = "", temp[100] = "";
	int arr[10];

	FILE *fl = fopen("D:\\test.txt", "w");
	srand(time(NULL));
	
	//запись в файл
	for (int i = 0; i < 10; i++)
	{
		num = -10 + rand() % 20;

		fputs(_itoa(num, a, 10), fl);
		fputc(' ', fl);
	}

	fclose(fl);

	fopen("D:\\test.txt", "r");

	//получаем строку из файла
	fgets(a, 100, fl);

	len = strlen(a);

	//строку в массив intов
	for (int i = 0, n = 0, k = 0; i < len; i++)
	{
		if (a[i] == ' ')
		{
			arr[k] = atoi(temp);
			k++;
			n = 0;
			continue;
		}
		
		temp[n] = a[i];
		temp[n + 1] = '\0';
		n++;
	}

	//выводим массив и считаем среднее значение положительных/отр. чисел
	int Neg = 0, Pos = 0, NegCounter = 0, PosCounter = 0;

	for (int i = 0; i < 10; i++)
	{
		if (arr[i] >= 0)
		{
			Pos += arr[i];
			PosCounter++;
		}

		else
		{
			Neg += arr[i];
			NegCounter++;
		}

		cout << arr[i] << ' ';
	}

	cout << endl << "negative med: " << Neg /  static_cast <double> (NegCounter) << endl << "positive med: " << Pos / static_cast <double> (PosCounter) << endl;

	fclose(fl);

	return 0;
}