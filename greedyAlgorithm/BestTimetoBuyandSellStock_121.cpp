/* ***********************************************************************

  > File Name: BestTimetoBuyandSellStock_121.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Tue 12 Feb 2019 03:44:31 PM CST

 ********************************************************************** */

/*
 * 给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。
 *
 * 如果你最多只允许完成一笔交易（即买入和卖出一支股票），设计一个算法来计算你所能获取的最大利润。
 *
 * 注意你不能在买入股票前卖出股票。

	示例 1:

	输入: [7,1,5,3,6,4]
	输出: 5
	解释: 在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6-1 = 5 。
     注意利润不能是 7-1 = 6, 因为卖出价格需要大于买入价格。
*/


/*
 * 保证先产生:minPrice
 * 后续每次判断利润是不是有增长
 * 例如:7 2 5 1 6 循环到1的时候,minPrice =1, 但profit还是 5-2,后续能卖出更多钱的时候再更新
 */

#include <vector>
#include <limits.h>
#include <stdio.h>

using std::vector;

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int profit = 0,  minPrice = INT_MAX;
		int size = prices.size();
		for (int i = 0; i < size; ++i) {
			if (prices[i] < minPrice) {
				minPrice = prices[i];
			} else if (prices[i] - minPrice > profit) {
				profit = prices[i] - minPrice;
			}
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
