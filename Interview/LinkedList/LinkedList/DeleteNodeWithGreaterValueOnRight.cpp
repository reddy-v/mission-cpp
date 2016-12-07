/**
* http://www.geeksforgeeks.org/delete-nodes-which-have-a-greater-value-on-right-side/
* Test cases
* Sorted list
* reverse sorted list
* 0 1 or more nodes in the list
*/

#include "stdafx.h"
#include "SList.h"
#include <iostream>
#include <vector>

using namespace std;


class DeleteNodeWithGreaterValueOnRight
{
public :
	node* Solution1(node* h)
	{
		auto temp = rever(h);
		auto head = temp;
		int maxfound = INT_MIN;
		while(temp!=nullptr || temp->next!=nullptr)
		{
			if(temp->next->data<maxfound)
			{
				auto t = temp->next;
				temp->next = temp->next->next;
				delete t;
			}
			else
			{
				temp = temp->next;
				maxfound = temp->data;
			}
		}
		return rever(head);
	}

	node* rever(node* h) const
	{
		if (h == nullptr || h->next == nullptr)
			return h;
		auto head = rever(h->next);
		h->next->next = h->next;
		h->next = nullptr;
		return head;
	}
};

int main()
{
	auto h = new node(10, new node(20, new node(18, new node(40, new node(50, new node(45, new node(38, nullptr)))))));
	auto h1=DeleteNodeWithGreaterValueOnRight().Solution1(h);
	auto temp = h1;
	while(temp!=NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
}