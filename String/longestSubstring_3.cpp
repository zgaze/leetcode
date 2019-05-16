/* ***********************************************************************

  > File Name: longestSubstring.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Tue 14 May 2019 06:11:50 PM CST

 ********************************************************************** */

#include <stdio.h>
#include <vector>
#include <string>
#include <stdio.h>
#include <climits>
#include <gtest/gtest.h>
#include <map>

using std::vector;
using std::string;

/*
 * 3. 无重复字符的最长子串
 * 给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
 * 示例 1:
 *
 * 输入: "abcabcbb"
 * 输出: 3 
 * 解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
 * 示例 2:
 *
 * 输入: "bbbbb"
 * 输出: 1
 * 解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
 * 示例 3:
 *
 * 输入: "pwwkew"
 * 输出: 3
 * 解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
 *
 * 请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
 *
 */


/*
 * 记录这个字符上一次出现的位置和一个窗口的开始位置，如果上一次出现比窗口靠后，更新窗口
 */


class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		if (s.size() < 2) {
			return s.size();
		}
		int offset_map[300];
		memset(offset_map, 0, sizeof offset_map);
		int size = s.length();
		int max = 0, last = 0;
		for (int i = 0; i < size; ++i) {
			int c = (int)s[i];
			if (offset_map[c] != 0 && offset_map[c] >= last) {
				max = std::max(max, i - last);
				last = offset_map[c];
			}
			offset_map[c] = i + 1;
		}
		return std::max(max, size - last);
	}
};


TEST(testCase,test0) {
	std::string s1{"abcabcbb"};
	std::string s2{"bbbbb"};
	std::string s3{"pwwkew"};
	std::string s4{"aa"};
	std::string s6{"au"};
	std::string s5{"abcabcbbcqoeqpwewqmsdfaaf"};
	std::string s7{"aab"};
	std::string s8{"aabcsef"};
	Solution s;
	EXPECT_EQ(s.lengthOfLongestSubstring(s1), 3);
	EXPECT_EQ(s.lengthOfLongestSubstring(s2), 1);
	EXPECT_EQ(s.lengthOfLongestSubstring(s3), 3);
	EXPECT_EQ(s.lengthOfLongestSubstring(s4), 1);
	EXPECT_EQ(s.lengthOfLongestSubstring(s6), 2);
	EXPECT_EQ(s.lengthOfLongestSubstring(s5), 8);
	EXPECT_EQ(s.lengthOfLongestSubstring(s7), 2);
	EXPECT_EQ(s.lengthOfLongestSubstring(s8), 6);
}


int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}

