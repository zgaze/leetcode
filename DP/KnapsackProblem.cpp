/* ***********************************************************************

  > File Name: KnapsackProblem.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Sun 14 Apr 2019 10:16:06 PM CST

 ********************************************************************** */

/* 01背包问题
 * 给定一组物品，每种物品都有自己的重量和价格，在限定的总重量内，我们如何选择，才能使得物品的总价格最高。
 */

/*
 * 对于最后一件物品，有两个选择：选则价值增加v[i]，但背包容量减少w[i],即f[i-1][W-w[i]]+v[i]；不选则都不变，即f[i-1][W]；
 * 状态转移方程便是：`f[i][W] = max{f[i-1][W],  f[i-1][W-w[i]]+v[i]}`。
 * 边界: f[0][W] = w[0] <= W ? v[0] : 0;
 */

#include <vector>
#include <stdio.h>
#include <iostream>

int bagV = 9;					        //背包大小
int item[5];					        //最优解情况
 
class Solution{
public:
	int FindMax(std::vector<int> & vi, std::vector<int>& wi, int W) {
		int dp[5][10] = { { 0 } };
		for (int i = 1; i <= 4; i++) {
			for (int j = 1; j <= W; j++) {
				if (j < wi[i]) {
					dp[i][j] = dp[i - 1][j];
				} else {
					dp[i][j] = std::max(dp[i - 1][j], dp[i - 1][j - wi[i]] + vi[i]);
				}
			}
		}

		//动态规划表的输出
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j <= W; j++) {
				std::cout << dp[i][j] <<' ';
			}
			std::cout << "\n";
		}
			
		return dp[4][9];
	}
};


int main()
{
	std::vector<int> v{0 , 1 , 3 , 5 , 7};
	std::vector<int> w{0 , 3 , 4 , 5 , 6};
	Solution s;
	int max_v = s.FindMax(v, w, bagV);
	printf("%d\n", max_v);
	return 0;
}


