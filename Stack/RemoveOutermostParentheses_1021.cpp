/* ***********************************************************************

  > File Name: RemoveOutermostParentheses_1021.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Thu 04 Jul 2019 12:04:47 PM CST

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
 *	有效括号字符串为空 ("")、"(" + A + ")" 或 A + B，其中 A 和 B 都是有效的括号字符串，+ 代表字符串的连接。例如，""，"()"，"(())()" 和 "(()(()))" 都是有效的括号字符串。
 *	如果有效字符串 S 非空，且不存在将其拆分为 S = A+B 的方法，我们称其为原语（primitive），其中 A 和 B 都是非空有效括号字符串。
 *	给出一个非空有效字符串 S，考虑将其进行原语化分解，使得：S = P_1 + P_2 + ... + P_k，其中 P_i 是有效括号字符串原语。
 *
 *	对 S 进行原语化分解，删除分解中每个原语字符串的最外层括号，返回 S 。
 *	示例 1：
 *
 *	输入："(()())(())"
 *	输出："()()()"
 *	解释：
 *	输入字符串为 "(()())(())"，原语化分解得到 "(()())" + "(())"，
 *	删除每个部分中的最外层括号后得到 "()()" + "()" = "()()()"。
 *	示例 2：
 *
 *	输入："(()())(())(()(()))"
 *	输出："()()()()(())"
 *	解释：
 *	输入字符串为 "(()())(())(()(()))"，原语化分解得到 "(()())" + "(())" + "(()(()))"，
 *	删除每隔部分中的最外层括号后得到 "()()" + "()" + "()(())" = "()()()()(())"。
 *	提示：
 *	S[i] 为 "(" 或 ")";S 是一个有效括号字符串
 */

class Solution {
public:
	string removeOuterParentheses(string S) {
		stack<char> st;
		string ret;
		ret.reserve(S.size());
		for (auto c: S) {
			bool begin_empty = st.empty();
			if (c == ')' && !st.empty()) {
				st.pop();
			} else {
				st.push(c);
			}
			if (!st.empty() && !begin_empty) {
				ret.push_back(c);
			}
		}
		return ret;
	}
};


TEST(testCase,test0) {
	std::string s1 {"(()())(())(()(()))"};
	string s1_out {"()()()()(())"};
	std::string s2 {"(()())(())"};
	string s2_out {"()()()"};
	Solution s;
	EXPECT_EQ(s.removeOuterParentheses(s1), s1_out);
	EXPECT_EQ(s.removeOuterParentheses(s2), s2_out);

}


int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}

