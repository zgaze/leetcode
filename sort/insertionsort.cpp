/* ***********************************************************************

  > File Name: insertionsort.cpp
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
 * 插入排序
 * 每次对于一个数。认定前面的已排序，那么将这个数插入合适的位置即可
 * 因为要插入，所以后面的需要往后移一个位置
 *
 */

class solution {
public:
	// 升序
	void insertionsort(std::vector<int> & n) {
		if (n.empty()) return;
		for (int i = 1; i < (int)n.size(); ++i) {
			int curr = n[i];
			for (int j = 0; j < i; ++j) {
				if (curr < n[j]) { // curr 应该在j前面
					int tmp = i;
					// 后面的往后一个位置，腾地方
					while (tmp > j) {n[tmp] = n[tmp-1]; tmp--;}
					n[j] = curr; // 插入n[i]
					break;
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
	s.insertionsort(nums);
	printvector(nums);
	s.insertionsort(nums1);
	printvector(nums1);
	s.insertionsort(nums2);
	printvector(nums2);
	s.insertionsort(nums3);
	printvector(nums3);
	s.insertionsort(nums4);
	printvector(nums4);
}


int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}

