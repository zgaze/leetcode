#include <vector>
#include <cstring>
#include <stdio.h>
/*
 *
 * 这里有 n 个一样的骰子，每个骰子上都有 k 个面，分别标号为 1 到 k 。
 * 给定三个整数 n、k 和 target，请返回投掷骰子的所有可能得到的结果（共有 kn 种方式），使得骰子面朝上的数字总和等于 target。
 * 由于答案可能很大，你需要对 109 + 7 取模。
 *
 *
 * */

class Solution {
public:
		// dp[n][target] = dp[n-1][target-1] + ... +dp[n-1][target-k] 
    int numRollsToTarget(int n, int k, int target) {
			//  n个(1-k) 的数+加起来等于target的组合数
			long m_num = 1e9+7;
			long count = 0;
			long dp[n+1][target+1];
			memset(dp, 0, sizeof(dp));
			dp[0][0] = 1;
			for (int i = 0; i <= n; ++i) {
				for (int t = 0; t <= target; ++t)  {
					for (int x = 1; x <= k; ++x) {
						if (t - x >= 0) {
							dp[i][t] = (dp[i][t] + dp[i - 1][t - x]) % m_num;
						}
					}
				}
			}
			return dp[n][target];
    }
};

int main() {
	Solution s;
	int x = 30, y = 30, z = 500;
	int count = s.numRollsToTarget(x, y, z);
	printf("用%d个%d面的骰子, 得到%d总和的可能性个数为%ld\n", x, y, z ,count);
	return 0;
}
