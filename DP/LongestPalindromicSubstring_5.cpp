/* ***********************************************************************

  > File Name: LongestPalindromicSubstring_5.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Thu 15 Aug 2019 02:12:35 PM CST

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
 * 5. 最长回文子串
 * 给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。
 *
 */

// 解法 1 暴力法
class Solution_1 {
public:
	bool isPalindromic(std::string & s, int begin, int end) {
		if (begin == end) {
			return true;
		}
		int l = begin, r = end;
		while ( l <= r) {
			if (s[l] != s[r]) {
				return false;
			}
			l ++;
			r --;
		}
		return true;
	}

	string longestPalindrome(string s) {
		int length = s.length();
		int max = 0, pos = 0;
		std::string ret;
		for (int i = 0; i < length; ++i) {
			for (int j = 0; j <= i; ++j) {
				if (isPalindromic(s, j, i)) {
					if (i - j + 1> max) {
						pos = j;
						max = i - j + 1;
					}
				}
			}
		}
		return s.substr(pos, max);

	}
};

class S {
public:
	string longestPalindrome(string s) {
		if (s.empty()) return s;
		int length = s.length();
		int dp[length][length];
		memset(dp, 0, sizeof(dp));
		for (int i = 0; i < length; ++i) {
			dp[i][i] = 0;
			if (i + 1 < length && s[i] == s[i+1]) {
				dp[i][i+1] = 1;
			}
		}
		int max = 0;
		int begin = 0;
		for (int i = 3; i < length; ++i) {
			for (int j = 0; j < i; ++j) {
				if (s[i] == s[j] && dp[j+1][i-1]) {
					dp[j][i] = 1; 
					if (max < i -j + 1) {
						max = i - j + 1;
						begin = j;
					}
				}
			}
		}
		return s.substr(begin, max);
	}
};

// dp
class Solution {
public:
	string longestPalindrome(string s)
	{
		if (s.empty()) return "";
		int len = s.size();
		if (len == 1)return s;
		int longest = 1;
		int start = 0;
		vector<vector<int> > dp(len,vector<int>(len));
		for (int i = 0; i < len; i++)
		{
			dp[i][i] = 1;
			if(i<len-1)
			{
				if (s[i] == s[i + 1])
				{
					dp[i][i + 1] = 1;
					start = i;
					longest = 2;
				}
			}
		}
		for (int l = 3; l <= len; l++)//子串长度
		{
			for (int i = 0; i+l-1 < len; i++)//枚举子串的起始点
			{
				int j=l+i-1;//终点
				if (s[i] == s[j] && dp[i+1][j-1]==1)
				{
					dp[i][j] = 1;
					start=i;
					longest = l;
				}
			}
		}
		return s.substr(start,longest);
	}
};


TEST(testCase,test0) {
	Solution s1;
	std::string s = "abcba";
	EXPECT_STREQ(s1.longestPalindrome(s).c_str(), "abcba");
}


int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}

