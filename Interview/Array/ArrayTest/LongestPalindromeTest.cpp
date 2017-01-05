#include "gtest/gtest.h"
#include "LongestPalindrome.h"
#include <vector>

using namespace std;

TEST(LongestPalindrome, CorrectTest)
{
	LongestPalindrome lp("abababa");
	ASSERT_EQ(7, lp.Solution1());
}