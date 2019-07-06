/* ***********************************************************************

  > File Name: NextGreaterElementI_496.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Fri 05 Jul 2019 02:43:38 PM CST

 ********************************************************************** */

#include <stdio.h>
#include <vector>
#include <string>
#include <stdio.h>
#include <climits>
#include <map>
#include <stack>
#include <gtest/gtest.h>

using std::vector;
using std::string;
using std::stack;

/*
 *
 * 给定两个没有重复元素的数组 nums1 和 nums2 ，其中nums1 是 nums2 的子集。找到 nums1 中每个元素在 nums2 中的下一个比其大的值。
 *
 * nums1 中数字 x 的下一个更大元素是指 x 在 nums2 中对应位置的右边的第一个比 x 大的元素。如果不存在，对应位置输出-1。
 *
 */


/*
 *
 * 单调栈：
 *     从后往前遍历,
 *     小个子 滚蛋
 */



class Solution {
public:
	vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
		std::map<int, int> kv;
		std::stack<int> st;
		int len = nums2.size();
		for (int i = len-1; i >=0 ; i--) {
			while (!st.empty() && st.top() <= nums2[i]) { // 记得用 <= 
				st.pop(); //  矮个起开，反正也被挡着了。。。
			}
			kv[nums2[i]] = st.empty() ? -1 : st.top(); // 这个元素身后的第一个高个
			st.push(nums2[i]);
		}
		vector<int> ret;
		for (int num: nums1) {
			auto it =  kv.find(num);
			if (kv.end() != it) {
				ret.push_back(it->second);
			}
		}
		return ret;
	}
};

static bool equal(vector<int>& nums1, vector<int>& nums2) {
	for (int i = 0; i < (int)nums1.size(); i++) {
		if (nums1[i] != nums2[i]) {
			printf("%d, %d, %d\n", i, nums1[i] , nums2[i]);
			return false;
		}
	}
	return true;
}

TEST(testCase,test0) {
	vector<int> a1 {4,1,2};
	vector<int> a2 {1,3,4,2};
	vector<int> a {-1,3,-1}; 
	vector<int> b1 {1,3,5,2,4};
	vector<int> b2 {6,5,4,3,2,1,7};
	vector<int> b {7,7,7,7,7};
	Solution s;
	vector<int> a_out = s.nextGreaterElement(a1, a2);
	vector<int> b_out = s.nextGreaterElement(b1, b2);
	EXPECT_TRUE(equal(a_out, a));
	EXPECT_TRUE(equal(b_out, b));
}


int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}

