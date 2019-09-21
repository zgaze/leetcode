/* ***********************************************************************

  > File Name: RussianDollEnvelopes_354.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 


 ********************************************************************** */

#include <stdio.h>
#include <vector>
#include <string>
#include <stdio.h>
#include <climits>
#include <gtest/gtest.h>
#include <algorithm>

using std::vector;
using std::string;

/*
 * 354. 俄罗斯套娃信封问题
 * 给定一些标记了宽度和高度的信封，宽度和高度以整数对形式 (w, h) 出现。当另一个信封的宽度和高度都比这个信封大的时候，这个信封就可以放进另一个信封里，如同俄罗斯套娃一样。
 *
 * 请计算最多能有多少个信封能组成一组“俄罗斯套娃”信封（即可以把一个信封放到另一个信封里面）。
 *
 * 说明:
 * 不允许旋转信封。
 *
 * 示例:
 *
 * 输入: envelopes = [[5,4],[6,4],[6,7],[2,3]]
 * 输出: 3 
 * 解释: 最多信封的个数为 3, 组合为: [2,3] => [5,4] => [6,7]。
 *
 *
 */
class Solution {
public:
    static bool myf(vector<int>& l, vector<int> &r) {
        if (l[0] == r[0]) return l[1] > r[1];
        return l[0] < r[0];
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        // 排序
        std::sort(envelopes.begin(), envelopes.end(), myf);
        // 问题降维, 变成对h 求上升子序列，即求envelopes[i][1]的最长上升子序列的长度
        int size = envelopes.size();
        if (size <= 1) {
            return size;
        }
        std::vector<int> dp(size, 0);
        int len = 0;
        for (auto e : envelopes) {
            auto it = lower_bound(dp.begin(), dp.begin() + len, e[1]);
	        *it = e[1];
            if (it - dp.begin() == len) {
                len ++;
            }
        }
        return len;
    }
};

TEST(testCase,test0) {
	Solution s;
	std::vector<vector<int>> s1{{5,4}, {6,4}, {6,7}, {2,3}, {1,1}};
	EXPECT_EQ(s.maxEnvelopes(s1), 4);
}


int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}

