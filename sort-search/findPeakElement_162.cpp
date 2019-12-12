/* ***********************************************************************

  > File Name: findPeakElement_162.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Thu 29 Aug 2019 03:47:29 PM CST

 ********************************************************************** */

#include <stdio.h>
#include <vector>
#include <string>
#include <stdio.h>
#include <climits>
#include <gtest/gtest.h>

using std::vector;
using std::string;

class Solution_1 {
public:
	int getx(vector<int>& nums, int x) {
		if (x < 0 || x >= (int)nums.size()) return INT_MIN;
		return nums[x];
	}
	int findPeakElement(vector<int>& nums) {
		if (nums.empty()) return 0;
		if (nums.size() == 1) return 0;
		int left = 0, right = nums.size();
		while (left < right) {
			int mid = left + (right - left) /2;
			if (getx(nums, mid) > getx(nums, mid + 1)) { // 下降区间
				if (getx(nums, mid) > getx(nums, mid - 1)) {
					return mid;
				}
				right = mid - 1;
			} else {
				left = mid + 1;
			}
		}
		if (left < (int)nums.size()) return left;
		return 0;
	}
};


class Solution_2 {
public:
	int findPeakElement(vector<int>& nums) {
		int left = 0, right = nums.size() - 1;
		while (left < right) {
			int mid = left + (right - left) / 2;
			if (nums[mid] > nums[mid+1]) { // 下降区间
				right = mid;
			} else {
				left = mid + 1;
			}
		}
		return left;
	}
};

class Solution {
public:
	int findPeakElement(vector<int>& nums) {
		int left = 0, right = nums.size() - 1;
		while (left < right) {
			int mid = left + (right - left) / 2;
			if (nums[mid] < nums[mid+1]) {// 上升区间
				left = mid + 1;
			} else {
				right = mid;
			}
		}
		return left;
	}
};

TEST(testCase,test0) {

}


int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}

