#pragma once
#include "BinaryTree.h"

class CreateBSTSortedArray : public BinaryTree
{
public:
	void CBSTInsert(const vector<int>& is, size_t i, size_t size);

	explicit CreateBSTSortedArray(const vector<int>& v)
	{
		CBSTInsert(v, 0, v.size() - 1);
	}

	~CreateBSTSortedArray();
};

