/* ***********************************************************************

  > File Name: DeleteNodeinaLinkedList_237.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Sun 14 Oct 2018 03:45:08 PM CST

 ********************************************************************** */
/*
 *
 * 编写一个函数来删除单个链表中的节点(尾巴除外)，只允许访问该节点。
 * Write a function to delete a node (except the tail) in a singly linked list, given only access to that node.
 *
 * 链表至少有两个元素。
 * The linked list will have at least two elements.
 * 所有节点的值都是唯一的。
 * All of the nodes' values will be unique. 
 * 给定的节点将不是尾部，它将始终是链表的一个有效节点。
 * The given node will not be the tail and it will always be a valid node of the linked list. 
 * 不要从函数中返回任何内容。
 * Do not return anything from your function. 
 */

/*
 * 没有头结点，并且是非尾节点
 * 交换node节点和node->next的值，删掉node->next即可
 */


//Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    void deleteNode(ListNode* node) {
		if (node == nullptr || node->next == nullptr) {
			return;
		}
		int tmp = node->val;
		node->val = node->next->val;
		node->next->val = tmp;
        node->next = node->next->next;
		// delete node->next;
    }
};
