/* ***********************************************************************

  > File Name: JumpGameII_45.cpp
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

class Solution {
public:
	// 贪心
	// 最后一个数字是多少都无关紧要
    int jump(vector<int>& nums) {
        if (nums.size() < 2) return 0;
		int end = 1, start = 0;
		int step = 0;
		while (end < (int)nums.size()-1) {
			int max_pos = 0;
			for (int i = start; i < end; ++i) {
				max_pos = std::max(max_pos, nums[i] + i);
			}
			start = end;      // 下一次起跳点范围开始的格子
			end = max_pos + 1;
			++step;
		}
        return step;
    }
};

TEST(testCase,test0) {
	std::vector<int> nums{2,3,1,1,4,6,4,1,2,3,0,4,5,2,1,1,2,3};
	Solution s;
	EXPECT_EQ(2, s.jump(nums));
}
int main(int argc, char* argv[]) {
	Solution s;
	std::vector<int> nums{2,3,1,1,4,6,4,1,2,3,0,4,5,2,1,1,2,3};
	int jump_cnt = s.jump(nums);
	printf("jump_cnt:%d \n", jump_cnt);
	printf("2,3,1,1,4,6,4,1,2,3,0,4,5,2,1,1,2,3 \n");
	return 0;
}

