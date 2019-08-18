/* ***********************************************************************

  > File Name: BestTimetoBuyandSellStockwithTransactionFee_714.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Tue 13 Aug 2019 06:47:09 PM CST

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
 * 714. 买卖股票的最佳时机含手续费
 * 给定一个整数数组 prices，其中第 i 个元素代表了第 i 天的股票价格 ；非负整数 fee 代表了交易股票的手续费用。
 *
 * 你可以无限次地完成交易，但是你每次交易都需要付手续费。如果你已经购买了一个股票，在卖出它之前你就不能再继续购买股票了。
 *
 * 返回获得利润的最大值。
 */

/*	
 *	只有一只股票。所以只有两种状态：持有现金和持有股票
 *	cash 表示 手头现金
 *	hold 表示 持有股票时的利润
 *	第i天的 cash[i] = max(cash[i-1], hold + price[i] - fee); 以price[i]的价格卖掉，扣掉手续费 fee
 *	持股利润 hold[i] = max(hold[i-1], cash -  price[i])。 现有的持股利润 和 花钱买股票后的持有利润比
 *
 */

class Solution {
public:
	int maxProfit(vector<int>& prices, int fee) {
		int cash = 0, hold = -prices[0];
		for (int i = 0; i <(int)prices.size(); ++i) {
			cash = std::max(cash, hold + prices[i] - fee);
			hold = std::max(hold, cash - prices[i]);

		}
		return cash;
	}
};


TEST(testCase,test0) {

}


int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}

