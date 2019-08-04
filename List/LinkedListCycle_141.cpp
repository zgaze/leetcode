/* ***********************************************************************

  > File Name: LinkedListCycle_141.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Sun 14 Oct 2018 04:54:11 PM CST

 ********************************************************************** */

/*
 * Given a linked list, determine if it has a cycle in it.
 * Can you solve it without using extra space?
 */

/*
 * 判断链表是否带环
 * 你能在不使用额外空间的情况下解决它吗?
 */

//Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


/*
 *
 * 思路：
 * 快慢指针，如果能相遇，说明带环
 *
 */

class Solution {
public:
	bool hasCycle(ListNode *head) {
		if (head == nullptr || head->next == nullptr) {
			return false;
		}
		ListNode *pa = head->next, *pb = head;
		while(pa != pb) {
			if (pa == nullptr || pa->next == nullptr) {
				return false;
			}
			pa = pa->next->next;
			pb = pb->next;
		}
		return true;
	}
};
