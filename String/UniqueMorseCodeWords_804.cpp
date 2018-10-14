/* ***********************************************************************

  > File Name: UniqueMorseCodeWords_804.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Sun 09 Sep 2018 03:01:02 PM CST

 ********************************************************************** */
/*
 * 给定几个单词，看看有几种不同的摩斯密码
 */

#include <vector>
#include <string>
#include <set>


using std::vector;
using std::string;
using std::set;

class Solution {
public:
	int uniqueMorseRepresentations(vector<string>& words) {
		static char* arr[26] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
		std::set<string> unique;
		std::string encode_str;
		for (auto & word: words) {
			encode_str.clear();
			for (auto & c :word) {
				encode_str+= arr[c-'a'];
			}
			unique.insert(encode_str);
		}
		return unique.size();
	}
};


int main()
{
}
