/* ***********************************************************************

  > File Name: AssignCookies.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Tue 12 Feb 2019 04:05:19 PM CST

 ********************************************************************** */

/*
 *
 * 假设你是一位很棒的家长，想要给你的孩子们一些小饼干。
 * 但是，每个孩子最多只能给一块饼干。对每个孩子 i ，都有一个胃口值 gi ，这是能让孩子们满足胃口的饼干的最小尺寸；
 * 并且每块饼干 j ，都有一个尺寸 sj 。如果 sj >= gi ，我们可以将这个饼干 j 分配给孩子 i ，这个孩子会得到满足。
 * 你的目标是尽可能满足越多数量的孩子，并输出这个最大数值。
 *
 */


#include <vector>
#include <algorithm>
using std::vector;

class Solution {
public:
	int findContentChildren(vector<int>& g, vector<int>& s) {
		int num = 0;
		std::sort(g.begin(), g.end());
		std::sort(s.begin(), s.end());
		int size_candy = s.size(); 
		int size_child = g.size();
		for (int j = 0; num < size_child && j < size_candy;) {
			if (s[j] >= g[num]) {
				num++;
				j++;
			} else { // 饼干太小,没人要
				j++;
			}
		}
		return num;
	}
};
int main()
{
	std::vector<int> prices{1,2};
	std::vector<int> prices1{1,2,3};
	Solution s;
	int findContentChildren = s.findContentChildren(prices, prices1);
	printf("findContentChildren is %d\n", findContentChildren);
	return 0;
}
