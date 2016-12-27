#include "gtest/gtest.h"
#include "LowestCommonAncestor.h"
#include <vector>

using namespace std;

TEST(LowestCommonAncestorTest, lcaBetween)
{
	LowestCommonAncestor lca({ 5,2,7,4,1,6 });
	ASSERT_EQ(5, lca.Solution1(1,6));
}

TEST(LowestCommonAncestorTest, lcaEqualValueRight)
{
	LowestCommonAncestor lca({ 5,2,7,4,1,6 });
	ASSERT_EQ(5, lca.Solution1(5, 6));
}

TEST(LowestCommonAncestorTest, lcaEqualValueLeft)
{
	LowestCommonAncestor lca({ 5,2,7,4,1,6 });
	ASSERT_EQ(2, lca.Solution1(2, 1));
}

TEST(LowestCommonAncestorTest, lcaNoValue)
{
	LowestCommonAncestor lca({ 5,2,7,4,1,6 });
	ASSERT_EQ(-1, lca.Solution1(8, 1));
}

TEST(LowestCommonAncestorTest, lcaNoValues)
{
	LowestCommonAncestor lca({ 5,2,7,4,1,6 });
	ASSERT_EQ(-1, lca.Solution1(8, 20));
}

TEST(LowestCommonAncestorTest1, lcaBetween)
{
	LowestCommonAncestor lca({ 5,2,7,4,1,6 });
	ASSERT_EQ(5, lca.Solution1(1, 6));
}

TEST(LowestCommonAncestorTest1, lcaEqualValueRight)
{
	LowestCommonAncestor lca({ 5,2,7,4,1,6 });
	ASSERT_EQ(5, lca.Solution1(5, 6));
}

TEST(LowestCommonAncestorTest1, lcaEqualValueLeft)
{
	LowestCommonAncestor lca({ 5,2,7,4,1,6 });
	ASSERT_EQ(2, lca.Solution1(2, 1));
}

TEST(LowestCommonAncestorTest1, lcaNoValue)
{
	LowestCommonAncestor lca({ 5,2,7,4,1,6 });
	ASSERT_EQ(-1, lca.Solution1(8, 1));
}

TEST(LowestCommonAncestorTest1, lcaNoValues)
{
	LowestCommonAncestor lca({ 5,2,7,4,1,6 });
	ASSERT_EQ(-1, lca.Solution1(8, 20));
}
