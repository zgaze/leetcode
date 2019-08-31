/* ***********************************************************************

  > File Name: BestTimetoBuyandSellStockwithCooldown_309.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Tue 20 Aug 2019 12:10:21 PM CST

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
 * 309. 最佳买卖股票时机含冷冻期
 * 给定一个整数数组，其中第 i 个元素代表了第 i 天的股票价格
 *
 * 设计一个算法计算出最大利润。在满足以下约束条件下，你可以尽可能地完成更多的交易（多次买卖一支股票）:
 *
 * 你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
 * 卖出股票后，你无法在第二天买入股票 (即冷冻期为 1 天)。
 *
 */

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int size = prices.size();
		if (size == 0) return 0;
		int cash[size], hold[size];
		memset(cash, 0, sizeof(cash));
		memset(hold, 0, sizeof(hold));
		cash[0] = 0;
		hold[0] = -prices[0];
		for (int i = 1; i < size; ++i) {
			cash[i] = std::max(cash[i-1], hold[i-1] + prices[i]);
			hold[i] = std::max(hold[i-1], i-2 >= 0 ? cash[i-2] - prices[i] : 0);
		}
		return cash[size-1];
	}
};

TEST(testCase,test0) {

}


int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}

