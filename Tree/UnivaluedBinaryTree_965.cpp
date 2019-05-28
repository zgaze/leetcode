/* ***********************************************************************

  > File Name: UnivaluedBinaryTree_965.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Tue 28 May 2019 05:03:28 PM CST

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
 *
 * 965. 单值二叉树
 * 如果二叉树每个节点都具有相同的值，那么该二叉树就是单值二叉树。
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
	bool isUnivalTree(TreeNode* root) {
		if (root == nullptr) {
			return true;
		}
		if (root->left && root->left->val != root->val) {
			return false;
		}
		if (root->right && root->right->val != root->val) {
			return false;
		}
		return isUnivalTree(root->left) && isUnivalTree(root->right);
	}
};

TEST(testCase,test0) {

}


int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}

