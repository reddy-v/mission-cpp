#include "stdafx.h"
#include "DList.h"


DList::DList()
{
}

node* DList::Insert(char x)
{
	if(tail==nullptr)
	{
		tail = new node(x, nullptr, nullptr);
		head = tail;
	}
	else
	{
		node* temp = new node(x, nullptr, nullptr);
		tail->next = temp;
		temp->prev = tail;
		tail = temp;
	}
	return tail;
}

void DList::Remove(node* n)
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
