class Solution {
public:
		int Depth(TreeNode* root) {
			if (root == nullptr) {
				return 0;
			}
			return 1+ std::max(Depth(root->left), Depth(root->right));
		}

    bool isBalanced(TreeNode* root) {
			if (root == nullptr) {
				return true;
			}
			if (abs(Depth(root->left) - Depth(root->right)) > 1) {
				return false;
			}
			return isBalanced(root->left) && isBalanced(root->right);
    }
};
