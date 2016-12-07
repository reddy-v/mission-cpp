/* Given N men and N women, where each person has ranked all members of the opposite sex 
in order of preference, marry the men and women together such that there are no two people
of opposite sex who would both rather have each other than their current partners.
If there are no such people, all the marriages are “stable”
* http://www.geeksforgeeks.org/stable-marriage-problem/
*
*/

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>

using namespace std;

class StableMarriageProblem
{
private :
	map<int, int> m;
	vector<int> v;
	int size;
public: 
	StableMarriageProblem(const vector<int>& vec, int N) : v(vec),size(N) { }
	map<int,int> Solution1()
	{
		queue<int> q;
		for (int i = 0; i < size; i++)
			q.push(i);
		while(!q.empty())
		{
			int i = q.front();
			int male = i;
			for(int j=0;j<size;j++)
			{
				int female = v[i*size + j];
				if(m.find(female)==m.end())
				{
					m[male] = female;
					m[female] = male;
					q.pop();
					break;
				}
				else
				{
					int male1 = m[female];
					if(prefer(female, male,male1))
					{
						m[female] = male;
						m[male] = female;
						q.pop();
						q.push(male1);
						break;
					}
				}
			}
		}
		return m;
	}

	bool prefer(int f, int m,int m1)
	{
		for(int i=0;i<size;i++)
		{
			if (m == v[f*size + i])
				return true;
			if (m1 == v[f*size + i])
				return false;
		}
	}
};

int holly13()
{
	StableMarriageProblem smp({ 7, 5, 6, 4 , 5, 4, 6, 7 , 4, 5, 6, 7 , 4, 5, 6, 7 , 0, 1, 2, 3 , 0, 1, 2, 3 , 0, 1, 2, 3 , 0, 1, 2, 3 }, 4);
	map<int, int> m = smp.Solution1();
	for(auto x: m)
	{
		cout << x.first << " " << x.second << endl;
	}
	return 0;
}