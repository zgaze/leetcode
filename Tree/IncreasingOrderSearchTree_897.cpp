/* ***********************************************************************

  > File Name: IncreasingOrderSearchTree_897.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Wed 07 Aug 2019 05:33:36 PM CST

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
 *
 * 给定一个树，按中序遍历重新排列树，使树中最左边的结点现在是树的根，并且每个结点没有左子结点，只有一个右子结点。
 *
 */

/*
 *
 * 解法： 中序遍历 建树即可
 *
 * 解法2 ：不新建树，修改原来的树
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
	TreeNode* increasingBST(TreeNode* root) {
		if (root == nullptr) {
			return nullptr;
		}
		TreeNode* new_head =nullptr;
		TreeNode* ptail = new_head;
		std::stack<TreeNode*> nodes;
		TreeNode* tmp = root;
		while (!nodes.empty() || tmp != nullptr) {
			while (tmp != nullptr) {
				nodes.push(tmp);
				tmp = tmp->left;
			}
			TreeNode* node = nodes.top();
			nodes.pop();
			if (ptail != nullptr) {
				ptail->right = new TreeNode(node->val);
				ptail = ptail->right;
			} else {
				new_head = ptail = new TreeNode(node->val);
			}
			tmp = node->right;
		}
		return new_head;
	}                  
};

class Solution_1 {
public:
	TreeNode* curr;
	void inorder(TreeNode* root) {
		if (root == nullptr) {
			return;
		}
		inorder(root->left);
		root->left = nullptr;
		curr->right = root;
		curr = curr->right;
		inorder(root->right);
	}
	TreeNode* increasingBST(TreeNode* root) {
		TreeNode* new_head = new TreeNode(0);
		curr = new_head;
		inorder(root);
		return new_head->right;
	}
};


TEST(testCase,test0) {

}


int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}

