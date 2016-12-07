/**
* http://www.geeksforgeeks.org/delete-n-nodes-after-m-nodes-of-a-linked-list/
* Test cases:
* neg value of m and/or n - not allowed
* 0 value of n and/or m - not allowed
* even n and m
* odd n and m
* odd size of the list
* even size of the list
*/

#include "stdafx.h"
#include "SList.h"
#include <iostream>
#include <vector>

using namespace std;

class DeleteNAfterMNodes
{
public :
	node* Solution1(node* h,int M, int N) // M is the after nodes and N to be deleted
	{
		auto temp = h;
		for(int i=0;i<M-1&&temp!=nullptr;i++)
		{
			temp = temp->next;
		}
		auto start = temp;
		if (temp == nullptr)
			return nullptr;
		for(int i=0;i<N&&temp->next!=nullptr;i++)
		{
			temp = temp->next;
		}
		if (temp->next == nullptr) {
			start->next = nullptr;
			return nullptr;
		}
		start->next = temp->next;

		Solution1(start->next, M, N);
		return h;
	}
};

int holly4()
{
	auto h = new node(1, new node(2, new node(3, new node(4, new node(5, new node(6, new node(7,nullptr)))))));
	auto h1 = DeleteNAfterMNodes().Solution1(h, 1, 3);
	auto temp = h1;
	while(temp!=nullptr)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	return 0;
}