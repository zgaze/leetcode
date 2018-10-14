/* ***********************************************************************

  > File Name: SearchInsertPosition_35.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Sat 15 Sep 2018 10:24:46 PM CST

 ********************************************************************** */
/*
 * Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
 *
 * You may assume no duplicates in the array.
 *
 */

#include <vector>
#include <iostream>

using std::vector;

class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		int right = nums.size() - 1;
		int left = 0;
		while (left <= right) {
			int middle = ((right - left) >> 1) + left;
			if (target == nums[middle]) {  // target is found
				return middle;
			} else if (target < nums[middle]) {
				right = middle - 1;
			} else {
				left = middle + 1;
			}
		}
		return left;
	}
};


int main()
{
	vector<int> list1{1,2,3,4};
	vector<int> list2{1,2,4,5,7};
	vector<int> list3{2,4,5,7};
	int target = 3;
	Solution s1;
	std::cout << s1.searchInsert(list1, target) << "\n";
	std::cout << s1.searchInsert(list2, target) << "\n";
	std::cout << s1.searchInsert(list3, 1) << "\n";
	std::cout << s1.searchInsert(list3, 8) << "\n";
	return 0;
}

