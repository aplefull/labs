#include "stdafx.h"
#include <iostream>
#include <cmath>

using namespace std;

double func1(double &);
double func2(double &);

int main()
{
	double step, a = -1.5, b = 1.5;
	step = (b - a) / 10.;
	for (a; a <= b+step/2; a += step) {
		cout << "x = " << a << " | cos(x)^3 = " << func1(a) << " | series decomposition = "<< func2(a) << endl;
	}
    return 0;
}

double func1(double &x) {
	return pow(cos(x), 3);
}

double func2(double &x) {
	double sum = 4, a = 3, b = 1;
	for (int n = 1; fabs(a + b) > 0.001; n++) {
		b *= -9 * x * x / (2 * n * (2 * n - 1));
		a *= -x * x / (2 * n * (2 * n - 1));
		sum += a + b;
	}
	return 0.25 * sum;
}
