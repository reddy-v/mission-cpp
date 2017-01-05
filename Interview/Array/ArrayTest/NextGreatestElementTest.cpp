

#include "gtest/gtest.h"
#include "NextGreaterElement.h"
#include <vector>
#include <map>

using namespace std;

TEST(NextGreatTestElement, ClearTest)
{
	map<int, int> m{ {98,INT_MIN},{23,54},{54,INT_MIN},{12,20},{20,27},{7,27},{27,INT_MIN} };
	NextGreaterElement nge;
	ASSERT_EQ(m,nge.Solution1({98,23,54,12,20,7,27}));
}