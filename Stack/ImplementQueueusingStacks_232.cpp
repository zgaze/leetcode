/* ***********************************************************************

  > File Name: ImplementQueueusingStacks_232.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Thu 04 Jul 2019 03:56:31 PM CST

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

/*
 *
 * 使用栈实现队列的下列操作：
 *
 * push(x) -- 将一个元素放入队列的尾部。
 * pop() -- 从队列首部移除元素。
 * peek() -- 返回队列首部的元素。
 * empty() -- 返回队列是否为空。
 */


class MyQueue {
public:
	/** Initialize your data structure here. */
	MyQueue() {

	}

	/** Push element x to the back of queue. */
	void push(int x) {
		// push A
		st_A.push(x);
	}

	/** Removes the element from in front of queue and returns that element. */
	int pop() {
		// A --> B B pop
		adj();
		int x = st_B.top();
		st_B.pop();
		return x;
	}

	/** Get the front element. */
	int peek() {
		adj();
		return st_B.top();
	}

	/** Returns whether the queue is empty. */
	bool empty() {
		return st_A.empty() && st_B.empty();

	}
protected:
	void adj() {
		// A --> B
		if (st_B.empty()) {
			while (!st_A.empty()) {
				int x = st_A.top();
				st_A.pop();
				st_B.push(x);
			}
		}
	}
	std::stack<int> st_A;
	std::stack<int> st_B;
};

TEST(testCase,test0) {

}

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}

