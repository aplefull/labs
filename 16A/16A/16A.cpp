#include "stdafx.h"
#include <iostream>
#include <string.h>
#include <math.h>

using namespace std;

struct stack
{
	double data;
	stack *next;
};

stack *AddStack(stack* p, double data)
{
	stack* t = new stack;
	t->data = data;
	t->next = p;
	return t;
}

stack *ReadStack(stack* p, double &data)
{
	stack *t = p;
	data = t->data;
	p = p->next;
	delete t;
	return p;
}

int priority(char ch)
{
	switch (ch)
	{
	case '(': case ')': return 0;
	case '+': case '-': return 1;
	case '*': case '/': return 2;
	case '^': return 3;
	default: return -1;
	}
}

void AddPostFix(char *strin, char *strout)
{
	stack *p = NULL;
	int n = 0;
	char ch;
	double data;

	for (int i = 0; i < strlen(strin); i++)
	{
		ch = strin[i];
		if (ch == '^')
		{
			int pr = priority(ch);
			while (p != NULL && priority((char)p->data) >= pr)
			{
				p = ReadStack(p, data);
				strout[n++] = (char)data;
			}
			p = AddStack(p, ch);
			continue;
		}

		if (ch >= 'A')
		{
			strout[n++] = ch;
			continue;
		}

		if (p == NULL || ch == '(')
		{
			p = AddStack(p, ch);
			continue;
		}

		if (ch == ')')
		{
			while (p->data != '(')
			{
				p = ReadStack(p, data);
				strout[n++] = (char)data;
			}
			p = ReadStack(p, data);
			continue;
		}

		int pr = priority(ch);
		while (p != NULL && priority((char)p->data) >= pr)
		{
			p = ReadStack(p, data);
			strout[n++] = (char)data;
		}
		p = AddStack(p, ch);
	}

	while (p != NULL)
	{
		p = ReadStack(p, data);
		strout[n++] = (char)data;
	}

	strout[n++] = '\0';
}

double rasAV(char *str, double *res)
{
	stack *p = NULL;
	char ch;
	double data, data1, data2;

	for (int i = 0; i < strlen(str); i++)
	{
		ch = str[i];

		if (ch >= 'A' && ch != '^')
		{
			p = AddStack(p, res[int(ch)]);
			continue;
		}

		p = ReadStack(p, data2);
		p = ReadStack(p, data1);
		switch (ch)
		{
		case '+': p = AddStack(p, data1 + data2); break;
		case '-': p = AddStack(p, data1 - data2); break;
		case '*': p = AddStack(p, data1 * data2); break;
		case '/': p = AddStack(p, data1 / data2); break;
		case '^': p = AddStack(p, pow(data1, data2)); break;
		}
	}

	p = ReadStack(p, data);
	return data;
}

int main()
{
	double res[122];
	char str[200], RPN[200], args[200];
	cout << "equation: ";
	cin >> str;
	int count = 0;
	bool NoError = true;

	if (str[0] == '+' || str[0] == '*' || str[0] == '/' || str[0] == '^' || str[0] == ')' || str[strlen(str) - 1] == '+' || str[strlen(str) - 1] == '-' || str[strlen(str) - 1] == '*' || str[strlen(str) - 1] == '/' || str[strlen(str) - 1] == '^' || str[strlen(str) - 1] == '(') {
		NoError = false;
	}
		
	if (str[0] < 'a' || str[0] > 'z') {
		cout << "wrong symbol" << endl;
		NoError = false;
	}

	if (str[0] >= 'a' && str[0] <= 'z') {
		args[count] = str[0];
		count++;
	}

	int openingBracket = 0, closingBracket = 0;
	if (str[0] == '(')
		openingBracket++;

	if (NoError == true)
	{

		for (int i = 1; i < strlen(str); i++)
		{
			if (str[i] == '(') openingBracket++;
			if (str[i] == ')') closingBracket++;
				
			if (closingBracket > openingBracket) {
				NoError = false;
				break;
			}

			if ((str[i] < 'a' || str[i] > 'z') && str[i] != '(' && str[i] != ')' && str[i] != '+' && str[i] != '-' && str[i] != '*' && str[i] != '/' && str[i] != '^') {
				cout << "wrong symbol" << endl;
				NoError = false;
				break;
			}

			if (str[i] == '0' && str[i - 1] == '/') {
				cout << "division by 0" << endl;
				NoError = false;
				break;
			}

			if (str[i] >= 'a' && str[i] <= 'z' && str[i - 1] >= 'a' && str[i - 1] <= 'z') {
				NoError = false;
				break;
			}
				
			if ((str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '^') && (str[i - 1] == '+' || str[i - 1] == '-' || str[i - 1] == '*' || str[i - 1] == '/' || str[i - 1] == '^')) {
				NoError = false;
				break;
			}
				
			if (str[i - 1] == '(' && (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '^')) {
				NoError = false;
				break;
			}

			if (str[i] == ')' && (str[i - 1] == '+' || str[i - 1] == '-' || str[i - 1] == '*' || str[i - 1] == '/' || str[i - 1] == '^')) {
				NoError = false;
				break;
			}

			if (str[i] >= 'a' && str[i] <= 'z') {
				args[count] = str[i];
				count++;
			}
		}

		if (openingBracket != closingBracket)
		{
			cout << "wrong number of brackets" << endl;
			NoError = false;
		}
	}


	if (NoError == true)
	{
		cout << "type in values" << endl;
		for (int i = 0; i < count; i++) {
			cout << args[i] << " = "; cin >> res[int(args[i])];
		}

		AddPostFix(str, RPN);

		cout << "RPN: " << RPN;

		double result = rasAV(RPN, res);

		if (isinf(result))
		{
			cout << endl << "infinity reached during the calculation" << endl;
			return 0;
		}

		if (isnan(result))
		{
			cout << endl << "unknow error occured during the calculation" << endl;
			return 0;
		}

		cout << endl << "result: " << result << endl;
		return 0;
	}

	else {
		cout << "syntax error" << endl;
		return 0;
	}
}