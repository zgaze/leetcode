/* ***********************************************************************

  > File Name: LongestValidParentheses_32.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Sun 07 Apr 2019 12:04:38 PM CST

 ********************************************************************** */

/*
 * 32. 最长有效括号
 * Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.
 * 给定一个只包含 '(' 和 ')' 的字符串，找出最长的包含有效括号的子串的长度。
 */

#include <string>
#include <stack>
using std::string;
using std::stack;

class Solution {
public:
	int longestValidParentheses(std::string s) {
		return std::max(calc(s, 0, 1, s.length(), '('), calc(s, s.length() -1, -1, -1, ')'));
	}
	int calc(std::string& chars , int i ,  int flag,int end, char cTem){
		int max = 0, sum = 0, currLen = 0,validLen = 0;
		for (;i != end; i += flag) {
			sum += (chars[i] == cTem ? 1 : -1);
			currLen ++;
			if(sum < 0){
				max = max > validLen ? max : validLen;
				sum = 0;
				currLen = 0;
				validLen = 0;
			}else if(sum == 0){
				validLen = currLen;
			}
		}
		return max > validLen ? max : validLen;
	}






	int longestValidParenthesesM(string s) {
		if (s.empty()) {
			return 0;
		}
		int len = s.length();
		int pos = s.find_first_of("(");
		std::stack<char> st;
		int max = 0;
		int ret = 0;
		for (int i = pos; i < len; ++i) {
			if (s[i] == '(') {
				st.push(s[i]);
			} else if (s[i] == ')') {
				if (!s.empty()) {
					st.pop();
					max += 2;
				} else {
					// 遇到非法),前面那些都无效了。
					std::stack<char> tmp;
					tmp.swap(st);
					ret = std::max(ret, max);
					max = 0;
				}
			}
		}
		ret = std::max(max, ret);
		return ret;
	}
};

int main() {
	std::string str{")()())"};
	Solution s;
	int max = s.longestValidParentheses(str);
	printf("=== %d\n", max);
	return 0;
}


