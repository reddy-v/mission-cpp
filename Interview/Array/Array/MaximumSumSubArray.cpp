

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class MaximiumSumSubArray
{
public :
	int Solution1(const vector<int>& v)
	{
		int max_so_far = 0;
		int max_ending_here = 0;
		for (auto x : v) {
			max_ending_here = max_ending_here + x;
			if (max_ending_here <= 0)
			{
				max_ending_here = 0;
			}
			else if (max_ending_here > max_so_far)
			{
				max_so_far = max_ending_here;
			}
		}
		return max_so_far;
	}
};


int holly24()
{
	MaximiumSumSubArray mssa;
	cout << mssa.Solution1({ -2, -3, 4, -1, -2, 1, 5, -3 }) << endl;
	return 0;
}