#include "stdafx.h"
#include "NormalBinaryTree.h"


NormalBinaryTree::NormalBinaryTree(const vector<int>& v) : BinaryTree()
{
	bool flag = false;
	for(const auto& x: v)
	{
		Insert(root, x, flag);
		flag = !flag;
	}
}

void NormalBinaryTree::Insert(unique_ptr<node>& n, int x, bool b)
{
	if(n==nullptr)

	if (!b)
	{
		Insert(n->left, x, !b);
	}
	else
		Insert(n->right, x, !b);
}


NormalBinaryTree::~NormalBinaryTree()
{
}
