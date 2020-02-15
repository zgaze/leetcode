/* ***********************************************************************

  > File Name: bubblesort.cpp
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
 * 冒泡排序：
 * 相邻的两两比较，大的往后移，每次把一个最大的冒泡到最后面
 *
 *
 */

class solution {
public:
	void bubblesort(std::vector<int> & n) {
		int len = n.size();
		for (int i = 1; i < len; ++i) {
			for (int j = 0; j < len - i; ++j) {
				if (n[j] > n[j+1]) {
					std::swap(n[j], n[j+1]);
				}
			}
		}
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
	s.bubblesort(nums);
	printvector(nums);
	s.bubblesort(nums1);
	printvector(nums1);
	s.bubblesort(nums2);
	printvector(nums2);
	s.bubblesort(nums3);
	printvector(nums3);
	s.bubblesort(nums4);
	printvector(nums4);
}

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}

