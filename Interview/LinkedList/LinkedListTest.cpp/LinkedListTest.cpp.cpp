// LinkedListTest.cpp.cpp : Defines the entry point for the console application.
//

#include "gtest/gtest.h"
#include "ReverseLinkedListRecursive.h"
#include <vector>

using namespace std;

TEST(ReverseLL, Success)
{
	vector<int> v{ 4,3,2,1 };
	ReverseLinkedListRecursive rllr({1,2,3,4});
	ASSERT_EQ(v, rllr.Verify());
}
