
#include "gtest/gtest.h"
#include "MaximumSubArrayAtMostOne.h"
#include <vector>

using namespace std;

TEST(MaximumSubArrayAtMostOne, CorrectTest)
{
	ASSERT_EQ(9,MaximumSubArrayAtMostOne::Solution1({-2,-3,4,-1,-2,1,5,-3}) );
}


TEST(MaximumSubArrayAtMostOne, CorrectTest1)
{
	ASSERT_EQ(12, MaximumSubArrayAtMostOne::Solution1({ -2,-3,4,-1,-2,1,5,-3,-9,-4,6,-4,4,2 }));
}

TEST(MaximumSubArrayAtMostOne, CorrectTest2)
{
	ASSERT_EQ(15, MaximumSubArrayAtMostOne::Solution1({ -2,-3,4,-1,-2,1,5,-3,8 }));
}

TEST(MaximumSubArrayAtMostOne, OnlyOnePositive)
{
	ASSERT_EQ(5, MaximumSubArrayAtMostOne::Solution1({ -2,-3,-1,-2,5,-3 }));
}

TEST(MaximumSubArrayAtMostOne, AllNegative)
{
	ASSERT_EQ(0, MaximumSubArrayAtMostOne::Solution1({ -2,-3,-1,-2,-8,-3 }));
}