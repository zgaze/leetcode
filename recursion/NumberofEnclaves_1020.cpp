/* ***********************************************************************

  > File Name: NumberofEnclaves_1020.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Mon 12 Aug 2019 10:27:03 AM CST

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
 * 给出一个二维数组 A，每个单元格为 0（代表海）或 1（代表陆地）。
 *
 * 移动是指在陆地上从一个地方走到另一个地方（朝四个方向之一）或离开网格的边界。
 *
 * 返回网格中无法在任意次数的移动中离开网格边界的陆地单元格的数量。
 *
 */


class Solution {
public:
	int count = 0;
	bool dfs(vector<vector<int>>& A, int sc, int sr, int flag, int mark) {
		int i = A.size();
		int j = A[0].size();
		if (sc < 0 || sc >= i) {
			return true;
		}
		if (sr < 0 || sr >= j) {
			return true;
		}
		if (A[sc][sr] != flag) {
			return false;
		}
		A[sc][sr] = mark;
		bool a = dfs(A, sc + 1, sr, flag, mark);
		bool b = dfs(A, sc - 1, sr, flag, mark);
		bool c = dfs(A, sc, sr + 1, flag, mark);
		bool d = dfs(A, sc, sr - 1, flag, mark);
		return a || b || c || d;
	}
	int numEnclaves(vector<vector<int>>& A) {
		int count = 0;
		int sc = A.size(); 
		if (sc == 0) return 0;
		int sr = A[0].size();   
		for (int i = 0; i < sc; ++i) {
			for (int j = 0; j < sr; ++j) {
				if (A[i][j] == 1 && !dfs(A, i, j, 1, 2)) {
					dfs(A, i, j, 2, 3);
				}   
			}   
		}
		for (int i = 0; i < sc; ++i) {
			for (int j = 0; j < sr; ++j) {
				if (A[i][j] == 3) {
					count ++;
				}   
			}   
		}
		return count;
	}   
};  


TEST(testCase,test0) {

}


int main(int argc, char* argv[]) {
	vector<vector<int>> a ={
		{0,0,0,0},
		{1,0,1,0},
		{0,1,1,0},
		{0,0,1,0},
	};
	Solution s;
	printf("%d\n", s.numEnclaves(a) );
	testing::InitGoogleTest(&argc,argv);
	return RUN_ALL_TESTS();
}

