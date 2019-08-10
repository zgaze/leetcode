/* ***********************************************************************

  > File Name: BinaryTreePaths_257.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Fri 09 Aug 2019 11:35:38 AM CST

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
 *
 * 257. 二叉树的所有路径
 * 给定一个二叉树，返回所有从根节点到叶子节点的路径。
 *
 * 说明: 叶子节点是指没有子节点的节点。
 *
 * Accepted
 */

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	vector<string> res;
	void dfs(TreeNode* root, vector<int> & path) {
		if (root == nullptr) return;
		path.push_back(root->val);
		if (root->left == nullptr && root->right == nullptr) {
			std::stringstream ss;
			for (auto i : path) {
				ss << i << "->";
			}
			std::string str = ss.str();
			str.resize(str.length() - 2);
			res.push_back(str);
		}
		dfs(root->left, path);
		dfs(root->right, path);
		path.pop_back();
	}

	vector<string> binaryTreePaths(TreeNode* root) {
		if (root == nullptr) {
			return res;
		}
		std::vector<int> path;
		dfs(root, path);
		return res;
	}
};

TEST(testCase,test0) {

}


int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}

