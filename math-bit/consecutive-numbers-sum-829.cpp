// 给定一个正整数 n，返回 连续正整数满足所有数字之和为 n 的组数 。 
/*
  示例 1:
	输入: n = 5
	输出: 2
	解释: 5 = 2 + 3，共有两组连续整数([5],[2,3])求和后为 5。
*/



class Solution {
public:
	  // 区间求和问题
		// 求和公式：((x+x+k-1)*k)/2 = n
		// (2x+k-1)*k=2n
		// 2xk +k^2-k = 2n
		// 2x=2n/k - k +1
		// 因为 x和k都是正整数
		// 2x = 2n/k -k + 1 >=2 (x大于等于1)
		// 2n/k >= k + 1
		// 2n/k > k
		// 2n > k*k
		int consecutiveNumbersSum(int n) {
        int ans = 0;
        n *= 2;
        for (int i = 1; i * i < n; ++i) {
            if (n % i != 0) continue;
            if ((n / i - (i - 1)) % 2 == 0)
                ans++;
        }
        return ans;
    }
}
