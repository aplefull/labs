#include "stdafx.h"
#include <iostream>

using namespace std;

struct list
{
	int data;
	list *left;
	list *right;
} *pointer;

void CreateList(list**, list**);
void AddToList(list*, int);
int main()
{


    return 0;
}

void CreateList(list **prev, list **next)
{
	*prev = new list;
	*next = new list;

	(*prev)->left = NULL;
	(*prev)->right = *next;
	(*next)->right = NULL;
	(*next)->left = *prev;
	return;
}

void AddToList(list *pointer, int data) {
	list *temp = new list;
	temp->data = data;
	temp->right = pointer->right;
	temp->left = pointer;
	pointer->right = temp;
	pointer->right->left = temp;

}