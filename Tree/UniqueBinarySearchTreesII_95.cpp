/* ***********************************************************************

  > File Name: ./Tree/UniqueBinarySearchTreesII_95.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Tue 13 Aug 2019 04:48:05 PM CST

 ********************************************************************** */

#include <stdio.h>
#include <vector>
#include <string>
#include <stdio.h>
#include <climits>
#include <gtest/gtest.h>

using std::vector;
using std::string;


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};



class Solution {
public:
	vector<TreeNode*> generate_trees(int begin, int end) {
		vector<TreeNode*> all_tree;
		if (begin > end) {
			all_tree.push_back(nullptr);
		}
		for (int i = begin; i <= end; ++i) {
			vector<TreeNode*> left_tree = generate_trees(begin, i - 1);
			vector<TreeNode*> right_tree = generate_trees(i + 1, end);
			for (auto l: left_tree) {
				for (auto r: right_tree) {
					TreeNode* root = new TreeNode(i);
					root->left = l;
					root->right = r;
					all_tree.push_back(root);
				}
			}
		}
		return all_tree;
	}

	vector<TreeNode*> generateTrees(int n) {
		vector<TreeNode*> all_tree;
		if (n == 0) {
			return all_tree;
		}
		return generate_trees(1, n);

	}
};

TEST(testCase,test0) {

}

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}

