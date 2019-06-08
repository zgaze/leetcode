/* ***********************************************************************

  > File Name: SubtreeofAnotherTree_572.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Sat 08 Jun 2019 11:19:54 PM CST

 ********************************************************************** */

#include <stdio.h>
#include <vector>
#include <string>
#include <stdio.h>
#include <climits>
#include <gtest/gtest.h>

using std::vector;
using std::string;

// Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
     
/*
 *
 * 给定两个非空二叉树 s 和 t，检验 s 中是否包含和 t 具有相同结构和节点值的子树。
 * s 的一个子树包括 s 的一个节点和这个节点的所有子孙。s 也可以看做它自身的一棵子树。
 *
 */

class Solution {                                                                        
public:                                                                                 
	bool isSameTree(TreeNode* p, TreeNode* q) {                                         
		if (p == nullptr && q == nullptr) {                                             
			return true;                                                                
		}                                                                               
		if (p && q && p->val == q->val) {
			return (isSameTree(p->left, q->left) && isSameTree(p->right, q->right));                                                                         
		}                                                                               
		return false;                                                                   
	}                                                                                   
	bool isSubtree(TreeNode* s, TreeNode* t) {
		if (isSameTree(s,t)) {                                                          
			return true;                                                                
		} 
		if (s == nullptr) {
			return false;                 
		}
		return (isSubtree(s->left, t) || isSubtree(s->right, t)); 
	}
};

TEST(testCase,test0) {

}


int main(int argc, char* argv[]) {
	testing::InitGoogleTest(&argc,argv);
	return RUN_ALL_TESTS();
}

