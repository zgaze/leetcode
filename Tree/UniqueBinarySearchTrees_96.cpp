/* ***********************************************************************

  > File Name: UniqueBinarySearchTrees_96.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Sun 04 Aug 2019 01:47:20 PM CST

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
 * 96. 不同的二叉搜索树
 * 给定一个整数 n，求以 1 ... n 为节点组成的二叉搜索树有多少种？
 *
 */

/*
 * G(0) = 1, G(1) = 1;
 * 解法：G(n) =  每个数字作为根节点 的 二叉搜索树之和 = ∑i ∈(1-n) {f(i)}
 * f(x) 表示 x作为根节点的二叉树数量, 等于左右子树的可能积分别是从1~x-1 和 x+1 ~ n;  f(x) = f(1 ~(x-1)) * f((x+1) - n)
 * 而f([1-(x-1)]) 就是从1~x-1的二叉树数量，即 G(x-1-1+1) = G(x-1);
 * 可以发现。1-3 和 3-5 其实是相等的，那么 f([(x+1) ~ n]) 就是 G(n-x-1+1) = G(n-x)
 * 结论： G(n) =  ∑ x ∈ (1-n) {G(x-1) * G(n-x)}
 */

class Solution {
public:
	int numTrees(int n) {
		if (n == 0 || n == 1) {
			return 1;
		}
		int G[n+1];
		memset(G, 0, sizeof(G));
		G[0] = G[1] = 1;
		for (int i = 2; i <= n; ++i) {
			for (int j = 1; j <= i; ++j) {
				G[i] += G[j-1] * G[i - j];
			}
		}	
		return G[n];
	}
};


TEST(testCase,test0) {
	Solution s;
	EXPECT_EQ(s.numTrees(1), 1);
	EXPECT_EQ(s.numTrees(2), 2);
	EXPECT_EQ(s.numTrees(3), 5);
	EXPECT_EQ(s.numTrees(4), 14);
}


int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}

