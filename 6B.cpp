#include "stdafx.h"
#include <iostream>
#include <cmath>

using namespace std;

double fish(double &);
double water(double);

int main()
{
	double step, a = -1.5, b = 1.5;
	step = (b - a) / 10.;
	for (; a <= b + step / 2; a += step) {
		cout << "x = " << a << " | cos(x)^3 = " << fish(a) << " | series decomposition = " << water(a) << endl;
	}
    return 0;
}

double fish(double &x) {
	return pow(cos(x), 3);
}

double water(double x) {
	double sum = 4, a = 3, b = 1;
	for (int n = 1; fabs(a + b) > 1e-4; n++) {
		b *= -9 * x * x / (2 * n * (2 * n - 1));
		a *= -x * x / (2 * n * (2 * n - 1));
		sum += a + b;
	}
	return 0.25 * sum;
}