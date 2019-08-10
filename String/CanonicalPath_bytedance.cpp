/* ***********************************************************************

  > File Name: CanonicalPath_bytedance.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Mon 05 Aug 2019 04:33:03 PM CST

 ********************************************************************** */

#include <stdio.h>
#include <vector>
#include <string>
#include <stdio.h>
#include <climits>
#include <iostream>
#include <gtest/gtest.h>

using std::vector;
using std::string;

class Solution {
public:
	string simplifyPath(string path) {
		std::vector<string> dirs;
		std::string ret;
		int begin = 1;
		int length = path.length();
		if (path[length-1] != '/') {
			path.append("/");
		}
		for (int i = 1; i <= length; ++i) {
			std::string tmp;
			if (path[i] == '/') {
				std::string tmp = path.substr(begin, i - begin);
				// 
				if (tmp == ".." && !dirs.empty()) {
					dirs.resize(dirs.size() -1);
				} else if (tmp == "." || tmp == "" || tmp == "..") {

				} else {
					dirs.push_back(tmp);
				}
				begin = i + 1;
			}
		}
		std::stringstream res;
		for (auto &s : dirs) {
			res << "/" << s;
		}
		if (dirs.empty()) {
			res << "/";
		}
		std::cout << "res: " << res.str() << "\n";
		return res.str();
	}
};

TEST(testCase,test0) {

}


int main(int argc, char* argv[]) {
	Solution s;
	s.simplifyPath("/a/./b/../../c");
	s.simplifyPath("/..");
	s.simplifyPath("/../");
	s.simplifyPath("/a//b////c/d//././/..");
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}

