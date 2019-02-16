/* ***********************************************************************

  > File Name: maxProfitII.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Tue 12 Feb 2019 03:00:41 PM CST

 ********************************************************************** */

/*
 * 122. 买卖股票的最佳时机 II
 * 给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。
 * 设计一个算法来计算你所能获取的最大利润。你可以尽可能地完成更多的交易（多次买卖一支股票）。
 */

/*
 * 解题思路:
 * 如果第二天涨就买,一直涨就一直持有,
 * 开始跌了就卖掉
 *
 */


#include <vector>
#include <stdio.h>
using std::vector;
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int profit = 0, np = 0;
		for (size_t i = 1; i < prices.size(); i++) {
			np = prices[i] - prices[i-1];
			profit += np > 0 ? np:0;
		}
		return profit;
	}
};



int main()
{
	std::vector<int> prices{7,1,5,3,6,4};
	std::vector<int> prices1{1,2,3,4,5};
	std::vector<int> prices2{2,1,2,0,1};
	Solution s;
	int maxProfit = s.maxProfit(prices);
	int maxProfit1 = s.maxProfit(prices1);
	int maxProfit2 = s.maxProfit(prices2);
	printf("maxProfit is %d\n", maxProfit);
	printf("maxProfit is %d\n", maxProfit1);
	printf("maxProfit is %d\n", maxProfit2);
	return 0;
}

