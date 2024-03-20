/*
 * 二叉树最大深度
 */

class Solution {
public:
	int maxDepth(TreeNode* root) {
		if (root == nullptr) return 0;
		return std::max(maxDepth(root->left), maxDepth(root->right)) + 1;
	}
};
