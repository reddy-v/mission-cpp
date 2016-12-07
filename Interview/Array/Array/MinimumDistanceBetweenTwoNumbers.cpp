/**
* http://www.geeksforgeeks.org/find-the-minimum-distance-between-two-numbers/
*/

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

class MinimumDistanceBetweenTwoNumbers
{
public:
	int Solution1(const vector<int>& v, int x, int y)
	{
		int i = 0, j = 1;
		int pos1 = 0, pos2 = 0;
		int mini = INT_MAX;
		while(i<v.size())
		{
			if(v[i]==x)
			{
				pos1 = i;
				if (pos2 != 0 || v[pos2]==y) {
					mini = min(mini, pos1 - pos2);
				}
			}
			else if(v[i]==y)
			{
				pos2 = i;
				if(pos1!=0 || v[pos1] == x)
				{
					mini = min(mini, pos2 - pos1);
				}
			}
			i++;
		}
		return mini;
	}
};

int holly10()
{
	MinimumDistanceBetweenTwoNumbers mdbtn;
	cout << mdbtn.Solution1({ 2, 5,7,8, 3, 5, 4, 4, 2, 6,8,3 },3,2 ) << endl;
	return 0;
}
