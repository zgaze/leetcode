/* ***********************************************************************

  > File Name: ConvertSortedListtoBST_109.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Thu 01 Aug 2019 10:39:28 AM CST

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
 * 给定一个单链表，其中的元素按升序排序，将其转换为高度平衡的二叉搜索树。
 *
 * 本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。
 *
 */

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}

};

class Solution {
public:
	ListNode* FindMiddleNode(ListNode* head) {
		ListNode* pa = head->next, *pb = head, *tmp = NULL;
		while (pa != nullptr && pa->next != nullptr) {
			pa = pa->next->next;
			tmp = pb;
			pb = pb->next;
		}
		if (tmp == nullptr) {
			tmp->next = nullptr;
		}
		return pb;
	}

	TreeNode* sortedListToBST(ListNode* head) {
		if (head == nullptr) {
			return nullptr;
		}
		ListNode* mid = FindMiddleNode(head);
		TreeNode* root = new TreeNode(mid->val);
		if (head == mid) {
			return root;
		}
		root->left = sortedListToBST(head);
		root->right = sortedListToBST(mid->next);
		return root;
	}

};



/*
class Solution {

  private ListNode findMiddleElement(ListNode head) {

    // The pointer used to disconnect the left half from the mid node.
    ListNode prevPtr = null;
    ListNode slowPtr = head;
    ListNode fastPtr = head;

    // Iterate until fastPr doesn't reach the end of the linked list.
    while (fastPtr != null && fastPtr.next != null) {
      prevPtr = slowPtr;
      slowPtr = slowPtr.next;
      fastPtr = fastPtr.next.next;
    }

    // Handling the case when slowPtr was equal to head.
    if (prevPtr != null) {
      prevPtr.next = null;
    }

    return slowPtr;
  }

  public TreeNode sortedListToBST(ListNode head) {

    // If the head doesn't exist, then the linked list is empty
    if (head == null) {
      return null;
    }

    // Find the middle element for the list.
    ListNode mid = this.findMiddleElement(head);

    // The mid becomes the root of the BST.
    TreeNode node = new TreeNode(mid.val);

    // Base case when there is just one element in the linked list
    if (head == mid) {
      return node;
    }

    // Recursively form balanced BSTs using the left and right halves of the original list.
    node.left = this.sortedListToBST(head);
    node.right = this.sortedListToBST(mid.next);
    return node;
  }
}
*/

TEST(testCase,test0) {

}


int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}

