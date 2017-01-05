/* http://www.byte-by-byte.com/stringcompression/
 * Given a string, write a function to compress it by shortening every sequence of the same character to that 
 * character followed by the number of repetitions. 
 * If the compressed string is longer than the original, you should return the original string.
 */

#include "stdafx.h"
#include <string>
#include <iostream>
#include <vector>
#include "String.h"

using namespace std;


string StringCompression::Solution1(const string& s)
{
	string res;  // result string
	int num = 1; // count the similar contiguous characters
	int siz = s.size() - 1;  
	// check similar characters till siz-2
	for (int i = 0; i < s.size() - 2; i++)
	{
		if (s[i] == s[i + 1])
		{
			num++;
		}
		else
		{
			if (num != 1)
				res = res + s[i] + to_string(num);
			else
				res = res + s[i];
			num = 1;
		}
	}
	if (s[siz - 1] == s[siz])
	{
		num++;
		res = res + s[siz] + to_string(num);
	}
	else
	{
		if (num != 1)
			res = res + s[siz - 1] + to_string(num) + s[siz];
		else
			res = res + s[siz - 1] + s[siz];
	}
	return res;
}

int holly2()
{
	StringCompression sc;
	cout << sc.Solution1("aaabbbcc") << endl;
	cout << sc.Solution1("aaaabcccc") << endl;
	return 0;
}
