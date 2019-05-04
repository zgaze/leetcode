/* ***********************************************************************

  > File Name: MinimumFallingPathSum_931.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Tue 30 Apr 2019 02:59:05 PM CST

 ********************************************************************** */
/*
 * 给定一个方形整数数组 A，我们想要得到通过 A 的下降路径的最小和。
 *
 * 下降路径可以从第一行中的任何元素开始，并从每一行中选择一个元素。在下一行选择的元素和当前行所选元素最多相隔一列。
 *
 *  
 *
 *  示例：
 *
 *  输入：[[1,2,3],[4,5,6],[7,8,9]]
 *  输出：12
 *  解释：
 *  可能的下降路径有：
 *  [1,4,7], [1,4,8], [1,5,7], [1,5,8], [1,5,9]
 *  [2,4,7], [2,4,8], [2,5,7], [2,5,8], [2,5,9], [2,6,8], [2,6,9]
 *  [3,5,7], [3,5,8], [3,5,9], [3,6,8], [3,6,9]
 *  和最小的下降路径是 [1,4,7]，所以答案是 12。
 */

/*
 * dp[x][y] = dp[x-1][y] + a[x][y];
 * 题目重点：最多相隔一列，即可以相隔一列
 */


#include <stdio.h>
#include <vector>
#include <string>
#include <stdio.h>
#include <climits>
#include<gtest/gtest.h>

using std::vector;
using std::string;

class Solution {
public:
	int minFallingPathSum(vector<vector<int>>& A) {
		if (A.empty() || A[0].empty()) return 0;
		int m = A.size();
		int n = A[0].size();
		int dp[m][n];
		for (int i = 0; i < n; ++i) {
			dp[0][i] = A[0][i]; 
		}
		for (int i = 1; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (j <= 0) {
					dp[i][j] = std::min(dp[i-1][j] + A[i][j], dp[i-1][j+1] + A[i][j]);
				} else if (j == n-1){
					dp[i][j] = std::min(dp[i-1][j] + A[i][j], dp[i-1][j-1] + A[i][j]);
				}else {
					dp[i][j] = std::min(std::min(dp[i-1][j] + A[i][j], dp[i-1][j-1] + A[i][j]), dp[i-1][j+1] + A[i][j]);
				}
			}
		}
		int min = INT_MAX;
		for (int i = 0; i < n; ++i) {
			min = std::min(dp[m-1][i], min);
		}
		return min;
	}
};

TEST(testCase,test0) {
	vector<vector<int>> A {
		{1,2,3},
		{4,5,6},
		{7,8,9},
	};
	vector<vector<int>> B {{17,82}, {1, -44}};
	Solution s;
	EXPECT_EQ(s.minFallingPathSum(A), 12);
	EXPECT_EQ(s.minFallingPathSum(B), -27);
}


int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}

