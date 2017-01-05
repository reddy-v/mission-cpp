// ArrayTest.cpp : Defines the entry point for the console application.
//

#include "gtest/gtest.h"
#include "AdditiveNumber.h"
#include "ArrayAddition.h"

TEST(AdditiveNumberTest, TrueCase123)
{
	AdditiveNumber an("123");
	ASSERT_EQ(true, an.Solution1());
}

TEST(AdditiveNumberTest, TrueCase122436)
{
	AdditiveNumber an("122436");
	ASSERT_EQ(true, an.Solution1());
}

TEST(AdditiveNumberTest, FalseCase1203)
{
	AdditiveNumber an("1203");
	ASSERT_EQ(true, an.Solution1());
}



TEST(ArrayAdditionTest, TrueCase123p934)
{
	ArrayAddition aa;
	vector<int> v = aa.Solution1({ 1,2,3 }, { 9,3,4 });
	ASSERT_EQ(v, vector<int>({1,0,5,7}));
}



