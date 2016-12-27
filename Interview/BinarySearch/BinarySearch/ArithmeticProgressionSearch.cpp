/**
* http://www.careercup.com/question?id=4798365246160896
*/

#include "stdafx.h"
#include "BinarySearch.h"
#include <cassert>
#include <algorithm>

int ArithmeticProgressionSearch::Solution1()
{
	if(v.size() < 3)
	{
		return -2; // Size should be atleast 3
	}
	decltype(v.size()) low = 0, high = v.size()-1;
	auto diff = min(v[1] - v[0], v[2] - v[1]);
	if(diff <= 0)
	{
		cout << "The AP sequence is wrong!";
		return -3; // Wrong sequence 
	}

	while(low<high)
	{
		auto mid = low + (high - low) / 2;
		unsigned int leftdiff = v[mid] - v[low];
		auto rightdiff = v[high] - v[mid];
		if(leftdiff > (mid-low)*diff)
		{
			if (mid - low == 1)
				return v[mid] + v[low] / 2;
			else if(leftdiff!=((mid-low)*diff+diff)) {
				return -3; // Sequence has many missing 
			}
			high = mid;
			continue;
		}
		else if(leftdiff < (mid - low)*diff)
		{
			return -3; // Sequence is either wrong or many missing
		}

		if (rightdiff > (high - mid)*diff)
		{
			if (high - mid == 1)
				return v[high] + v[mid] / 2;
			else if (rightdiff != ((high - mid)*diff + diff)) {
				return -3; // Sequence has many missing 
			}
			low = mid;
			continue;
		}
		else if (rightdiff < (high - mid)*diff)
		{
			return -3;
		}
	}
	return -1; // Some error in the progression 
}

