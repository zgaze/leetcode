/* ***********************************************************************

  > File Name: Candy_135.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Tue 20 Aug 2019 10:47:01 AM CST

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
 * 135. 分发糖果
 *
 * 老师想给孩子们分发糖果，有 N 个孩子站成了一条直线，老师会根据每个孩子的表现，预先给他们评分。
 *
 * 你需要按照以下要求，帮助老师给这些孩子分发糖果：
 *
 * 每个孩子至少分配到 1 个糖果。
 * 相邻的孩子中，评分高的孩子必须获得更多的糖果。
 * 那么这样下来，老师至少需要准备多少颗糖果呢？
 *
 */

class Solution {
public:
	int candy(vector<int>& ratings) {
		int size = ratings.size();
		if (size < 2) {return size;};
		int num[size];
		for (int i = 0; i < size;++i) {
			num[i] = 1;
		}
		for (int i = 1; i < size; ++i) {
			if (ratings[i] > ratings[i-1] && num[i] <= num[i-1]) {
				//printf("%d(%d) > %d(%d) , but %d(%d) <= %d(%d) \n ", ratings[i], i, ratings[i-1],i-1, num[i], i, num[i-1], i-1);
				num[i] = num[i-1] + 1;
				//printf("so add to %d(%d) \n", num[i], i);
			}
		}
		for (int i = size-1; i > 0; --i) {
			if (ratings[i-1] > ratings[i] && num[i-1] <= num[i]) {
				//printf("%d(%d) > %d(%d) , but %d(%d) <= %d(%d) \n", ratings[i-1], i-1, ratings[i], i, num[i-1], i-1,  num[i], i);
				num[i-1] = num[i] + 1;
				//printf("so add to %d(%d) \n", num[i-1], i-1);
			}
		}
		int sum = 0;
		//std::stringstream s1;
		for (int i = 0; i < size; ++i) {
			//s1 << "  ratings:" << ratings[i] <<"  num" << num[i];
			sum += num[i];
		}
		//std::cout << s1.str() << "\n";
		return sum;
	}
};

TEST(testCase,test0) {
	Solution s;
	std::vector<int> ratings_1{1,0,2};
	EXPECT_EQ(s.candy(ratings_1), 5);
	std::vector<int> ratings_2{1,2,2};
	EXPECT_EQ(s.candy(ratings_2), 4);
	std::vector<int> ratings_3{1,2,3,4,5,6,7,8,9,10,11,12,13};
	EXPECT_EQ(s.candy(ratings_3), 91);
	std::vector<int> ratings_4{12,11,10,9,8,7,6,7,8,9,10,11,12,13};
	EXPECT_EQ(s.candy(ratings_4), 63);

}


int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}

