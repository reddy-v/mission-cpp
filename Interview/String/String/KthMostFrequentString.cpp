#include "stdafx.h"
#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;
typedef pair<string, int> pairsi;

bool operator<(const pairsi& p1, const pairsi& p2)
{
	return p1.second < p2.second;
}

class KthMostFrequentString
{
public :
	vector<string> Solution1(const vector<string>& v, int k)
	{
		map<string, int> m;
		set<pair<int, string>> s;
		vector<string> res;
		int count = 0;
		for (auto x : v)
			m[x]++;
		for (auto& x : m)
		{
			s.insert({x.second,x.first});
		}

		auto mt = s.begin();
		auto et = s.end();
		et--;
		int key = 0;
		while (mt != et)
		{
			if (count == k-1)
			{
				key = mt->first;
				break;
			}
			if (mt->first != (++mt)->first)
			{
				count++;
			}
		}
		if(key==0)
		{
			auto mt = s.begin();
			auto et = s.end();
			et--;
			int key = 0;
			count = 0;
			while (mt != et)
			{
				if (count == k - 1)
					break;
				count++;
			}
			res.push_back(mt->second);
		}
		for_each(s.begin(), s.end(), [&res, key](auto p1) { if (p1.first == key) { res.push_back(p1.second); } });
		return res;
	}
};


int main()
{
	KthMostFrequentString kmfs;
	vector<string> v = kmfs.Solution1({"I","I","am","an","asshole", "an"}, 4);
	for (auto x : v)
		cout << x << endl;
}
