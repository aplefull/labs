#include "stdafx.h"
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int k;
	double x, y, q, f, a;
	cout << "1 - sh(x), 2 - x^2, 3 - e^x" << endl;
	cin >> k;
	cout << "Type in x and y" << endl;
	cin >> x >> y;

	switch (k)
	{
	case 1:{
		f = sinh(x);
		cout << "f = sinh(" << x << ")" << " = " << f << endl;
		break;
		}

	case 2:{
		f = x * x;
		cout << "f = " << x << "^2" << " = " << f << endl;
		break;
		}

	case 3:{
		f = exp(x);
		cout << "f = e^" << x << " = " << f << endl;
		break;
		}
	}

	a = y * f;

	if (a == 10) {
		q = log(x) - f * f;
		cout << "q = log(" << x << ")" << " - " << f << "^2" << endl;
	}
	else {

		if (a < 10) {
			q = 2 * y - 10 * sin(x);
			cout << "q = 2*" << y << " - 10 * sin(" << x << ")" << endl;
		}
			else {
			q = y * y + f * f;
			cout << "q = " << y << "^2" << " + " << f << "^2" << endl;
			}
	}
		cout << "q = " << q << endl;

    return 0;
}

