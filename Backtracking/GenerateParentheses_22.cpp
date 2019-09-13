/* ***********************************************************************

  > File Name: GenerateParentheses_22.cpp
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
 * 22. 括号生成
 * 给出 n 代表生成括号的对数，请你写出一个函数，使其能够生成所有可能的并且有效的括号组合。
 *
 * 例如，给出 n = 3，生成结果为：
 *
 * [
 *   "((()))",
 *   "(()())",
 *   "(())()",
 *   "()(())",
 *   "()()()"
 * ]
 */

class Solution {
public:
	void backtrack(vector<string>& res, int left, int right, std::string& now, int max) {
		if (2 * now.length() == (size_t)max) {
			res.push_back(now);
			return;
		} else {
			if (left < max) {
				now.append("(");
				backtrack(res, left + 1, right, now, max);
				now.resize(now.size() - 1);
			}
			if (right < left) {
				now.append(")");
				backtrack(res, left, right + 1, now, max);
				now.resize(now.size() - 1);
			}
		}
	}
	vector<string> generateParenthesis(int n) {
		int left = 0, right = 0;
		vector<string> res;
		std::string now;
		now.resize(2*n);
		backtrack(res, left, right, now, n);
		return res;
	}
};

TEST(testCase,test0) {

}


int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}

