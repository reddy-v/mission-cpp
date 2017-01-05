#pragma once

struct noded
{
	char data;
	noded* next=nullptr;
	noded* prev=nullptr;
	noded(int d,noded* n,noded* p) : data(d), next(n), prev(p) { }
};
class DList
{
	noded* head=nullptr;
	noded* tail=nullptr;
public:
	DList();
	noded* Insert(char);
	void Remove(noded*);
	inline char HeadData() const
	{
		if (head != nullptr)
			return head->data;
		else
			return '-';
	}
	~DList();
};

