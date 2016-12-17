/*
 * http://www.byte-by-byte.com/anagrams/
 * check if two strings are anagrams
 */

#include "stdafx.h"
#include <string>
#include <iostream>
#include <vector>
#include "String.h"

using namespace std;

class TwoStringsAnagrams
{
public :
	bool Solution1(const string& s1, const string& s2)
	{
		if (s1.length() != s2.length())
			return false;
		vector<int> v(1 << 8, 0);
		for (const auto& x: s1)
		{
			v[x]++;
		}
		for (const auto& x : s2)
		{
			v[x]--;
		}
		for (auto& x: v)
		{
			if (x != 0)
				return false;
		}
		return true;
	}
};

int holly1()
{
	TwoStringsAnagrams tsa;
	cout << boolalpha << tsa.Solution1("afdwwdfda", "fddfdxwaa") << endl;
	return 0;
}
