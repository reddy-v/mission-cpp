/*
* Given two sorted arrays such the arrays may have some common elements.Find the sum of the maximum sum
* path to reach from beginning of any array to end of any of the two arrays.We can switch from one array
* to another array only at common elements.
*
* Time complexity is O(n + m)
* Space complexity is O(1)
*
* http://www.geeksforgeeks.org/maximum-sum-path-across-two-arrays/
*/

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;


class MaximumSumPathTwoArrays
{
public :
	int Solution1(const vector<int>& v1, const vector<int>& v2)
	{
		int i = 0, j = 0;
		int sum1 = 0, sum2 = 0, sum = 0;
		while (i < v1.size() && j < v2.size())
		{
			if(v1[i]==v2[j])
			{
				if(sum1>sum2)
				{
					sum += sum1 + v1[i];
				}
				else
				{
					sum += sum2 + v2[j];
				}
				i++;
				j++;
				sum1 = 0;
				sum2 = 0;
			}
			else if(v1[i] < v2[j])
			{
				sum1 += v1[i++];
			}
			else
			{
				sum2 += v2[j++];
			}
		}
		if(i==v1.size())
		{
			for (int k = j; k < v2.size(); k++)
				sum2 += v2[k];
		}
		else if(j==v2.size())
		{
			for (int k = i; k < v1.size(); k++)
				sum1 += v1[k];
		}
		if (sum1 <= sum2)
		{
			sum += sum2;
		}
		else
		{
			sum += sum1;
		}
		return sum;
	}
};

int holly9()
{
	MaximumSumPathTwoArrays mspt;
	cout << mspt.Solution1({ 2, 3, 7, 10, 12, 15, 30, 34 }, { 1, 5, 7, 8, 10, 15, 16, 19 }) << endl;
	return 0;
}