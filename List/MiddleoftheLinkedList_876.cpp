/* ***********************************************************************

  > File Name: MiddleoftheLinkedList_876.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Sat 13 Oct 2018 01:16:38 PM CST

 ********************************************************************** */

//Given a non-empty, singly linked list with head node head, return a middle node of linked list.

//If there are two middle nodes, return the second middle node.

#include <stdio.h>

//Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* middleNode(ListNode* head) {
		if (head == nullptr)
			return nullptr;
		ListNode* iter = head;
		int length = 0;
		while (iter) {
			length ++;
			iter = iter->next;
		}
		iter = head;
		length = (length >> 1) + 1 - 1;
		while (length) {
			length --;
			iter = iter->next;
		}
		return iter;
	}
};

class Solution1 {
public:
	ListNode* middleNode(ListNode* head) {
		if (head == nullptr)
			return nullptr;
		ListNode* fast = head;
		ListNode* slow = head;
		int step = 0;
		while (fast) {
			step ++;
			if ((step % 2) != 0) {
				slow = slow->next;
			}
			fast = fast->next;
		}
		return slow;
	}
};
