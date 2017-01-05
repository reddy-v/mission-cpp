/*http://www.geeksforgeeks.org/maximum-sum-subarray-removing-one-element/

 Maximum sum subarray removing at most one element

Given an array, we need to find maximum sum subarray, removing one element is also allowed to get the maximum sum. */
#include "stdafx.h"
#include "MaximumSubArrayAtMostOne.h"
#include <algorithm>



MaximumSubArrayAtMostOne::MaximumSubArrayAtMostOne()
{
}

int MaximumSubArrayAtMostOne::Solution1(const vector<int>& v)
{
	int minInRange=0;
	int start = 0, end = 0;
	int maxTillNow = v[0] >0 ? v[0] : 0;
	int maxCurr=v[0];
	int FinalMax = 0;
	for (int i = 0; i < v.size(); ++i)
	{
		if (v[i] > 0 && maxCurr < 0)
			maxCurr = v[i];
		else {
			maxCurr += v[i];
			start = i;
		}
		if (maxCurr < 0) {
			maxTillNow = 0;
			start = i;
			minInRange = 0;
		}
		else if(maxCurr > maxTillNow)
		{
			maxTillNow = maxCurr;
			if (minInRange < 0)
				FinalMax = std::max(FinalMax,maxTillNow - minInRange);
			else
				FinalMax = std::max(maxTillNow,FinalMax);
		}
		else if(maxCurr < maxTillNow)
		{
			if (minInRange > v[i] && v[i] < 0)
				minInRange = v[i];
			else if (minInRange > 0)
				minInRange = 0;
		}
	}
	return FinalMax;
}

MaximumSubArrayAtMostOne::~MaximumSubArrayAtMostOne()
{
}
