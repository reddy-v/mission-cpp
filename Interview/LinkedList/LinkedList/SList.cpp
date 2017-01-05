#include "stdafx.h"
#include "SList.h"
#include <iostream>

using namespace std;


SList::SList()
{
}

SList::SList(const std::vector<int>& v)
{
	head = new node(v[0],nullptr);
	size++;
	node* temp = head;
	for(int i=1;i<v.size();i++)
	{
		size++;
		temp->next = new node(v[i], nullptr);
		temp = temp->next;
	}
}

void SList::setHead(node* n)
{
	head = n;
}

void SList::Insert(int x)
{
	node* temp = new node(x, head);
	head = temp;
}

void SList::Print() const
{
	node* temp = head;
	while(temp!=nullptr)
	{
		cout << temp->data;
		temp = temp->next;
	}
	cout << endl;
}

std::vector<int> SList::tovec()
{
	vector<int> v;
	auto temp = Head();
	while(temp!=nullptr)
	{
		v.push_back(temp->data);
		temp = temp->next;
	}
	return v;

}

SList::~SList()
{
}
