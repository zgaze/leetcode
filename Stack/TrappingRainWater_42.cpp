/* ***********************************************************************

  > File Name: TrappingRainWater_42.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 


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
 * 给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
 * https://leetcode-cn.com/problems/trapping-rain-water/
 *
 * 此处给出单调栈解法
 */

class Solution {
public:
	int trap(vector<int>& height) {
		std::stack<int> st;
		int res = 0;
		for (int i = 0; i < (int)height.size(); ++i) {
			while (!st.empty() && height[i] > height[st.top()]) {
				int top = st.top();
				st.pop();
				if (st.empty()) break;
				int distance = i - st.top() - 1; // 当前和前一个较小值直接x轴距离
				// top的两边取小的。和top求高度差
				int bounded_height = std::min(height[i], height[st.top()]) - height[top];
				res += distance * bounded_height;
			}
			st.push(i);
		}
		// 最后还在栈里那些，因为右边没有比他更高的柱子。所以无法存水。被放弃
		return res;
	}
};


TEST(testCase,test0) {
	Solution s;
	std::vector<int> height{0,1,0,2,1,0,1,3,2,1,2,1,7,40,2,3};
	EXPECT_EQ(s.trap(height), 12);
}


int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}

