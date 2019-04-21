/* ***********************************************************************

  > File Name: ClimbingStairs_70.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Sun 21 Apr 2019 02:04:46 PM CST

 ********************************************************************** */

/*
 * 假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
 *
 * 每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
 *
 * 注意：给定 n 是一个正整数。
 */

/*
 * 解题思路：
 * 一次只能爬1或者2，那么到达终点最后一步是走1步的话，前面有f(n-1)种走法，最后一步是走2步的话，前面有f(n-2)种走法，
 * 那么到达n就有f(n-1)+f(n-2)种走法.
 */
#include<gtest/gtest.h>

class Solution {
public:
	int climbStairs(int n) {
		int dp[n+1];
		dp[0] = 1;
		dp[1] = 1;
		for (int i = 2; i <= n; ++i) {
			dp[i] = dp[i-1] + dp[i-2];
		}
		return dp[n];
	}
};

TEST(testCase,test0){
	Solution s;
	EXPECT_EQ(s.climbStairs(1), 1);
	EXPECT_EQ(s.climbStairs(2), 2);
	EXPECT_EQ(s.climbStairs(3), 3);
	EXPECT_EQ(s.climbStairs(4), 5);
	EXPECT_EQ(s.climbStairs(5), 8);
	EXPECT_EQ(s.climbStairs(6), 13);
	EXPECT_EQ(s.climbStairs(13), 377);
}

int main(int argc, char** argv)
{
	testing::InitGoogleTest(&argc,argv);
	return RUN_ALL_TESTS();
}
