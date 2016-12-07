#pragma once
#include <vector>

struct node
{
	int data;
	node* next;
	node(int d,node* n) : data(d), next(n) { }
};
class SList
{
	node* head=nullptr;
	int size=0;
public:
	SList();
	SList(const std::vector<int>& v);
	inline int siz() const { return size; }
	inline node* Head() const { return head;  }
	void Insert(int);
	void Print() const;
	~SList();
};

