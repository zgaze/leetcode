/* ***********************************************************************

  > File Name: RangeSumofBST_938.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Sun 26 May 2019 02:02:09 PM CST

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

/*
 *
 *
 * 给定二叉搜索树的根结点 root和两个整数L和R，返回 L 和 R（含）之间的所有结点的值的和。
 *
 * 二叉搜索树保证具有唯一的值。
 */

/*
 * 解题：
 * 主要考察二叉搜索树的性质: 右侧的节点值都大于根节点，左侧节点的值都小于根节点
 */

// Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class LeetTree {
public:
	LeetTree(std::vector<int> nodes) 
	{
		if (nodes.empty()) {
			return;
		}
		root = new TreeNode(nodes[0]);
		std::stack<TreeNode*> save_p;
		save_p.push(root);
		int length = nodes.size();
		for (int i = 1; i < length; ++i) {
			if (save_p.empty()) {
				break;
			}
			TreeNode * proot = save_p.top();
			save_p.pop();
			proot->left = new TreeNode(nodes[i]);
			save_p.push(proot->left);
			if (i < length - 1) {
				proot->right = new TreeNode(nodes[i + 1]);
				i ++;
				save_p.push(proot->right);
			}
		}
	}
	void Print(TreeNode* root) {
		if (root != nullptr) {
			printf("root: %d ", root->val);
			if (root->left != nullptr) {
				printf("left: %d ", root->left->val);
			}
			if (root->right != nullptr) {
				printf("right: %d ", root->right->val);
			}
			printf("\n");
			Print(root->left);
			Print(root->right);
		}
	}

	~LeetTree()
	{
		FreeMemory(root);
	}
	TreeNode* Root() {
		return root;
	}

protected:
	//中序遍历结果, INT_MIN表示节点不存在
	void FreeMemory(TreeNode* node) {
		if (node != nullptr) {
			FreeMemory(node->left);
			FreeMemory(node->right);
			delete node;
		}
	}
	TreeNode* root = nullptr;
};

class Solution {
public:
	int rangeSumBST(TreeNode* root, int L, int R) {
		if (root == nullptr) {
			return 0;
		}
		if (root->val > R) {
			return rangeSumBST(root->left, L, R);
		}
		if (root->val < L) {
			return rangeSumBST(root->right, L, R);
		} else {
			return root->val + rangeSumBST(root->left, L, R) + rangeSumBST(root->right, L, R);
		}

	}
};


TEST(testCase,test0) {
	LeetTree tree = std::vector<int>{1, 2, 3};
	tree.Print(tree.Root());
	Solution s;
	EXPECT_EQ(s.rangeSumBST(tree.Root(), 1, 4), 6);

}


int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}

