#include "stdafx.h"
#include <iostream>

using namespace std;

double flying_pan(int n, double k,  int i);

int main()
{
	double k;
	int n, i;
	cout << "n&k: ";
	cin >> n >> k;


	cout << flying_pan(n, k, 1) << endl;
    return 0;
}

double flying_pan(int n, double k, int i)
{
	if (i == n)
	{
		return pow(n, k);
	}

	return pow(i, k) + flying_pan(n, k, i + 1);
}
