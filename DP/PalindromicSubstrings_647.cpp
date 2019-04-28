/* ***********************************************************************

  > File Name: PalindromicSubstrings_647.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Wed 24 Apr 2019 04:57:08 PM CST

 ********************************************************************** */

#include <stdio.h>
#include <vector>
#include <string>
#include <stdio.h>
#include <climits>
#include<gtest/gtest.h>

/*
 *
 * 给定一个字符串，你的任务是计算这个字符串中有多少个回文子串。
 *
 * 具有不同开始位置或结束位置的子串，即使是由相同的字符组成，也会被计为是不同的子串。  @提示1
 *
 * 示例 1:
 *
 * 输入: "abc"
 * 输出: 3
 * 解释: 三个回文子串: "a", "b", "c". @提示2
 * 示例 2:
 *
 * 输入: "aaa"
 * 输出: 6
 * 说明: 6个回文子串: "a", "a", "a", "aa", "aa", "aaa".
 * 注意:
 *
 * 输入的字符串长度不会超过1000。
 */

/*
 * 动态规划法：Is[i][j] 为true表示区间i->j为回文。
 * 根据提示2，单个字符串是回文： Is[i][i] = true;
 * 根据提示2，只要区间不同，记为不同子串
 *
 *
 */


using std::vector;
using std::string;

TEST(testCase,test0) {

}


int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}

