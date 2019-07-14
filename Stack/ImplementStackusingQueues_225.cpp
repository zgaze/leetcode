/* ***********************************************************************

  > File Name: ImplementStackusingQueues_225.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Mon 08 Jul 2019 05:14:47 PM CST

 ********************************************************************** */

#include <stdio.h>
#include <vector>
#include <string>
#include <stdio.h>
#include <climits>
#include <queue>
#include <gtest/gtest.h>

using std::vector;
using std::string;

/*
 *
 * 225. 用队列实现栈
 *
 * 使用队列实现栈的下列操作：
 *
 * push(x) -- 元素 x 入栈
 * pop() -- 移除栈顶元素
 * top() -- 获取栈顶元素
 * empty() -- 返回栈是否为空
 * 
 */

/*
 * 队列没有栈那种来回颠倒的能力。从一个队列移动到另一个队列还是一样的
 * 因此每次插入都要往最前面插。所以就需要另一个队列来回倒腾: 
 * 每次放入空队列，把另一个队列的元素全部移到追加到这个空队列
 * 结果：原来有数的队列变空，元素都移动到 原来的空队列，新插入的元素在队首
 *
 */


class MyStack {
public:
	/** Initialize your data structure here. */
	MyStack() {
	}

	/** Push element x onto stack. */
	void push(int x) {
		auto & st_null = A.empty() ?  A : B;
		st_null.push(x);
		auto & st_not_null = A.empty() ?  A : B;
		while (!st_not_null.empty()) {
			int ele = st_not_null.front();
			st_not_null.pop();
			st_null.push(ele);
		}
	}

	/** Removes the element on top of the stack and returns that element. */
	int pop() {
		auto & st = A.empty() ?  B : A;
		int ele = st.front();
		st.pop();
		return ele;
	}

	/** Get the top element. */
	int top() {
		auto & st = A.empty() ?  B : A;
		return st.front();
	}

	/** Returns whether the stack is empty. */
	bool empty() {
		return A.empty() && B.empty();

	}
protected:
	std::queue<int> A;
	std::queue<int> B;
};


TEST(testCase,test0) {

}


int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}

