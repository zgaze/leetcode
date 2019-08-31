/* ***********************************************************************

  > File Name: SortList_148.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Tue 20 Aug 2019 04:11:24 PM CST

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
 * 148. 排序链表
 *
 * 在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序。
 *
 */


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* merge(ListNode* n1, ListNode* n2) {
		ListNode * new_head = n1->val < n2->val? n1 : n2;
		ListNode * curr = new_head;
		if (n1->val < n2->val) {
			n1 = n1->next;
		} else {
			n2 = n2->next;
		}
		while(n1 != nullptr || n2 != nullptr) {
			if (n1 == nullptr) {
				curr->next = n2;
				n2 = n2->next;
			} else if (n2 == nullptr) {
				curr->next = n1;
				n1 = n1->next;
			} else {
				if (n1->val < n2->val) {
					curr->next = n1;
					n1 = n1->next;
				} else {
					curr->next = n2;
					n2 = n2->next;
				}
			}   
			curr = curr->next;
		}
		return new_head;
	}
	
	ListNode* party_sort(ListNode* head) {
		if (head == nullptr || head->next == nullptr) return head;
		ListNode* one = head, *two = head->next;
		while(two != nullptr && two->next != nullptr) {
			one = one->next;
			two = two->next->next;
		}
		ListNode* p2 = one->next;
		one->next = nullptr;
		ListNode* p3 = party_sort(head);
		std::stringstream ss;
		ListNode* tmp = p3;
		ss << "begin : ";
		while(tmp) {
			ss << " " << tmp->val;
		}
		std::cout << ss.str();
		ListNode* p4 = party_sort(p2);
		ss.clear();
		tmp = p4;
		ss << "begin : ";
		while(tmp) {
			ss << " " << tmp->val;
		}
		std::cout << ss.str();
		return merge(p3, p4);
	}
	ListNode* sortList(ListNode* head) {
		if(head == nullptr) {
			return head;
		}
		return party_sort(head);
	}
};

TEST(testCase,test0) {

}


int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}

