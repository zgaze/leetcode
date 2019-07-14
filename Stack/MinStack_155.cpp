/* ***********************************************************************

  > File Name: MinStack_155.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Mon 08 Jul 2019 05:51:47 PM CST

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
 * 155. 最小栈
 * 设计一个支持 push，pop，top 操作，并能在常数时间内检索到最小元素的栈。
 *
 * push(x) -- 将元素 x 推入栈中。
 * pop() -- 删除栈顶的元素。
 * top() -- 获取栈顶元素。
 * getMin() -- 检索栈中的最小元素。
 *
 */

/*
 *	因为栈的特性：所以最小值的处理并不麻烦
 *	例如：data :[5 2 3 1 4]  mins;[5 2 1] 不需要3 的原因是: 3 一定比5先出栈，比 2 后出栈
 *	千万不要想复杂了, 比较时 == 也需要注意，处理相同值情况
 */

class MinStack {
public:
	/** initialize your data structure here. */
	MinStack() {
	}

	void push(int x) {
		data.push(x);
		if (mins.empty() || x <= mins.top()) { // 需要用 <= ,处理重复数
			mins.push(x);
		}
	}

	void pop() {
		int x = data.top();
		data.pop();
		if (x == mins.top()) {
			mins.pop();
		}
	}

	int top() {
		return data.top();
	}

	int getMin() {
		return mins.top();
	}
protected:
	stack<int> data;
	stack<int> mins;
};


TEST(testCase,test0) {

}


int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}

