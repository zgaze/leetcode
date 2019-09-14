/* ***********************************************************************

  > File Name: FriendCircles_547.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Fri 16 Aug 2019 02:39:37 PM CST

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
 * 547 朋友圈
 * 班上有 N 名学生。其中有些人是朋友，有些则不是。他们的友谊具有是传递性。如果已知 A 是 B 的朋友，B 是 C 的朋友，那么我们可以认为 A 也是 C 的朋友。所谓的朋友圈，是指所有朋友的集合。
 *
 * 给定一个 N * N 的矩阵 M，表示班级中学生之间的朋友关系。如果M[i][j] = 1，表示已知第 i 个和 j 个学生互为朋友关系，否则为不知道。你必须输出所有学生中的已知的朋友圈总数。
 *
 */

class Solution {
public:
	int Find(int* circle, int x) {
		if (circle[x] == x || circle[x] == -1) {
			return x;
		} else {
			return Find(circle, circle[x]);
		}
	}
	int findCircleNum(vector<vector<int>>& M) {
		int size = M.size();
		int circle[size];
		memset(circle, -1 , sizeof circle);
		for (int i = 0; i < size; ++i) {
			for (int j = 0; j <= i; ++j) {
				if (M[i][j] == 1) {
					int y = Find(circle, i);
					int x = Find(circle, j);
					circle[y] = x;
					// printf("%d -> %d ; %d -> %d \n", i, j, y,x);
				}
			}
		}
		std::set<int> ret;
		for (int i = 0; i < size; ++i) {
			int x = Find(circle, i);
			//printf("%d->%d \n", i, x);
			ret.insert(x);
		}
		return ret.size();
	}
};

TEST(testCase,test0) {

}


int main(int argc, char* argv[]) {
	vector<vector<int>> s {
		{1,0,0,1},
		{0,1,1,0},
		{0,1,1,1},
		{1,0,1,1},
	};
	Solution s1;
	s1.findCircleNum(s);
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}

