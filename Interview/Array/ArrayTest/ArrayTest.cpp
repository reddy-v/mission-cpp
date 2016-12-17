// ArrayTest.cpp : Defines the entry point for the console application.
//

#include "gtest/gtest.h"
#include "Arrayh.h"

TEST(arraytest, sampletest)
{
	AdditiveNumber an("123");
	ASSERT_EQ(true, an.Solution1());
}

