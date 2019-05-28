/* ***********************************************************************

  > File Name: SearchinaBinarySearchTree_700.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Tue 28 May 2019 04:39:38 PM CST

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
 * 700. 二叉搜索树中的搜索
 * 给定二叉搜索树（BST）的根节点和一个值。 你需要在BST中找到节点值等于给定值的节点。 
 * 返回以该节点为根的子树。 如果节点不存在，则返回 NULL。
 */


/*
 * pass ! 
 */

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* searchBST(TreeNode* root, int val) {
		if (root == nullptr) {
			return root;
		}
		if (root->val == val) {
			return root;
		}
		TreeNode* l = searchBST(root->left, val);
		TreeNode* r = searchBST(root->right, val);
		if (l) {
			return l;
		}
		return r; 
	}
};

TEST(testCase,test0) {

}


int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}

