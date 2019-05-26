/* ***********************************************************************

  > File Name: MaximumDepthofBinaryTree_104.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Sun 26 May 2019 03:10:52 PM CST

 ********************************************************************** */

#include <stdio.h>
#include <vector>
#include <string>
#include <stdio.h>
#include <climits>
#include <map>
#include <stack>
#include <gtest/gtest.h>

using std::vector;
using std::string;

/*
 * 104. 二叉树的最大深度
 * 给定一个二叉树，找出其最大深度。
 *
 * 二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。
 *
 * 说明: 叶子节点是指没有子节点的节点。
 */

/*
 * 树的最大高度 = 左子树高度和右子树高度中较大者 + 1；
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
	int maxDepth(TreeNode* root) {
		if (root == nullptr) {
			return 0;
		}
		return 1 + std::max(maxDepth(root->left), maxDepth(root->right));
	}
	// 循环的深度优先搜索
	int maxDepthRange(TreeNode* root) {
		int max = 0;
		std::map<TreeNode*, int> search_stat;
		std::stack<TreeNode*> searchs;
		searchs.
	}
};

TEST(testCase,test0) {

}


int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}

