/* ***********************************************************************

  > File Name: BinaryTreeLevelOrderTraversalII_107.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Sun 02 Jun 2019 11:34:06 PM CST

 ********************************************************************** */

#include <stdio.h>
#include <vector>
#include <string>
#include <stdio.h>
#include <climits>
#include <queue>
#include <gtest/gtest.h>

using std::vector;
using std::string;

/*
 * 102. 二叉树的层次遍历
 * 给定一个二叉树，返回其按层次遍历的节点值。 （即逐层地，从左到右访问所有节点）。
 *
 */

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> ret;
		if (root == nullptr) {
			return ret;
		}
		std::vector<int> level;
		std::queue<TreeNode*> nodes;
		nodes.push(root);
		size_t size = 1;
		while (!nodes.empty()) {
			TreeNode* head = nodes.front();
			nodes.pop();
			level.push_back(head->val);
			if (head->left) {
				nodes.push(head->left);
			}
			if (head->right) {
				nodes.push(head->right);
			}
			// 一层完了，存起来
			if (size == level.size()) {
				ret.push_back(level);
				level.clear();
				size = nodes.size();
			}
		}
    	return ret;
    }
};


int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}

