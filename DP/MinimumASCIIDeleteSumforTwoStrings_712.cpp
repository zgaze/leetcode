/* ***********************************************************************

  > File Name: MinimumASCIIDeleteSumforTwoStrings_712.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Sun 28 Apr 2019 05:47:41 PM CST

 ********************************************************************** */

/*
 * 712. 两个字符串的最小ASCII删除和
 * 给定两个字符串s1, s2，找到使两个字符串相等所需删除字符的ASCII值的最小和。
 *
 * 示例 1:
 *
 * 输入: s1 = "sea", s2 = "eat"
 * 输出: 231
 * 解释: 在 "sea" 中删除 "s" 并将 "s" 的值(115)加入总和。
 * 在 "eat" 中删除 "t" 并将 116 加入总和。
 * 结束时，两个字符串相等，115 + 116 = 231 就是符合条件的最小和。
 *
 * 示例 2:
 *
 * 输入: s1 = "delete", s2 = "leet"
 * 输出: 403
 * 解释: 在 "delete" 中删除 "dee" 字符串变成 "let"，
 * 将 100[d]+101[e]+101[e] 加入总和。在 "leet" 中删除 "e" 将 101[e] 加入总和。
 * 结束时，两个字符串都等于 "let"，结果即为 100+101+101+101 = 403 。
 * 如果改为将两个字符串转换为 "lee" 或 "eet"，我们会得到 433 或 417 的结果，比答案更大。
 */

/*
 * 1.s1[i-1] == s2[j-1]，新增的两个字符相等的情况下，没有必要删除之前的结果，因此dp[i][j] = dp[i-1][j-1]
 * 2.s1[i-1] != s2[j-1]，取三者的最小值
 * (1)保留s2串，删除s1串的字符，dp[i][j] = dp[i-1][j] + s1.charAt(i-1)
 * (2)保留s1串，删除s2串的字符，dp[i][j] = dp[i][j-1] + s1.charAt(j-1)
 * (3)删除s1、s2串的字符，dp[i][j] = dp[i-1][j-1] + s1.charAt(i-1) + s2.charAt(j-1)
*/



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
	// 解法1：
	int minimumDeleteSum(string s1, string s2) {
		int size_1 = s1.size();
		int size_2 = s2.size();
		int dp[size_1+1][size_2+1];
		dp[0][0] = 0;
		for (int i = 1; i <= size_1; ++i) {
			dp[i][0] = s1[i-1] + dp[i-1][0];
		}
		for (int i = 1; i <= size_2; ++i) {
			dp[0][i] = s2[i-1] + dp[0][i-1];
		}
		for (int i = 1; i <= size_1; ++i) {
			for (int j = 1; j <= size_2; ++j) {
				if (s1[i-1] == s2[j-1]) {
					dp[i][j] = dp[i-1][j-1];
				} else {
					int num_1 = dp[i-1][j-1] + s1[i-1] + s2[j-1];
					dp[i][j] = std::min(std::min(num_1, dp[i-1][j] + s1[i-1]), dp[i][j-1] + s2[j-1]);
				}
			}
		}
		return dp[size_1][size_2];
	}
};

TEST(testCase,test0) {
	std::string s1 = "sea", s2 = "eat";
	std::string s3 = "delete", s4 = "leet";
	Solution s;
	EXPECT_EQ(s.minimumDeleteSum(s1, s2), 231);
	EXPECT_EQ(s.minimumDeleteSum(s3, s4), 403);
}


int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}

