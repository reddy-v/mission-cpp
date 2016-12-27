#pragma once
#include "BinaryTree.h"
class LowestCommonAncestor : public BinaryTree
{
	const BinaryTree::node* Solution1Util(const BinaryTree::node* r, const BinaryTree::node* a, const BinaryTree::node* b) const;
	const BinaryTree::node* Solution2Util(const node* node, const BinaryTree::node* find, const BinaryTree::node* node1) const;
public:
	explicit LowestCommonAncestor(const vector<int>&);
	void print() const;
	int Solution1(int x, int y) const;
	int Solution12(int x, int y) const;
	~LowestCommonAncestor();
};

