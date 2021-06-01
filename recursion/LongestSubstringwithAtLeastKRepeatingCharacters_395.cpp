/* ***********************************************************************

  > File Name: LongestSubstringwithAtLeastKRepeatingCharacters_395.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 


 ********************************************************************** */

#include <stdio.h>
#include <vector>
#include <string>
#include <stdio.h>
#include <climits>
#include <gtest/gtest.h>

using std::vector;
using std::string;


class Solution {
public:
	int dfs(string &s, int begin, int end,int k) {
		std::vector<int> offset(26, 0);
		for (int i = begin; i <= end; ++i) {
			offset[s[i]-'a'] ++;
		}
		char split = '0';
		for (int i = 0; i < 26; ++i) {
			if (offset[i] > 0 && offset[i] < k) {
				split = 'a' + i;
				break;
			}
		}
		if (split == '0') {
			return end - begin + 1;
		}
		int ret = 0;
		int i = begin;
		while (i <= end) {
			while (i <= end && s[i] == split) {i++;}
			int start = i;
			while(i <= end && s[i] != split) {i++;}
			ret = std::max(ret, dfs(s, start, i-1, k));
		}
		return ret;
	}
	int longestSubstring(string s, int k) {
		int n = s.length();
		return dfs(s, 0, n - 1, k);
								    }
};


TEST(testCase,test0) {
	std::string s1 = "aaabb";
	Solution s;
	EXPECT_EQ(s.longestSubstring(s1, 3), 3);
	EXPECT_EQ(s.longestSubstring("ababbc", 2), 5);

}
int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}

