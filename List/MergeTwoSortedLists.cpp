/* ***********************************************************************

  > File Name: MergeTwoSortedLists.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Sat 01 Sep 2018 03:56:11 PM CST

 ********************************************************************** */

/**
 *   Definition for singly-linked list.
 *    struct ListNode {
 *         int val;
 *         ListNode *next;
 *         ListNode(int x) : val(x), next(NULL) {}
 *       };
 */


#include <cstdio>
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

/*
class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (l1 == NULL) return l2;
		if (l2 == NULL) return l1;
		ListNode* head;
		if (l1->val < l2->val) {
			head = l1;
			l1 = l1->next;
		} else {
			head = l2;
			l2 = l2->next;
		}
		ListNode* curr = head;
		while (l1 && l2) {
			if (l1->val < l2->val) {
				curr->next = l1;
				curr = curr->next;
				l1 = l1->next;
			} else {
				curr->next = l2;
				curr = curr->next;
				l2 = l2->next;
			}
		}
		if (l1) curr->next = l1;
		if (l2) curr->next = l2;
		return head;
	}
};
*/


class Solution2 {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (l1 == NULL) return l2;
		if (l2 == NULL) return l1;
		ListNode* p1 = l1 , *p2 = l2, *tail = NULL;
		while (p1 && p2) {
			ListNode** min = &(p1->val < p2->val ? p1 : p2);
			if (tail != NULL) {
				tail->next = *min;
			}
			tail = *min;
			*min = (*min)->next;
		}
		tail->next = p1 ? p1 : p2;
		return l1->val < l2->val ? l1 : l2;
	}
};


class Solution1 {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (l1 == NULL) return l2;
		if (l2 == NULL) return l1;
		ListNode* head = l1->val < l2->val ? l1 : l2;
		ListNode* another = l1->val < l2->val ? l2: l1;
		head->next = mergeTwoLists(head->next, another);
		return head;
	}
};



int main()
{
	ListNode *l1 = new ListNode(0), *l2= new ListNode(1);
	ListNode* curr_1 = l1, * curr_2 = l2;
	for (int i = 1; i < 10 ;i++) {
		ListNode* node = new ListNode(i);
		curr_2->next = node;
		curr_2 = curr_2->next;
	}
	for (int i = 1; i < 10 ;i++) {
		ListNode* node = new ListNode(i);
		curr_1->next = node;
		curr_1 = curr_1->next;
	}
	auto print = [](ListNode* node) {while(node) {printf("%d  ", node->val); node = node->next;} printf("\n");};
	print(l1);
	print(l2);
	//Solution1 s1;
	Solution2 s2;
	//ListNode* mergred_1 = s1.mergeTwoLists(l1, l2);
	ListNode* mergred_2 = s2.mergeTwoLists(l1, l2);
	//print(mergred_1);
	print(mergred_2);
	return 0;
}










