/* ***********************************************************************

  > File Name: PathSum_112.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Thu 08 Aug 2019 11:43:08 AM CST

 ********************************************************************** */

#include <stdio.h>
#include <vector>
#include <string>
#include <stdio.h>
#include <climits>
#include <stack>
#include <gtest/gtest.h>

using std::vector;
using std::string;
using std::stack;

/*
 * 112. 路径总和
 * 给定一个二叉树和一个目标和，判断该树中是否存在根节点到叶子节点的路径，这条路径上所有节点值相加等于目标和。
 *
 * 说明: 叶子节点是指没有子节点的节点。
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
	bool hasPathSum(TreeNode* root, int sum) {
		if (root == nullptr)
			   return false;
		if (root->left == nullptr && root->right == nullptr) {
			return root->val == sum;
		}  else {
			return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
		}
	}
};

// 用栈
class Solution_Stack {
public:
	bool hasPathSum(TreeNode* root, int sum) {
		if (root == nullptr) {
			return false;
		}
		std::stack<std::pair<TreeNode*, int>> nodes;
		nodes.push({root, sum});
		while (!nodes.empty()) {
			auto &node = nodes.top();
			int curr_sum = node.second;
			TreeNode* curr_node = node.first;
			if (curr_node->left == nullptr && curr_node->right == nullptr && curr_sum == 0) {
				return true;
			}
			if (node.first->right != nullptr) {
				nodes.push({curr_node->right, curr_sum - curr_node->right->val});
			}
			if (curr_node->left != nullptr) {
				nodes.push({curr_node->left, curr_sum - curr_node->left->val});
			}
			nodes.pop();
		}
		return false;
	}
};



TEST(testCase,test0) {

}


int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}

