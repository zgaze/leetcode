/* ***********************************************************************

  > File Name: HammingDistance_461.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Sun 09 Sep 2018 03:14:16 PM CST

 ********************************************************************** */
/*
 * The Hamming distance between two integers is the number of positions at which the corresponding bits are different.
 * 两个整数之间的汉明距离指的是这两个数字对应二进制位不同的位置的数目。
 *
 */

/*
 * 异或变成一个数，变成数一个数二进制1的个数
 *  不用bitset也行，自己算1的个数
 *
 *
 */



#include <stdio.h>

#include <stdint.h>
#include <bitset>

using std::bitset;


class Solution {
public:
	int hammingDistance(int x, int y) {
		int64_t bit_sum = x^y;
		std::bitset<64> bt(bit_sum);
		/*
		 int distance = 0;
		 while (newInt > 0) {
		 distance += newInt & 1;
		 newInt >>= 1;
		}
		 */
		return bt.count();
	}
};
