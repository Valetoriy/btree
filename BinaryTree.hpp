#pragma once

#include <iostream>

class BinaryTree
{
	int value;
	BinaryTree* left;
	BinaryTree* right;

	BinaryTree* FindMin(BinaryTree* root)
	{
		while (root->left != 0) root = root->left;
		return root;
	}
public:
	BinaryTree(int x) : value(x), left(0), right(0) {};

	void add(int x)
	{
		if (x <= value)
		{
			if (left == 0) left = new BinaryTree(x);
			else left->add(x);
		}
		else if (x > value)
		{
			if (right == 0) right = new BinaryTree(x);
			else right->add(x);
		}
	}

	BinaryTree* remove(int x)
	{
		BinaryTree* root = this;
		if (x < value && left != 0) left = left->remove(x);
		else if (x > value && right != 0) right = right->remove(x);
		else if (x == value)
		{
			if (left == 0 && right == 0)
			{
				delete root;
				root = 0;
			}
			else if (left == 0)
			{
				BinaryTree* temp = root;
				root = right;
				delete temp;
			}
			else if (right == 0)
			{
				BinaryTree* temp = root;
				root = left;
				delete temp;
			}
			else
			{
				BinaryTree* temp = FindMin(right);
				value = temp->value;
				right = right->remove(temp->value);
			}
		}
		return root;
	}

	void print()
	{
		if (left != 0) left->print();
		std::cout << value << " ";
		if (right != 0) right->print();
	}
};