/* ***********************************************************************

  > File Name: BinaryTreePostorderTraversal_145.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Wed 07 Aug 2019 07:13:18 PM CST

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
 
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
		vector<int> ret;
		if (root == nullptr) {
			return ret;
		}
		std::stack<int> res;
		std::stack<TreeNode*> nodes;
		nodes.push(root);
		while (!nodes.empty()) {
			TreeNode* node = nodes.top();
			nodes.pop();
			res.push(node->val);
			if (node->left) nodes.push(node->left);
			if (node->right) nodes.push(node->right);
		}
		while (!res.empty()) {
			int x = res.top();
			ret.push_back(x);
			res.pop();
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

