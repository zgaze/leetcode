/* ***********************************************************************

  > File Name: PermutationinString.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Thu 16 May 2019 04:12:24 PM CST

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
 * 567. 字符串的排列
 * 给定两个字符串 s1 和 s2，写一个函数来判断 s2 是否包含 s1 的排列。
 * 换句话说，第一个字符串的排列之一是第二个字符串的子串。
 *
 * 示例1:
 *
 * 输入: s1 = "ab" s2 = "eidbaooo"
 * 输出: True
 * 解释: s2 包含 s1 的排列之一 ("ba").
 *  
 *  示例2:
 *
 *  输入: s1= "ab" s2 = "eidboaoo"
 *  输出: False
 *   
 *   注意：
 *
 *   输入的字符串只包含小写字母
 *   两个字符串的长度都在 [1, 10,000] 之间
 */


/*
 * 思路：排列即每个出现一次
 * 所以处理一下s1,记录出现的次数。遍历S2，如果连续出现所有S1中出现的字符串即可
 */

class Solution {
public:
	bool checkInclusion(string s1, string s2) {
		if (s1.empty()) {
			return true;
		}
		if (s2.empty()) {
			return false;
		}
		int nums[300], tmp[300];
		memset(nums, 0, sizeof nums);
		memset(tmp, 0, sizeof tmp);
		for (auto c: s1) {
			nums[(int)c] ++;
		}
		int size_1 = s1.size();
		int size_2 = s2.size();
		for (int i = 0; i < size_2; ++i) {
			int c = (int)s2[i];
			if (nums[c] == 0) {
				continue;
			}
			int same = 0;
			for (int j = i; j < size_2; ++j) {
				int c1 = (int)s2[j];
				if (nums[c1] > tmp[c1]) {
					same ++;
					tmp[c1] ++;
					if (same == size_1) {
						return true;
					}
				} else {
					memset(tmp, 0, sizeof tmp);
					break;
				}
			}
		}
		return false;
	}
};


TEST(testCase,test0) {
	std::string s1 = "ab", s2 = "eidbaooo";
	std::string s3 = "adc", s4 = "dcda";
	std::string s5 = "abc", s6 = "bcbcba";
	std::string s7 = "abc", s8 = "bbbbcbba" ;
	Solution s;
	EXPECT_EQ(s.checkInclusion(s1, s2), true);
	EXPECT_EQ(s.checkInclusion(s3, s4), true);
	EXPECT_EQ(s.checkInclusion(s5, s6), true);
	EXPECT_EQ(s.checkInclusion(s7, s8), false);
}


int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}

