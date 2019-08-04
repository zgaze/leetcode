/* ***********************************************************************

  > File Name: IntersectionofTwoLinkedLists_160.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Tue 07 May 2019 06:39:59 PM CST

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
 * 编写一个程序，找到两个单链表相交的起始节点。
 * 可假定整个链表结构中没有循环。
 * 如果两个链表没有交点，返回 null.
 *
 */

/*
 * 1. 判断两个节点相等，需要判断地址
 * 方法三：双指针法
 * 创建两个指针 pApA 和 pBpB，分别初始化为链表 A 和 B 的头结点。然后让它们向后逐结点遍历。
 * 当 pApA 到达链表的尾部时，将它重定位到链表 B 的头结点 (你没看错，就是链表 B); 类似的，当 pBpB 到达链表的尾部时，将它重定位到链表 A 的头结点。
 * 若在某一时刻 pApA 和 pBpB 相遇，则 pApA/pBpB 为相交结点。
 *
 * 想弄清楚为什么这样可行, 可以考虑以下两个链表: A={1,3,5,7,9,11} 和 B={2,4,9,11}，相交于结点 9。 
 * 由于 B.length (=4) < A.length (=6)，pBpB 比 pApA 少经过 22 个结点，会先到达尾部。
 * 将 pBpB 重定向到 A 的头结点，pApA 重定向到 B 的头结点后，pBpB 要比 pApA 多走 2 个结点。因此，它们会同时到达交点。
 * 如果两个链表存在相交，它们末尾的结点必然相同。因此当 pApA/pBpB 到达链表结尾时，记录下链表 A/B 对应的元素。若最后元素不相同，则两个链表不相交。
 *
 * 理论：假设 相交部分长度为g, 单独部分分别为x，y; 那么此算法下。两个指针经过的长度都是 x+y+2g,如果g >0, 那么他们的尾元素必然相等。并且开始相等的地方就是交点。
 * 复杂度分析
 *
 * 时间复杂度 : O(m+n)O(m+n)。
 * 空间复杂度 : O(1)O(1)。
 *
 *
 */

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
    
class Solution {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		if (headA == nullptr || headB == nullptr) {
			return nullptr;
		}
		ListNode *pa = headA, *pb = headB;
		while (pa != pb) {
			pa = (pa == nullptr) ? headB : pa->next;
			pb = (pb == nullptr) ? headA : pb->next;
		}
		return pa;
	}
};


TEST(testCase,test0) {

}


int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}

