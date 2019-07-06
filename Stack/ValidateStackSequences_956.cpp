/* ***********************************************************************

  > File Name: ValidateStackSequences_956.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Thu 04 Jul 2019 10:17:52 AM CST

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
 * 给定 pushed 和 popped 两个序列，只有当它们可能是在最初空栈上进行的推入 push 和弹出 pop 操作序列的结果时，返回 true；否则，返回 false 。
 *	示例 1：
 *
 *	输入：pushed = [1,2,3,4,5], popped = [4,5,3,2,1]
 *	输出：true
 *	解释：我们可以按以下顺序执行：
 *	push(1), push(2), push(3), push(4), pop() -> 4,
 *	push(5), pop() -> 5, pop() -> 3, pop() -> 2, pop() -> 1
 */

class Solution {
public:
	bool validateStackSequences_1(vector<int>& pushed, vector<int>& popped) {
		if (pushed.size() != popped.size()) {
			return false;
		}
		int i = 0, j = 0;
		int pushed_size = pushed.size();
		int popped_size = popped.size();
		std::stack<int> A;
		while (j < popped_size) {
			if (A.empty() || A.top() != popped[j]) {
				if (i < pushed_size) {
					A.push(pushed[i]);
					i ++;
				} else {
					return false;
				}
			} else if (A.top() == popped[j]) {
				A.pop();
				j ++;
			}
		}
		return true;
	}

	bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
		int j = 0;
		stack<int> A;
		for (int i : pushed) {
			A.push(i);
			while (!A.empty() && A.top() == popped[j]) {
				A.pop();
				j++;
			}
		}
		return A.empty();
	}
};


TEST(testCase,test0) {
	vector<int> push {1,2,3,4,5};
	vector<int> pop_1 {4,5,3,2,1};
	vector<int> pop_2 {4,5,3,1,2};
	vector<int> pop_3 {4,5,3,3,1};
	Solution s;
	EXPECT_TRUE(s.validateStackSequences(push, pop_1));
	EXPECT_FALSE(s.validateStackSequences(push, pop_2));
	EXPECT_FALSE(s.validateStackSequences(push, pop_3));
}


int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}

