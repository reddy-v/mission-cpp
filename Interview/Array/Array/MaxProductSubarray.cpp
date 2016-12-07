/*
* Find the contiguous subarray within an array(containing at least one number) which has the largest product.
*
* Time complexity is O(n)
* Space complexity is O(1)
*
* http://www.geeksforgeeks.org/maximum-product-subarray/
*https ://leetcode.com/problems/maximum-product-subarray/
	*/

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

class MaxProductSubarray
{
public :
	int Solution1(const vector<int>& v)
	{
		int start = 0;
		int max_ending_here = 1;
		int min_ending_here = 1;
		int max_so_far = 0;
		for(int i=start;i<v.size();i++)
		{
			if (v[i] > 0)
				max_ending_here *= v[i];
			else if (v[i] == 0) {
				max_ending_here = 1;
				min_ending_here = 1;
			}
			else
			{
				int temp = max_ending_here;
				max_ending_here = max(min_ending_here*v[i],1);
				min_ending_here = temp*v[i];
			}

			if (max_ending_here > max_so_far)
				max_so_far = max_ending_here;
		}
		return max_so_far;
	}
};

int holly14()
{
	MaxProductSubarray mps;
	cout << mps.Solution1({ 1, -2, -3, 0, 7, -8, -2 }) << endl;
	return 0;
}
