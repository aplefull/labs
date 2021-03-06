#include "stdafx.h"
#include <iostream>

using namespace std;

double fish(int);
double not_fish(int);


int main()
{
	int n;

	cout << "n: ";
	cin >> n;

	cout << fish(n) << endl << not_fish(n) << endl;

    return 0;
}

//рекурсия
double fish(int n) {

	if (n == 0)
	{
		return 0;
	}

	if (n == 1)
	{
		return 1. / (1 + 1. / 2);
	}

	else
	{
		return 1/(n + fish(n - 1));
	}


}

//цикл
double not_fish(int n)
{
	double sum = 1 / 2.;

	if (n == 0)
	{
		return 0;
	}

	for (int i = 1; i <= n; i++)
	{
		sum = 1 / (i + sum);
	}

	return sum;
}
