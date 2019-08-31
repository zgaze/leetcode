/* ***********************************************************************

  > File Name: addTwoNumbers_2.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Tue 06 Aug 2019 03:39:47 PM CST

 ********************************************************************** */

#include <stdio.h>
#include <vector>
#include <string>
#include <stdio.h>
#include <climits>
#include <gtest/gtest.h>

using std::vector;
using std::string;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
    
class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode *p1 = l1, *p2 = l2, *new_head = nullptr;
		ListNode* ptail = new_head;
		int carry = 0;
		while(p1 != nullptr || p2 != nullptr) {
			int x = p1 ? p1->val : 0;
			int y = p2 ? p2->val : 0;
			int sum = x + y + carry;
			carry = 0;
			if (sum >= 10) {
				sum -= 10;
				carry = 1;
			}
			ListNode* p = new ListNode(sum);
			if (ptail == nullptr) {
				ptail = p;
				new_head = p;
			} else {
				ptail ->next = p;
				ptail = ptail->next;
			}
			if (p1 != nullptr) p1 = p1->next;
			if (p2 != nullptr) p2 = p2->next;
		}
		if (carry > 0) {
			ListNode* p = new ListNode(1);
			ptail ->next = p;
		}
		return new_head;
	}
	void print(ListNode* head) {
		if (head == nullptr) {
			printf("null  ");
		} else if (head->next == nullptr) {
			printf("  %d ", head->val);
		} else {
			print(head->next);
			printf(" %d ", head->val);
		}
	}
	ListNode* build(std::vector<int> & nums, int begin) {
		int length = nums.size();
		if (begin >= length) {
			return nullptr;
		}
		ListNode* head = new ListNode(nums[begin]);
		head->next = build(nums, begin + 1);
		return head;
	}
};


TEST(testCase,test0) {

}


int main(int argc, char* argv[]) {
	Solution ss;
	std::vector<int> nums1 {1,2,3,4,5,6,7,8,9};
	ListNode* head1  = ss.build(nums1, 0);
	std::vector<int> nums2 {0};
	ListNode* head2  = ss.build(nums2, 0);
	ListNode* head = ss.addTwoNumbers(head1, head2);
	ss.print(head);
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}

