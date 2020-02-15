/* ***********************************************************************

  > File Name: mergesort.cpp
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
 * 归并排序
 * 步骤1：把长度为n的输入序列分成两个长度为n/2的子序列；
 * 步骤2：对这两个子序列分别采用归并排序；
 * 步骤3：将两个排序好的子序列合并成一个最终的排序序列。
 * 时间复杂度：最好、最差、平均都是O(nlgn),
 * 空间复杂度 O(n)
 * 稳定? 稳定
 */

class solution {
public:
	void merge(std::vector<int>& n, int begin1, int end1, int begin2, int end2) {
		std::vector<int> tmp(n);
		int i = begin1;
		while (begin1 <= end1 && begin2 <= end2) {
			if (n[begin1] <= n[begin2]) {
				tmp[i++] = n[begin1++];
			} else {
				tmp[i++] = n[begin2++];
			}
		}
		while (begin1 <= end1) {
			tmp[i++] = n[begin1++];
		}
		while (begin2 <= end2) {
			tmp[i++] = n[begin2++];
		}
		std::swap(n, tmp);
	}
	void halfsort(std::vector<int>& n, int begin, int end) {
		if (begin == end) return;
		if (end - begin == 1) {
			if (n[begin] > n[end]) std::swap(n[begin], n[end]);
		} else {
			int mid = (begin + end) / 2;
			halfsort(n, begin, mid);
			halfsort(n, mid + 1, end);
			merge(n, begin, mid, mid+1, end);
		}
	}
	void mergesort(std::vector<int> &n) {
		halfsort(n, 0, n.size() -1);
	}
};

template <typename T>
void printvector(std::vector<T> & n) {
	std::stringstream ss;
	for (auto & c : n) {
		ss << c << " ";
	}
	std::cout << ss.str() << "\n";
}


TEST(testCase,test0) {
	solution s;
	std::vector<int> nums{0,3,4,6,5,1,2,7};
	std::vector<int> nums1{3,4,6,5,1,2,7};
	std::vector<int> nums2{6,5,1,2,7};
	std::vector<int> nums3{7,6,5,4,3,2,1,0};
	std::vector<int> nums4{0,1,2,3,4,5,6,7,8,9};
	std::vector<int> nums5{0};
	std::vector<int> nums6{0,5,0,7};
	s.mergesort(nums);
	printvector(nums);
	s.mergesort(nums1);
	printvector(nums1);
	s.mergesort(nums2);
	printvector(nums2);
	s.mergesort(nums3);
	printvector(nums3);
	s.mergesort(nums4);
	printvector(nums4);
	s.mergesort(nums5);
	printvector(nums5);
	s.mergesort(nums6);
	printvector(nums6);
}


int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}

