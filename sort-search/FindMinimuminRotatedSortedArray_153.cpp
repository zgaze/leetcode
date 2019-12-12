/* ***********************************************************************

  > File Name: FindMinimuminRotatedSortedArray_153.cpp
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
 * 寻找旋转排序数组中的最小值
 *	假设按照升序排序的数组在预先未知的某个点上进行了旋转。
 *
 *	( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。
 *
 *	请找出其中最小的元素。
 *
 *	你可以假设数组中不存在重复元素。
 */

class Solution_2 {
public:
	int findMin(vector<int>& nums) {
		if (nums.size() == 1) return nums[0];
		int left = 0, right = nums.size();
		if (nums[right-1] > nums[left]) return nums[left];
		while(left < right) {
			int mid = left + (right - left) / 2;
			if (nums[mid] < nums[mid-1]) {
				return nums[mid];
			}
			if (nums[mid] > nums[0]) {
				left = mid + 1;
			} else {
				right = mid;
			}
		}
		return nums[left];
	}
};

class Solution {
public:
	int findMin(vector<int>& nums) {
		if (nums.empty()) return 0;
		int left = 0, right = nums.size() - 1;
		if (nums[right] >= nums[left])  return nums[left];
		while (left < right) {
			int mid = left + (right - left) / 2;
			if (nums[mid] > nums[mid+1]) {
				return nums[mid+1];
			}
			// 第一个递增区间上
			if (nums[mid] > nums[right]) {
				left = mid + 1; // 第一个递增区间并且大于right 说明肯定在mid的右边
			} else {
				// <= right 说明在递减区间上，同时mid可能就是最小值，所以不能减1
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

