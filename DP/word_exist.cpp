/* ***********************************************************************

  > File Name: word_exist.cpp
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
 *
 * 给定一个二维网格和一个单词，找出该单词是否存在于网格中。
 *
 * 单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。
 *
 * 示例:
 *
 * board =
 * [
 *   ['A','B','C','E'],
 *   ['S','F','C','S'],
 *   ['A','D','E','E']
 * ]
 *
 * 给定 word = "ABCCED", 返回 true.
 * 给定 word = "SEE", 返回 true.
 * 给定 word = "ABCB", 返回 false.
 *
 */

class Solution { 
 public:
     vector<vector<int>> visited;
     bool helper(vector<vector<char>>& board, int i, int j, string& word, int index) { 
         if (i < 0 || i >= (int)board.size()) return false;
         if (j < 0 || j >= (int)board[0].size()) return false;
         if (board[i][j] != word[index]) {
             return false;
         } 
         if (visited[i][j] == 1) return false;
         visited[i][j] = 1;
         //printf("%c %c ,[%d-%d]index: %d continue\n",board[i][j],word[index], i, j,index);
         if (index + 1 == word.size()) return true;
         bool res = helper(board, i, j+1, word, index+1) || helper(board, i, j-1, word, index+1) ||
             helper(board, i-1, j, word, index+1) || helper(board, i+1, j, word, index+1);
         visited[i][j] = 0;
         return res;
     }
     bool exist(vector<vector<char>>& board, string word) { 
         int col = board.size();
         int row = board[0].size();
         visited = vector<vector<int>>(col, vector<int>(row, 0));
         int index = 0;
         for (int i = 0;i < col; ++i) {
             for (int j = 0;j < row; ++j) {
                 if (helper(board, i, j, word, index)) {
                     return true;
                 }
             }
         }
         return false;
     }
 };

TEST(testCase,test0) {

}


int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}

