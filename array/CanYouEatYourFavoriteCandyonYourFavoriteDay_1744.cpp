/* ***********************************************************************

  > File Name: CanYouEatYourFavoriteCandyonYourFavoriteDay_1744.cpp
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
 * 给你一个下标从 0 开始的正整数数组 candiesCount ，其中 candiesCount[i] 表示你拥有的第 i 类糖果的数目。
 * 同时给你一个二维数组 queries ，其中 queries[i] = [favoriteTypei, favoriteDayi, dailyCapi] 。

你按照如下规则进行一场游戏：

你从第 0 天开始吃糖果。
你在吃完 所有 第 i - 1 类糖果之前，不能 吃任何一颗第 i 类糖果。
在吃完所有糖果之前，你必须每天 至少 吃 一颗 糖果。
请你构建一个布尔型数组 answer ，满足 answer.length == queries.length 。answer[i] 为 true 的条件是：在每天吃 不超过 dailyCapi 颗糖果的前提下，你可以在第 favoriteDayi 天吃到第 favoriteTypei 类糖果；否则 answer[i] 为 false 。注意，只要满足上面 3 条规则中的第二条规则，你就可以在同一天吃不同类型的糖果。

请你返回得到的数组 answer 。
*/

class Solution {
public:
    vector<bool> canEat(vector<int>& candiesCount, vector<vector<int>>& queries) {
			// 要吃到第i种糖果,需要先吃掉pre_sum[i]个别的糖果
			vector<bool> ret;
			ret.reserve(queries.size());
			std::vector<int64_t> pre_sum(1 + candiesCount.size());
			for (int i = 0; i < (int)candiesCount.size(); ++i) {
				pre_sum[i+1] = pre_sum[i] + candiesCount[i];
			}
			for (int i = 0; i < (int)queries.size(); ++i) {
				int t = queries[i][0];
				int d = queries[i][1];
				int c = queries[i][2];
				int64_t eat_max = c * (d+1); // 每天吃c个
				int64_t eat_min = d + 1; // 每天只吃一个
				// printf("[%d,%d,%d]\n", t,d,c);
				// 每天努力吃也吃不完前面的 和 每天只吃一个还是没到日子就吃完了两种失败情况
				// [eat_min, eat_max] [pre_sum[t]+1, pre_sum[t+1]] 两个区间是否有交集
				if (eat_max < pre_sum[t]+1 || eat_min > pre_sum[t+1]) {
					ret.push_back(false);
				} else {
					ret.push_back(true);
				}
			}
			return ret;
    }
};

TEST(testCase,test0) {
	Solution s;
	std::vector<bool> except{true,false,true};
	std::vector<int> candiesCount = {7,4,5,3,8};
	std::vector<std::vector<int>> queries = {{0,2,2},{4,2,4},{2,13,1000000000}};
	auto ret = s.canEat(candiesCount, queries);
	EXPECT_EQ(3, ret.size());
	EXPECT_EQ(ret[0], except[0]);
	EXPECT_EQ(ret[1], except[1]);
	EXPECT_EQ(ret[2], except[2]);
}


int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}

