/* ***********************************************************************

  > File Name: BestTimetoBuyandSellStockIV_188.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Sun 18 Aug 2019 02:50:09 PM CST

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
 * 买卖股票的最佳时机 IV
 * 给定一个数组，它的第 i 个元素是一支给定的股票在第 i 天的价格。
 *
 * 设计一个算法来计算你所能获取的最大利润。你最多可以完成 k 笔交易。
 *
 * 注意: 你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
 *
 *
 */

/* base case：
 * dp[-1][k][0] = dp[i][0][0] = 0
 * dp[-1][k][1] = dp[i][0][1] = -infinity
 *
 * 状态转移方程：
 * dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1] + prices[i])
 * dp[i][k][1] = max(dp[i-1][k][1], dp[i-1][k-1][0] - prices[i])
 *
 *
 *  持股 表示持有股票时的收益
 *  持币 表示只持有现金时的收益
 *  持币[i][k] = max(持币[i-1][k], 持股[i-1][k] + prices[i]) // 不动和卖出求max
 *  持股[i][k] = max(持股[i-1][k], 持币[i-1][k-1] - prices[i]) // 不动和买入求max
 *  最后需要返回持币[i][k]。
 * 
 */



class Solution {
public:
	int maxProfit_k_inf(vector<int>& prices) {
		int n = prices.size();
		int dp_i_0 = 0, dp_i_1 = INT_MIN;
		for (int i = 0; i < n; i++) {
			int temp = dp_i_0;
			dp_i_0 = std::max(dp_i_0, dp_i_1 + prices[i]);
			dp_i_1 = std::max(dp_i_1, temp - prices[i]);
		}
		return dp_i_0;
	}

	int maxProfit(int k, vector<int>& prices) {
		if (prices.empty()) return 0;
		int size = prices.size();
		if (k > size/2) return maxProfit_k_inf(prices);
		std::vector<vector<int>> cash(size, vector<int>(k+1, 0));
		std::vector<vector<int>> hold(size, vector<int>(k+1, 0));
		for (int i = 0; i < size; ++i) {
			for (int j = 1; j <= k; ++j) {
				if (i == 0) {
					cash[i][j] = 0;
					hold[i][j] = -prices[i];
					continue;
				}
				cash[i][j] = std::max(cash[i-1][j], hold[i-1][j] + prices[i]);
				hold[i][j] = std::max(hold[i-1][j], cash[i-1][j-1] - prices[i]);
				printf("%d day k: %d cash: %d\n", i, j, cash[i][j]);
			}
		}
		return cash[size-1][k];
	}
};

TEST(testCase,test0) {
	std::vector<int> prices{1,2,3,4,5,6};
	Solution s;
	EXPECT_EQ(s.maxProfit(2, prices), 7);

}


int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}

