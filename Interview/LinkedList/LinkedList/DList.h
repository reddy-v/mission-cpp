#pragma once

struct node
{
	char data;
	node* next=nullptr;
	node* prev=nullptr;
	node(int d,node* n,node* p) : data(d), next(n), prev(p) { }
};
class DList
{
	node* head=nullptr;
	node* tail=nullptr;
public:
	DList();
	node* Insert(char);
	void Remove(node*);
	inline char HeadData() const
	{
		if (head != nullptr)
			return head->data;
		else
			return '-';
	}
	~DList();
};

