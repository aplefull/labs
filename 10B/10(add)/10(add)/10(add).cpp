#include "stdafx.h"
#include <iostream>
#include <cmath>

using namespace std;

double apple(int, int);

int main()
{
	int n;
	cout << "n: ";
	cin >> n;
	
	cout << apple(n, 1) << endl;

    return 0;
}

double apple(int n, int k)
{
	if (n == 0)
	{
		return 0;
	}

	if (n == k)
	{
		return sqrt(n);
	}

	else
	{
		return sqrt(k + apple(n, k + 1));
	}

}