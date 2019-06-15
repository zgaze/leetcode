/* ***********************************************************************

  > File Name: LowestCommonAncestorofaBinarySearchTree_235.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Sat 15 Jun 2019 10:19:58 PM CST

 ********************************************************************** */

#include <stdio.h>
#include <vector>
#include <string>
#include <stdio.h>
#include <climits>
#include <gtest/gtest.h>

using std::vector;
using std::string;

TEST(testCase,test0) {

}

/*
 * 给定一个二叉搜索树, 找到该树中两个指定节点的最近公共祖先。
 * 百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”

*/
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (root == nullptr || p == nullptr || q == nullptr) {
			return nullptr;
		}
		int a = p->val, b = q->val;
		if (a > b) {
			std::swap(a, b);
		}
		if (root->val >= a && root->val <= b) {
			// 如果一个大于根节点，另一个小于根节点，说明根节点就是最小公共祖先
			return root;
		} else if (root->val > a && root->val > b) {
			// 如果都小于根节点，说明还在左子树上
			return lowestCommonAncestor(root->left, p, q);
		} else {
			return lowestCommonAncestor(root->right, p, q);
		}
		return nullptr;
    }
};


int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}

