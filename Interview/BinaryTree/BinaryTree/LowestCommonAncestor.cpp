#include "stdafx.h"
#include "LowestCommonAncestor.h"
#include <iostream>

LowestCommonAncestor::LowestCommonAncestor(const vector<int>& v) : BinaryTree(v)
{
}

void LowestCommonAncestor::print() const
{
	print();
}

int LowestCommonAncestor::Solution1(int x, int y) const
{
	auto lcaret = Solution1Util(getRoot(),find(x), find(y));
	if (lcaret == nullptr)
		return -1;
	else
		return lcaret->data;
}

int LowestCommonAncestor::Solution12(int x, int y) const
{
	auto lcaret = Solution2Util(getRoot(), find(x), find(y));
	if (lcaret == nullptr)
		return -1;
	else
		return lcaret->data;
}

const BinaryTree::node* LowestCommonAncestor::Solution1Util(const BinaryTree::node* r, const BinaryTree::node* a, const BinaryTree::node* b) const
{
	if(a==nullptr || b==nullptr || r==nullptr)
	{
		return nullptr;
	}
	if (r == a || r == b)
		return r;
	auto left = Solution1Util(r->left.get(), a, b);
	auto right = Solution1Util(r->right.get(), a, b);

	if (left != nullptr && right != nullptr)
		return r;
	else if (left == nullptr && right == nullptr)
		return nullptr;
	return left != nullptr ? left : right;
}

const BinaryTree::node* LowestCommonAncestor::Solution2Util(const node* node, const BinaryTree::node* node1, const BinaryTree::node* node2) const
{
	if(node==nullptr || node1 == nullptr || node2==nullptr)
	{
		return nullptr;
	}
	auto temp = node;
	while(temp!=nullptr)
	{
		if ((node1->data > temp->data && node2->data < temp->data) || (node1->data < temp->data && node2->data > temp->data))
			return temp;
		else if (node1 == temp || node2 == temp)
			return temp;
		else if (node1->data > temp->data && node2->data > temp->data)
			temp = temp->right.get();
		else
			temp = temp->left.get();
	}
}

LowestCommonAncestor::~LowestCommonAncestor()
{
}

