#pragma once
#include <string>
#include <vector>
using namespace std;

class AdditiveNumber
{
	string s;
public :
	AdditiveNumber(const string& str) : s(str) {  }
	bool Solution1();
};

class ArrayAddition
{
public :
	vector<int> Solution1(const vector<int>& v1, const vector<int>& v2);
};