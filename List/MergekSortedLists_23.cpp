/* ***********************************************************************

  > File Name: MergekSortedLists_23.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Fri 23 Aug 2019 04:50:03 PM CST

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
 * 23. 合并K个排序链表
 * 合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。
 *
 * 示例:
 *
 * 输入:
 * [
 *   1->4->5,
 *   1->3->4,
 *   2->6
 * ]
 * 输出: 1->1->2->3->4->4->5->6
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
		if (n1 == nullptr) return n2;
		if (n2 == nullptr) return n1;
		ListNode* head = nullptr;
		if (n1->val > n2->val) {
			head = n2;
			n2 = n2->next;
		} else {
			head = n1;
			n1 = n1->next;
		}
		while(n1 || n2) {
			if (n1 == nullptr) {
				head->next = n2;
				n2 = n2->next;
			} else if (n2 == nullptr) {
				head->next = n1;
				n1 = n1->next;
			} else if (n1->val < n2->val) {
				head->next = n1; 
				n1 = n1->next;
			} else {
				head->next = n2;
				n2 = n2->next;
			}
		}
		return head;
	}
	ListNode* party_merge(vector<ListNode*>& lists, int begin, int end) {
		if (end == begin ) {
			return lists[begin];
		}
		if (end - begin == 1) {
			return merge(lists[begin], lists[end]);
		}
		int mid = (begin + end ) / 2;
		ListNode* pl = party_merge(lists, begin, mid);
		ListNode* pr = party_merge(lists, mid+1, end);
		return merge(pl, pr);
	}
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		if (lists.empty()) return nullptr;
		int size = lists.size();
		if (size == 1) {
			return lists[0];
		}
		return party_merge(lists, 0, size);
	}
};

TEST(testCase,test0) {

}


int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}

