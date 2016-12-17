/* 
 * http://www.byte-by-byte.com/consecutivearray/
 * Given an unsorted array, find the length of the longest sequence of consecutive numbers in the array.
 */


#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>

using namespace std;

class LongestSubSequenceofConsecutiveNumbers
{
public :
	int Solution1(const vector<int>& v) 
	{
		unordered_set<int> us;
		int count = 0;
		int max = 0;
		for (auto x : v)
			us.insert(x);
		for (auto x : us)
		{
			if (us.find(x - 1) != us.end())
				continue;
			count = 0;
			while (us.find(x++) != us.end()) {
				count++;
			}
			if (count > max)
				max = count;
		}
		return max;
	}
};

int holly20()
{
	LongestSubSequenceofConsecutiveNumbers lsofcn;
	cout << lsofcn.Solution1({ 1,2, 7,5,4,6, 14,23,11,12, 8 } ) << endl;
	return 0;
}