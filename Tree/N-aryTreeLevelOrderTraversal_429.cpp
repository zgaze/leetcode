/* ***********************************************************************

  > File Name: N-aryTreeLevelOrderTraversal_429.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Fri 31 May 2019 02:44:50 PM CST

 ********************************************************************** */

#include <stdio.h>
#include <vector>
#include <string>
#include <stdio.h>
#include <climits>
#include <queue>
#include <gtest/gtest.h>

using std::vector;
using std::string;

/*
 *
 * 429. N叉树的层序遍历
 * 给定一个 N 叉树，返回其节点值的层序遍历。 (即从左到右，逐层遍历)。
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
	vector<vector<int>> levelOrder(Node* root) {
		vector<vector<int>> ret;
		if (root == nullptr) {
			return ret;
		}
		std::queue<Node*> nodes;
		nodes.push(root);
		vector<int> level;
		size_t size = 1;
		while (!nodes.empty()) {
			Node* head = nodes.front();
			nodes.pop();
			level.push_back(head->val);
			for (auto child : head->children) {
				nodes.push(child);
			}
			if (level.size() == size) {
				ret.push_back(level);
				size = nodes.size();
				level.clear();
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

