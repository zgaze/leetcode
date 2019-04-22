/* ***********************************************************************

  > File Name: CountingBits_338.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Mon 22 Apr 2019 08:25:36 PM CST

 ********************************************************************** */

/*
 *
 * 给定一个非负整数 num。对于 0 ≤ i ≤ num 范围中的每个数字 i ，计算其二进制数中的 1 的数目并将它们作为数组返回。
 *
 * 示例 1:
 *
 * 输入: 2
 * 输出: [0,1,1]
 * 示例 2:
 *
 * 输入: 5
 * 输出: [0,1,1,2,1,2]
 * 进阶:
 *
 * 给出时间复杂度为O(n*sizeof(integer))的解答非常容易。但你可以在线性时间O(n)内用一趟扫描做到吗？
 * 要求算法的空间复杂度为O(n)。
 * 你能进一步完善解法吗？要求在C++或任何其他语言中不使用任何内置函数（如 C++ 中的 __builtin_popcount）来执行此操作。
 *
 *
 */


/*
 * i & (i - 1)可以去掉i最右边的一个1（如果有），因此 i & (i - 1）是比 i 小的，
 * 而且i & (i - 1)的1的个数已经在前面算过了，所以i的1的个数就是 i & (i - 1)的1的个数加上1
 *
 */

#include <stdio.h>
#include <vector>
#include <string>
#include <stdio.h>
#include <climits>
#include <algorithm>
#include<gtest/gtest.h>

using std::vector;
using std::string;

class Solution {
public:
	vector<int> countBits(int num) {
		std::vector<int> dp;
		dp.resize(num+1);
		dp[0] = 0;
		for (int i = 1; i <= num; ++i) {
			dp[i] = dp[i&(i-1)] + 1;
		}
		return dp;
	}
};

TEST(testCase,test0) {
	vector<int> answer_2{0,1,1};
	vector<int> answer_5{0,1,1,2,1,2};
	Solution s;
	EXPECT_TRUE(std::equal(answer_2.begin(), answer_2.end(), s.countBits(2).begin()));
	EXPECT_TRUE(std::equal(answer_5.begin(), answer_5.end(), s.countBits(5).begin()));
	/*
	std::vector<int> bits = s.countBits(50); 
	std::stringstream str;
	for (auto bit : bits) {
		str << bit << " "; 
	}
	// 0 1 1 2 1 2 2 3 1 2 2 3 2 3 3 4 1 2 2 3 2 3 3 4 2 3 3 4 3 4 4 5 1 2 2 3 2 3 3 4 2 3 3 4 3 4 4 5 2 3 3
	std::cout << str.str() << "\n";
	*/
}


int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}

