/* ***********************************************************************

  > File Name: N-aryTreePreorderTraversal_589.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Thu 30 May 2019 06:04:48 PM CST

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

/*
 *
 * 给定一个 N 叉树，返回其节点值的前序遍历。
 */

/*
 * 递归写法: 遍历根节点，从左到右遍历children
 *
 * 循环写法：逆序遍历children
 *
 *
 */


// Definition for a Node.
class Node {
public:
	int val;
	vector<Node*> children;

	Node() {}

	Node(int _val, vector<Node*> _children) {
		val = _val;
		children = _children;
	}
};

class Solution {
public:
	// 递归解法
	void preorder_r(std::vector<int>& res, Node* root) {
		if (root != nullptr) {
			res.push_back(root->val);
			for (auto node : root->children) {
				preorder_r(res, node);
			}
		}
	}
	vector<int> preorder(Node* root) {
		std::vector<int> ret;
		preorder_r(ret, root);
		return ret;
	}
	vector<int> preorder_iteration(Node* root) {
		std::vector<int> ret;
		if (root == nullptr) {
			return ret;
		}
		std::stack<Node*> nodes;
		nodes.push(root);
		while (!nodes.empty()) {
			Node* now = nodes.top();
			nodes.pop();
			if (now == nullptr) {
				continue;
			}
			ret.push_back(now->val);
			for (auto iter = now->children.rbegin(); iter != now->children.rend(); ++iter) {
				nodes.push(*iter);
			}
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

