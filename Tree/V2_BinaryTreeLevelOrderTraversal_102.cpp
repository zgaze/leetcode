/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
	struct TreeNodeWithLevel {
		TreeNode* node;
		int level;
	};
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> ret;
		if (root == nullptr) return ret;
		std::queue<TreeNodeWithLevel> nodes;
		nodes.push({root, 0});
		while(!nodes.empty()) {
			TreeNodeWithLevel nl = nodes.front();
			int level = nl.level;
			TreeNode* node = nl.node;
			if (ret.size() < level+1) {
				ret.resize(level+1);
			}
			ret[level].push_back(node->val);
			nodes.pop();
			if (node->left) {
				nodes.push({node->left, level + 1});
			}
			if (node->right) {
				nodes.push({node->right, level + 1});
			}
		} 
		return ret;

	}
};

int main() {
	return 0;
}
