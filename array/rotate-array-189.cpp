/*
 *
 * 给定一个整数数组 nums，将数组中的元素向右轮转 k 个位置，其中 k 是非负数。
 *
 *
 *
 */

class Solution {
public:
	//  k = 3 [1,2,3,4,5,6,7]  [5,6,7,1,2,3,4]
    void rotate(vector<int>& nums, int k) {
			if (k == 0 || nums.size() == 0 || k %nums.size() == 0) {
				return 0;
			}
			int n = nums.size();
			k %= n;
			nums.insert(nums.end(); nums.begin(), nums.end());
			for (int i = 0; i < n; ++i) {
				nums[i] = nums[n-k+i];
			}
			nums.resize(n);
    }
};
