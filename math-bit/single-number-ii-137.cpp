/*
 * 给你一个整数数组 nums ，除某个元素仅出现 一次 外，其余每个元素都恰出现 三次 。请你找出并返回那个只出现了一次的元素。
 * 你必须设计并实现线性时间复杂度的算法且使用常数级空间来解决此问题。
*/
#include <vector>
#include <stdio.h>
#include <cstring>
using namespace std;

#define clr_bit(x, n) ( (x) &= ~(1 << (n)) )
#define set_bit(x, n) ( (x) |= (1 << (n)) )
#define get_bit(x, n) ( ((x)>>(n)) & 1 )

class Solution {
public:
    int singleNumber(vector<int>& nums) {
			int c[32];
			memset(c, 0, sizeof(c));
			for (int n : nums) {
				for (int i = 0; i < 32; ++i) {
					c[i] += ((n>>i)&1);
					c[i] %= 2;
				}
			}
			int ret = 0;
			for (int i = 0; i < 32; ++i) {
				if (c[i] > 0) {
					ret |= (1 << i);
				}
			}
			return ret;
    }
};

int main() {
	Solution s;
	std::vector<int> nums{2,2,3,1,3};
	int ret = s.singleNumber(nums);
	printf("singleNumber :%d\n", ret);
	return 0;
}
