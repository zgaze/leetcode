/* ***********************************************************************

  > File Name: MinimumAddtoMakeParenthesesValid_921.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Tue 09 Jul 2019 02:24:14 PM CST

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
 *
 * 921. 使括号有效的最少添加
 *	给定一个只由 '(' 和 ')' 括号组成的字符串 S，我们需要添加最少的括号（ '(' 或是 ')'，可以在任何位置），以使得到的括号字符串有效。
 *
 *	从形式上讲，只有满足下面几点之一，括号字符串才是有效的：
 *
 *	它是一个空字符串，或者
 *	它可以被写成 AB （A 与 B 连接）, 其中 A 和 B 都是有效字符串，或者
 *	它可以被写作 (A)，其中 A 是有效字符串。
 *	给定一个括号字符串，返回为使结果字符串有效而必须添加的最少括号数。
 *
 */


class Solution {
public:
	int minAddToMakeValid(string S) {
		stack<char> st;
		int num = 0;
		for (auto c: S) {
			if (c == '(') {
				st.push(c);
			} else if (st.empty()){
				num ++;
			} else {
				st.pop();
			}
		}
		while (!st.empty()) {
			num ++;
			st.pop();
		}
		return num;
	}
};

TEST(testCase,test0) {
	Solution s;
	string s1 = "())";
	string s2 = "(((";
	string s3 = "()";
	string s4 = "()))((";
	EXPECT_EQ(s.minAddToMakeValid(s1), 1);
	EXPECT_EQ(s.minAddToMakeValid(s2), 3);
	EXPECT_EQ(s.minAddToMakeValid(s3), 0);
	EXPECT_EQ(s.minAddToMakeValid(s4), 4);
}


int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}

