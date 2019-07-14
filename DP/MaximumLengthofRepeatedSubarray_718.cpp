/* ***********************************************************************

  > File Name: MaximumLengthofRepeatedSubarray_718.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Fri 12 Jul 2019 04:23:18 PM CST

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
 * 给两个整数数组 A 和 B ，返回两个数组中公共的、长度最长的子数组的长度。
 *
 * 示例 1:
 *
 * 输入:
 * A: [1,2,3,2,1]
 * B: [3,2,1,4,7]
 * 输出: 3
 * 解释: 
 * 长度最长的公共子数组是 [3, 2, 1]。
 *
 */


/*
 * dp[i][j] 表示从A[i:] 和 B[j:] 的最长子数组的长度
 * dp[i][j] = (A[i] == B[j]) ? dp[i+1][j+1] + 1 : 0;
 * 可能为0: 会因为一个字母不匹配导致归0,因此保存更新最大值
 * 
 */
class Solution {
public:
	int findLength(vector<int>& A, vector<int>& B) {
		int ret = 0;
		int lenA = A.size(), lenB = B.size();
		int dp[lenA+1][lenB+1];
		memset(dp, 0, sizeof(dp));
		for (int i = lenA -1; i >= 0; --i) {
			for (int j = lenB-1; j >=0; --j) {
				dp[i][j] = (A[i] == B[j]) ? dp[i+1][j+1] + 1: 0;
				if (ret < dp[i][j]) {
					ret = dp[i][j];
					// printf("%d %d, num: %d\n", i, j, ret);
				}
			}
		}
		return ret;
	}
};

TEST(testCase,test0) {
	vector<int> a1 = {1,2,3,2,1};
	vector<int> b1 = {3,2,1,4,7};
	Solution s;
	EXPECT_EQ(s.findLength(a1, b1), 3);
}


int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}

