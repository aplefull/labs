#include "stdafx.h"
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int a, b, c, d, sumPos, sumNeg;
	sumPos = 0;
	sumNeg = 0;
	cout << "Type in 4 numbers: " << endl;
	cin >> a >> b >> c >> d;
	a >= 0 ? sumPos += a : sumNeg += abs(a);
	b >= 0 ? sumPos += b : sumNeg += abs(b);
	c >= 0 ? sumPos += c : sumNeg += abs(c);
	d >= 0 ? sumPos += d : sumNeg += abs(d);
	cout << "Sum of posivive: " << sumPos << endl;
	cout << "Sum of negative: " << sumNeg << endl;
	cout << sumPos - sumNeg << endl;

    return 0;
}

