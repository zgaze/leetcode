/* ***********************************************************************

  > File Name: BackspaceStringCompare_844.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Mon 08 Jul 2019 06:06:39 PM CST

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
 * 844. 比较含退格的字符串
 *
 * 给定 S 和 T 两个字符串，当它们分别被输入到空白的文本编辑器后，判断二者是否相等，并返回结果。 # 代表退格字符。
 *
 * 示例 1：
 *
 * 输入：S = "ab#c", T = "ad#c"
 * 输出：true
 * 解释：S 和 T 都会变成 “ac”。
 *
 */

class Solution {
public:
	bool backspaceCompare(string S, string T) {
		stack<char> s;
		stack<char> t;
		for (auto c : S) {
			if (c != '#') {
				s.push(c);
			} else if (!s.empty()) {
				s.pop();
			}
		}
		for (auto c : T) {
			if (c != '#') {
				t.push(c);
			} else if (!t.empty()) {
				t.pop();
			}
		}
		if (s.size() != t.size()) {
			return false;
		}
		while (!s.empty()) {
			if (s.top() != t.top()) {
				return false;
			}
			s.pop();
			t.pop();
		}
		return true;
	}
};



TEST(testCase,test0) {
	std::string s1 = "ab#c";
	std::string s2 = "ad#c";
	std::string s3 = "ab##";
	std::string s4 = "c#d#";
	std::string s5 = "a##c";
	std::string s6 = "#a#c";
	std::string s7 = "a#c";
	std::string s8 = "b";
	Solution s;
	EXPECT_TRUE(s.backspaceCompare(s1, s2));
	EXPECT_TRUE(s.backspaceCompare(s3, s4));
	EXPECT_TRUE(s.backspaceCompare(s5, s6));
	EXPECT_FALSE(s.backspaceCompare(s7, s8));
}


int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}

