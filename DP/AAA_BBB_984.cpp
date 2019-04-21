/* ***********************************************************************

  > File Name: AAA_BBB_984.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Sun 21 Apr 2019 03:27:59 PM CST

 ********************************************************************** */

#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <climits>
#include<gtest/gtest.h>



/*
 * 给定两个整数 A 和 B，返回任意字符串 S，要求满足：
 * S 的长度为 A + B，且正好包含 A 个 'a' 字母与 B 个 'b' 字母；
 * 子串 'aaa' 没有出现在 S 中；
 * 子串 'bbb' 没有出现在 S 中。
 *
 */

using std::vector;
using std::string;

class Solution_1 {
public:
	string compute_dp(std::vector<std::vector<std::string>>& dp, int A, int B) {
		if (dp[A][B] != "") {
			//std::cout << A << "-" << B << " : " << dp[A][B] <<  std::endl;
			return dp[A][B];
		}
		if (B > A) {
			dp[A][B] = dp[1][2] + compute_dp(dp, A-1, B-2);
		} else if(B == A){
			dp[A][B] = dp[1][1] + compute_dp(dp, A-1, B-1);
		} else {
			dp[A][B] = dp[2][1] + compute_dp(dp, A-2, B-1);
		}
		//std::cout << A << "-" << B << " : " << dp[A][B] <<  std::endl;
		return  dp[A][B];
	}

	string strWithout3a3b(int A, int B) {
		int row = A, col = B;
		if (A < 3 ) {
			row = 3;
		}
		if(B < 3) {
			col = 3;
		}
		std::vector<std::vector<std::string>> dp;
		for (int i = 0; i < row+1; ++i) {
			std::vector<std::string> vec_str;
			for(int j = 0; j < col+1; ++j) {
				std::string s = "";
				vec_str.push_back(std::move(s));
			}
			dp.push_back(std::move(vec_str));
		}
		//std::cout << dp[1][1] << dp[1][2] << std::endl;
		dp[0][1] = "b";
		dp[0][2] = "bb";
		dp[1][0] = "a";
		dp[2][0] = "aa";
		dp[1][1] = A > B ? "ba" : "ab";
		dp[1][2] = "bba";
		dp[2][1] = "aab";
		compute_dp(dp, A, B);
		return dp[A][B];
		//return "hh";
	}
};


// 后面还可以写成循环
class Solution {
public:
	string compute_str(int A, int B) {
		if (A == 0) {
			if (B == 0) return "";
			if (B == 1) return "b";
			if (B == 2) return "bb";
		}
		if (A == 1) {
			if (B == 1) return "ba";
			if (B == 2) return "bba";
		}
		if (B > A) {
			return compute_str(1, 2) + compute_str(A-1, B-2);
		} else {
			return compute_str(1, 1) + compute_str(A-1, B-1);
		}
	}
	string strWithout3a3b(int A, int B) {
		if (A <= B) {
			return compute_str(A, B);
		} else {
			auto s = compute_str(B, A);
			for(auto& c : s) {
				if (c == 'a') c= 'b';
				else c = 'a';
			}
			return s;
		}

	}
};



TEST(testCase,test0) {
	Solution s;
	Solution_1 s1;
	EXPECT_EQ(s.strWithout3a3b(1, 1), s1.strWithout3a3b(1, 1));
	EXPECT_EQ(s.strWithout3a3b(1, 2), s1.strWithout3a3b(1, 2));
	EXPECT_EQ(s.strWithout3a3b(1, 3), s1.strWithout3a3b(1, 3));
	EXPECT_EQ(s.strWithout3a3b(1, 4), s1.strWithout3a3b(1, 4));
	EXPECT_EQ(s.strWithout3a3b(2, 3), s1.strWithout3a3b(2, 3));
	EXPECT_EQ(s.strWithout3a3b(2, 4), s1.strWithout3a3b(2, 4));
	EXPECT_EQ(s.strWithout3a3b(2, 5), s1.strWithout3a3b(2, 5));
	EXPECT_EQ(s.strWithout3a3b(2, 6), s1.strWithout3a3b(2, 6));
	EXPECT_EQ(s.strWithout3a3b(3, 5), s1.strWithout3a3b(3, 5));
	EXPECT_EQ(s.strWithout3a3b(3, 6), s1.strWithout3a3b(3, 6));
	EXPECT_EQ(s.strWithout3a3b(3, 7), s1.strWithout3a3b(3, 7));
	EXPECT_EQ(s.strWithout3a3b(3, 8), s1.strWithout3a3b(3, 8));
	EXPECT_EQ(s.strWithout3a3b(2, 1), s1.strWithout3a3b(2, 1));
	EXPECT_EQ(s.strWithout3a3b(3, 1), s1.strWithout3a3b(3, 1));
	EXPECT_EQ(s.strWithout3a3b(4, 1), s1.strWithout3a3b(4, 1));
	EXPECT_EQ(s.strWithout3a3b(4, 2), s1.strWithout3a3b(4, 2));
	EXPECT_EQ(s.strWithout3a3b(5, 2), s1.strWithout3a3b(5, 2));
	EXPECT_EQ(s.strWithout3a3b(6, 2), s1.strWithout3a3b(6, 2));
}


int main(int argc, char* argv[]) {
	Solution s;
	std::cout << s.strWithout3a3b(1, 1) << "\n";
	std::cout << s.strWithout3a3b(1, 2) << "\n";
	std::cout << s.strWithout3a3b(1, 3) << "\n";
	std::cout << s.strWithout3a3b(1, 4) << "\n";
	std::cout << s.strWithout3a3b(2, 3) << "\n";
	std::cout << s.strWithout3a3b(2, 4) << "\n";
	std::cout << s.strWithout3a3b(2, 5) << "\n";
	std::cout << s.strWithout3a3b(2, 6) << "\n";
	std::cout << s.strWithout3a3b(3, 5) << "\n";
	std::cout << s.strWithout3a3b(3, 6) << "\n";
	std::cout << s.strWithout3a3b(3, 7) << "\n";
	std::cout << s.strWithout3a3b(3, 8) << "\n";
	std::cout << s.strWithout3a3b(2, 1) << "\n";
	std::cout << s.strWithout3a3b(3, 1) << "\n";
	std::cout << s.strWithout3a3b(4, 1) << "\n";
	std::cout << s.strWithout3a3b(4, 2) << "\n";
	std::cout << s.strWithout3a3b(5, 2) << "\n";
	std::cout << s.strWithout3a3b(6, 2) << "\n";
	//return 0;
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}

