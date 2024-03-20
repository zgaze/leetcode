#include <cstdio>
#include "tree.h"
#include <cstdint>

using std::vector;

class Solution {
public:
	TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>&inorder) {
		if (preorder.empty()) {
			return nullptr;
		}
		int b = 0, e = preorder.size() - 1, i = 0;
		TreeNode* node = Helper(preorder, inorder, b, e, i);
		return node;
	}

	TreeNode* Helper(std::vector<int>& preorder, std::vector<int>&inorder,
		int begin, int end, int& r_index) {
		if (begin == end) {
			TreeNode* node = new TreeNode(inorder[begin]);
			r_index ++;
			return node;
		}
		int i = begin;
		for (; i <= end; ++i) {
			if (preorder[r_index] == inorder[i]) {
				r_index++;
				break;
			}
		}
		if (i > end) {
			return nullptr;
		}
		TreeNode* node = new TreeNode(inorder[i]);
		node->left = Helper(preorder, inorder, begin,  i-1, r_index);
		node->right = Helper(preorder, inorder, i + 1,  end, r_index);
		return node;
	}
};
