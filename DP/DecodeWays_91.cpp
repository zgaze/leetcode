/* ***********************************************************************

  > File Name: DecodeWays_91.cpp
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

/*
 * 一条包含字母 A-Z 的消息通过以下方式进行了编码：

'A' -> 1
'B' -> 2
...
'Z' -> 26
给定一个只包含数字的非空字符串，请计算解码方法的总数。

*/
class Solution {
public:
	int numDecodings(string s) {
		int len = s.length();
		int dp[len];
		memset(dp, 0, sizeof(dp));
		dp[0] = 1;
		for (int i = 1; i < len; ++i) {
			if (s[i] == '0') {
				if (s[i-1] == '1' || s[i-1] == 2) dp[i] = dp[i-1];
				else return 0;
			} else if (dp[i-1] == '1' || (dp[i-1] == '2' && dp[i] <= '6')) {
				dp[i] = i-2 >= 0 ? (dp[i-1] + dp[i-2]) : dp[i-1] + 1;
			} else {
				dp[i] = dp[i-1];
			}
		}
		return dp[len - 1];
	}
};

TEST(testCase,test0) {
	Solution s;
	EXPECT_EQ(s.numDecodings("12"), 2);
	EXPECT_EQ(s.numDecodings("226"), 3);
	EXPECT_EQ(s.numDecodings("227"), 2);
}


int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}

