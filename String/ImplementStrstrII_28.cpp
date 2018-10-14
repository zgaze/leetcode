/* ***********************************************************************

  > File Name: strStr_1.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Sat 08 Sep 2018 03:11:58 PM CST

 ********************************************************************** */

#include <stdio.h>
#include <iostream>
#include <string>
using std::string;

static const auto __ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int* computePrefixArray(string pattern) {
        int *prefixArr = new int[pattern.length()];

        int border = 0;
        prefixArr[0] = 0;

        for (int i = 1; i < pattern.length(); i++) {
            while (border > 0 && pattern[i] != pattern[border])
                border = prefixArr[border - 1];

            if (border == 0) {
                border = pattern[i] == pattern[0] ? 1 : 0;
            }
            else {
                border = border + 1;
            }

            prefixArr[i] = border;
						printf("%d %d ", i, prefixArr[i]);
        }
				printf("\n");
        return prefixArr;
    }

    int strStr(string text, string pattern) {
        if (text.length() == 0 && pattern.length() == 0)
            return 0;

        if (pattern.length() == 0)
            return 0;

        // compute prefix Array
        int* prefixArr = computePrefixArray(pattern);
				for (int i = 0; i < pattern.length(); ++i) 
				{
					printf("%d %d  ->", i, prefixArr[i]);
				}
				printf("\n");
        int i = 0, border = 0;
        int foundIdx = -1;

        while (i < text.length()) {
            if (text[i] == pattern[border]) {
                border = border + 1;

                if (border == pattern.length()) {
                    // Found pattern in text, return index
                    foundIdx = (i - pattern.length() + 1);
                    break;
                }
            }
            else {
                if (border > 0) {
                    border = prefixArr[border - 1];
                    continue;
                }
            }

            i++;
        }

        delete prefixArr;
        prefixArr = NULL;

        return foundIdx;
    }
};

int main()
{
	Solution a;
	string s1 = "hello", s2 = "ll";
	int slen = a.strStr(s1, s2);
	printf("%d\n", slen);
	return 0;
}

