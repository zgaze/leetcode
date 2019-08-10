/* ***********************************************************************

  > File Name: ReverseString_bytedace.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Mon 05 Aug 2019 02:45:41 PM CST

 ********************************************************************** */

#include <stdio.h>
#include <vector>
#include <string>
#include <stdio.h>
#include <climits>
#include <iostream>
#include <gtest/gtest.h>

using std::vector;
using std::string;

/*
 *	给定一个字符串，逐个翻转字符串中的每个单词。
 *	输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
 *	如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。
 *
 */

class Solution {
public:
	enum SpaceStat{
		NOT_NEED = 0, 
		CAN_USE  = 1,
		USED     = 2,
	};

	void reverseWords_r(string &s, int begin, int end) {
		while (begin <= end) {
			std::swap(s[begin++] , s[end--]);
		}
	}

	string reverseWords(string s) {
		int length = s.length();
		int vaild = 0;
		std::vector<int> indexs;
		SpaceStat stat = NOT_NEED;
		for (int i = 0; i < length; ++i) { // 循环去掉多余的空格
			if (s[i] != ' ') {
				s[vaild++] = s[i];
				stat = SpaceStat::CAN_USE;
			} else if (stat == SpaceStat::CAN_USE) {
				s[vaild++] = s[i];
				stat = SpaceStat::USED;
			}
		}
		if (s[vaild-1] == ' ') { // 最后的一个空格去掉, vaild 就是有效的字符串长度
			vaild --;
		}
		std::cout << s.substr(0, vaild) << "  length: " << vaild <<"\n";
		int begin = 0, end = 0;
		for (int i = 0; i <= vaild; ++i) {
			if (i == vaild) {
				reverseWords_r(s, begin, vaild - 1);
			} else if (s[i] == ' ') {
				end = i - 1;
				reverseWords_r(s, begin, end);
				begin = i + 1;
			}
		}
		reverseWords_r(s, 0, vaild-1);
		return s.substr(0, vaild);
	}
};

TEST(testCase,test0) {
}


int main(int argc, char* argv[]) {
	Solution s;
	std::string s1 = "    hello      world    xx    ";
	std::string s2 = "the sky is blue";
	std::cout << s.reverseWords(s1) << "\n";
	std::cout << s.reverseWords(s2) << "\n";
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}

