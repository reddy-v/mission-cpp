/**
* http://www.geeksforgeeks.org/maximum-of-all-subarrays-of-size-k/
* Test cases
* input containg neg and pos values
* val of k is neg 0 or pos
* val of k is larger than size of input
* val of k is same as size of input
*/

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

class MaximumOfSubarrayOfSizeK
{
public :
	vector<int> Solution1(const vector<int>& v, int k)
	{
		vector<int> result;
		int maxi = *max_element(v.begin(), std::next(v.begin(), k));
		result.push_back(maxi);
		for(int i=1;i<v.size()-k;i++)
		{
			if(maxi==v[i-1])
			{
				maxi = v[i];
				for(int j=i;j<i+k;j++)
				{
					if (v[i] > maxi)
						maxi = v[i];
				}
				result.push_back(maxi);
			}
			else {
				maxi = max(maxi, v[k+i]);
				result.push_back(maxi);
			}
		}
		return result;
	}
};

int holly11()
{
	MaximumOfSubarrayOfSizeK mofos;
	vector<int> res=mofos.Solution1({ 1, 2, 3, 1, 4, 5, 2, 3, 6 },3);
	for(auto x: res)
	{
		cout << x << " ";
	}
	return 0;
}