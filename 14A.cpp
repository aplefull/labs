#include "stdafx.h"
#include <iostream>

using namespace std;

struct list
{
	int data;
	list *prev;
	list *next;
};

void CreateList(list *&beg, list *&end, int num)
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

list* push_right(list *end, int data)
{
	list *t = new list;
	end->next = t;
	t->prev = end;
	t->data = data;
	t->next = NULL;
	return t;
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

list* Swap(list *first, list *second)
{
	if (second == first)
	{
		cout << "First element is minimal." << endl;
		return first;
	}

	if (first->next != second)
	{
		list *t = first->next;
		first->next->prev = second;
		second->prev->next = first;
		if (second->next != NULL)
		{
			second->next->prev = first;
		}
		first->next = second->next;
		first->prev = second->prev;
		second->prev = NULL;
		second->next = t;
		return second;
	}

	else
	{
		list *t = second->next;
		second->next->prev = first;
		second->next = first;
		second->prev = NULL;
		first->prev = second;
		first->next = t;
		return second;
	}
}

list* min(list *beg) 
{
	list *t = beg;
	list *min = beg;

	while(t != NULL)
	{
		if (min->data > t->data)
		{
			min = t;
		}

		t = t->next;
	}

	return min;
}

int main()
{
	list *beg, *end;
	int data, n;

	cout << "n of elements to add: ";
	cin >> n;

	cout << "number: ";
	cin >> data;
	CreateList(beg, end, data);
	for (int i = 0; i < n - 1; i++)
	{
		cout << "number: ";
		cin >> data;
		end = push_right(end, data);
	}

	Display(beg);

	beg = Swap(beg, min(beg));

	Display(beg);
	ClearList(beg);

    return 0;
}
