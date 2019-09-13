/* ***********************************************************************

  > File Name: EditDistance_72.cpp
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
 * 72. 编辑距离
 * 给定两个单词 word1 和 word2，计算出将 word1 转换成 word2 所使用的最少操作数 。
 *
 * 你可以对一个单词进行如下三种操作：
 *
 * 插入一个字符
 * 删除一个字符
 * 替换一个字符
 * 示例 1:
 *
 * 输入: word1 = "horse", word2 = "ros"
 * 输出: 3
 * 解释: 
 * horse -> rorse (将 'h' 替换为 'r')
 * rorse -> rose (删除 'r')
 * rose -> ros (删除 'e')
 * 示例 2:
 *
 * 输入: word1 = "intention", word2 = "execution"
 * 输出: 5
 * 解释: 
 * intention -> inention (删除 't')
 * inention -> enention (将 'i' 替换为 'e')
 * enention -> exention (将 'n' 替换为 'x')
 * exention -> exection (将 'n' 替换为 'c')
 * exection -> execution (插入 'u')
 *
 */

class Solution {
public:
	int minDistance(string word1, string word2) {
		int l1 = word1.length();
		int l2 = word2.length();
		if (l1 == 0) return l2;
		if (l2 == 0) return l1;
		int dp[l1+1][l2+1];
		memset(dp, 0, sizeof(dp));
		for (int i = 0; i <= l1; ++i) {
			dp[i][0] = i;
		}
		for (int j = 0; j <= l2; ++j) {
			dp[0][j] = j;
		}
		for (int i = 1; i <= l1; ++i) {
			for (int j = 1; j <= l2; ++j) {
				int min = std::min(dp[i-1][j], dp[i][j-1]);
				if (word1[i-1] == word2[j-1]) {
					dp[i][j] = 1 + std::min(min, dp[i-1][j-1] - 1);
				} else {
					dp[i][j] = 1 + std::min(min, dp[i-1][j-1]);
				}
			}
		}
		return dp[l1][l2];
	}
};


TEST(testCase,test0) {

}


int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}

