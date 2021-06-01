/* ***********************************************************************

  > File Name: LargestNumber_179.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 


 ********************************************************************** */
#include <algorithm>
#include <stdio.h>
#include <vector>
#include <string>
#include <stdio.h>
#include <climits>
#include <gtest/gtest.h>

using std::vector;
using std::string;

class Solution {
public:
	string largestNumber(vector<int>& nums) {
		// 比较 a+b和 b+a 哪个大即可
		std::string ret = "";
		std::sort(nums.begin(), nums.end(), 
			[](const int &num_l,const int &num_r) {
			std::string l = std::to_string(num_l) + std::to_string(num_r);
			std::string r = std::to_string(num_r) + std::to_string(num_l);
			return l > r;}
			);
		for (auto num: nums) {
			ret.append(std::to_string(num));
		}
		if (ret[0] == '0') return "0";
		return ret;
	}
};

class Solution_ERR1 {
public:
    // 比较 a+b和 b+a 哪个大即可
    string largestNumber(vector<int>& nums) {
        // 比较 a+b和 b+a 哪个大即可
        std::sort(nums.begin(), nums.end(),
            [](const int &num_l, const int &num_r) {
                std::string l = std::to_string(num_l) + std::to_string(num_r);
                std::string r = std::to_string(num_r) + std::to_string(num_l);
                int len = l.length();
                for (int i = 0; i < len; ++i) {
				printf("%d vs %d %s, %s, i:%d, %c, %c len:%lu \n",
					num_l, num_r, l.c_str(), r.c_str(), i, l[i] , r[i], l.length());
                    if (l[i] > r[i]) {
                        return true;
                    } else if (l[i] < r[i]) {
                        return false;
                    }
                }
                return false;
            });
        if (nums[0] == 0) {
            return "0";
        }
        std::string ret;
        for (auto num: nums) {
            ret.append(std::to_string(num));
        }
        return ret;
    }
};

TEST(testCase,test0) {
	std::vector<int> a{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	std::vector<int> a1{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	Solution_ERR1 s;
	EXPECT_EQ(true, s.largestNumber(a)=="0");
}


int main(int argc, char* argv[]) {
	testing::InitGoogleTest(&argc,argv);
	return RUN_ALL_TESTS();
}

