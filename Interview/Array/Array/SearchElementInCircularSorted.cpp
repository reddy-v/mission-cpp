/*
 * http://www.geeksforgeeks.org/search-an-element-in-a-sorted-and-pivoted-array/
 * An element in a sorted array can be found in O(log n) time via binary search. 
 * But suppose we rotate an ascending order sorted array at some pivot unknown to you beforehand. 
 * So for instance, 1 2 3 4 5 might become 3 4 5 1 2. 
 * Devise a way to find an element in the rotated array in O(log n) time
 **/

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class SearchElementInCircularSorted
{
public :
	bool Solution1(const vector<int>& v, int x)
	{
		int low = 0;
		int high = v.size() - 1;

		while(low<=high)
		{
			int mid = low + (high - low) / 2;
			if(x==v[mid])
			{
				return true;
			}
			else if(v[mid] <= v[high])
			{
				if(x > v[mid] && x <= v[high])
				{
					low = mid + 1;
				}
				else
				{
					high = mid - 1;
				}
			}
			else
			{
				if (x >= v[low] && x < v[mid])
				{
					low = mid + 1;
				}
				else
					high = mid - 1;
			}

		}
		return false;
	}
};

int holly21()
{
	SearchElementInCircularSorted seics;
	cout << boolalpha << seics.Solution1({ 6,7,1,2,3,4,5 }, 5) << endl;
	cout << boolalpha << seics.Solution1({ 6,7,1,2,3,4,5 }, 10) << endl;
	return 0;
}