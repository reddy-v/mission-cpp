#pragma once
#include <string>
using namespace std;
class LongestPalindrome
{
	string str;
public:
	explicit LongestPalindrome(const string& s) : str(s) { }
	int Solution1() const;
	~LongestPalindrome();
};

