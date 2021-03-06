#include "stdafx.h"
#include <iostream>

using namespace std;

struct tree
{
	int data;
	tree *left, *right;
};

void add(tree *&t, int a)
{
	if (t == NULL)
	{
		tree *node = new tree;
		node->data = a;
		node->right = node->left = NULL;
		t = node;
		return;
	}

	if (a > t->data)
	{
		add(t->right, a);
		return;
	}

	if (a < t->data)
	{
		add(t->left, a);
		return;
	}

	else
	{
		cout << "Duplicates are not allowed." << endl;
		return;
	}
}

void Pre_order(tree *&t)
{
	if (t != NULL)
	{
		cout << t->data << " ";
		Pre_order(t->left);
		Pre_order(t->right);
	}
}

void Post_order(tree *&t)
{
	if (t != NULL)
	{
		Post_order(t->left);
		Post_order(t->right);
		cout << t->data << " ";
	}
}

void In_order(tree *&t)
{
	if (t != NULL)
	{
		In_order(t->left);
		cout << t->data << " ";
		In_order(t->right);
	}
}

void erase(tree *t) 
{
	if (t != NULL)
	{
		erase(t->left);
		erase(t->right);
		delete t;
	}
	t = NULL;
}

tree* Delete(tree *&t, int key) 
{
	tree *temp1 = t, *temp2 = t; //temp2 - элемент на уровень выше

	while (temp1 != NULL && temp1->data != key)
	{
		temp2 = temp1;

		if (key < temp1->data)
		{
			temp1 = temp1->left;
		}

		else
		{
			temp1 = temp1->right;
		}
	}

	if (temp1 == NULL)
	{
		cout << "There is no such element." << endl;
		return t;
	}

	if (temp1->left == NULL && temp1->right == NULL) //нет дочерних
	{
		if (temp2 == temp1)
		{
			delete temp1;
			return NULL;
		}

		if (temp2->left == temp1)
		{
			temp2->left = NULL;
		}

		else
		{
			temp2->right = NULL;
		}

		delete temp1;
		return t;
	}

	if (temp1->left == NULL) //один дочерний справа
	{
		if (temp1 == temp2)
		{
			temp1 = temp1->right;
			delete temp2;
			return temp1;
		}

		if (temp1 == temp2->left)
		{
			temp2->left = temp1->right;
			delete temp1;
			return t;
		}

		else
		{
			temp2->right = temp1->right;
			delete temp1;
			return t;
		}
	}

	if (temp1->right == NULL) //один дочерний слева
	{
		if (temp1 == temp2)
		{
			temp1 = temp1->left;
			delete temp2;
			return temp1;
		}

		if (temp1 == temp2->left)
		{
			temp2->left = temp1->left;
			delete temp1;
			return t;
		}

		else
		{
			temp2->right = temp1->left;
			delete temp1;
			return t;
		}
	}

	tree *w = temp1->left, *v = NULL;
	if (w->right == NULL)
	{
		w->right = temp1->right;
	}

	else
	{
		while (w->right != NULL)
		{
			v = w;
			w = w->right;
		}

		v->right = w->left;
		w->left = temp1->left;
		w->right = temp1->right;
	}

	if (temp1 == temp2)
	{
		delete temp1;
		return w;
	}

	if (temp2->left == temp1)
	{
		temp2->left = w;
		delete temp1;
	}

	else
	{
		temp2->right = w;
		delete temp1;
	}

	return t;
}

int FindEven(tree *&t) 
{
	int num;
	if (t != NULL) 
	{
		if (t->data % 2 == 0)
		{
			return t->data;
		}
		
		num = FindEven(t->left);
		if (num % 2 == 0)
		{
			return num;
		}

		num = FindEven(t->right);
		if (num % 2 == 0)
		{
			return num;
		}
		
	}

	return -1;
	
}


int main()
{
	tree *root = NULL;
	int data, n;

	cout << "number of elements: ";
	cin >> n;

	cout << "root: ";
	cin >> data;

	add(root, data);
	for (int i = 0; i < n - 1; i++)
	{
		cout << "element: ";
		cin >> data;
		add(root, data);
	}

	cout << "Pre-order: ";
	Pre_order(root);
	cout << endl;

	cout << "Post-order: ";
	Post_order(root);
	cout << endl;

	cout << "In-order: ";
	In_order(root);
	cout << endl;

	int num = FindEven(root);
	while (num != -1)
	{
		root = Delete(root, num);
		num = FindEven(root);
	}
	
	cout << "Pre-order (odd elements): ";
	Pre_order(root);
	cout << endl;

	return 0;
}

