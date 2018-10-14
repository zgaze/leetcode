/* ***********************************************************************

  > File Name: RomantoInteger.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Sun 19 Aug 2018 09:39:10 PM CST

 ********************************************************************** */

#include <string>
#include <stdio.h>
using std::string;

class Solution {
public:
	int romanToInt(string s) {
		int nums[128] = {0};
		nums['I'] = 1;
		nums['V'] = 5;
		nums['X'] = 10;
		nums['L'] = 50;
		nums['C'] = 100;
		nums['D'] = 500;
		nums['M'] = 1000;
		int res = 0;
		for (int i = 0; i < s.length(); ++i) {
			if ((i < s.length() -1) && (nums[s[i]] < nums[s[i+1]])) {
				res +=  nums[s[i+1]] - nums[s[i]];
			} else {
				res += nums[s[i]]; 
			}
			printf("x = %d\n", res);
		}
		return res;
	}
};


int main()
{
	std::string str("MCMXCIV");
	Solution a;
	int res = a.romanToInt(str);
	printf("res = %d\n", res);
	return 0;
}
