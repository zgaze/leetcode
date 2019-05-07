/* ***********************************************************************

  > File Name: searchMatrix.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Tue 07 May 2019 03:07:27 PM CST

 ********************************************************************** */

#include <stdio.h>
#include <vector>
#include <string>
#include <stdio.h>
#include <climits>
#include <gtest/gtest.h>

using std::vector;
using std::string;

/*编写一个高效的算法来搜索 m x n 矩阵 matrix 中的一个目标值 target。该矩阵具有以下特性：
 *
 * 每行的元素从左到右升序排列。
 * 每列的元素从上到下升序排列。
 * 示例:
 *
 * 现有矩阵 matrix 如下：
 *
 * [
 *   [1,   4,  7, 11, 15],
 *   [2,   5,  8, 12, 19],
 *   [3,   6,  9, 16, 22],
 *   [10, 13, 14, 17, 24],
 *   [18, 21, 23, 26, 30]
 * ]
 * 给定 target = 5，返回 true。
 * 给定 target = 20，返回 false。
 */

/*
 * 以左下角的数为基准，小于目标值，则向右移动，大于目标值，则向上移动
 *
 */


class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		if (matrix.empty() || matrix[0].empty()) {
			return false;
		}
		int row_size = matrix.size();
		int col_size = matrix[0].size();
		int row = row_size- 1, col = 0;
		while(row >= 0 && col < col_size) {
			if (target == matrix[row][col]) {
				return true;
			} else if (matrix[row][col] > target) {
				row --; // target 小就向上
			} else {
				col ++; // target 大就往右
			}
		}
		return false;
	}
};

TEST(testCase,test0) {
	std::vector<std::vector<int>> matrix {
		{1,   4,  7, 11, 15},
		{2,   5,  8, 12, 19},
		{3,   6,  9, 16, 22},
		{10, 13, 14, 17, 24},
		{18, 21, 23, 26, 30},
	};
	Solution s;
	EXPECT_EQ(s.searchMatrix(matrix, 1), true);
	EXPECT_EQ(s.searchMatrix(matrix, 2), true);
	EXPECT_EQ(s.searchMatrix(matrix, 3), true);
	EXPECT_EQ(s.searchMatrix(matrix, 4), true);
	EXPECT_EQ(s.searchMatrix(matrix, 5), true);
	EXPECT_EQ(s.searchMatrix(matrix, 6), true);
	EXPECT_EQ(s.searchMatrix(matrix, 7), true);
	EXPECT_EQ(s.searchMatrix(matrix, 8), true);
	EXPECT_EQ(s.searchMatrix(matrix, 9), true);
	EXPECT_EQ(s.searchMatrix(matrix, 10), true);
	EXPECT_EQ(s.searchMatrix(matrix, 30), true);
	EXPECT_EQ(s.searchMatrix(matrix, 0), false);
	EXPECT_EQ(s.searchMatrix(matrix, 31), false);
}


int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}

