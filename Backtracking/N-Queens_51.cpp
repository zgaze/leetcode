/* ***********************************************************************

  > File Name: N-Queens_51.cpp
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
 * 51. N皇后
 * n 皇后问题研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
 * 给定一个整数 n，返回所有不同的 n 皇后问题的解决方案。
 *
 * 每一种解法包含一个明确的 n 皇后问题的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。
 *
 */
#include<cmath>

class Solution {
public:
	vector<vector<string>> res;
	vector<int> lines;
	vector<int> rows;
	vector<int> left;
	vector<int> right;
	void mark(int i, int j, int n ,int r) {
		lines[i] = r;
		rows[j] = r;
		left[i+j] = r;
		right[i-j+2*n] = r;
	}
	
	bool check(int i, int j, int n) {
		return lines[i] + rows[j] + left[i+j] + right[i-j + 2*n];
	}
	void backtrack(vector<string> &map, int now, int n) {
		for (int i = 0; i < n; ++i) {
			if (!check(now, i, n) && map[now][i] != 'Q') {
				map[now][i] = 'Q';
				mark(now, i, n, 1);
				if (now + 1== n) {
					res.push_back(map);
				} else {
					backtrack(map, now+1, n);
				}
				map[now][i] = '.';
				mark(now, i, n ,0);
			} 
		}
	}

	vector<vector<string>> solveNQueens(int n) {
		lines = std::vector<int>(n, 0);
		rows = std::vector<int>(n, 0);
		left = std::vector<int>(2 *n, 0);
		right = std::vector<int>(4*n, 0);
		vector<string> map(n, std::string(n, '.'));
		backtrack(map, 0, n);
		return res;
	}
};


TEST(testCase,test0) {

}


int main(int argc, char* argv[]) {
	Solution s;
	s.solveNQueens(5);
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}

