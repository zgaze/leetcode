/* ***********************************************************************

  > File Name: Subsets_78.cpp
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
 * 78. 子集
 * 给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。
 *
 */

class Solution {
public:
	vector<vector<int>> res;
	void backtrack(vector<int>& nums, vector<int> &path, int now, int need) {
		if (need ==  (int)path.size()) {
			res.push_back(path);
		} else {
			for (int i = now; i < (int)nums.size(); ++i) {
				path.push_back(nums[i]);
				backtrack(nums, path, i+1, need);
				path.pop_back();
			}
		}
	}
	vector<vector<int>> subsets(vector<int>& nums) {
		int size = nums.size();
		res.push_back(vector<int>{});
		for (int i = 1; i <= size; ++i) {
			vector<int> path;
			backtrack(nums, path, 0, i);
		}
		return res;   
	}
};

TEST(testCase,test0) {

}


int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}

