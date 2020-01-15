/* ***********************************************************************

  > File Name: LongestValidParentheses_32.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Mon 19 Aug 2019 10:18:20 AM CST

 ********************************************************************** */

#include <stdio.h>
#include <vector>
#include <string>
#include <stdio.h>
#include <climits>
#include <stack>
#include <gtest/gtest.h>

using std::vector;
using std::string;
using std::stack;

/*
 * 给定一个只包含 '(' 和 ')' 的字符串，找出最长的包含有效括号的子串的长度。
 */

class Solution {
public:
	int longestValidParentheses(string s) {
		if (s.empty()) return 0;
		int length = s.length();
		std::stack<int> indexes;
		int max = 0;
		indexes.push(-1);
		for (int i = 0; i < length; ++i) {
			if (s[i] == '(') {
				indexes.push(i);
			} else {
				indexes.pop();
				if (indexes.empty()) {
					indexes.push(i);
				}
				int x = indexes.top();
				max = std::max(i - x , max);
			}
		}
		return max;
	}
};

TEST(testCase,test0) {
	Solution s;
	std::string s1 = "(()";
	std::string s2 = ")()())";
	std::string s3 = ")((())";
	EXPECT_EQ(s.longestValidParentheses(s1), 2);
	EXPECT_EQ(s.longestValidParentheses(s2), 4);
	EXPECT_EQ(s.longestValidParentheses(s3), 4);
}


int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}

