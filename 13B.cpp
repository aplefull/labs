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
void AddToStack(stack*, int, int);
int Max(stack*);


int main()
{
	int x, size;
	stack *ptr = new stack;
	ptr = NULL;

	cout << "size: ";
	cin >> size;

	cout << "elements: ";
	for (int i = 0; i < size; i++)
	{
		cin >> x;
		AddStack(ptr, x);
	}

	Read(ptr);
	cout << endl;

	AddToStack(ptr, Max(ptr), 999999);

	Read(ptr);

	DeleteStack(ptr);
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

void AddToStack(stack *pointer, int place, int data)
{
	stack *temp = new stack;
	for (int i = 0; i < place - 1; i++)
	{
		pointer = pointer->next;
	}

	temp->data = data;
	if (pointer->next == NULL)
	{
		temp->next = NULL;
	}

	else
	{
		temp->next = pointer->next;
	}
	pointer->next = temp;

}

int Max(stack* pointer) {
	int max = pointer->data, index = 0;
	for (int i = 0; pointer->next != NULL; i++)
	{
		pointer = pointer->next;
		if (pointer->data > max)
		{
			max = pointer->data;
			index = i + 2;
		}
	}
	return index;
}
