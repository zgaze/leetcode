/* ***********************************************************************

  > File Name: mountainArr.cpp
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

class MountainArray {
public:
	int get(int index);
	int length();
};
 
class Solution {
public:
	int findmax(MountainArray &mountainArr, int begin, int end) {
		int mid = (begin + end) / 2;
		int mid_n = mountainArr.get(mid);
		int mid_n_1 = mountainArr.get(mid - 1);
		int mid_n1 = mountainArr.get(mid + 1);
		if (mid_n > mid_n_1 && mid_n < mid_n1) { // 上升区间
			return findmax(mountainArr, mid, end);
		}
		if (mid_n < mid_n_1 && mid_n > mid_n1) { // 下降区间
			return findmax(mountainArr, begin, mid);
		}
		return mid;
	}
	int binary_search(MountainArray &mountainArr, int begin, int end, int target) {
		while (begin <= end) {
			int mid = (begin + end) / 2; 
			int mid_n = mountainArr.get(mid);
			if (mid_n < target) {
				begin = mid + 1;
			} else if (mid_n > target) {
				end = mid - 1;
			} else {
				return mid;
			}
		}
		return -1;
	}
	// 下降数组
	int binary_search_1(MountainArray &mountainArr, int begin, int end, int target) {
		while (begin <= end) {
			int mid = (begin + end) / 2; 
			int mid_n = mountainArr.get(mid);
			if (mid_n > target) {
				begin = mid + 1;
			} else if (mid_n < target) {
				end = mid - 1;
			} else {
				return mid;
			}
		}
		return -1;
	}
    int findInMountainArray(int target, MountainArray &mountainArr) {
		int max_index = findmax(mountainArr, 0, mountainArr.length());
		int s1 = binary_search(mountainArr, 0, max_index, target);
		int s2 = binary_search(mountainArr, max_index, mountainArr.length() - 1, target);
		if (s1 >= 0 && s2 >= 0) return std::min(s1, s2);
		return std::max(s1, s2);
        
    }
};


TEST(testCase,test0) {

}




int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}

