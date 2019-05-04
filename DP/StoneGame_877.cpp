/* ***********************************************************************

  > File Name: StoneGame_877.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Sat 04 May 2019 11:37:46 AM CST

 ********************************************************************** */
/*
 *
 * 亚历克斯和李用几堆石子在做游戏。偶数堆石子排成一行，每堆都有正整数颗石子 piles[i] 。
 *
 * 游戏以谁手中的石子最多来决出胜负。石子的总数是奇数，所以没有平局。
 *
 * 亚历克斯和李轮流进行，亚历克斯先开始。 每回合，玩家从行的开始或结束处取走整堆石头。 这种情况一直持续到没有更多的石子堆为止，此时手中石子最多的玩家获胜。
 *
 * 假设亚历克斯和李都发挥出最佳水平，当亚历克斯赢得比赛时返回 true ，当李赢得比赛时返回 false 。
 *
 *  
 *
 *  示例：
 *
 *  输入：[5,3,4,5]
 *  输出：true
 *  解释：
 *  亚历克斯先开始，只能拿前 5 颗或后 5 颗石子 。
 *  假设他取了前 5 颗，这一行就变成了 [3,4,5] 。
 *  如果李拿走前 3 颗，那么剩下的是 [4,5]，亚历克斯拿走后 5 颗赢得 10 分。
 *  如果李拿走后 5 颗，那么剩下的是 [3,4]，亚历克斯拿走后 4 颗赢得 9 分。
 *  这表明，取前 5 颗石子对亚历克斯来说是一个胜利的举动，所以我们返回 true 。
 *
 */

/*
 * 极小化极大
 * dp[i][j] 表示从第i堆到第j堆亚历克斯能获得的最大得分
 * 如果玩家是亚历克斯，那么她将取走 piles[i] 或 piles[j] 颗石子，增加她的分数。之后，总分为 piles[i] + dp(i+1, j) 或 piles[j] + dp(i, j-1)；我们想要其中的最大可能得分。
 *
 * 如果玩家是李，那么他将取走 piles[i] 或 piles[j] 颗石子，减少亚历克斯这一数量的分数。之后，总分为 -piles[i] + dp(i+1, j) 或 -piles[j] + dp(i, j-1)；我们想要其中的最小可能得分
 * 需要判断当前是谁的回合
 */


#include <stdio.h>
#include <vector>
#include <string>
#include <stdio.h>
#include <climits>
#include<gtest/gtest.h>

using std::vector;
using std::string;

class Solution {
public:
	bool stoneGame(vector<int>& piles) {
		int N = piles.size();
		int dp[N+2][N+2];
		memset(dp, 0, sizeof(dp));
		for(int size = 1; size <= N; ++size) {
			for(int i = 0, j = size-1; j < N; ++j, ++i) {
				int parity = (j + i + N) % 2;
				if (parity == 1) {
					dp[i+1][j+1] = std::max(piles[i] + dp[i+2][j+1], piles[j] + dp[i+1][j]);
					// printf("alex: %d-%d: %d \n", i, j, dp[i+1][j+1]);
				} else {
					dp[i+1][j+1] = std::min(dp[i+2][j+1] - piles[i], dp[i+1][j] - piles[j]);
					// printf("lee:  %d-%d: %d \n", i, j, dp[i+1][j+1]);
				}
			}
		}
		return dp[1][N] > 0;
	}
};


TEST(testCase,test0) {
	Solution solu;
	vector<int> piles {5,3,4,5};
	EXPECT_EQ(solu.stoneGame(piles), true);
}


int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}

