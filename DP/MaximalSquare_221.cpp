/* ***********************************************************************

  > File Name: MaximalSquare_221.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Sun 18 Aug 2019 11:03:33 AM CST

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
 * 221. 最大正方形
 * 在一个由 0 和 1 组成的二维矩阵内，找到只包含 1 的最大正方形，并返回其面积。
 *
 *
 * dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1] ) + 1;
 * 画图即可理解，如果 上方，左边，和左上 都是一样的，说明是 3个边长x的正方形。加上自己的1.就是x+1的正方形
 * 反之，取最小值 + 1, 意思是 必须要三个都满足，才能+1,  画图能很好理解
 *
 */


class Solution {
public:
	int maximalSquare(vector<vector<char>>& matrix) {
		if (matrix.empty() || matrix[0].empty())  return 0;
		int M = matrix.size(), N = matrix[0].size();
		int dp[M][N];
		memset(dp, 0, sizeof(dp));
		int max_len = 0;
		for (int i = 0; i < M; ++i) {
			for (int j = 0; j < N; ++j) {
				if (matrix[i][j] == 1) {
					int s1 = (i - 1 >= 0) ? dp[i-1][j]: 0;
					int s2 = (j - 1 >= 0) ? dp[i][j-1]: 0;
					int s3 = (j - 1 >= 0 && i -1 >= 0) ? dp[i-1][j-1] : 0;
					dp[i][j] = std::min(s1, std::min(s2, s3)) + 1;
					max_len = std::max(max_len, dp[i][j]);
				}
			}
		}
		return max_len * max_len;
	}
};

TEST(testCase,test0) {

}


int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}

