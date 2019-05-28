/* ***********************************************************************

  > File Name: N-aryTreePostorderTraversal_590.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Tue 28 May 2019 03:28:31 PM CST

 ********************************************************************** */

#include <stdio.h>
#include <vector>
#include <string>
#include <stdio.h>
#include <climits>
#include <stack>
#include <iterator>
#include <gtest/gtest.h>

using std::vector;
using std::string;
/*
 *
 * 590. N叉树的后序遍历
 * 给定一个 N 叉树，返回其节点值的后序遍历。
 */

/*
 * 后序遍历：左 右 根的顺序
 *
 *
 */

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
	vector<int> postorder(Node* root) {
		std::vector<int> ret;
		std::stack<Node*> children;
		children.push(root);
		while (!children.empty()) {
			Node* node = children.top();
			children.pop();
			ret.push_back(node->val);
			auto it = node->children.rbegin();
			for (;it != node->children.rend(); ++it) {
				children.push(*it);
			}
		}
		int len = ret.size();
		for (int i = 0, j = len -1; i < j; ++i, --j) {
			std::swap(ret[i], ret[j]);
		}
		// std::reverse(ret.begin(), ret.end()); required c++20
		return ret;
	}

	void postorder_r(Node* root, vector<int> &res) {
		if (root != nullptr) {
			for (auto node : root->children) {
				postorder_r(node, res);
			}
			res.push_back(root->val);
		}
	}
};


TEST(testCase,test0) {

}


int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}

