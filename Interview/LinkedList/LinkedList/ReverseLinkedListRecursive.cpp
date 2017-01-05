#include "stdafx.h"
#include "ReverseLinkedListRecursive.h"



ReverseLinkedListRecursive::ReverseLinkedListRecursive(const vector<int>& v) : s(v)
{
}

void ReverseLinkedListRecursive::ReverseList(node* n)
{
	if (n == nullptr)
		return;
	if (n->next == nullptr) {
		s.setHead(n);
		return;
	}
	ReverseList(n->next);
	n->next->next = n;
	n->next = nullptr;
}

void ReverseLinkedListRecursive::Solution1()
{
	ReverseList(s.Head());
}

ReverseLinkedListRecursive::~ReverseLinkedListRecursive()
{
}
