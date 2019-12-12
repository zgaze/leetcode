/* ***********************************************************************

  > File Name: SearchinRotatedSortedArray_33.cpp
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
    int search(vector<int>& nums, int target) {
        if (nums.empty()) return -1;
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = (left + right) / 2;
            if (target == nums[mid]) return mid;
            if (nums[mid] >= nums[left]) { // 第一区间
                // target 位于left mid这个单调区间
                if (target < nums[mid] && target >= nums[left]) {
                    right = mid;
                } else {
                    left = mid + 1;
                }
            } else if (nums[mid] <= nums[right]) { // mid位于第二区间上
                if (target > nums[mid] && target <= nums[right]) {
                    left = mid;
                } else {
                    right = mid - 1;
                }
            } else {
                // 不存在的情况
                return -1;
            }
        }
		if (target == nums[left]) return left;
        return -1;
    }
};

TEST(testCase,test0) {
	std::vector<int> nums{4,5,6,7,0,1,2};
	Solution s;
	EXPECT_EQ(s.search(nums, 4), 0);
	EXPECT_EQ(s.search(nums, 5), 1);
	EXPECT_EQ(s.search(nums, 6), 2);
	EXPECT_EQ(s.search(nums, 7), 3);
	EXPECT_EQ(s.search(nums, 8), -1);
	EXPECT_EQ(s.search(nums, 0), 4);
	EXPECT_EQ(s.search(nums, 1), 5);
	EXPECT_EQ(s.search(nums, 2), 6);
	EXPECT_EQ(s.search(nums, 3), -1);
	// 
	std::vector<int> nums1{4,5,1};
	EXPECT_EQ(s.search(nums1, 4), 0);
	EXPECT_EQ(s.search(nums1, 5), 1);
	EXPECT_EQ(s.search(nums1, 1), 2);
	EXPECT_EQ(s.search(nums1, 0), -1);
	EXPECT_EQ(s.search(nums1, 2), -1);
	EXPECT_EQ(s.search(nums1, 6), -1);
	// 
	std::vector<int> nums2{5,1};
	EXPECT_EQ(s.search(nums2, 5), 0);
	EXPECT_EQ(s.search(nums2, 1), 1);
	EXPECT_EQ(s.search(nums2, 0), -1);
	EXPECT_EQ(s.search(nums2, 4), -1);
	// 
	std::vector<int> nums3{1,2,3,4};
	EXPECT_EQ(s.search(nums3, 1), 0);
	EXPECT_EQ(s.search(nums3, 2), 1);
	EXPECT_EQ(s.search(nums3, 3), 2);
	EXPECT_EQ(s.search(nums3, 4), 3);
	EXPECT_EQ(s.search(nums3, 5), -1);
	EXPECT_EQ(s.search(nums3, 0), -1);
}



int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}

