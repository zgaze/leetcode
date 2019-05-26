/* ***********************************************************************

  > File Name: MergeTwoBinaryTrees.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Sun 26 May 2019 02:53:01 PM CST

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
 * 617. 合并二叉树
 * 给定两个二叉树，想象当你将它们中的一个覆盖到另一个上时，两个二叉树的一些节点便会重叠。
 *
 * 你需要将他们合并为一个新的二叉树。合并的规则是如果两个节点重叠，那么将他们的值相加作为节点合并后的新值，否则不为 NULL 的节点将直接作为新二叉树的节点。
 */

//Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
		TreeNode* ret = t1 ? t1 : t2;
		if (t1 && t2) {
			ret->val = t1->val + t2->val;
			ret->left  = mergeTrees(t1->left, t2->left);
			ret->right = mergeTrees(t1->right, t2->right);
		}
		return ret;
	}
};

TEST(testCase,test0) {

}


int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}

