/**
* http://www.geeksforgeeks.org/check-if-array-elements-are-consecutive/
*/

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

class CheckIfArrayElementsAreConsecutive
{
public :
	bool Solution1(const vector<int>& v)
	{
		auto mi = *min_element(v.begin(), v.end());
		int s = v.size();
		for(int i=0;i<v.size();i++)
		{
			if (abs(v[i]) - mi >= s)
				return false;
			if (v[abs(v[i]) - mi] < 0)
				return false;
			const_cast<int&>(v[abs(v[i]) - mi]) = -v[abs(v[i]) - mi];
		}
		return true;
	}
};

int holly25()
{
	CheckIfArrayElementsAreConsecutive ciaeac;
	cout << boolalpha << ciaeac.Solution1({ 3,5,2,4,1 }) << endl;
	return 0;
}