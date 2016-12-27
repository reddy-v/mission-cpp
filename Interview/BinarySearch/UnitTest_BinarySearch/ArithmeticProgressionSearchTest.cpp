// UnitTest_BinarySearch.cpp : Defines the entry point for the console application.
//

#include "gtest/gtest.h"
#include "BinarySearch.h"
#include <vector>

TEST(ArithematicProgressionBinarySearchTest, EmptryVector)
{
	vector<int> v;
	ArithmeticProgressionSearch aps(v);
	ASSERT_EQ(-2,aps.Solution1());
}

TEST(ArithematicProgressionBinarySearchTest, VectorLessthan3)
{
	vector<int> v{1,2};
	ArithmeticProgressionSearch aps(v);
	ASSERT_EQ(-2, aps.Solution1());
}

TEST(ArithematicProgressionBinarySearchTest, InvalidAP)
{
	vector<int> v{2,1,2,3,4,5,6};
	ArithmeticProgressionSearch aps(v);
	ASSERT_EQ(-3, aps.Solution1());
}

TEST(ArithematicProgressionBinarySearchTest, RandomVector)
{
	vector<int> v{ 1,2,6,7,9,12 };
	ArithmeticProgressionSearch aps(v);
	ASSERT_EQ(-3, aps.Solution1());
}

TEST(ArithematicProgressionBinarySearchTest, EqualElementVector)
{
	vector<int> v{ 1,2,3,4,5,5,6 };
	ArithmeticProgressionSearch aps(v);
	ASSERT_EQ(-3, aps.Solution1());
}
