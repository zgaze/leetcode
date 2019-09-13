/* ***********************************************************************

  > File Name: RestoreIPAddresses_93.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 


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
 * 给定一个只包含数字的字符串，复原它并返回所有可能的 IP 地址格式。
 *
 * 示例:
 *
 * 输入: "25525511135"
 * 输出: ["255.255.11.135", "255.255.111.35"]
 *
 */

class Solution {
public:
	vector<string> res;
	string tmp;
	bool isvaild(std::string &s, int begin, int end) { // 左闭右闭
		if (end - begin <= 2 && end - begin >= 0) {
			std::string subs = s.substr(begin, end-begin+1);
			int num = stoi(subs);
			if (num >= 0 && num <= 255) {
				// std::cout << subs << " is ok  \n";
				return true;
			}
		}
		return false;
	}
	void Place(std::string &s, vector<int> &path) {
		tmp.clear();
		tmp.resize(s.length() + 3, '.');
		int x = 0;
		for (int i = 0, j = 0; i < (int)s.length() || x < (int)path.size(); ++j) {
			if (x < (int)path.size() && i == path[x] + 1) {
				tmp[j] ='.';
				x ++;
			} else {
				tmp[j] = s[i];
				++i;
			}
		}
		res.push_back(tmp);
		std::cout << tmp << "\n";
	}

	void backtrack(string &s, vector<int> &path, int now) {
		for (int i = now; i < (int)s.length(); ++i) {
			int begin = path.empty() ? -1 : path.back();
			if (isvaild(s, begin + 1, i)) {
				path.push_back(i);
				if (path.size() == 3) {
					if (isvaild(s, i+1, s.length()-1)) { 
						Place(s, path);
					} 
				} else {
					backtrack(s, path, i + 1);
				}
				path.pop_back();
			}
		}
	}

	vector<string> restoreIpAddresses(string s) {
		if (s.length() < 4 || s.length() > 12) {
			return res;
		}
		vector<int> path;
		backtrack(s, path, 0);
		return res;
	}
};


TEST(testCase,test0) {

}


int main(int argc, char* argv[]) {
	Solution s;
	std::string s1 = "25525511135";
	std::string s2= "123456789";
	std::string s3 = "1234567890";
	std::string s4 = "255255255255";
	//std::vector<int> path{3, 6, 8};
	// s.Place(s1, path);
	s.restoreIpAddresses(s1);
	s.restoreIpAddresses(s2);
	s.restoreIpAddresses(s3);
	s.restoreIpAddresses(s4);
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}

