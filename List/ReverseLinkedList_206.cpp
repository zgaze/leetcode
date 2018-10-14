/* ***********************************************************************

  > File Name: ReverseLinkedList_206.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Sat 13 Oct 2018 02:08:56 PM CST

 ********************************************************************** */

/*
 * Reverse a singly linked list.
 *
 * Example:
 *
 * Input: 1->2->3->4->5->NULL
 * Output: 5->4->3->2->1->NULL
 * //循环或者递归 
 * A linked list can be reversed either iteratively or recursively. Could you implement both?
 */


//Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


// 循环 Accepted
class Solution_1 {
public:
	ListNode* reverseList(ListNode* head) {
		if (head == nullptr || head->next == nullptr) {
			return head;
		}
		ListNode* new_head = head;
		ListNode* tmp = nullptr;
		while(head->next) {
			// such as 1->2->3
			tmp = head->next; 
			head->next = head->next->next; // 1 -> 3
			tmp->next = new_head; // 2 -> 1
			new_head = tmp; // head = 2;
		}
		return new_head;
	}
};


// 递归 栈保存所有指针
// Accepted
class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		if (head == nullptr || head->next == nullptr) {
			return head;
		}
		ListNode* new_head = reverseList(head->next);
		head->next->next = head; // 2->3->2 ; 1->2
		head->next = nullptr; // 3->2; 1->2
		return new_head;
	}
};










