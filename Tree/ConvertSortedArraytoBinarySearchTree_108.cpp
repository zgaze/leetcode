/* ***********************************************************************

  > File Name: ConvertSortedArraytoBinarySearchTree_108.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Thu 30 May 2019 06:27:52 PM CST

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
 * 将一个按照升序排列的有序数组，转换为一棵高度平衡二叉搜索树。
 *
 * 本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。
 */

/*
 *
 *
 *
 *
 *
 */



// Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
       
class Solution {
public:
	TreeNode* sortedArrayToBSTSub(vector<int>& nums, int begin, int end) {
		if (begin > end) {
			return nullptr;
		}
		int mid = (begin + end) / 2;
		TreeNode * root = new TreeNode(nums[mid]);
		root->left = sortedArrayToBSTSub(nums, begin, mid - 1);
		root->right = sortedArrayToBSTSub(nums, mid + 1, end);
		return root;
	}

	TreeNode* sortedArrayToBST(vector<int>& nums) {
		if (nums.empty()) {
			return nullptr;
		}
		return sortedArrayToBSTSub(nums, 0, nums.size() -1 );
	}
};

TEST(testCase,test0) {
	Solution s;
	std::vector<int> arr{-10,-3,0,5,9};
	s.sortedArrayToBST(arr);
}


int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}

