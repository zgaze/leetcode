/* ***********************************************************************

  > File Name: heapsort.cpp
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
		void heapsort(std::vector<int> &nums) {
			int sz = nums.size();
			if (sz < 2) return;
			for (int i = sz/2; i >= 0; --i) {
				adjust(nums, i, sz);
			}
			for (int i = sz -1; i > 0; --i) {
				std::swap(nums[i], nums[0]);
				adjust(nums, 0, i);
			}
			return;
		}
		void adjust(std::vector<int> &nums, int index, int len) {
			for (int i = index*2+1; i < len; i *= 2) {
				if (i + 1 < len && nums[i] < nums[i+1]) {
					i ++;
				}
				if (nums[index] < nums[i]) {
					std::swap(nums[index], nums[i]);
					index = i;
				} else {
					break;
				}
			}
		}
};

TEST(testCase,test0) {
	std::vector<int> n{-1, 5, 2, 6, 9, 3, 0, 1, 7, 4, 8};
	Solution s;
	s.heapsort(n);
	std::stringstream ss;
	for (auto n1 : n) {
		ss << n1 << " ";
	}
	std::cout << ss.str() << "\n";
}


int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}

