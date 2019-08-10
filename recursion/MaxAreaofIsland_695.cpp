/* ***********************************************************************

  > File Name: MaxAreaofIsland_695.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Thu 08 Aug 2019 03:57:57 PM CST

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
 *
 * 给定一个包含了一些 0 和 1的非空二维数组 grid , 一个 岛屿 是由四个方向 (水平或垂直) 的 1 (代表土地) 构成的组合。你可以假设二维矩阵的四个边缘都被水包围着。
 *
 * 找到给定的二维数组中最大的岛屿面积。(如果没有岛屿，则返回面积为0。)
 *
 */


class Solution {
public:
	int Flood(vector<vector<int>>& grid, int sr, int sc) {
		if (sr < 0 || sr >= (int)grid.size()) return 0;
		if (sc < 0 || sc >= (int)grid[0].size()) return 0;
		if (grid[sr][sc] == 0) return 0;
		grid[sr][sc] = 0;
		return Flood(grid, sr - 1, sc) + Flood(grid, sr + 1, sc) + Flood(grid, sr, sc + 1) + Flood(grid, sr, sc - 1);
	}
	int maxAreaOfIsland(vector<vector<int>>& grid) {
		int sr = grid.size();
		if (sr == 0) {return 0;}
		int sc = grid[0].size();
		int max = 0;
		for (int i = 0; i < sr; ++i) {
			for (int j = 0; j < sc; ++j) {
				if (grid[i][j] == 1) {
					max = std::max(Flood(grid, i, j), max);
				}
			}
		}
		return max;
	}
};

TEST(testCase,test0) {

}


int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}

