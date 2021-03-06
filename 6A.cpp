#include "stdafx.h"
#include <iostream>
#include <cmath>

using namespace std;

double func(double &);

int main()
{
	double step, a = 0.44, b = 1.1;
	step = (b - a) / 10.;
	for (; a <= b + step / 2; a += step) {
		cout << "x = " << a << " answ = " << func(a) << endl;
	}
	return 0;
}


double func(double &x) {
	double sum = 0;
	for (int i = 1; i <= 9; i++) {
		sum += 2 * tan(i*x)*tan(i*x) - sqrt(fabs(x));
	}
	return sum;
}
