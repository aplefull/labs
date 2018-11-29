#include "stdafx.h"
#include <iostream>
#include <cmath>

using namespace std;

double func(double &, int &);

int main()
{
	double step, a = 0.44, b = 1.1;
	int n = 9;
	step = (b - a) / 10.;
	for (; a <= b + step / 2; a += step) {
		cout << "x = " << a << " answ = " << func(a, n) << endl;
	}
	return 0;
}


double func(double &x, int&n) {
	double sum = 0;
	for (int i = 1; i <= n; i++) {
		sum += 2 * tan(i*x)*tan(i*x) - sqrt(fabs(x));
	}
	return sum;
}
