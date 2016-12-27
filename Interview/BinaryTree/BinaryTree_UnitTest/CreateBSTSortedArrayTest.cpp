
#include "gtest/gtest.h"
#include "CreateBSTSortedArray.h"
#include <vector>

using namespace std;

TEST(CreateBSTSortedArray, checkLength)
{
	CreateBSTSortedArray cbsa({1,2,3,4,5,6,7});
	int llength=cbsa.lengthUtil(cbsa.getRoot()->left.get());
	int rlength = cbsa.lengthUtil(cbsa.getRoot()->right.get());
	cout << llength << endl;
	ASSERT_EQ(llength, rlength);
}

TEST(CreateBSTSortedArray, checkBST)
{
	CreateBSTSortedArray cbsa({ 1,2,3,4,5,6,7,8 });
	ASSERT_EQ(true, cbsa.checkBST());
}