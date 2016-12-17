/* 
Count the number of occurrences in a sorted array
http://www.geeksforgeeks.org/count-number-of-occurrences-in-a-sorted-array/
Given a sorted array arr[] and a number x, write a function that counts the occurrences of x in arr[]. 
Expected time complexity is O(Logn)
*/

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class CountOccurenceInSortedArray
{
public :
	int Solution1(const vector<int>& v, int x)
	{
		int low = 0;
		int high = v.size() - 1;
		int lower=0;
		int higher=0;
		while(low<=high)
		{
			int mid = low + (high - low) / 2;
			if (x == v[mid])
			{
				lower = mid;
				high = mid - 1;
			}
			else if (x < v[mid])
			{
				high = mid - 1;
			}
			else
				low = mid + 1;
		}
		low = 0;
		high = v.size() - 1;
		while (low <= high)
		{
			int mid = low + (high - low) / 2;
			if (x == v[mid])
			{
				higher=mid;
				low = mid + 1;
			}
			else if (x < v[mid])
			{
				high = mid - 1;
			}
			else
				low = mid + 1;
		}
		return higher - lower+1;
	}
};

int holly23()
{
	CountOccurenceInSortedArray coisa;
	cout << coisa.Solution1({ 1,2,3,3,4,5,5,5,5,5,6,7,7,7,7,9 }, 7) << endl;
	cout << coisa.Solution1({ 1,2,3,3,4,5,5,5,5,5,6,7,7,7,7,9 }, 3) << endl;
	return 0;
}