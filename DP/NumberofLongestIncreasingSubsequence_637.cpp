/* ***********************************************************************

  > File Name: NumberofLongestIncreasingSubsequence_637.cpp
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
 * 给定一个未排序的整数数组，找到最长递增子序列的个数。
 *
 * 示例 1:
 *
 * 输入: [1,3,5,4,7]
 * 输出: 2
 * 解释: 有两个最长递增子序列，分别是 [1, 3, 4, 7] 和[1, 3, 5, 7]。
 * 示例 2:
 *
 * 输入: [2,2,2,2,2]
 * 输出: 5
 * 解释: 最长递增子序列的长度是1，并且存在5个子序列的长度为1，因此输出5。
 * 注意: 给定的数组长度不超过 2000 并且结果一定是32位有符号整数。
 *
 */


class Solution {
public:
	int findNumberOfLIS(vector<int>& nums) {
		int length = nums.size();
		if (length <= 1) return length;
		int dp_l[length];
		int dp_count[length];
		memset(dp_l, 0, sizeof(dp_l));
		for(int i = 0; i < length; ++i) {
			dp_count[i] = 1;
		}
		int longest = 0;
		for (int l = 0; l < length; ++l) {
			for (int i = 0; i < l; ++i) {
				if (nums[i] < nums[l]) { // ???
					if (dp_l[i] >= dp_l[l]) {
						dp_l[l] = dp_l[i] + 1;
						longest = std::max(longest,  dp_l[l]);
						dp_count[l] = dp_count[i];
					}
				}
			}
		}
		int res = 0;
		for (int i = 0; i < length; ++i) {
			if (dp_l[i] == longest) {
				res += dp_count[i];
			}
		}
		return res;
	}
};


TEST(testCase,test0) {

}


int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}

