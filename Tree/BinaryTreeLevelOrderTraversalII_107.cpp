/* ***********************************************************************

  > File Name: BinaryTreeLevelOrderTraversalII_107.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Sat 15 Jun 2019 10:36:12 PM CST

 ********************************************************************** */

#include <stdio.h>
#include <vector>
#include <string>
#include <stdio.h>
#include <climits>
#include <gtest/gtest.h>
#include <queue>

using std::vector;
using std::string;

/*
 * 给定一个二叉树，返回其节点值自底向上的层次遍历。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ret;
        if (root == nullptr) {
            return ret;
        }             
        std::vector<int> level;
        std::queue<TreeNode*> nodes;
        nodes.push(root);
        size_t size = 1;
        while (!nodes.empty()) {
            TreeNode* head = nodes.front();
            nodes.pop();
            level.push_back(head->val);
            if (head->left) {
                nodes.push(head->left);
            }               
            if (head->right) {
                nodes.push(head->right);
            }               
            // 一层完了，存起来
            if (size == level.size()) {
                ret.push_back(level);
                level.clear();
                size = nodes.size();
            }
        }
        vector<vector<int>> final;
        final.reserve(ret.size());
        for  (auto it = ret.rbegin(); it != ret.rend(); ++it) {
            final.push_back(*it);
        }
        return final;
    }
};




TEST(testCase,test0) {

}


int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}

