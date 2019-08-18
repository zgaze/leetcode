/* ***********************************************************************

  > File Name: BestTimetoBuyandSellStockIII_123.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Sun 18 Aug 2019 04:05:56 PM CST

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
 *
 * 给定一个数组，它的第 i 个元素是一支给定的股票在第 i 天的价格。
 *
 * 设计一个算法来计算你所能获取的最大利润。你最多可以完成 两笔 交易。
 *
 * 注意: 你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
 *
 */

// 你最多可以完成 两笔 交易。
class Solution { 
public:
    int maxProfit(vector<int>& prices) { 
        int size = prices.size();
        if (size == 0) return 0;
        int cash[size][3];
        int hold[size][3];
        memset(cash, 0, sizeof(cash));
        memset(hold, 0, sizeof(hold));
        for (int i = 0; i < size;++i) { 
            for (int j = 2; j > 0; j--) {                                       
                if (i == 0) { 
                    cash[i][j] = 0;
                    hold[i][j] = -prices[i];
                    continue;
                } 
                cash[i][j] = std::max(cash[i-1][j], hold[i-1][j] + prices[i]);
                hold[i][j] = std::max(hold[i-1][j], cash[i-1][j-1] - prices[i]);
            } 
        } 
        return cash[size-1][2];
    } 
};

TEST(testCase,test0) {

}


int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}

