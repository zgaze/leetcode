/* ***********************************************************************

  > File Name: RemoveDuplicatesfromSortedListII_82.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Mon 26 Aug 2019 21:31:18 AM CST

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
 * 82. 删除排序链表中的重复元素 II
 * 给定一个排序链表，删除所有含有重复数字的节点，只保留原始链表中 没有重复出现 的数字。
 *
 * 示例 1:
 *
 * 输入: 1->2->3->3->4->4->5
 * 输出: 1->2->5
 * 示例 2:
 *
 * 输入: 1->1->1->2->3
 * 输出: 2->3
 *
 */

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
    
class Solution_1 {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		if (head == nullptr) return head;
		if (head->next == nullptr || head->next->val != head->val) {
			head->next = deleteDuplicates(head->next);
			return head;
		}
		while (head->next && head->next->val == head->val) {
			head = head->next;
		}
		return deleteDuplicates(head->next);
	}
};


class Solution {  
public:           
	ListNode* deleteDuplicates(ListNode* head) {
		if (head == nullptr) return head;
		ListNode* curr = head;
		ListNode* new_head = nullptr;
		ListNode* ps = new_head;
		while(curr) {
			if (curr->next && curr->next->val == curr->val) {
				while(curr->next && curr->next->val == curr->val) {
					curr = curr->next;
				} 
			} else {
				if (ps == nullptr) {
					new_head = ps = curr;
				} else {
					ps->next = curr;
					ps = ps->next;
				}
			}
			curr = curr->next;

		}
		if (ps != nullptr) {ps->next = nullptr;}
		return new_head;
	}
};

TEST(testCase,test0) {

}


int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}

