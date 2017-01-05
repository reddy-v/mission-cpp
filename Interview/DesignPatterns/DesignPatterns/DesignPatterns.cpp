// DesignPatterns.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include "boost/algorithm/searching/knuth_morris_pratt.hpp"
#include <algorithm>
#include <new>

using namespace std;

namespace bas = boost::algorithm;
using sIter = string::iterator;



template <typename T> 
class AlgorithmTest
{
private : 
	T container;
public :
	explicit AlgorithmTest(const T& c) : container(c) { }
	

};

int main()
{
	std::string str{"This is a sample string"};
	std::string st{ "is" };
	bas::knuth_morris_pratt<sIter> a{ st.begin(), st.end() };
	auto x=a(str.begin(), str.end());
	cout << distance(str.begin(),x.first) << endl;
	cout << distance(str.begin(), x.second) << endl;
	int count = 20;


    return 0;
}

