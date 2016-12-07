/*
* Given an array of meeting time intervals consisting of start and end times[[s1, e1], [s2, e2], ...](si < ei),
	*find the minimum number of conference rooms required.
	*
	* Both methods have time comlexity of nlogn
	* Method 1 has space complexity of O(1)
	*
	* https://leetcode.com/problems/meeting-rooms-ii/
*/

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

class Meeting
{
public :
	int Solution1(const vector<pair<double,double>>& c)
	{
		vector<double> start;
		vector<double> end;
		for(auto& x: c)
		{
			start.push_back(x.first);
			end.push_back(x.second);
		}
		sort(start.begin(), start.end());
		sort(end.begin(), end.end());
		auto j = 0;
		int rooms = 0;
		for(auto i=0;i<start.size();i++)
		{
			if (start[i] < end[j])
			{
				rooms++;
			}
			else
				j++;
		}
		return rooms;
	}
};

int holly8()
{
	Meeting m;
	cout << m.Solution1({ { 1,3 }, { 2,4 }, { 3,9 }, { 1,6 } }) << endl;
	return 0;
}