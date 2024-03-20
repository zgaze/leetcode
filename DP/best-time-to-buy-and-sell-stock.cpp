/*
 *
 * 给定一个数组 prices ，它的第 i 个元素 prices[i] 表示一支给定股票第 i 天的价格。
 * 你只能选择 某一天 买入这只股票，并选择在 未来的某一个不同的日子 卖出该股票。设计一个算法来计算你所能获取的最大利润。
 * 返回你可以从这笔交易中获取的最大利润。如果你不能获取任何利润，返回 0 。
*/

// 没有手续费，只能买卖一次

class Solution {
public:
    int maxProfit(vector<int>& prices) {
			int ret = 0;
			int profix = 0;
			int sell = -1, buy = INT_MAX;
			for (int i = 0; i < prices.size(); ++i) {
				if (prices[i] < buy) {
					buy = prices[i];
				}
				// 卖出获利，再买回来
				if (prices[i] > buy) {
					profix = prices[i] - buy;
					ret = std::max(ret, profix);
				}
			}
			return ret;
    }
};
