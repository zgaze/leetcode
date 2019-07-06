/* ***********************************************************************

  > File Name: BaseballGame_682.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Fri 05 Jul 2019 02:16:33 PM CST

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
 * 你现在是棒球比赛记录员。
 * 给定一个字符串列表，每个字符串可以是以下四种类型之一：
 * 1.整数（一轮的得分）：直接表示您在本轮中获得的积分数。
 * 2. "+"（一轮的得分）：表示本轮获得的得分是前两轮有效 回合得分的总和。
 * 3. "D"（一轮的得分）：表示本轮获得的得分是前一轮有效 回合得分的两倍。
 * 4. "C"（一个操作，这不是一个回合的分数）：表示您获得的最后一个有效 回合的分数是无效的，应该被移除。
 *
 * 每一轮的操作都是永久性的，可能会对前一轮和后一轮产生影响。
 * 你需要返回你在所有回合中得分的总和。
 *
 */
class Solution {
public:
	int calPoints(vector<string>& ops) {
		std::vector<int> st; // 假装是栈
		for (auto s : ops) {
			if (s == "+") {
				int len = st.size();
				int score = 0;
				if (len > 2) {
					score = st[len-1] + st[len-2];
				} else {
					for (int i = 0; i < len; ++i) {
						score += st[i];
					}
				}
				st.push_back(score);
			} else if (s == "C") {
				if (!st.empty()) {
					st.pop_back();
				}
			} else if (s == "D") {
				int score = 2 *(st.empty() ? 0 : st.back());
				st.push_back(score);
			} else {
				int score = std::stoi(s);
				st.push_back(score);
			}
		}
		int ret = 0;
		for (int score : st) {
			ret += score;
		}
		return ret;
	}
};


TEST(testCase,test0) {
	std::vector<string> s1{"5","2","C","D","+"};
	std::vector<string> s2{"5","-2","4","C","D","9","+","+"};
	Solution s;
	//EXPECT_EQ(s.calPoints(s1), 30);
	EXPECT_EQ(s.calPoints(s2), 27);
}


int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}

