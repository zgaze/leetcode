/*
 *
 * 给定一个字符串 s ，找到 它的第一个不重复的字符，并返回它的索引 。如果不存在，则返回 -1 。
 *
 */

class Solution {
public:
    int firstUniqChar(string s) {
			int code[26] = {0};
			for (char c: s) {
				code[c - 'a'] ++;
			}
			for (int i = 0; i < s.size(); ++i) {
				if (code[s[i] - 'a'] == 1) {
					return i;
				}
			}
			return -1;
    }
};
