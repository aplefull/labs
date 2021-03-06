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

	if(a < t->data)
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

int NodeSum(tree *&t) 
{
	int sum = 0;

	if (t == NULL) {
		return 0;
	}

	else if (t->right != NULL && t->left != NULL)
	{
		sum += t->data;
	}

	sum += NodeSum(t->right);
	sum += NodeSum(t->left);

	return sum;
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
	for (int i = 0; i < n-1; i++)
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

	cout << endl << "Sum of nodes with 2nd degree = " << NodeSum(root) << endl;

    return 0;
}

