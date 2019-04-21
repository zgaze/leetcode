/*
 *
 * 给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
 *
 * 示例:
 *
 * 输入: [-2,1,-3,4,-1,2,1,-5,4],
 * 输出: 6
 * 解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
 * 进阶:
 *
 * 如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的分治法求解。
 *
 */

#include <vector>
#include <string>
#include <stdio.h>
#include <climits>
#include<gtest/gtest.h>

using std::vector;
using std::string;

class Solution {
public:
	// 负数越加越小, 所以遇到负数和就放弃，取单个最大负数即可
	// 这就是题目说的O(n)的解法
	int maxSubArray_1(vector<int> & nums) {
		if (nums.empty()) {
			return 0;
		}
		int max = nums[0];
		int size = nums.size();
		int sub_max = 0;
		int i = 0;
		for (; i < size; ++i) {
			sub_max = sub_max + nums[i];
			max = std::max(sub_max, max);
			if (sub_max < 0) {
				sub_max = 0;
			}
		}
		return max;
	}
	// dp 公式f(n) = max(f(n-1)+A[n], A[n])
	int maxSubArray_dp(vector<int> & nums) {
		if (nums.empty()) {
			    return 0;
		}
		int max = nums[0];
		int size = nums.size();
		int dp[size] = {0};
		dp[0] = nums[0];
		for (int i = 1; i<size; ++i) {
			dp[i] = std::max(dp[i-1] + nums[i], nums[i]);
			max = std::max(dp[i], max);
		}
		return max;
	}
	int maxSubArray(vector<int>& nums) {
		return maxSubArray_1(nums);
	}
};

TEST(testCase,test0) {
	std::vector<int> nums_1{-2,1,-3,4,-1,2,1,-5,4};
	std::vector<int> nums_2{-1,-2};
	Solution s;
	EXPECT_EQ(s.maxSubArray_dp(nums_1), 6);
	EXPECT_EQ(s.maxSubArray_dp(nums_2), -1);
}

int main(int argc, char** argv) {
	testing::InitGoogleTest(&argc,argv);
	return RUN_ALL_TESTS();        
}


