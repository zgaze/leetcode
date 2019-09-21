/* ***********************************************************************

  > File Name: MinimumCostForTickets_983.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 


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
 * 983. 最低票价
 * 在一个火车旅行很受欢迎的国度，你提前一年计划了一些火车旅行。在接下来的一年里，你要旅行的日子将以一个名为 days 的数组给出。每一项是一个从 1 到 365 的整数。
 *
 * 火车票有三种不同的销售方式：
 *
 * 一张为期一天的通行证售价为 costs[0] 美元；
 * 一张为期七天的通行证售价为 costs[1] 美元；
 * 一张为期三十天的通行证售价为 costs[2] 美元。
 * 通行证允许数天无限制的旅行。 例如，如果我们在第 2 天获得一张为期 7 天的通行证，那么我们可以连着旅行 7 天：第 2 天、第 3 天、第 4 天、第 5 天、第 6 天、第 7 天和第 8 天。
 *
 * 返回你想要完成在给定的列表 days 中列出的每一天的旅行所需要的最低消费。
 */

class Solution {
public:
    std::vector<int> mem;
	// 第last天之前的钱都已经付过了
    int helper(vector<int>& days, vector<int>& costs, int index, int last) {
        if (index >= (int)days.size()) return 0;
        int day = days[index];
        if (day < last) {
            return  helper(days, costs, index + 1, last);
        }
        if (mem[index] != 0) {
            // printf("cache cost %d %d\n", index, mem[index]);
            return mem[index];
        }
		// 在day天买票，有效期到day+x
        int cost1 = costs[0] + helper(days, costs, index + 1, day + 1);
        int cost2 = costs[1] + helper(days, costs, index + 1, day + 7);
        int cost3 = costs[2] + helper(days, costs, index + 1, day + 30);
        int min_c = std::min(cost1, std::min(cost2, cost3));
        mem[index] = min_c;
        return min_c;
    }
	void clear() {
		mem.clear();
	}
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        if (days.empty()) return 0;
        mem.resize(days.size());
        return helper(days, costs, 0, 0);
    }
};

TEST(testCase,test0) {
	Solution s;
	std::vector<int> days1{1,4,6,7,8,20};
	std::vector<int> costs1 {2, 7, 15};
	std::vector<int> days2 {1,2,3,4,5,6,7,8,9,10,30,31};
	EXPECT_EQ(s.mincostTickets(days1, costs1), 11);
	s.clear();
	EXPECT_EQ(s.mincostTickets(days2, costs1), 17);
}


int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}
