#pragma once
#include "BinaryTree.h"
class NormalBinaryTree :
	public BinaryTree
{
public:
	NormalBinaryTree(const vector<int>& v);
	void Insert(unique_ptr<node>& n,int x, bool);
	~NormalBinaryTree();
};

