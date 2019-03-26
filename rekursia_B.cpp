//вычислить число сочетаний по формуле C энное в нулевой степени = С энное в степени n = 1,
//С энное в степени К = (С (энное - 1) в степени  К) + (С (энное - 1) в степени К.

#include "pch.h"
#include <iomanip>
#include<iostream>
using namespace std;
int fun(int k, int n) {
	if (k == n || k == 0) {
		return 1;
	}
	else
	{
		return fun(k, n - 1) + fun(k - 1, n - 1);
	}

}

int main(){
	setlocale (LC_ALL, "ru");
	int a, b;
	cout << "введите a : ";
	cin >> a;
	cout << endl << "Введите b : ";
	cin >> b;
	cout << endl << "Число сочетаний : " << fun(a, b);
    return 0;
}