/* ***********************************************************************

  > File Name: House_Robber_198.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Fri 22 Feb 2019 07:16:58 PM CST

 ********************************************************************** */

/*
你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。

给定一个代表每个房屋存放金额的非负整数数组，计算你在不触动警报装置的情况下，能够偷窃到的最高金额。

示例 1:

输入: [1,2,3,1]
输出: 4
解释: 偷窃 1 号房屋 (金额 = 1) ，然后偷窃 3 号房屋 (金额 = 3)。
     偷窃到的最高金额 = 1 + 3 = 4 。
	 示例 2:

	 输入: [2,7,9,3,1]
	 输出: 12
	 解释: 偷窃 1 号房屋 (金额 = 2), 偷窃 3 号房屋 (金额 = 9)，接着偷窃 5 号房屋 (金额 = 1)。
	      偷窃到的最高金额 = 2 + 9 + 1 = 12 。
*/

/*
 * dp: 最后一间房，要么偷，要么不偷
 * 公式： f(n) = max(f(n-2) + a[n], f(n-1))
 */


#include <vector>
#include<gtest/gtest.h>
#include <stdio.h>

using std::vector;

class Solution {
public:
	int rob(vector<int>& nums) {
		if (nums.empty()) {
			return 0;
		}
		const int n = nums.size();
		int money[n+1];
		money[0] = 0;
		money[1] = nums[0];
		for (int i = 2; i <= n; ++i) {
			money[i] = std::max(nums[i-1] + money[i-2], money[i-1]);
		}
		return money[n];
	}
};

TEST(test_rob, dp) {
	Solution s;
	std::vector<int> nums_1{1,2,3,1};
	std::vector<int> nums_2{2,7,9,3,1};
	EXPECT_EQ(s.rob(nums_1), 4);
	EXPECT_EQ(s.rob(nums_2), 12);
}


int main(int argc, char** argv) {
	testing::InitGoogleTest(&argc,argv);
	return RUN_ALL_TESTS();
}
