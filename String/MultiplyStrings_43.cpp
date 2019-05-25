/* ***********************************************************************

  > File Name: MultiplyStrings_43.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Sat 18 May 2019 03:54:28 PM CST

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
 * 解题思路：
 * 1. m位数*n位数最多m+n位
 * 2. 第i位*第j位的数值会落在第i+j位，这里都从第1位开始数; 如果从第0位开始数，第i位*第j位落在(i*j+1)位
 * 3. 初始一个足够长的数组，循环O(n^2)把结果都累加到数组里即可
 * 4. 去掉数组前面的0
 *
 */

class Solution {
public:
	string multiply(string num1, string num2) {
		if (num1.empty() || num2.empty()) {
			return "";
		}
		if (num1 == "0" || num2 == "0") {
			return "0";
		}
		int m = num1.length(), n = num2.length();
		int * buf = new int[m+n];
		memset(buf, 0, (m+n)*sizeof(int));
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				buf[i+j+1] += (num1[i]- '0') * (num2[j] - '0');
			}
		}
		for (int i = m+n-1; i > 0; i--) {
			int c = buf[i];
			if (c > 9) {
				buf[i] = (c % 10);
				buf[i-1] += (c/10);
			}
		}
		// int 转char
		char ret[m+n];
		memset(ret, '0', sizeof ret);
		for (int i = m+n-1; i >= 0; i--) {
			ret[i] =  buf[i] + '0';
		}
		if (ret[0] == '0') {
			return string(string(ret), 1, m+n-1);
		}
		delete[] buf;
		return string(ret, 0, m+n);
	}
};

/*
TEST(testCase,test0) {
	std::string s1 = "99", s2 = "999";
	Solution s;
	EXPECT_EQ(s.multiply(s1, s2), "98901");
	EXPECT_EQ(s.multiply("1", "2"), "2");
	EXPECT_EQ(s.multiply("2", "3"), "6");
	EXPECT_EQ(s.multiply("555555555", "559205550004"), "310669749691552472220");
	EXPECT_EQ(s.multiply("1000000000000000000", "559205550004"), "559205550004000000000000000000");
}
*/


int main(int argc, char* argv[]) {
    //testing::InitGoogleTest(&argc,argv);
    //return RUN_ALL_TESTS();
	std::string s1 = "1000000000000000000", s2 = "559205550004";
	Solution s;
	s.multiply(s1, s2);
	return 0;
}

