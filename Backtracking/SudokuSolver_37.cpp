/* ***********************************************************************

  > File Name: SudokuSolver_37.cpp
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

class Solution {
public:
	bool is_solve = false;
	int col[9][10];
	int row[9][10];
	int boxes[9][10];
	
	bool check(int i, int j, int num) {
		int b_index = 3*(i/3) + (j/3);
		return col[i][num] + row[j][num] + boxes[b_index][num] == 0;
	}

	void mark(vector<vector<char>>& board, int i, int j, int num) {
		col[i][num] ++;
		row[j][num] ++;
		int b_index = 3*(i/3) + (j/3);
		boxes[b_index][num]++;
		board[i][j] = num + '0';
	}

	void unmark(vector<vector<char>>& board, int i, int j, int num) {
		col[i][num] --;
		row[j][num] --;
		int b_index = 3*(i/3) + (j/3);
		boxes[b_index][num] --;
		board[i][j] = '.';
	}
	void PlaceNext(vector<vector<char>>& board, int i, int j) {
		if (i == 8 && j == 8) {
			is_solve = true;
		} else {
			if (j == 8) {
				backtrace(board, i +1, 0);
			} else {
				backtrace(board, i, j + 1);	
			}
		}
	}
	void backtrace(vector<vector<char>>& board, int i, int j) {
		if (board[i][j] == '.') {
			for (int num = 1; num < 10; ++num) {
				if (check(i, j, num)) {
					mark(board, i, j, num);
					PlaceNext(board, i, j);
					if (!is_solve) unmark(board, i, j, num);
				}
			}
		} else {
			PlaceNext(board, i, j);
		}
	}
	void solveSudoku(vector<vector<char>>& board) {
		memset(col, 0, sizeof(col));
		memset(row, 0, sizeof(row));
		memset(boxes, 0, sizeof(boxes));
		for (int i = 0; i < 9; ++i) {
			for (int j = 0; j <9; ++j) {
				if (board[i][j] != '.') {
					mark(board, i, j, board[i][j] - '0');
				}
			}
		}
		backtrace(board, 0, 0);
	}
};

TEST(testCase,test0) {

}


int main(int argc, char* argv[]) {
	Solution s;
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}

