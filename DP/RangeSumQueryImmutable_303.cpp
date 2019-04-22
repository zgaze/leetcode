/* ***********************************************************************

  > File Name: RangeSumQueryImmutable_303.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Mon 22 Apr 2019 05:40:14 PM CST

 ********************************************************************** */

/*
 * 给定一个整数数组  nums，求出数组从索引 i 到 j  (i ≤ j) 范围内元素的总和，包含 i,  j 两点。
 *
 * 示例：
 *
 * 给定 nums = [-2, 0, 3, -5, 2, -1]，求和函数为 sumRange()
 *
 * sumRange(0, 2) -> 1
 * sumRange(2, 5) -> -1
 * sumRange(0, 5) -> -3
 * 说明:
 *
 * 你可以假设数组不可变。
 * 会多次调用 sumRange 方法。
 */

/*
 * 多次调用，那么就保存从第一个到每一个位置的和a[n],求x->y的差，就用a[y]-a[x-1]就好
 */



#include <stdio.h>
#include <vector>
#include <string>
#include <stdio.h>
#include <climits>
#include<gtest/gtest.h>

using std::vector;
using std::string;

class NumArray {
public:
	NumArray(vector<int>& nums) {
		if (nums.empty()) return;
		int size = nums.size();
		sums.resize(size);
		sums[0] = nums[0];
		for (int i = 1; i < size; ++i) {
			sums[i] = nums[i] + sums[i-1];
		}
	}

	int sumRange(int i, int j) {
		if (i == 0) { // 包含i,j
			return sums[j];
		} else {
			return sums[j] - sums[i-1];
		}
	}
private:
	std::vector<int> sums;
};

TEST(testCase,test0) {
	std::vector<int> nums{-2, 0, 3, -5, 2, -1};
	NumArray na(nums);
	EXPECT_EQ(na.sumRange(0, 0), -2);
	EXPECT_EQ(na.sumRange(0, 2),  1);
	EXPECT_EQ(na.sumRange(2, 5), -1);
	EXPECT_EQ(na.sumRange(0, 5), -3);
}


int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}

