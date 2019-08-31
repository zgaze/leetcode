/* ***********************************************************************

  > File Name: ReverseLinkedListII_92.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Fri 23 Aug 2019 02:52:47 PM CST

 ********************************************************************** */

#include <stdio.h>
#include <vector>
#include <string>
#include <stdio.h>
#include <climits>
#include <stack>
#include <gtest/gtest.h>

using std::vector;
using std::string;
using std::stack;

/*
 * 92. 反转链表 II
 * 反转从位置 m 到 n 的链表。请使用一趟扫描完成反转。
 *
 * 说明:
 * 1 ≤ m ≤ n ≤ 链表长度。
 *
 */

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


// accept
class Solution_stack {
public:
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		if (m == n) return head;
		if (head == nullptr) {
			return head;
		}
		std::stack<ListNode*> nodes;
		ListNode* prev = nullptr, *curr = head, *new_head = head;
		ListNode* broker = nullptr;
		for (int i = 1; i <= n; ++i) {
			if (i >= m && curr != nullptr) {
				nodes.push(curr);
			}
			if (i == m) {
				broker = prev; 
			}
			prev = curr;
			curr = curr->next;
		}
		while(!nodes.empty()) {
			ListNode* top = nodes.top();
			if (broker == nullptr) {
				broker = top;
				new_head = broker;
			} else {
				broker->next = top;
				broker = broker->next;
			}
			nodes.pop();
		}
		broker->next = curr;
		return new_head;
	}
};


// accept
class Solution {                                                                     
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {                         
        if (m == n) return head;
        if (head == nullptr) {                                                       
            return head; 
        }
        ListNode* prev = nullptr, *curr = head, *new_head = (m == 1) ? nullptr: head;
        int i = 1;
        for (; i < m; ++i) {
            prev = curr;
            curr = curr->next;
        }
        printf("=== curr : %d", curr->val);
        ListNode *begin = curr, *broken = prev;
        while(curr && i <= n) {
            ListNode* next = curr->next;
            curr->next = prev;                                                                       
            prev = curr;                           
            curr = next;
            if (broken != nullptr) {
                broken ->next = prev;
            }
            i ++;                                  
        }
        begin->next = curr;
        if (new_head == nullptr) new_head = prev;
        return new_head;                           
    }                                              
};  

TEST(testCase,test0) {

}


int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}

