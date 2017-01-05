#include "stdafx.h"
#include "LongestPalindrome.h"
#include <vector>
#include <algorithm>


int LongestPalindrome::Solution1() const
{
	string s(2 * str.size() + 3, '#');
	auto j = 0;
	for (auto i = 2; i < s.size() - 1; ++i)
	{
		if (i % 2 == 0) {
			s[i] = str[j];
			j++;
		}
	}
	s[0] = '$';
	s[s.size() - 1] = '@';
	std::vector<int> v(s.size(), 0);
	auto C = 1, R = 1;
	for (auto i = 2; i < s.size(); ++i)
	{
		if (R == (s.size() - 2))
			break;
		auto mirr = 2 * C - i;
		if (i < R)
			v[i] = min(R - i, v[mirr]);
		while (s[i + 1 + v[i]] == s[i - (1 + v[i])])
			v[i]++;
		if ((i + v[i])>R)
		{
			//cout << R << endl;
			C = i;
			R = i + v[i];
		}
	}
	return *max_element(v.begin(), v.end());
}

LongestPalindrome::~LongestPalindrome()
{
}
