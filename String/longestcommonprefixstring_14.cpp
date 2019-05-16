/* ***********************************************************************

  > File Name: longestcommonprefixstring.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Thu 16 May 2019 03:15:04 PM CST

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
 *
 * 编写一个函数来查找字符串数组中的最长公共前缀。
 *
 * 如果不存在公共前缀，返回空字符串 ""。
 *
 * 示例 1:
 *
 * 输入: ["flower","flow","flight"]
 * 输出: "fl"
 * 示例 2:
 *
 * 输入: ["dog","racecar","car"]
 * 输出: ""
 * 解释: 输入不存在公共前缀。
 * 说明:
 *
 * 所有输入只包含小写字母 a-z 。
 */

/*
 *
 * 思路：公共前缀，即：前面的一样。那么只需比较每个字符串的前x个字符就好了，不断通过比较缩小x
 *
 */


class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		if (strs.empty()) {
			return "";
		}
		string ret = strs[0];
		int ret_len = ret.size();
		for (auto & str : strs) {
			if (str.empty() || ret_len == 0) {
				return "";
			}
			int tmp_len = str.length();
			if (tmp_len < ret_len) {
				ret_len = tmp_len;
			}
			for (int i = 0;i < ret_len; ++i) {
				if (ret[i] != str[i]) {
					ret_len = i;
					break;
				}
			}
		}
		return ret.substr(0, ret_len);
	}
};

TEST(testCase,test0) {
	vector<string> strs1 = {"flower","flow","flight"};
	vector<string> strs2 = {"llower","flow","flight"};
	vector<string> strs3 = {"a"};
	vector<string> strs4 = {"", ""};
	vector<string> strs5 = {"", "", ""};
	vector<string> strs7 = {"a", "a", "a"};
	vector<string> strs8 = {"a", "a"};
	vector<string> strs9 = {"a", "", "aa"};
	Solution s;
	EXPECT_EQ(s.longestCommonPrefix(strs1), string("fl"));
	EXPECT_EQ(s.longestCommonPrefix(strs2), string(""));
	EXPECT_EQ(s.longestCommonPrefix(strs3), string("a"));
	EXPECT_EQ(s.longestCommonPrefix(strs4), string(""));
	EXPECT_EQ(s.longestCommonPrefix(strs5), string(""));
	EXPECT_EQ(s.longestCommonPrefix(strs7), string("a"));
	EXPECT_EQ(s.longestCommonPrefix(strs8), string("a"));
	EXPECT_EQ(s.longestCommonPrefix(strs9), string(""));
}


int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}

