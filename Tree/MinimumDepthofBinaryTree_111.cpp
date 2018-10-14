/* ***********************************************************************

  > File Name: MinimumDepthofBinaryTree.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Wed 19 Sep 2018 08:45:42 PM CST

 ********************************************************************** */

#include <stdio.h>
#include <algorithm>
#include <queue>

using std::max;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
	int minDepth(TreeNode* root) {
		if (root == NULL)
			return 0;
		if (root->left == NULL &&  root->right == NULL)
			return 1;
		int left = 1000000, right = 1000000;
		if (root->left) left = minDepth(root->left);
		if (root->right) right = minDepth(root->right);
		return std::min(right, left) + 1;
	}
};
