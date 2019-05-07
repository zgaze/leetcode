/* ***********************************************************************

  > File Name: Palindrome.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Tue 07 May 2019 04:47:25 PM CST

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
 * 验证回文串
 *
 * 给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。
 *
 * 说明：本题中，我们将空字符串定义为有效的回文串。
 *
 * 示例 1:
 *
 * 输入: "A man, a plan, a canal: Panama"
 * 输出: true
 * 示例 2:
 *
 * 输入: "race a car"
 * 输出: false
 */

class Solution {
public:
	int Next(string& s, int i, int flag) {
		while(i >= 0 && i <(int)s.length() ) {
			if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9') || (s[i] >= 'A' && s[i] <= 'Z')){
				return i;
			} else {
				i += flag;
			}
		}
		return i;
	}
	bool Equel(char c1, char c2) {
		if (c1 == c2) {
			return true;
		}
		int gap = 'a'-'A';
		if (c1 >= 'A' && c1 <= 'Z' && c1 + gap == c2) {
			return true;
		}
		if (c2 >= 'A' && c2 <= 'Z' && c2 + gap == c1) {
			return true;
		}
		return false;
	}
	bool isPalindrome(string s) {
		int size = s.length();
		int next_i = Next(s, 0, 1);
		int next_j = Next(s, size-1, -1);
		while(next_j >= next_i) {
			if (!Equel(s[next_i], s[next_j])) {
				return false;
			}
			int i = next_i + 1, j = next_j - 1;
			next_i = Next(s, i, 1);
			next_j = Next(s, j, -1);
		}
		return true;
	}
};

TEST(testCase,test0) {
	std::string s1 = "race a car";
	std::string s2 = "A man, a plan, a canal: Panama";
	std::string s3 = ".a";
	std::string s4 = "0P";
	Solution s;
	EXPECT_EQ(s.isPalindrome(s1), false);
	EXPECT_EQ(s.isPalindrome(s2), true);
	EXPECT_EQ(s.isPalindrome(s3), true);
	EXPECT_EQ(s.isPalindrome(s4), false);
}


int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}

