// Кол-во "wse" в строке.
#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	int n = 0;
	char a[100];
	gets_s(a);

	while (strstr(a, "wse") != NULL){

		strcpy_s(a, strstr(a, "wse"));

		for (int i = 0; i < strlen(a) - 3; i++){
				a[i] = a[i + 3];
		}
		n++;
	}

	cout << n;
	return 0;
}