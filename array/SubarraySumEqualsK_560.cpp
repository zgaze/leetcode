/* ***********************************************************************

  > File Name: SubarraySumEqualsK_560.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 


 ********************************************************************** */

#include <stdio.h>
#include <vector>
#include <string>
#include <stdio.h>
#include <climits>
#include <map>
#include <gtest/gtest.h>

using std::vector;
using std::string;

/*
 *	560. 和为K的子数组
 *	给定一个整数数组和一个整数 k，你需要找到该数组中和为 k 的连续的子数组的个数。
 *
 *	示例 1 :
 *
 *	输入:nums = [1,1,1], k = 2
 *	输出: 2 , [1,1] 与 [1,1] 为两种不同的情况。
 */


/* 
 * 本题常规解法：复杂度为O(n^3)
 *
 * 使用sum[i] 保存从0到i位置的数组和。num[i] - num[j],就是j到k位置的和。
 * 使用sum[i]可以避免重复求和。优化这一步可以达到O(n^2)
 * 
 * 类似两数之后，可以保存和出现的次数，然后顺序遍历的时候看有没有和是该数值的，求出即可
 *
 *
 */

class Solution {
public:
	int subarraySum(vector<int>& nums, int k) {
		if (nums.empty()) return 0;
		int count = 0, sum = 0;
		int sz = nums.size();
		std::map<int, int> sum_count; // 和为sum的可能有多个，需要记录个数
		sum_count[0] = 1;
		for (int i = 0; i < sz; ++i) {
			sum += nums[i];
			int v = sum - k; // v == 0,即说明0-i的子数组和位k，因为map需要初始化sum_count[0] = 1
			auto it = sum_count.find(v); // 找到i以前，sum比当前位置小k的sum[i]
			if (it != sum_count.end()) {
				count += it->second;
			}
			sum_count[sum] ++;
		}
		return count;
	}
};

TEST(testCase,test0) {
	Solution s;
	std::vector<int> a1{1,1,1,1};
	EXPECT_EQ(s.subarraySum(a1, 2), 3);
}


int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}

