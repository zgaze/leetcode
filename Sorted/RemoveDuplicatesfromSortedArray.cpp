/* ***********************************************************************

  > File Name: RemoveDuplicatesfromSortedArray.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Sat 01 Sep 2018 05:06:28 PM CST

 ********************************************************************** */
// 删除重复数组，返回有效长度，不能借用额外空间

#include <vector>
#include <stdio.h>

using std::vector;

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.empty()) return 0;
		int length = 0;
		for (int& num : nums) {
			if (num != nums[length]) {
				length ++;
				nums[length] = num;
			}
		}
		return  length + 1;
	}
};

int main()
{
	int a[10] = {1, 1, 2, 3, 4, 5, 5, 5 ,6};
	vector<int> nums(&a[0], &a[9]);
	Solution s1;
	int length = s1.removeDuplicates(nums);
	for (int i = 0; i < length; ++i) {
		printf("--%d", nums[i]);
		printf("\n");
	}
	return 0;
}
