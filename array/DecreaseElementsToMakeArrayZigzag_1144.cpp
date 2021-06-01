/* ***********************************************************************

  > File Name: DecreaseElementsToMakeArrayZigzag_1144.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Tue 06 Aug 2019 10:25:21 AM CST

 ********************************************************************** */

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
	int movesToMakeZigzag(vector<int>& nums) {
		int length = nums.size();
		int resa = 0, resb = 0;
		for (int i = 0; 2 * i + 1 < length; ++i) {
			int x = 2 * i + 1;
			if (x + 1 < length) {
			}
		}
		return std::min(resa, resb);
	}
};

using std::min;
class Solution_e {
public:
	int movesToMakeZigzag(vector<int>& nums) {
		int n1=0,n2=0;
		for(int i=0;i<nums.size();i+=2){
			int t=INT_MAX;
			if(i+1<nums.size()) t=min(t,nums[i+1]);
			if(i-1>=0) t=min(t,nums[i-1]);
			if(nums[i]>=t)
				n1+=nums[i]-t+1;
		}
		for(int i=1;i<nums.size();i+=2){
			int t=nums[i-1];
			if(i+1<nums.size()){
				t=min(t,nums[i+1]);
			}
			if(nums[i]>=t)
				n2+=nums[i]-t+1;
		}
		return min(n1,n2);
	}
};

TEST(testCase,test0) {
	//Solution s;
	//vector<int> nums1{9,6,1,6,2};
	//EXPECT_EQ(s.movesToMakeZigzag(nums1), 4);
	//vector<int> nums2{2,7,10,9,8,9};
	//EXPECT_EQ(s.movesToMakeZigzag(nums2), 4);
	//vector<int> nums3{2,1,2};
	//EXPECT_EQ(s.movesToMakeZigzag(nums3), 0);
	Solution_e sa;
	vector<int> nums4{5,1,5,7};
	EXPECT_EQ(sa.movesToMakeZigzag(nums4), 3);

}


int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}

