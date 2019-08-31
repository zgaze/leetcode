/* ***********************************************************************

  > File Name: RemoveNthNodeFromEndofList_19.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Mon 26 Aug 2019 11:11:04 AM CST

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
 * 19. 删除链表的倒数第N个节点
 * 给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。
 *
 * 示例：
 *
 * 给定一个链表: 1->2->3->4->5, 和 n = 2.
 *
 * 当删除了倒数第二个节点后，链表变为 1->2->3->5.
 * 说明：
 *
 * 给定的 n 保证是有效的。
 *
 * 进阶：
 *
 * 你能尝试使用一趟扫描实现吗？
 */

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
    
class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		if (head == nullptr) {
			return head;
		}
		ListNode* ps = nullptr, *pf = head;
		while(n > 0) {
			pf = pf->next;
			n--;
		}
		if (n != 0)  return head;
		if (pf == nullptr) return head->next;
		while(pf != nullptr) {
			pf = pf->next;
			if (ps == nullptr) {
				ps = head;
			} else {
				ps = ps->next;
			}
		}
		ps->next = ps->next->next;
		return head;
	}
};

TEST(testCase,test0) {

}


int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}

