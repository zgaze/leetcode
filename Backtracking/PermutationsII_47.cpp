/* ***********************************************************************

  > File Name: PermutationsII_47.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 


 ********************************************************************** */

#include <stdio.h>
#include <vector>
#include <string>
#include <stdio.h>
#include <climits>
#include <gtest/gtest.h>
#include <algorithm>

using std::vector;
using std::string;

/*
 * 47. 全排列 II
 *
 * 给定一个可包含重复数字的序列，返回所有不重复的全排列。
 *
 */

class Solution {
public:
	vector<vector<int>> res;
	vector<int> visited;
	void backtrack(vector<int>& nums, vector<int>& path, int begin) {
		if (path.size() == nums.size()) {
			res.push_back(path);
			return;
		}
		for (int i = 0; i < (int)nums.size(); ++i) {
			if (visited[i]) 
				continue;
			if (i > 0 && nums[i] == nums[i-1] && !visited[i-1]) {
				continue;
			}
			path.push_back(nums[i]);
			visited[i] = 1;
			backtrack(nums, path, begin + 1);
			visited[i] = 0;
			path.pop_back();
		}
	}

	vector<vector<int>> permuteUnique(vector<int>& nums) {
		if (nums.empty()) return res;
		visited.resize(nums.size());
		std::sort(nums.begin(), nums.end());
		vector<int> path;
		backtrack(nums, path, 0);
		return res;
	}
};

TEST(testCase,test0) {

}


int main(int argc, char* argv[]) {
	vector<int> a {0,1,0,0,9};      
	Solution s;                            
	vector<vector<int>> ret = s.permuteUnique(a);
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

