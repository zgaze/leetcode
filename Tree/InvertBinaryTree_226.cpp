/* ***********************************************************************

  > File Name: InvertBinaryTree_226.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Sun 26 May 2019 03:06:02 PM CST

 ********************************************************************** */

#include <stdio.h>
#include <vector>
#include <string>
#include <stdio.h>
#include <climits>
#include <gtest/gtest.h>

using std::vector;
using std::string;

//Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
/*
 *
 * 翻转一棵二叉树。
 * tips: 每个节点的左右孩子交换
 */

class Solution {
public:
	TreeNode* invertTree(TreeNode* root) {
		if (root) {
			std::swap(root->left, root->right);
			invertTree(root->left);
			invertTree(root->right);
		}
		return root;
	}
};

TEST(testCase,test0) {

}


int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}

