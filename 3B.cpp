#include "stdafx.h"
#include <cmath>
#include <iostream>

using namespace std;

int main()
{
	double a, b, x, step, res, sum;
	a = -2;
	b = -0.1;
	x = a;
	step = (b - a) / 10.;

	while (x <= b) {
		res = x * cos(x);
		cout << x << "*cos("<< x << ") = " << res;
		 res = sum = x;
			for (int n = 1; n <= 140; n++) {
			res *= -x * x / ((2 * n - 1)*(2 * n));
			sum += res;
			}
		cout << " | " << sum << endl;
		x += step;
	}
	return 0;
}
