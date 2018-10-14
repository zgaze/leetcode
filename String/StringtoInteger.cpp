/* ***********************************************************************

  > File Name: StringtoInteger.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Sat 18 Aug 2018 10:13:09 PM CST

 ********************************************************************** */

/*
 * 8. String to Integer (atoi)
 * Implement atoi which converts a string to an integer.
 */
#include <string>
#include <climits>
#include <stdio.h>
class Solution {
public:
  int myAtoi(std::string str) {
    int res = 0;
    bool after_space = false, after_sign = false, minus = false;      
    for (char c : str) {                  
      switch(c) {                         
      case '0' :
      case '1' :
      case '2' :
      case '3' :
      case '4' :
      case '5' :
      case '6' :
      case '7' :
      case '8' :
      case '9' :
        after_space = true;
        after_sign = true;
        if (res >= INT_MAX / 10) {
          if (res > INT_MAX / 10) {
            if (minus) return INT_MIN;
            return INT_MAX;
          }
          if (minus &&  c > '8') return INT_MIN;
          if (!minus && c > '7') return INT_MAX;
          res = res * 10 + c - '0';
          goto Goret;
        }
        res = res * 10 + c - '0';
        break;
      case '+':
      case '-':
        if (after_sign) goto Goret;
        after_space = true;
        after_sign = true;
        if (c == '-') minus = true;
        break;
      case ' ':
        if (after_space) goto Goret;
        break;
      default:
        goto Goret;
        break;
      } 
    } 
Goret:
    if (minus) return 0 - res;
    return res;
  } 
};


int main()
{
	return 0;
}
