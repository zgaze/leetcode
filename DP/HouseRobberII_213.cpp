/* ***********************************************************************

  > File Name: HouseRobberII_213.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Thu 20 Sep 2018 08:47:58 PM CST

 ********************************************************************** */
/*
 * 你是一个专业的小偷，计划偷窃沿街的房屋，每间房内都藏有一定的现金。
 * 这个地方所有的房屋都围成一圈，这意味着第一个房屋和最后一个房屋是紧挨着的。
 * 同时，相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。
 *
 * 给定一个代表每个房屋存放金额的非负整数数组，计算你在不触动警报装置的情况下，能够偷窃到的最高金额。
 */

#include<vector>
using std::vector;

class Solution {
public:
	int getRob(vector<int>& nums, int begin, int end) {
		if (end - begin == 2) {
			return std::max(nums[begin] + nums[end], nums[end-1]);
		}
		if (end - begin == 1) {
			return std::max(nums[begin], nums[end]);
		}
		return std::max(getRob(nums, begin, end -1) , getRob(nums, begin + 1, end));
	}

	int rob(vector<int>& nums) {
		return getRob(nums, 0, nums.size());
	}
};
