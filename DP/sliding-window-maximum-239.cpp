/*
	 给你一个整数数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。
	 返回 滑动窗口中的最大值 。
*/

class Solution {
public:
	  // 单调递减队列
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
			std::deque<int> n;
			vector<int> ret(nums.size()-k + 1);
			for (int i = 0; i < nums.size(); ++i) {
				if (!n.empty() && i - n.front() > k) {
					n.pop_front();
				}
				while (!n.empty() && nums[i] > nums[n.back()]) {
					n.pop_back();
				}
				n.push_back(i);
				if (i >= k-1) {
					ret[i-k+1] = nums[n.front()];
				}
			}
			return ret;
    }
};
