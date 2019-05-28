/* ***********************************************************************

  > File Name: MaximumDepthofN-aryTree_559.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Tue 28 May 2019 04:48:23 PM CST

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
 * 559. N叉树的最大深度
 * 给定一个 N 叉树，找到其最大深度。
 *
 * 最大深度是指从根节点到最远叶子节点的最长路径上的节点总数。
 * 只有一个根节点，深度为1
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
	int maxDepth(Node* root) {
		if (root == nullptr) {
			return 0;
		}
		int max = 0;
		for (auto node: root->children) {
			max = std::max(max, maxDepth(node));
		}
		return max + 1;
	}
};


TEST(testCase,test0) {

}


int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}

