// BinaryTree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "BinaryTree.h"
#include <iostream>


void BinaryTree::Insert(int x)
{
	auto n= make_unique<node>(nullptr, nullptr, x);
	if(root==nullptr)
	{
		root = std::move(n);
		return;
	}
	else
	{
		auto temp = root.get();
		auto prev = root.get();
		while(temp!=nullptr)
		{
			temp->siz++;
			prev = temp;
			if (x < temp->data)
				temp = temp->left.get();
			else
				temp = temp->right.get();
		}
		if (x < prev->data)
			prev->left = std::move(n);
		else
			prev->right = std::move(n);
	}
}

BinaryTree::BinaryTree(const vector<int>& v)
{
	for(const auto& x: v)
	{
		Insert(x);
	}
}

const BinaryTree::node* BinaryTree::find(int x) const
{
	auto temp = root.get();
	while(temp!=nullptr)
	{
		if (x > temp->data)
			temp = temp->right.get();
		else if (x < temp->data)
			temp = temp->left.get();
		else
			return temp;
	}
	return nullptr;
}

void BinaryTree::print() const
{
	print(root);
}

int BinaryTree::lengthUtil(const node* node)
{
	if (node == nullptr)
		return 0;
	return 1 + lengthUtil(node->left.get()) + lengthUtil(node->right.get());
}

int BinaryTree::length()
{
	return lengthUtil(getRoot());
}

bool BinaryTree::checkBSTUtil(const node* node, int min, int max) const
{
	if(node==nullptr)
	{
		return true;
	}
	if(node->data < min || node->data >= max) {
		return false;
	}
	return checkBSTUtil(node->left.get(), min, node->data) && checkBSTUtil(node->right.get(), node->data, max);
}

bool BinaryTree::checkBST()
{
	auto temp = getRoot();
	return checkBSTUtil(temp, INT_MIN, INT_MAX);
}

int BinaryTree::printIndex(int x) const
{

}

void BinaryTree::print(const unique_ptr<node>& n) const
{
	if (n == nullptr)
		return;
	print(n->left);
	std::cout << n->data << endl;
	print(n->right);
}
