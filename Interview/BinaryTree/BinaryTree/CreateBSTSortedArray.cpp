#include "stdafx.h"
#include "CreateBSTSortedArray.h"



void CreateBSTSortedArray::CBSTInsert(const vector<int>& is, size_t i, size_t size)
{
	auto mid = i + (size - i) / 2;
	if (size - i == 1)
	{
		Insert(is[i]);
		Insert(is[size]);
		return;
	}
	else if (i == size) {
		Insert(is[mid]);
		return;
	}
	else {
		Insert(is[mid]);
		CBSTInsert(is, i, mid - 1);
		CBSTInsert(is, mid + 1, size);
	}
}

CreateBSTSortedArray::~CreateBSTSortedArray()
{
}
