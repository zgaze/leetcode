/* ***********************************************************************

  > File Name: SameTree_100.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Sat 08 Jun 2019 11:10:20 PM CST

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
 * 给定两个二叉树，编写一个函数来检验它们是否相同。
 *
 * 如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的。
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
	bool isSameTree(TreeNode* p, TreeNode* q) {
		if (p == nullptr && q == nullptr) {
			return true;
		}
		if (p && q) {
			if (p->val != q->val) {
				return false;
			} else {
				return (isSameTree(p->left, q->left) && isSameTree(p->right, q->right)); 
			}
		}
		return false;
	}
};


TEST(testCase,test0) {

}


int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}

