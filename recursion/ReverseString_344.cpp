/* ***********************************************************************

  > File Name: ReverseString_344.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Thu 08 Aug 2019 05:59:49 PM CST

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
 * 344. 反转字符串
 *
 * 编写一个函数，其作用是将输入的字符串反转过来。输入字符串以字符数组 char[] 的形式给出。
 *
 * 不要给另外的数组分配额外的空间，你必须原地修改输入数组、使用 O(1) 的额外空间解决这一问题。
 *
 * 你可以假设数组中的所有字符都是 ASCII 码表中的可打印字符。
 *
 */

class Solution {
public:
	void helper(vector<char>& s, int begin, int end) {
		if (begin >= end) {
			return;
		}
		std::swap(s[begin], s[end]);
		helper(s, begin + 1, end - 1);
	}
	void reverseString(vector<char>& s) {
		int length = s.size();
		helper(s, 0, length - 1);
	}
};

TEST(testCase,test0) {

}


int main(int argc, char* argv[]) {
	Solution sss;
	vector<char> s {'h','e','l','l','o'};
	sss.reverseString(s);
	for (auto c : s) {
		printf("%c  ", c);
	}
	printf("  \n");
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}

