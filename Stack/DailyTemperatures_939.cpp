/* ***********************************************************************

  > File Name: DailyTemperatures_939.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Tue 09 Jul 2019 04:35:08 PM CST

 ********************************************************************** */

#include <stdio.h>
#include <vector>
#include <string>
#include <stdio.h>
#include <climits>
#include <stack>
#include <sys/time.h>
#include <gtest/gtest.h>

using std::vector;
using std::string;
using std::stack;

/*
 *
 * 739. 每日温度
 * 根据每日 气温 列表，请重新生成一个列表，对应位置的输入是你需要再等待多久温度才会升高超过该日的天数。如果之后都不会升高，请在该位置用 0 来代替。
 *
 * 例如，给定一个列表 temperatures = [73, 74, 75, 71, 69, 72, 76, 73]，你的输出应该是 [1, 1, 4, 2, 1, 1, 0, 0]。
 *
 * 提示：气温 列表长度的范围是 [1, 30000]。每个气温的值的均为华氏度，都是在 [30, 100] 范围内的整数。
 *
 */


/*
 * 单调栈：下一个更大问题
 *
 */

class Solution {
public:
	vector<int> dailyTemperatures(vector<int>& T) {
		stack<int> st;
		vector<int> ret;
		int len = T.size();
		ret.reserve(len);
		for (int i = len; i >=0; --i) {
			while (!st.empty() && T[i] >= st.top()) {
				st.pop(); // 小的从栈里滚开
			}
			ret[i] = st.empty() ? 0 : st.top();
			st.push(T[i]);
		}
		return ret;
	}
};


TEST(testCase,test0) {
	Solution s;
}


int main(int argc, char* argv[]) {
	struct timeval tv;
	gettimeofday(&tv, NULL);
	printf("%ld, %ld\n", tv.tv_sec, tv.tv_usec);
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}

