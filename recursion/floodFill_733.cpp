/* ***********************************************************************

  > File Name: floodFill_733.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Thu 08 Aug 2019 10:55:33 AM CST

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
 * 二维矩阵 图像渲染问题
 *
 */

/*
 *
 * 有一幅以二维整数数组表示的图画，每一个整数表示该图画的像素值大小，数值在 0 到 65535 之间。
 *
 * 给你一个坐标 (sr, sc) 表示图像渲染开始的像素值（行 ，列）和一个新的颜色值 newColor，让你重新上色这幅图像。
 *
 * 为了完成上色工作，从初始坐标开始，记录初始坐标的上下左右四个方向上像素值与初始坐标相同的相连像素点，接着再记录这四个方向上符合条件的像素点与他们对应四个方向上像素值与初始坐标相同的相连像素点，……，重复该过程。将所有有记录的像素点的颜色值改为新的颜色值。
 *
 * 最后返回经过上色渲染后的图像。
 *
 * 示例 1:
 *
 * 输入: 
 * image = [[1,1,1],[1,1,0],[1,0,1]]
 * sr = 1, sc = 1, newColor = 2
 * 输出: [[2,2,2],[2,2,0],[2,0,1]]
 * 解析: 
 * 在图像的正中间，(坐标(sr,sc)=(1,1)),
 * 在路径上所有符合条件的像素点的颜色都被更改成2。
 * 注意，右下角的像素没有更改为2，
 * 因为它不是在上下左右四个方向上与初始点相连的像素点。
 *
 */

class Solution {
public:
	void Fill(vector<vector<int>>& image, int sr, int sc, int newColor, int originColor) {
		if (sr < 0 || sr >= (int)image.size()) return;
		if (sc < 0 || sc >= (int)image[0].size()) return;
		if (image[sr][sc] != originColor) return;
		image[sr][sc] = newColor;
		Fill(image, sr - 1, sc, newColor, originColor);
		Fill(image, sr + 1, sc, newColor, originColor);
		Fill(image, sr, sc - 1, newColor, originColor);
		Fill(image, sr, sc + 1, newColor, originColor);
	}
	vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
		int originColor = image[sr][sc];
		if (newColor == originColor) {
			return image;
		}
		Fill(image, sr, sc, newColor, originColor);
		return image;
	}
};


TEST(testCase,test0) {

}


int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}

