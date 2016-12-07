/*
* Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct
* numbers from the original list.
*
* For example,
*Given 1->2->3->3->4->4->5, return 1->2->5.
* Given 1->1->1->2->3, return 2->3.
*
* https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
*/

#include "stdafx.h"
#include "SList.h"
#include <iostream>
#include <vector>

using namespace std;

class DeleteDuplicateNodes
{
public :
	node* Solution1(node* n)
	{
		auto prev = new node(INT_MIN, n);
		auto dummy = prev;
		auto temp = n;
		while(temp!=nullptr)
		{
			while(temp->next!=nullptr && temp->data==temp->next->data)
			{
				temp = temp->next;
			}
			if (prev->next == temp)
				prev = temp;
			else
				prev->next = temp->next;
			temp = temp->next;
		}
		return dummy->next;
	}
};

int holly3()
{
	auto head = new node(1, new node(1, new node(1, new node(2, new node(3, nullptr)))));
	auto res = DeleteDuplicateNodes().Solution1(head);
	auto temp = res;
	while(temp!=nullptr)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	return 0;
}