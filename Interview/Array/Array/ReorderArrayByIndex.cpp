/*
* Given two arrays one with values and other with index where values should be positioned.Move values to correct
* position
*
* Time complexity - O(n)
* Space complexity - O(1)
*
* http://www.geeksforgeeks.org/reorder-a-array-according-to-given-indexes/
*/


#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class ReorderArrayByIndex
{
public :
	void Solution1(vector<int>& actual, const vector<int>& index)
	{
		vector<int> temp(actual);
		for(int i=0;i<index.size();i++)
		{
			actual[index[i]] = temp[i];
		}
	}
};

int holly15()
{
	ReorderArrayByIndex rab;
	vector<int> v = { 11,10,12 };
	rab.Solution1(v, { 1,0,2 });
	for(auto x: v)
	{
		cout << x << " ";
	}
	return 0;
}