/* ***********************************************************************

  > File Name: Combinations_77.cpp
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
 * 77. 组合
 *
 * 给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。
 *
 * 示例:
 * 输入: n = 4, k = 2
 * 输出:
 * [
 *   [2,4],
 *   [3,4],
 *   [2,3],
 *   [1,2],
 *   [1,3],
 *   [1,4],
 * ]
 */

class Solution {
public:
	vector<vector<int>> res;
	void backtrack(vector<int> &path, int now, int k, int n) {
		if ((int)path.size() == k) {
			res.push_back(path);
			return;
		} 
		for (int i = now; i < n; ++i) {
			path.push_back(i);
			backtrack(path, i + 1, k, n);
			path.pop_back();
		}
	}
	vector<vector<int>> combine(int n, int k) {
		if (n == 0 || k == 0)
			return res;
		vector<int> path;
		backtrack(path, 1, k, n+1);
		return res;
	}
};


TEST(testCase,test0) {

}


int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}

