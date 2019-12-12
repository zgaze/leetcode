/* ***********************************************************************

  > File Name: SymmetricTree_101.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 


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
 * 给定一个二叉树，检查它是否是镜像对称的。
 *
 * 例如，二叉树 [1,2,2,3,4,4,3] 是对称的。
 *
 *        1
 *       / \
 *      2   2
 *     / \ / \
 *    3  4 4  3
 */

/**
 *  * Definition for a binary tree node.
 */
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
	bool issame(TreeNode* root1, TreeNode* root2) {
		if (root1 == nullptr && root2 == nullptr) 
			return true;
		if (root1 == nullptr || root2 == nullptr) {
			return false;
		}
		return root1->val == root2->val && issame(root1->left, root2->right) && issame(root2->left, root1->right);
	}
	bool isSymmetric(TreeNode* root) {
		if (root == nullptr) return true;
		return issame(root->left, root->right);
	}
};

TEST(testCase,test0) {

}


int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}

