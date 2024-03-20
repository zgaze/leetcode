
#include <vector>
#include <stdio.h>

using std::vector;
class Solution {
public:
	vector<int> singleNumber(vector<int>& nums) {
		vector<int> ret {0,0};
		int x_num = 0;
		for (int n : nums) {
			x_num ^= n;
		}
		//printf("x_num :%d\n", x_num);
		int diff_idx = -1;
		for (int i = 0; i < 32; ++i) {
			if ((x_num>>i) & 1) {
				diff_idx = i;
				break;
			} 
		}
		//printf("diff_idx:%d\n", diff_idx);
		for (int n :nums) {
			if ((n>>diff_idx) & 1) {
				ret[0] ^= n;
			} else {
				ret[1] ^= n;
			}
		}
		return ret;
	}
};

int main() {
	Solution s;
	vector<int> nums = {2,2,1,3, 555555,555555};
	vector<int> ret = s.singleNumber(nums);
	printf("singleNumber :%d %d\n", ret[0], ret[1]);
	return 0;
}
