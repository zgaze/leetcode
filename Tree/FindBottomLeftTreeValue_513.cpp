/* ***********************************************************************

  > File Name: FindBottomLeftTreeValue_513.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Thu 08 Aug 2019 02:50:56 PM CST

 ********************************************************************** */

#include <stdio.h>
#include <vector>
#include <string>
#include <stdio.h>
#include <climits>
#include <queue>
#include <gtest/gtest.h>

using std::vector;
using std::string;

/*
 * 513. 找树左下角的值
 * 给定一个二叉树，在树的最后一行找到最左边的值。
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
	int findBottomLeftValue(TreeNode* root) {
		int max_deep = 0, ret_v = 0;
		if (root == nullptr) {
			return 0;
		}
		std::queue<std::pair<TreeNode*, int> > nodes;
		nodes.push({root, 0});
		while (!nodes.empty()) {
			TreeNode* node = nodes.front().first;
			int level = nodes.front().second;
			nodes.pop();
			if (node->left == nullptr && node->right == nullptr && level > max_deep) {
				max_deep = level;
				ret_v = node->val;
			}
			if (node->left != nullptr) {
				nodes.push({node->left, level + 1});
			}
			if (node->right != nullptr) {
				nodes.push({node->right, level + 1});
			}
		}
		return ret_v;
	}
};

TEST(testCase,test0) {

}


int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}

