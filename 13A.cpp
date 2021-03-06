#include "stdafx.h"
#include <iostream>
#define NULL 0

using namespace std;


struct stack
{
	int data;
	stack *next;
};

void AddStack(stack*&, int);
void Read(stack*);
void DeleteStack(stack*);
int PositiveCount(stack*);


int main()
{
	int x, size;
	stack *test = new stack;
	test = NULL;

	cout << "size: ";
	cin >> size;

	cout << "elements: ";
	for (int i = 0; i < size; i++)
	{
		cin >> x;
		AddStack(test, x);
	}

	Read(test);
	cout << endl;

	int pos = PositiveCount(test);

	if (pos > size - pos)
	{
		cout << "There are more positive elements in array." << endl;
	}

	else
	{
		if (pos != size - pos)
		{
			cout << "There are more negative elements in array." << endl;
		}

		else
		{
			cout << "Stack has equal number of positive and negative elements." << endl;
		}
	}

	DeleteStack(test);
    return 0;
}

void AddStack(stack *&pointer, int data) {
	stack *newPointer = new stack;
	newPointer->data = data;
	newPointer->next = pointer;
	pointer = newPointer;
}

void Read(stack *pointer) {
	stack *newPointer = pointer;
	while (newPointer != NULL)
	{
		cout << "Data: " << newPointer->data << endl;
		newPointer = newPointer->next;
	}
}

void DeleteStack(stack* pointer) {
	stack *temp;
	while (pointer != NULL)
	{
		temp = pointer;
		pointer = pointer->next;
		delete temp;
	}
}

int PositiveCount(stack* pointer) {
	int counter = 0;

	while (pointer != NULL)
	{
		if (pointer->data >= 0)
		{
			counter++;
			pointer = pointer->next;
		}

		else
		{
			pointer = pointer->next;
		}
	}
	return counter;
}
