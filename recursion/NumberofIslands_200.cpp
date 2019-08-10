/* ***********************************************************************

  > File Name: NumberofIslands_200.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Thu 08 Aug 2019 11:22:34 AM CST

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
 * 200. 岛屿数量
 *
 * 给定一个由 '1'（陆地）和 '0'（水）组成的的二维网格，计算岛屿的数量。一个岛被水包围，并且它是通过水平方向或垂直方向上相邻的陆地连接而成的。你可以假设网格的四个边均被水包围。
 *
 */

/*
 * 解法1；DFS  顺序遍历二维数组。如果是岛，把他周围的岛都变成水。 ++
 *
 *
 *
 */

class Solution {
public:
	void Flood(vector<vector<char>>& grid, int sr, int sc) {
		if (sr < 0 || sr >= (int)grid.size()) return;
		if (sc < 0 || sc >= (int)grid[0].size()) return;
		if (grid[sr][sc] == '0') return;
		grid[sr][sc] = '0';
		Flood(grid, sr - 1, sc);
		Flood(grid, sr + 1, sc);
		Flood(grid, sr, sc + 1);
		Flood(grid, sr, sc - 1);
	}
	int numIslands(vector<vector<char>>& grid) {
		if (grid.empty()) return 0;
		int sr = grid.size();
		int sc = grid[0].size();
		int island_num = 0;
		for (int i = 0; i < sr; ++i) {
			for (int j = 0; j < sc; ++j) {
				if (grid[i][j] == '1') {
					++ island_num;
					Flood(grid, i, j);
				}
			}
		}
		return island_num;
	}
};


TEST(testCase,test0) {

}


int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}

