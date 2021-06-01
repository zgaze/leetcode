/* ***********************************************************************

  > File Name: quicksort.cpp
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
 * 快速排序：
 * 快速排序使用分治法来把一个串（list）分为两个子串（sub-lists）。具体算法描述如下：
 * 	步骤1：从数列中挑出一个元素，称为 “基准”（pivot ）；
 *  步骤2：重新排序数列，所有元素比基准值小的摆放在基准前面，所有元素比基准值大的摆在基准的后面（相同的数可以到任一边）。在这个分区退出之后，该基准就处于数列的中间位置。这个称为分区（partition）操作；
 *  步骤3：递归地（recursive）把小于基准值元素的子数列和大于基准值元素的子数列排序。
 *
 *	时间复杂度 ：最佳情况：T(n) = O(nlgn),最差情况：T(n) = O(n2) 平均情况：T(n) = O(nlgn)
 *  空间复杂度：原地,不需要额外空间
 */

class solution {
public:
	// 另一种partition方法
	int partation_I(std::vector<int> & n, int begin, int end) {
		int flag = n[begin];
		int i = begin;
		for (int j = begin + 1; j <= end; ++j) {
			if (n[j] < flag) {
				i++;
				std::swap(n[j], n[i]);
			}
		}
		std::swap(n[i], n[begin]);
		return i;
	}

	int partation(std::vector<int> & n, int begin, int end) {
		int i = begin, j = end;
		int x = n[begin]; // 基准数
		while (i < j) {
			while (i < j && n[j] >= x) j--;
			if (i < j) {
				n[i] = n[j];
				//i++;
			}
			while (i < j && n[i] < x) i++;
			if (i < j) {
				n[j] = n[i];
				//j--;
			}
		}
		n[i] = x;
		return i;
	}
	void r_quicksort(std::vector<int> & n, int begin, int end) {
		if (begin >= end) return;
		if (begin - end == 1) {
			if (n[begin] > n[end]) std::swap(n[begin] , n[end]);
			return;
		}
		int mid = partation_I(n, begin, end);
		r_quicksort(n, begin, mid - 1);
		r_quicksort(n, mid + 1, end);
	}
	void quicksort(std::vector<int> & n) {
		if (n.size() < 2) return;
		r_quicksort(n, 0, n.size() -1);
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
	s.quicksort(nums);
	printvector(nums);
	s.quicksort(nums1);
	printvector(nums1);
	s.quicksort(nums2);
	printvector(nums2);
	s.quicksort(nums3);
	printvector(nums3);
	s.quicksort(nums4);
	printvector(nums4);
}

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}

