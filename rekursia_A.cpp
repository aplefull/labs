#include "pch.h"
#include <iomanip>
#include<iostream>
using namespace std;

int proz(int a[], int i, int j) {
	if (i == j) {
			if (a[i] < 0) return a[i];
		else return 1;
	}
	else
		return proz(a, i, (i + j) / 2)*proz(a,(i + j) / 2 + 1 , j);

}

int main() {
	int  n, i;
	bool t = false;
	setlocale(LC_ALL, "ru");
	cout << "Введите количество элементов массива" << endl;
	cin >> n;
	int *a = new int[n];
	cout << "Введите " << n << " элемента(ов) массива" << endl;
	for (i = 0; i < n; i++) {
		cout << "Введите элемент массива [" << i + 1 << "]     ";
		cin >> a[i];
	}
	for (i = 0; i < n; i++) {
		if (a[i] < 0) {
			t = true;
		}
	}
	if (t) {
		cout << "Произведение отрицательных элементов массива: " << proz(a, 0, n - 1) << endl;
	}
	else cout << "все элементы массива положительные." << endl;
	delete[] a;
	system("pause");
	return 0;
}