#include "stdafx.h"
#include "NextGreaterElement.h"
#include <stack>
using namespace std;

NextGreaterElement::NextGreaterElement()
{
}

map<int,int> NextGreaterElement::Solution1(const vector<int>& v) const
{
	map<int,int> result;
	stack<int> s;
	int i = 0;
	for(auto& x: v)
	{
		if (s.empty() || x <= s.top())
			s.push(x);
		else if(x > s.top())
		{
			auto count = 1;
			while(s.top()<x || s.empty())
			{
				result[s.top()] = x;
				s.pop();
			}
			s.push(x);
		}
		i++;
	}
	while(!s.empty())
	{
		result[s.top()] = INT_MIN;
		s.pop();
	}
	return result;
}

NextGreaterElement::~NextGreaterElement()
{
}
