/* ***********************************************************************

  > File Name: EvaluateReversePolishNotation_150.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Fri 05 Jul 2019 04:07:34 PM CST

 ********************************************************************** */

#include <stdio.h>
#include <vector>
#include <string>
#include <stdio.h>
#include <climits>
#include <stack>
#include <gtest/gtest.h>

/*
 *
 * 根据逆波兰表示法，求表达式的值。
 *
 * 有效的运算符包括 +, -, *, / 。每个运算对象可以是整数，也可以是另一个逆波兰表达式。
 *	说明：
 *
 *	整数除法只保留整数部分。
 *	给定逆波兰表达式总是有效的。换句话说，表达式总会得出有效数值且不存在除数为 0 的情况。
 */

using std::vector;
using std::string;

class Solution {
public:
	int evalRPN(vector<string>& tokens) {
		std::stack<int> a;
		for (auto s : tokens) {
			if (s == "+") {
				int a1 = a.top();
				a.pop();
				int a2 = a.top();
				a.pop();
				a.push(a2 + a1);
			} else if (s == "-") {
				int a1 = a.top();
				a.pop();
				int a2 = a.top();
				a.pop();
				a.push(a2 - a1);
			} else if (s == "*") {
				int a1 = a.top();
				a.pop();
				int a2 = a.top();
				a.pop();
				a.push(a2 * a1);
			} else if (s == "/") {
				int a1 = a.top();
				a.pop();
				int a2 = a.top();
				a.pop();
				a.push(a2 / a1);
			} else {
				a.push(std::stoi(s));
			}
		}
		return a.top();
	}
};

TEST(testCase,test0) {
	vector<string> s1 {"2", "1", "+", "3", "*"};
	vector<string> s2 {"4", "13", "5", "/", "+"};
	vector<string> s3 {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
	Solution s;
	EXPECT_EQ(s.evalRPN(s1), 9);
	EXPECT_EQ(s.evalRPN(s2), 6);
	EXPECT_EQ(s.evalRPN(s3), 22);

}


int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}

