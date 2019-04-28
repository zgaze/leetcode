/* ***********************************************************************

  > File Name: ArithmeticSlices_413.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Sun 28 Apr 2019 04:40:09 PM CST

 ********************************************************************** */

/*
 * 如果一个数列至少有三个元素，并且任意两个相邻元素之差相同，则称该数列为等差数列。
 * 例如，以下数列为等差数列:
 *
 * 1, 3, 5, 7, 9
 * 7, 7, 7, 7
 * 3, -1, -5, -9
 * 以下数列不是等差数列。
 * 1, 1, 2, 5, 7
 *
 *  数组 A 包含 N 个数，且索引从0开始。数组 A 的一个子数组划分为数组 (P, Q)，P 与 Q 是整数且满足 0<=P<Q<N 。
 *
 *  如果满足以下条件，则称子数组(P, Q)为等差数组：
 *  元素 A[P], A[p + 1], ..., A[Q - 1], A[Q] 是等差的。并且 P + 1 < Q 。
 *  函数要返回数组 A 中所有为等差数组的子数组个数。
 *
 *
 */

/*
 * dp算以x结尾的等差数列个数：如1,2,3,4,5 以3结尾的1个，1,2,3 以5结尾的3个:1-2-3-4-5,2-3-4-5,3-4-5;
 * 那么f(n) =sum(dp[2]...dp[n])
 * 1, 1, 1, 1, 2, 3, 4, 5 : 分别是 0,0,1,2,0,1,2,3
 */

#include <stdio.h>
#include <vector>
#include <string>
#include <stdio.h>
#include <climits>
#include<gtest/gtest.h>

using std::vector;
using std::string;

class Solution {
public:
	int numberOfArithmeticSlices(vector<int>& A) {
		if (A.size() < 3) {
			return 0;
		}
		int dp[A.size()];
		dp[0] = dp[1] = 0;
		int sum = 0;
		for (int i = 2; i < (int)A.size(); ++i) {
			if (A[i-1] - A[i-2] == A[i] - A[i-1]) {
				dp[i] = dp[i-1] + 1;
			} else {
				dp[i] = 0;
			}
			sum += dp[i];
		}
		return sum;
	}
};

TEST(testCase,test0) {
	std::vector<int> test_v1 {1, 3, 5, 7, 9};
	std::vector<int> test_v2 {1, 1, 1, 1, 2, 3, 4, 5};
	Solution s;
	EXPECT_EQ(s.numberOfArithmeticSlices(test_v1), 6);
	EXPECT_EQ(s.numberOfArithmeticSlices(test_v2), 9);
}


int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}

