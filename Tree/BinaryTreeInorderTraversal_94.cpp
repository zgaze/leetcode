/* ***********************************************************************

  > File Name: BinaryTreeInorderTraversal_94.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Mon 08 Jul 2019 06:37:19 PM CST

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
 * 94. 二叉树的中序遍历
 * 给定一个二叉树，返回它的中序 遍历。
 * 进阶: 递归算法很简单，你可以通过迭代算法完成吗？
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
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> ret;
		TreeNode * curr = root;
		std::stack<TreeNode*> s;
		while (curr != nullptr || !s.empty()) {
			while (curr != nullptr) {
				s.push(curr);
				curr = curr->left;
			}
			TreeNode * node = s.top();
			s.pop();
			ret.push_back(node->val);
			curr = curr->right;
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

