/* ***********************************************************************

  > File Name: LongestIncreasingSubsequence_300.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Fri 12 Jul 2019 05:09:00 PM CST

 ********************************************************************** */

#include <stdio.h>
#include <vector>
#include <string>
#include <stdio.h>
#include <climits>
#include <gtest/gtest.h>

using std::vector;
using std::string;

/*
 * 300. 最长上升子序列
 *
 * 给定一个无序的整数数组，找到其中最长上升子序列的长度。
 *
 * 示例:
 *
 * 输入: [10,9,2,5,3,7,101,18]
 * 输出: 4 
 * 解释: 最长的上升子序列是 [2,3,7,101]，它的长度是 4。
 *
 */

/*
 *
 *
 */

class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		int ret = 0;
		int len = nums.size();
		int dp[len];
		memset(dp, 0, sizeof(dp));
		for (int i = 0; i < len; ++i) {
			int max = 0;
			for (int j = 0; j < len; ++j) {
				if (nums[i] > nums[i]) {
					max = std::max(max, dp[i]);
				}
			}
			dp[i] = max + 1;
			ret = std::max(dp[i], ret);
		}
		return ret;
	}

};

TEST(testCase,test0) {
	Solution s;
	vector<int> nums {10,9,2,5,3,7,101,18};
	EXPECT_EQ(s.lengthOfLIS(nums), 4);
}


int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}

