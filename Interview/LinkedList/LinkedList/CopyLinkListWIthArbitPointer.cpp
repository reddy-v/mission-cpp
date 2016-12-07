/*
* A linked list is given such that each node contains an additional random pointer which could point
* to any node in the list or null.Return a deep copy of the list.
*
* Time complexity is O(n)
* Space complexity is O(1)
*
* https://leetcode.com/problems/copy-list-with-random-pointer/
*/
#include "stdafx.h"
#include "SList.h"
#include <iostream>
#include <vector>

using namespace std;

struct noder
{
	noder* random;
	noder* next;
	int data;
	noder(int d, noder* n, noder* r) : data(d),next(n),random(r) { }
};

class CopyLinkListWIthArbitPointer
{
	noder* head;
public :
	CopyLinkListWIthArbitPointer(noder* h) : head(h) { }
	noder* Solution1()
	{
		auto temp = head;
		while(temp!=nullptr)
		{
			auto next = temp->next;
			auto n = new noder(temp->data, next, nullptr);
			temp->next = n;
			temp = next;
		}

		temp = head;
		while(temp!=nullptr)
		{
			temp->next->random = temp->random->next;
			temp = temp->next->next;
		}

		auto newhead = head->next;
		auto copy = head->next;
		temp = head;
		while(temp!=nullptr)
		{
			temp->next = temp->next->next;
			if(copy->next!=nullptr)
				copy->next = copy->next->next;
			temp = temp->next;
			if(temp!=nullptr)
			copy = temp->next;
		}

		return newhead;
	}

	~CopyLinkListWIthArbitPointer()
	{
		auto temp = head;
		auto temp1 = head;
		while (temp != nullptr)
		{
			temp1 = temp->next;
			delete temp;
			temp = temp1;
		}
	}
};


int holly2()
{
	noder* h = new noder(1, nullptr, nullptr);
	noder* h1 = new noder(2, nullptr, nullptr);
	noder* h2 = new noder(3, nullptr, nullptr);
	h->random = h2;
	h1->random = h;
	h2->random = h1;
	h->next = h1; h1->next = h2;
	CopyLinkListWIthArbitPointer cllwap(h);
	auto nh = cllwap.Solution1();
	auto temp = nh;
	while(temp!=nullptr)
	{
		cout << temp->data << " ";
		if (temp->next != nullptr)
			cout << temp->next->data;
		if (temp->random != nullptr)
			cout << " " << temp->random->data;
		cout << endl;
		temp = temp->next;
	}
	return 0;
}