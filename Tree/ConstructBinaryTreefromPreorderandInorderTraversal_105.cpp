/* ***********************************************************************

  > File Name: ConstructBinaryTreefromPreorderandInorderTraversal_105.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Mon 12 Aug 2019 11:23:13 AM CST

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
 * 根据一棵树的前序遍历与中序遍历构造二叉树。
 *
 * 注意:
 * 你可以假设树中没有重复的元素。
 *
 * 例如，给出
 *
 * 前序遍历 preorder = [3,9,20,15,7]
 * 中序遍历 inorder = [9,3,15,20,7]
 *
 */

// Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

// 前序： 根 左右 ，中序 左根右
// 前序能找到根，但是分不清左右；中序可以确定左右
class Solution {
public:
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int begin, int end, int& index) {
        if (end < begin) return nullptr;
        if (index == (int)inorder.size()) return nullptr;
        int root_val = preorder[index];
        int i = begin;
        for (;i <= end; ++i) {
            if (inorder[i] == root_val) break;
        }
        index ++;
        TreeNode* root = new TreeNode(inorder[i]);
		// 从开始到根节点前面 的是左子树
        root->left = build(preorder, inorder, begin, i-1, index);
        root->right = build(preorder, inorder, i+1, end, index);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty()) return nullptr;
        int index = 0;
        return build(preorder,inorder,0, preorder.size()-1, index);
    }
};

TEST(testCase,test0) {

}


int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}

