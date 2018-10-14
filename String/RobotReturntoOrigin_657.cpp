/* ***********************************************************************

  > File Name: RobotReturntoOrigin_657.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Sun 09 Sep 2018 03:25:45 PM CST

 ********************************************************************** */
/*
 * 657. Robot Return to Origin
 *
 * There is a robot starting at position (0, 0), the origin, on a 2D plane. 
 * Given a sequence of its moves, judge if this robot ends up at (0, 0) after it completes its moves.
 * The move sequence is represented by a string, and the character moves[i] represents its ith move. 
 * Valid moves are R (right), L (left), U (up), and D (down). 
 * If the robot returns to the origin after it finishes all of its moves, return true. Otherwise, return false.
 *
 * 在二维平面上，有一个机器人从原点 (0, 0) 开始。
 * 给出它的移动顺序，判断这个机器人在完成移动后是否在 (0, 0) 处结束。
 * 移动顺序由字符串表示。字符 move[i] 表示其第 i 次移动。
 * 机器人的有效动作有 R（右），L（左），U（上）和 D（下）。
 * 如果机器人在完成所有动作后返回原点，则返回 true。否则，返回 false。
 */

#include <string>

using std::string;

class Solution {
public:
	bool judgeCircle(string moves) {
		int cross = 0;
		int vertical = 0;
		for (auto &c : moves) {
			if (c == 'R') cross ++;
			else if (c == 'L') cross --;
			else if (c == 'U') vertical ++;
			else  vertical --;
		}
		return vertical == 0 && cross == 0;
	}
};







