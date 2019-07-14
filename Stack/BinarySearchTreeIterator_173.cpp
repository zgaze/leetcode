/* ***********************************************************************

  > File Name: BinarySearchTreeIterator_173.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Tue 09 Jul 2019 03:15:20 PM CST

 ********************************************************************** */

#include <stdio.h>
#include <vector>
#include <string>
#include <stdio.h>
#include <climits>
#include <queue>
#include <stack>
#include <gtest/gtest.h>

using std::vector;
using std::string;
using std::queue;
using std::stack;

/*
 *
 * 173. 二叉搜索树迭代器
 *
 * 实现一个二叉搜索树迭代器。你将使用二叉搜索树的根节点初始化迭代器。
 *
 * 调用 next() 将返回二叉搜索树中的下一个最小的数。
 *
 */

/*
 * 其实就是让中序遍历 
 */


// Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
         

class BSTIterator {
public:
	BSTIterator(TreeNode* root) {
		stack<TreeNode*> st;
		TreeNode* curr = root;
		while (curr != nullptr || !st.empty()) {
			while (curr != nullptr) {
				st.push(curr);
				curr = curr->left; // 找到最左边
			}
			TreeNode* node = st.top();
			nums.push(node->val); // 输出最左边
			st.pop();
			curr = curr->right; // 往右
		}
	}

	/** @return the next smallest number */
	int next() {
		int x = nums.front();
		nums.pop();
		return x;
	}

	/** @return whether we have a next smallest number */
	bool hasNext() {
		return ! nums.empty();
	}
protected:
	std::queue<int> nums;
};

TEST(testCase,test0) {

}


int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}

