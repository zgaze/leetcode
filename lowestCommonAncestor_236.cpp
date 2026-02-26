#include <iostream>
#include <stdio.h>
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    TreeNode *ans;
    TreeNode *DFS(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (root == nullptr) {
            return nullptr;
        }
        TreeNode* res = nullptr;
        if (root == p || root == q) {
            res = root;
        }
        TreeNode *left = DFS(root->left, p, q);
        TreeNode *right = DFS(root->right, p, q);
        if (left != nullptr && right != nullptr) {
            if (ans == nullptr) ans = root;
        }
        if (res && (left || right)&& ans == nullptr) ans = root;
        return left == nullptr ? right : left;
    }
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (root == nullptr) {
            return nullptr;
        }
        DFS(root, p, q);
        return ans;
    }
};

class Solution {
public:
    TreeNode* ans;
    bool dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) return false;
        bool lson = dfs(root->left, p, q);
        bool rson = dfs(root->right, p, q);
        if ((lson && rson) || ((root->val == p->val || root->val == q->val) && (lson || rson))) {
            ans = root;
        } 
        return lson || rson || (root->val == p->val || root->val == q->val);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, p, q);
        return ans;
    }
};


