/* ***********************************************************************

  > File Name: ContainerWithMostWater_11.cpp
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

/*给定 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0)。找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。

说明：你不能倾斜容器，且 n 的值至少为 2。

链接：https://leetcode-cn.com/problems/container-with-most-water
*/

class Solution {
public:
	int maxArea(vector<int>& height) {
		int i = 0, j = height.size() -1 ;
		int res = 0;
		while (i < j) {
			int tmp = std::min(height[i], height[j]) * (j-i);
			res = std::max(res, tmp);
			if (height[i] > height[j]) {
				j--;
			} else {
				i++;
			}
		}
		return res;
	}
};

TEST(testCase,test0) {
	Solution s1;
	std::vector<int> height {1,8,6,2,5,4,8,3,7};
	EXPECT_EQ(s1.maxArea(height), 48);
}


int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}

