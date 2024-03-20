#include <vector>
#include<stdint.h>

class Solution {
public:
	void Helper(TreeNode* root, int32_t depth) {
		if (depth > min_depth) {
			return;
		}
		if (root->left == NULL &&  root->right == NULL) {
			min_depth = std::min(depth, min_depth);
			return;
		}
		if (root->left) Helper(root->left, depth+1);
		if (root->right) Helper(root->right, depth+1);
	}
	int minDepth(TreeNode* root) {
		if (root == nullptr) return 0;
		Helper(root, 1);
		return min_depth;
	}
 int32_t min_depth = INT_MAX;
};
