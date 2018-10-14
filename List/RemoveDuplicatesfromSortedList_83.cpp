/* ***********************************************************************

  > File Name: RemoveDuplicatesfromSortedList_83.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Sun 14 Oct 2018 03:59:02 PM CST

 ********************************************************************** */

/*
 * Given a sorted linked list, delete all duplicates such that each element appear only once.
 * Example 1:
 *
 * Input: 1->1->2
 * Output: 1->2
 *
 */


/*
 * Accepted
 * 有序嘛，和有序数组差不多
 * 注意循环判断条件
 */

//Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		if (head == nullptr || head->next == nullptr) {
			return head;
		}
		ListNode* curr = head;
		while (curr) {
			ListNode* uniq = curr->next;
			// 找到下一个值不等于当前节点的节点
			while(uniq && curr->val == uniq->val) {
				uniq = uniq->next;
			}
			// 当前的节点的next 置为那个不等于的节点
			curr->next = uniq;
			curr = curr->next;
		}
		return head;
	}
};
