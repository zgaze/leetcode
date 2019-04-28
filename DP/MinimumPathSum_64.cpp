/* ***********************************************************************

  > File Name: MinimumPathSum_64.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Tue 23 Apr 2019 10:42:39 AM CST

 ********************************************************************** */

/*
 * 给定一个包含非负整数的 m x n 网格，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。
 *
 * 说明：每次只能向下或者向右移动一步。
 *
 * 示例:
 *
 * 输入:
 * [
 *   [1,3,1],
 *   [1,5,1],
 *   [4,2,1]
 * ]
 * 输出: 7
 * 解释: 因为路径 1→3→1→1→1 的总和最小。
 */


/*
 * dp: 
 * f(i, j) = min(f(i-1, j) + a[i][j], f(i, j-1) + a[i][j]);
 * 自己画一个3*3的表格，即可
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
	int minPathSum(vector<vector<int>>& grid) {
		int m = grid.size();
		int n = grid[0].size();
		if (grid.empty() || grid[0].empty()) {
			return 0;
		}
		int dp[m][n];
		for (int i = 0; i < m; ++i) {
			for(int j = 0; j < n; ++j) {
				// 
				if (i == 0 && j == 0) {
					dp[i][j] = grid[i][j];
				} else if (i == 0) {
					dp[i][j] = dp[i][j-1] + grid[i][j];
				} else if (j == 0) {
					dp[i][j] = dp[i-1][j] + grid[i][j];
				} else {
					dp[i][j] = std::min(dp[i-1][j] + grid[i][j], dp[i][j-1] + grid[i][j]);
				}
			}
		}
		return dp[m-1][n-1];
	}
};


TEST(testCase,test0) {
	Solution s;
	std::vector<vector<int>> v{
		{1,3,1,1},
		{1,5,3,1},
		{4,2,1,2},
	};
	EXPECT_EQ(s.minPathSum(v), 9);
}


int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}

