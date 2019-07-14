/* ***********************************************************************

  > File Name: BinaryTreePreorderTraversal_144.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Tue 09 Jul 2019 03:46:36 PM CST

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
 * 144. 二叉树的前序遍历
 * 迭代
 */

/*
 * 借助栈：每次输出根节点，输入 右，左节点
 *	
 */

// Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
      
class Solution {
public:
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> ret;
		if (root == nullptr) 
			return ret;
		stack<TreeNode*> st;
		st.push(root);
		while (!st.empty()) {
			TreeNode* node = st.top();
			st.pop();
			ret.push_back(node->val);
			if (node->right) st.push(node->right);
			if (node->left) st.push(node->left);
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

