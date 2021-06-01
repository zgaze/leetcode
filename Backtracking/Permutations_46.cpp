/* ***********************************************************************

  > File Name: Permutations_46.cpp
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
 * 46. 全排列
 * 给定一个没有重复数字的序列，返回其所有可能的全排列。
 *
 */

class Solution {
public:
	vector<vector<int>> ret;
	void helper(vector<int>& nums, int fisrt) {
		if (fisrt == (int)nums.size()) {
			ret.push_back(nums);
			return;
		}

		for (int i = 0; i < (int)nums.size(); ++i) {
			std::swap(nums[i], nums[fisrt]);
			helper(nums, fisrt + 1);
			std::swap(nums[i], nums[fisrt]);
		}
	}
	vector<vector<int>> permute(vector<int>& nums) {
		helper(nums, 0);
		return ret;
	}
};


class Solution1 {
public:
	vector<vector<string>> ret;
	vector<int> visited;
	void backtrack(vector<string>& nums, vector<string>& path) {
		if (path.size() == nums.size()) {
			ret.push_back(path);
			return;
		}
		for (int i = 0; i < (int)nums.size(); ++i) {
			if (visited[i])
				continue;
			path.push_back(nums[i]);
			visited[i] = 1;
			backtrack(nums, path);
			visited[i] = 0;
			path.pop_back();
		}
	}
	vector<vector<string>> permute(vector<string>& nums) {
		visited.resize(nums.size());
		vector<string> path;
		backtrack(nums, path);
		return ret;
	}
};


TEST(testCase,test0) {

}


int main(int argc, char* argv[]) {
	vector<string> a {"溪" ,"页" ,"芦","梨","荷",  "塘","都","渔","冬","安","佑","雁","虞","良","泽","期","枫","风","林","空","山","雾","远","半"};
	Solution1 s;
	vector<vector<string>> ret = s.permute(a);
	for (auto &  v: ret) {
		std::stringstream ss;
		for (auto a : v) {
			ss << a << " ";
		}
		std::cout << ss.str() << "\n";
	}
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}

