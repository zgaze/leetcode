/* ***********************************************************************

  > File Name: Leaf-Similar_Trees_872.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Fri 09 Aug 2019 11:21:57 AM CST

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


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
/*
 * 872. 叶子相似的树
 *
 * 请考虑一颗二叉树上所有的叶子，这些叶子的值按从左到右的顺序排列形成一个 叶值序列 。
 *
 * 判断两棵树的叶子节点组成的序列是否相等
 *
 *
 */

class Solution {
public:
	void helper(TreeNode* root, vector<int>& v) {
		if (root == nullptr) return;
		stack<TreeNode*> s;
		TreeNode* curr = root;
		while(!s.empty() || curr != nullptr) {
			while(curr != nullptr) {
				if (curr->left == nullptr && curr->right == nullptr) {
					v.push_back(curr->val);
				}
				s.push(curr);
				curr = curr->left;
			}
			TreeNode* node = s.top();
			s.pop();
			curr = node->right;
		}
	}

	bool leafSimilar(TreeNode* root1, TreeNode* root2) {
		vector<int> v1, v2;
		helper(root1, v1);
		helper(root2, v2);
		return v1 == v2;
	}
};

TEST(testCase,test0) {

}


int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}

