/* ***********************************************************************

  > File Name: selectsort.cpp
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
 * 选择排序：
 * 每次选出一个最小的，放到最前面
 *
 *
 */

class solution {
public:
	void selectsort(std::vector<int> & n) {
		for (int i = 0; i < (int)n.size(); ++i) {
			int min = i;
			for (int j = i; j < (int)n.size(); ++j) {
				if (n[j] < n[min]) {min = j;}
			}
			std::swap(n[min], n[i]);
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
	s.selectsort(nums);
	printvector(nums);
	s.selectsort(nums1);
	printvector(nums1);
	s.selectsort(nums2);
	printvector(nums2);
	s.selectsort(nums3);
	printvector(nums3);
	s.selectsort(nums4);
	printvector(nums4);
}


int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}

