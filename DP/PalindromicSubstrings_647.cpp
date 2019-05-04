/* ***********************************************************************

  > File Name: PalindromicSubstrings_647.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Wed 24 Apr 2019 04:57:08 PM CST

 ********************************************************************** */

#include <stdio.h>
#include <vector>
#include <string>
#include <stdio.h>
#include <climits>
#include <gtest/gtest.h>

/*
 *
 * 给定一个字符串，你的任务是计算这个字符串中有多少个回文子串。
 *
 * 具有不同开始位置或结束位置的子串，即使是由相同的字符组成，也会被计为是不同的子串。  @提示1
 *
 * 示例 1:
 *
 * 输入: "abc"
 * 输出: 3
 * 解释: 三个回文子串: "a", "b", "c". @提示2
 * 示例 2:
 *
 * 输入: "aaa"
 * 输出: 6
 * 说明: 6个回文子串: "a", "a", "a", "aa", "aa", "aaa".
 * 注意:
 *
 * 输入的字符串长度不会超过1000。
 */

/*
 * 动态规划法：Is[i][j] 为true表示区间i->j为回文。
 * 根据提示2，单个字符串是回文： Is[i][i] = true;
 * 根据提示1，只要区间不同，记为不同子串
 * 只有当s[i] == s[j]并且字符段[i + 1, j - 1]是回文串的时候，s[i, j]才能说是回文串
 * if (s[i] == s[j] && dp[i + 1][j - 1]){
 *	   dp[i][j] = true;
 *	   result += 1;
 * }
 */

using std::vector;
using std::string;

class Solution {
public:
	int countSubstrings(string s) {
		int length = s.length();
		bool dp[length][length];
		memset(dp, 0, sizeof(dp));
		int result = 0;
		for (int i = length -1; i >= 0; --i) {
			for (int j = i; j < length; ++j)  {
				if (j - i <= 1 && s[i] == s[j]) {
					dp[i][j] = true;
					result ++;
				} else if (s[i] == s[j] && dp[i + 1][j - 1]) {
					dp[i][j] = true;
					result ++;
				}
			}
		}
		return result;
	}
};



TEST(testCase,test0) {
	std::string s1{"abc"};
	std::string s2{"longtimenosee"};
	std::string s3{"aaa"};
	Solution s;
	EXPECT_EQ(s.countSubstrings(s1), 3);
	EXPECT_EQ(s.countSubstrings(s2), 14);
	EXPECT_EQ(s.countSubstrings(s3), 6);
}


int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}

