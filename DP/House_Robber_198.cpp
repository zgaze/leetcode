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

#include <vector>

using std::vector;
#include <stdio.h>
class Solution {
public:
	int rob(vector<int>& nums) {
		const size_t n = nums.size();
		int money[n] = {0};
		money[n-1] = nums[n-1];
		printf("money %d, %d\n", n-1, money[n-1]);
		money[n-2] = std::max(nums[n-1], nums[n-2]);
		printf("money %d, %d\n", n-2, money[n-2]);
		money[n-3] = std::max(money[n-1] + nums[n-3], money[n-2]);
		printf("money %d, %d\n", n-3, money[n-3]);
		for (int i = n-4; i >= 0; --i) {
			money[i] = std::max(nums[i] + money[i+2], nums[i+1] + money[i+3]);
			printf("money %d, %d\n", i, money[i]);
		}
		return money[0];
	}
};


int main() {
	vector<int> aaa{1,2,3,1};
	Solution s;
	int money = s.rob(aaa);
	printf("====%d\n", money);
}
