/* ***********************************************************************

  > File Name: ReverseInteger.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Sat 18 Aug 2018 09:59:57 PM CST

 ********************************************************************** */

#include <stdio.h>
#include <cmath>
#include <stdint.h>
#include <limits.h>
#include <stdlib.h>

/*
 * 7. Reverse Integer
 * Given a 32-bit signed integer, reverse digits of an integer.
 */
class Solution {
public:
	int reverse(int x) {
		int res = 0;
		while(x != 0) {
			if (abs(res) > INT_MAX / 10) return 0;
			res = res * 10 + x /10;
			x /= 10;
		}
		return res;
	}
};
