#include "stdafx.h"
#include "DList.h"


DList::DList()
{
}

noded* DList::Insert(char x)
{
	if(tail==nullptr)
	{
		tail = new noded(x, nullptr, nullptr);
		head = tail;
	}
	else
	{
		noded* temp = new noded(x, nullptr, nullptr);
		tail->next = temp;
		temp->prev = tail;
		tail = temp;
	}
	return tail;
}

void DList::Remove(noded* n)
{
	auto prev = n->prev;
	auto next = n->next;
	if (prev != nullptr)
		prev->next = next;
	else
		head = next;
	if (next != nullptr)
		next->prev = prev;
	else
		tail = prev;
	delete n;
}

DList::~DList()
{
}
