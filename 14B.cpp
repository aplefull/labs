#include "stdafx.h"
#include <iostream>

using namespace std;

struct list
{
	char data;
	list *next, *prev;
};

void CreateList(list *&beg, list *&end, char num)
{
	list *t = new list;
	t->data = num;
	t->next = t->prev = NULL;
	beg = end = t;
}

void Display(list *beg)
{
	cout << "list: ";
	while (beg != NULL)
	{
		cout << beg->data << " ";
		beg = beg->next;
	}
	cout << endl;
}

list* push_right(list *end, char data)
{
	list *t = new list;
	end->next = t;
	t->prev = end;
	t->data = data;
	t->next = NULL;
	return t;
}

void Delete(list *&element)
{
	list *t = element;
	if (t->next == NULL)
	{
		t->prev->next = NULL;
	}

	else if (t->prev == NULL)
	{
		t->next->prev = NULL;
	}
	
	else
	{
		t->prev->next = t->next;
		t->next->prev = t->prev;
	}

	delete t;
}

void ClearList(list *&beg)
{
	list *t;
	while (beg != NULL)
	{
		t = beg->next;
		delete beg;
		beg = t;
	}
}


int main()
{
	list *beg = NULL, *end = NULL;
	int n;
	char data;

	cout << "n of elements to add: ";
	cin >> n;

	cout << "char: ";
	cin >> data;
	CreateList(beg, end, data);
	for (int i = 0; i < n - 1; i++)
	{
		cout << "char: ";
		cin >> data;
		end = push_right(end, data);
	}

	Display(beg);
	
	list *buff;
	for (list *temp = beg; temp != NULL; temp = temp->next)
	{
		for (list *temp2 = temp->next; temp2 != NULL;)
		{
			if (temp->data == temp2->data)
			{
				buff = temp2->next;
				Delete(temp2);
				temp2 = buff;

				if (temp2 == NULL)
				{
					break;
				}
			}

			else
			{
				temp2 = temp2->next;
			}
		}
	}

	Display(beg);
	ClearList(beg);

	return 0;
}

