/* ***********************************************************************

  > File Name: ConstructBinaryTreefromInorderandPostorderTraversal_106.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 


 ********************************************************************** */

#include <stdio.h>
#include <vector>
#include <string>
#include <stdio.h>
#include <climits>
#include <gtest/gtest.h>

using std::vector;
using std::string;




/**
 * Definition for a binary tree node.
 */
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

/*
 * 根据一棵树的中序遍历与后序遍历构造二叉树。
 *
 * 注意:
 * 你可以假设树中没有重复的元素。
 *
 * 例如，给出
 *
 * 中序遍历 inorder = [9,3,15,20,7]
 * 后序遍历 postorder = [9,15,7,20,3]
 */

class Solution {
public:
    TreeNode* build(vector<int>& inorder, vector<int>& postorder, int begin, int end, int &index) {
        if (end < begin) return nullptr;
        if (index < 0) return nullptr;
        int val = postorder[index];
        int i = begin;
        for (; i <= end; ++i) {
            if (val == inorder[i]) break;
        }
        index --;
        TreeNode* root = new TreeNode(val);
        //printf("create: %d\n", root->val);
        root->right = build(inorder, postorder, i+1, end, index);
        root->left = build(inorder, postorder, begin, i-1, index);
        //printf("root: %d,left:%d,right:%d\n", root->val, root->left? root->left->val : 0, root->right ? root->right->val : 0);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.empty()) return nullptr;
        int index = inorder.size()-1;
        return build(inorder, postorder, 0, inorder.size()-1, index);
    }
};

TEST(testCase,test0) {

}


int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}

