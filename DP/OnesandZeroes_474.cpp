/* ***********************************************************************

  > File Name: OnesandZeroes_474.cpp
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

class Solution {
public:
	void count_zero_one(std::string& str, int &zeros, int &ones) {
		for (auto c : str) {
			if (c=='0') {
				zeros++;
			} else {
				ones++;
			}
		}
	}
	int findMaxForm(vector<string>& strs, int m, int n) {
		int l = strs.size();
		int dp[l+1][m+1][n+1];
		memset(dp, 0, sizeof(dp));
		for (int i = 1; i <= l; ++i) {
			int zeros = 0;
			int ones = 0;
			count_zero_one(strs[i-1], zeros, ones);
			for (int j = 0; j <= m; ++j) {
				for (int k = 0; k <= n; ++k) {
					if (j >= zeros && k >= ones) {
						// 选了的话，容量就减少。长度+1
						// 不选的话，就等于
						dp[i][j][k] = std::max(dp[i-1][j][k], dp[i-1][j-zeros][k-ones] + 1);
					} else {
						// 容量不够 没法选了
						dp[i][j][k] = dp[i-1][j][k];
					}
				}
			}
		}
		return dp[l][m][n];
	}
};


TEST(testCase,test0) {
	std::vector<std::string> strs = {"10","0001","111001","1","0"};
	Solution s;
	EXPECT_EQ(4, s.findMaxForm(strs, 5, 3));
}


int main(int argc, char* argv[]) {
	testing::InitGoogleTest(&argc,argv);
	return RUN_ALL_TESTS();
}

