#include "stdafx.h"
#include <iostream>
#include <string.h>
#include <math.h>
#include <ctype.h>

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
		case '/':

			if (data2 == 0 && data1 != 0)
			{
				cout << endl << "division by zero: " << data1 << "/" << data2;
				return INFINITY;
			}

			if (data1 == 0 && data2 == 0)
			{
				cout << endl << "0 is divided by 0, assuming it equals 1";
				return 1;
			}

			p = AddStack(p, data1 / data2); break;

		case '^': p = AddStack(p, pow(data1, data2)); break;
		}
	}

	p = ReadStack(p, data);
	return data;
}

bool CheckInput(char *str, char *args, int *count)
{
	int len = strlen(str);
	if (str[0] == '+' || str[0] == '*' || str[0] == '/' || str[0] == '^' || str[0] == ')') {
		cout << "equation can't start with arithmetic operation or closing bracket" << endl;
		return 0;
	}

	if (str[len - 1] == '+' || str[len - 1] == '-' || str[len - 1] == '*' || str[len - 1] == '/' || str[len - 1] == '^' || str[len - 1] == '(')
	{
		cout << "equation can't end with arithmetic operation or opening bracket" << endl;
		return 0;
	}

	if ((str[0] < 'a' || str[0] > 'z') && str[0] != '(') {
		cout << "wrong symbol, only lowercase letters from a to b and [+,-,*,/,^,(,)] are allowed" << endl;
		return 0;
	}

	if (((str[0] >= 'a' && str[0] <= 'z') && str[1] == '(') || ((str[1] >= 'a' && str[1] <= 'z') && str[0] == ')'))
	{
		cout << "can't have a letter and a bracket together" << endl;
		return 0;
	}

	if (str[0] >= 'a' && str[0] <= 'z') {
		args[*count] = str[0];
		(*count)++;
	}

	int Bracket = 0;
	if (str[0] == '(')
	{
		Bracket++;
	}

	for (int i = 1; i < len; i++)
	{
		if (str[i] == '(') Bracket++;
		if (str[i] == ')') Bracket--;

		if (Bracket < 0) {
			cout << "wrong balance of brakets" << endl;
			return 0;
		}

		if ((str[i] < 'a' || str[i] > 'z') && str[i] != '(' && str[i] != ')' && str[i] != '+' && str[i] != '-' && str[i] != '*' && str[i] != '/' && str[i] != '^') {
			cout << "wrong symbol, only lowercase letters from a to b and [+,-,*,/,^,(,)] are allowed" << endl;
			return 0;
		}

		if (str[i] >= 'a' && str[i] <= 'z' && str[i - 1] >= 'a' && str[i - 1] <= 'z') {
			cout << "two consequent letters are not allowed" << endl;
			return 0;
		}

		if ((str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '^') && (str[i - 1] == '+' || str[i - 1] == '-' || str[i - 1] == '*' || str[i - 1] == '/' || str[i - 1] == '^')) {
			cout << "two consequent operation signs are not allowed" << endl;
			return 0;
		}

		if (str[i - 1] == '(' && (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '^')) {
			cout << "can't have an arithmetic operator after opening bracket" << endl;
			return 0;
		}

		if (((str[i - 1] >= 'a' && str[i - 1] <= 'z') && str[i] == '(') || ((str[i] >= 'a' && str[i] <= 'z') && str[i - 1] == ')'))
		{
			cout << "can't have a letter and a bracket together" << endl;
			return 0;
		}

		if (str[i] == ')' && (str[i - 1] == '+' || str[i - 1] == '-' || str[i - 1] == '*' || str[i - 1] == '/' || str[i - 1] == '^')) {
			cout << "can't have an arithmetic operator before closing bracket" << endl;
			return 0;
		}

		if (str[i] >= 'a' && str[i] <= 'z') {
			args[*count] = str[i];
			(*count)++;
		}
	}

	if (Bracket != 0)
	{
		cout << "wrong balance of brakets" << endl;
		return 0;
	}

	return true;

}

int main()
{
	double res[122];
	char str[200], RPN[200], args[200];
	cout << "equation: ";
	cin >> str;
	int count = 0;

	if (!CheckInput(str, args, &count))
	{
		return 0;
	}

	cout << "type in values" << endl;
	for (int i = 0; i < count; i++) {
		double test;
		cout << args[i] << " = "; 
		cin >> test;

		if(!cin)
		{
			cout << "wrong input, type in number" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			i--;
		}

		else
		{
			res[int(args[i])] = test;
		}

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