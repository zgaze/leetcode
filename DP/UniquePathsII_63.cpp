/* ***********************************************************************

  > File Name: UniquePathsII_63.cpp
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
 * 一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。
 *
 * 机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。
 *
 * 现在考虑网格中有障碍物。那么从左上角到右下角将会有多少条不同的路径？
 *
 */



class Solution { 
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		int col = obstacleGrid.size();
		if (obstacleGrid.empty()) return 0;
		int row = obstacleGrid[0].size();
		int64_t dp[col][row];
		memset(dp, 0, sizeof(dp));
		for (int i = 0; i < col; ++i) {
			for (int j = 0; j < row; ++j) {
				if (i==0 && j ==0) {
					dp[0][0] = obstacleGrid[0][0] ? 0 : 1;
				}  else if (obstacleGrid[i][j] == 1) {
					dp[i][j] = 0;
				} else {
					dp[i][j] = 1;
					int64_t up = (i - 1 >= 0) ? dp[i-1][j] : 0;
					int64_t left = (j-1 >=0) ? dp[i][j-1] : 0;
					dp[i][j] = up + left;
				}
			}
		}
		return dp[col-1][row-1];
	}
};


TEST(testCase,test0) {

}


int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}

