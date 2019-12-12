/* ***********************************************************************

  > File Name: MedianofTwoSortedArrays_4.cpp
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
 * 4. 寻找两个有序数组的中位数
 *
 * 给定两个大小为 m 和 n 的有序数组 nums1 和 nums2。
 *
 * 请你找出这两个有序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。
 *
 * 你可以假设 nums1 和 nums2 不会同时为空。
 *
 */

/*
 * 中位数：偶数个数的，最中间两个数的平均数;奇数个数，最中间那个数
 * 方案一：对有序数据归并，归并到一半，就可以求到中位数了 时间复杂度 O((m+n))
 *
 */

class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int sz_1 = nums1.size(), sz_2 = nums2.size();
		// 有一个为空的情况
		if (nums1.empty() || nums2.empty()) {
			int index = nums1.empty() ? sz_2: sz_1;
			auto & nums = nums1.empty() ? nums2 : nums1;
			if ((index & 1) == 0) { // 偶数个
				return (nums[index/2] + nums[index/2 - 1]) / 2.0;
			} else {
				return 1.0 * nums[index/2];
			}
		}
		int total = sz_1 + sz_2;
		if ((total & 1) == 0) {
			return (findKth(nums1, nums2, 0, 0, total/2) + findKth(nums1, nums2, 0, 0, total/2 + 1)) / 2.0;
		}  else {
			return findKth(nums1, nums2, 0, 0, total/2 + 1);
		}
	}
	// 寻找两个排序数组第k个
	double findKth(vector<int>& nums1, vector<int>& nums2, int b1, int b2, int k) {
		//当a 或 b 超过数组长度，则第k个数为另外一个数组第k个数
		if (b1 == (int)nums1.size()) return nums2[b2 + k - 1];
		if (b2 == (int)nums2.size()) return nums1[b1 + k - 1];
		//k为1时，两数组最小的那个为第一个数
		if (k == 1) return std::min(nums1[b1], nums2[b2]);
		int m1 = INT_MAX, m2 = INT_MAX;
		if (b1 + k/2 - 1 < (int)nums1.size()) 
			m1 = nums1[b1 + k/2 - 1];
		if (b2 + k/2 - 1 < (int)nums2.size()) 
			m2 = nums2[b2 + k/2 - 1];
		if (m1 < m2) { // m1的右侧
			return findKth(nums1, nums2, b1 + k/2, b2, k - k / 2);
		} else {
			return findKth(nums1, nums2, b1, b2 + k/2 , k - k / 2);
		}
	}

};

class Solution_1 {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int m = nums1.size(), n = nums2.size();
		if (n < m) {
			std::swap(n, m);
			std::swap(nums1, nums2);
		}
		int imin = 0, imax = m, halfLen = (m + n + 1) / 2;
		while (imin <= imax) {
			int i = (imax + imin) / 2;
			int j = halfLen - i;
			if (i < imax && nums2[j-1] > nums1[i]) {
				imin = i + 1; // i is too small
			} else if (i > imin && nums1[i-1] >nums2[j]) {
				imax = i - 1;
			} else {
				int maxleft = 0;
				if (i == 0) {maxleft = nums2[j-1];}
				else if (j == 0) {maxleft = nums1[i-1];}
				else {maxleft = std::max(nums2[j-1], nums1[i-1]);}
				if ((m + n) % 2)  return maxleft; // 奇数返回左边最大的即可

				int minright = 0;
				if (i == m) {minright = nums2[j];}
				else if (j == n) {minright = nums1[i];}
				else { minright = std::min(nums2[j], nums1[i]);}
				return (maxleft + minright) / 2.0;
			}
		}
		return 0.0;
	}
};

TEST(testCase,test0) {
	std::vector<int> v1 {1, 2, 13, 14, 15};
	std::vector<int> v2 {1, 2, 8, 9, 15};
	Solution s;
	printf("index: %d is %f\n", 1, s.findKth(v1, v2, 0, 0, 1));
	printf("index: %d is %f\n", 2, s.findKth(v1, v2, 0, 0, 2));
	printf("index: %d is %f\n", 3, s.findKth(v1, v2, 0, 0, 3));
	printf("index: %d is %f\n", 4, s.findKth(v1, v2, 0, 0, 4));
	printf("index: %d is %f\n", 5, s.findKth(v1, v2, 0, 0, 5));
	printf("index: %d is %f\n", 6, s.findKth(v1, v2, 0, 0, 6));
	printf("index: %d is %f\n", 7, s.findKth(v1, v2, 0, 0, 7));
	printf("index: %d is %f\n", 8, s.findKth(v1, v2, 0, 0, 8));
	printf("index: %d is %f\n", 9, s.findKth(v1, v2, 0, 0, 9));
	printf("index: %d is %f\n", 10, s.findKth(v1, v2, 0, 0, 10));

}


int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}

