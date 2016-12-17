/* 
*
*
* http://www.byte-by-byte.com/maxstack/
 */
#include "stdafx.h"
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class MaxStack
{
private :
	struct node
	{
		int data;
		int max_till_now;
	};
	stack<node> s;
	int max=INT_MIN;
public :
	void push(int x)
	{
		s.push({ x, max });
		if (x > max)
			max = x;
	}
	int pop()
	{
		if (s.empty())
			return INT_MIN;
		int m = s.top().data;
		if(m==max)
		{
			max = s.top().max_till_now;
		}
		s.pop();
	}

	int maxi()
	{
		return max;
	}

	bool empty()
	{
		return s.empty();
	}
};

int main()
{
	MaxStack ms;
	ms.push(1);
	ms.push(2);
	ms.push(3);
	ms.push(8);

	ms.push(4);
	ms.push(2);
	while(!ms.empty())
	{
		ms.pop();
		cout << ms.maxi() << endl;
	}
}