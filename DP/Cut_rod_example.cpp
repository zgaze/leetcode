/* ***********************************************************************

  > File Name: Cut_rod_example.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Sun 03 Mar 2019 03:17:27 PM CST

 ********************************************************************** */

/*
 * 不同长度的钢条，具有不同的价值，而切割工序没有成本支出，公司管理层希望知道最佳切割方案.
 * 假定钢条的长度均为整数：用数组v[I]表示钢条长度为I所具有的价值v[] = {0,1,5,8,9,10,17,17,20,24,30};用r[I]表示长度为I的钢条能获取的最大价值。
 */


#include<bits/stdc++.h>

int cut_rod(std::vector<int>& v) {
	int length = v.size();
	int r[length] = {0};
	for (int i = 0; i < length; ++i) {
		int profit = 0;
		for (int j = 1; j <= i; ++j) {
			profit = std::max(profit, v[j] + r[i - j]);
		}
		r[i] = profit;
		printf("%d %d\n", i, r[i]);
	}
	return r[length-1];
}

int main()
{
	std::vector<int> a{0,1,5,8,9,10,17,17,20};
	//std::vector<int> a{0,1,5,8,9,10,17,17,20,24,30};
	int max = cut_rod(a);
	printf("max is %d\n", max);
	return 0;
}
