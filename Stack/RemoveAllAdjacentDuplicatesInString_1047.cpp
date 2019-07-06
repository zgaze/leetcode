/* ***********************************************************************

  > File Name: RemoveAllAdjacentDuplicatesInString_1047.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Fri 05 Jul 2019 12:00:20 PM CST

 ********************************************************************** */

#include <stdio.h>
#include <vector>
#include <string>
#include <stdio.h>
#include <climits>
#include <stack>
#include <gtest/gtest.h>

using std::vector;
using std::string;
using std::stack;
/*
 *
 * 给出由小写字母组成的字符串 S，重复项删除操作会选择两个相邻且相同的字母，并删除它们。
 *
 * 在 S 上反复执行重复项删除操作，直到无法继续删除。
 *
 * 在完成所有重复项删除操作后返回最终的字符串。答案保证唯一。
 *
 */


class Solution {
public:
	string removeDuplicates(string S) {
		string ret;
		int len = S.length();
		for (int i = 0; i < len ; ++i) {
			if (ret.empty() || ret.back() != S[i]) {
				ret.push_back(S[i]);
			} else {
				if (ret.back() == S[i]) {
					ret.pop_back();
				}
			}
		}
		return ret;
	}
};


TEST(testCase,test0) {
	string s1 {"aabbc"};
	string s1_out = "c";
	Solution s;
	EXPECT_EQ(s.removeDuplicates(s1), s1_out);
}


int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}

