/**
* http://www.geeksforgeeks.org/sum-of-two-linked-lists/
* Test case
* Either of list is null
* Size of list1 is greater, equal or smaller than list2
* Add with carry in main
* Add with carry in remaining
*/

#include "stdafx.h"
#include "SList.h"
#include <iostream>
#include <vector>

using namespace std;

class AddNumberRepresentedByLinkList
{
public :
	SList Solution1(SList n1, SList n2)
	{
		vector<int> sl;
		int carry = 0;
		carry=add(n1.Head(), n2.Head(), sl);
		if (carry != 0)
			sl.push_back(carry);
		reverse(sl.begin(), sl.end());

		return SList(sl);
	}

	int add(node* n1, node* n2, vector<int>& sl)
	{
		if (n1 == nullptr || n2 == nullptr)
			return 0;
		int carry=add(n1->next, n2->next, sl);
		sl.push_back((n1->data + n2->data+carry) % 10);
		return (n1->data + n2->data+carry) / 10;
	}
};

int holly1()
{
	AddNumberRepresentedByLinkList anrbll;
	SList n1({9,9, 9,9 , 9 });
	SList n2({ 9,9,9 });
	if (n1.siz() != n2.siz())
	{
		if (n1.siz()>n2.siz())
		{
			int diff = n1.siz() - n2.siz();
			for (int i = 0; i<diff; i++)
			{
				n2.Insert(0);
			}
		}
		else if (n2.siz()>n1.siz())
		{
			int diff = n2.siz() - n1.siz();
			for (int i = 0; i<diff; i++)
			{
				n1.Insert(0);
			}
		}
	}
	SList sl3 = anrbll.Solution1(n1, n2);
	n1.Print();
	n2.Print();
	sl3.Print();
	return 0;
}