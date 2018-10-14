/* ***********************************************************************

  > File Name: ToLowerCase_709.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Sun 09 Sep 2018 02:46:20 PM CST

 ********************************************************************** */
/*
 * Implement function ToLowerCase() that has a string parameter str, and returns the same string in lowercase.
 */


#include <string>

using std::string;

class Solution {
public:
	string toLowerCase(string str) {
		for (auto & c : str) {
			if (c >= 'A' && c <= 'Z') {
				c += 33;
			}
		}
		return str;
	}
};

