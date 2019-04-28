/* ***********************************************************************

  > File Name: Triangle_120.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Sun 28 Apr 2019 01:54:53 PM CST

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
 * 给定一个三角形，找出自顶向下的最小路径和。每一步只能移动到下一行中相邻的结点上。
 *
 * 例如，给定三角形：
 *
 * [
 *      [2],
 *     [3,4],
 *   [6,5,7],
 *  [4,1,8,3]
 * ]
 * 自顶向下的最小路径和为 11（即，2 + 3 + 5 + 1 = 11）。
 * 说明：
 * 如果你可以只使用 O(n) 的额外空间（n 为三角形的总行数）来解决这个问题，那么你的算法会很加分。
 */


/*
 * 典型dp：
 * 到达第line行，第x个的最小距离可求 f(line,x) = min(f(line-1, x), f(line-1, x-1)) + a[line][x];
 * 如果要优化空间复杂度，公式改为f(line) = min(f(line,i)) (0<x<line-1)
 */

class Solution {
public:
	int minimumTotal(vector<vector<int>>& triangle) {
		if (triangle.empty()) return 0;
		int size = triangle.size();
		int dp[size][size];
		dp[0][0] = triangle[0][0];
		for (int i = 1; i < size; ++i) {
			for (int j = 0; j < (int)triangle[i].size(); ++j) {
				if (j == (int)triangle[i].size() -1)  {
					dp[i][j] = dp[i-1][j-1] + triangle[i][j];
				} else if (j > 0){
					dp[i][j] = std::min(dp[i-1][j-1], dp[i-1][j]) + triangle[i][j];
				} else {
					dp[i][j] = dp[i-1][0] + triangle[i][j];
				}
			}
		}
		int ret = INT_MAX;
		for (int i = 0; i < size; ++i) {
			ret = std::min(ret, dp[size-1][i]);
		}
		return ret;
	}
};

TEST(testCase,test0) {
	std::vector<vector<int>> triangle {
		{2},
		{3,4},
		{6,5,7},
		{4,1,8,3},
	};
	Solution s;
	EXPECT_EQ(s.minimumTotal(triangle), 11);
}


int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}

