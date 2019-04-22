/* ***********************************************************************

  > File Name: MinCostClimbingStairs_746.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Mon 22 Apr 2019 07:27:41 PM CST

 ********************************************************************** */

/*
 * 数组的每个索引做为一个阶梯，第 i个阶梯对应着一个非负数的体力花费值 cost[i](索引从0开始)。
 *
 * 每当你爬上一个阶梯你都要花费对应的体力花费值，然后你可以选择继续爬一个阶梯或者爬两个阶梯。
 *
 * 您需要找到达到楼层顶部的最低花费。在开始时，你可以选择从索引为 0 或 1 的元素作为初始阶梯。
 *
 * 示例 1:
 *
 * 输入: cost = [10, 15, 20]
 * 输出: 15
 * 解释: 最低花费是从cost[1]开始，然后走两步即可到阶梯顶，一共花费15。
 *  示例 2:
 *
 *  输入: cost = [1, 100, 1, 1, 1, 100, 1, 1, 100, 1]
 *  输出: 6
 *  解释: 最低花费方式是从cost[0]开始，逐个经过那些1，跳过cost[3]，一共花费6。
 *  注意：
 *
 *  cost 的长度将会在 [2, 1000]。
 *  每一个 cost[i] 将会是一个Integer类型，范围为 [0, 999]。
 */

/* 
 * 这道题很坑，重要的点，站上阶梯不花钱，但是从这个楼梯往上走要花钱，cost[i]
 * 所以可以在cost[i]最后补一个0，必须走到0这个位置才算完成，那么根据爬两步到这里和爬一步到这里,可以得到dp公式：
 * f(N) = min(f(N-2)+cost[N-2], f(N-1) + cost[N-1]);
 * 显然边界条件有：0,1作为起点，又作为终点是不用爬的，不用花钱
 * f(0) = 0;
 * f(1) = 0;
 */

#include <printf.h>
#include <vector>
#include <string>
#include <stdio.h>
#include <climits>
#include<gtest/gtest.h>

using std::vector;
using std::string;

class Solution {
public:
	int minCostClimbingStairs(vector<int>& cost) {
		if (cost.empty()) {
			return 0;
		}
		int size = cost.size() + 1; // 补上终点
		int dp[size]; 
		dp[0] = 0;
		dp[1] = 0;
		for (int i = 2; i < size; ++i) {
			dp[i] = std::min(dp[i-1]+cost[i-1], cost[i-2] + dp[i-2]);
		}
		return dp[size-1];
	}
};


TEST(testCase,test0) {
	std::vector<int> cost_1{1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
	std::vector<int> cost_2{10, 15, 20};
	Solution s;
	EXPECT_EQ(s.minCostClimbingStairs(cost_1), 6);
	EXPECT_EQ(s.minCostClimbingStairs(cost_2), 15);
}


int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}

