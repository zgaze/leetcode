/* ***********************************************************************

  > File Name: LongestArithmeticSequence_1027.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 


 ********************************************************************** */

#include <stdio.h>
#include <vector>
#include <string>
#include <stdio.h>
#include <climits>
#include <unordered_map>
#include <gtest/gtest.h>

using std::vector;
using std::string;

/*
 * 给定一个整数数组 A，返回 A 中最长等差子序列的长度。
 *
 * 回想一下，A 的子序列是列表 A[i_1], A[i_2], ..., A[i_k] 
 * 其中 0 <= i_1 < i_2 < ... < i_k <= A.length - 1。
 * 如果 B[i+1] - B[i]( 0 <= i < B.length - 1) 的值都相同，那么序列 B 是等差的。
 *
 */

class Solution {
public:
	int longestArithSeqLength(vector<int>& A) {
		if (A.empty()) return 0;
		int res = 1, len = A.size();
		// map: cha值 ---> dp[i] 
		std::vector<std::unordered_map<int, int>> dp(len);
		for (int i = 0; i < len; ++i) {
			for (int j = 0; j < i; ++j) {
				int k = A[i] - A[j];
				if (dp[j][k] != 0) { // 差值为k的序列，已经有长度了。+1即可
					dp[i][k] = dp[j][k] + 1;
				} else {
					// 注意不是jk, 本次计算由j推导到i
					dp[i][k] = 2;
				}
				res = std::max(res, dp[i][k]);
			}
		}
		return res;
	}
};

TEST(testCase,test0) {
	Solution s;
	std::vector<int> A2 {9,4,7,2,10};
	std::vector<int> A1 {3,6,9,12};
	std::vector<int> A3 {20,1,15,3,10,5,8};
	EXPECT_EQ(s.longestArithSeqLength(A1), 4);
	EXPECT_EQ(s.longestArithSeqLength(A2), 3);
	EXPECT_EQ(s.longestArithSeqLength(A3), 4);
}


int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}

