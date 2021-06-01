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
 // quick sort 来排序
class Solution {
public:
    ListNode* partion(ListNode* begin, ListNode* end) {
		int flag = begin->val;
		ListNode* pos = begin->next, *prev = begin;
		while (pos != end) {
			if (pos->val < flag) {
				prev = prev->next;
				std::swap(pos->val, prev->val);
			}
			pos = pos->next;
		}
		std::swap(prev->val, begin->val);
        return prev;
    }

    void quicksort(ListNode* begin, ListNode* end) {
        if (begin == end) return;
        ListNode * p = partion(begin, end);
        quicksort(begin, p);
        quicksort(p->next, end);
    }

	ListNode* sortList(ListNode* head) {
		if (head == nullptr) return nullptr;
		quicksort(head, nullptr);
         return head;
     }
};

TEST(testCase,test0) {
	ListNode * p1 = new ListNode(4);
	ListNode * p2 = new ListNode(1);
	ListNode * p3 = new ListNode(2);
	ListNode * p4 = new ListNode(3);
	p1->next = p2;
	p2->next = p3;
	p3->next = p4;
	Solution s;
	s.sortList(p1);
}


int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}

