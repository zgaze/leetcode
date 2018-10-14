/* ***********************************************************************

  > File Name: strStr.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Sat 08 Sep 2018 02:47:16 PM CST

 ********************************************************************** */

/*
 *
 * 实现 strStr() 函数。
 *
 * 给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)。如果不存在，则返回  -1。
 */

#include <string>
#include <string.h>

using std::string;

class Solution {
public:
	int strStr(string haystack, string needle) {
		if (haystack.length() < needle.length()) {
			return -1;
		}
		if (needle.empty()) {
			return 0;
		}
		for (size_t i = 0; i < haystack.length(); ++i) {
			if (needle[0] == haystack[i]) {
				if (strncmp(&needle[0], &haystack[i], needle.length()) == 0) {
					return i;
				}
			} 
		}
		return -1;
	}
};
