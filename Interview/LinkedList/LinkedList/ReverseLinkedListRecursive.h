#pragma once
#include "SList.h"
#include <vector>
using namespace std;
class ReverseLinkedListRecursive
{
	SList s;
public:
	ReverseLinkedListRecursive(const vector<int>&);
	void ReverseList(node* node);
	void Solution1();
	inline vector<int> Verify()
	{
		return s.tovec();
	}
	~ReverseLinkedListRecursive();
};

