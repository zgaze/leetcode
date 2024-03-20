class Solution {
public:
	/*
	 * F(0) = 0，F(1) = 1
	 F(n) = F(n - 1) + F(n - 2)，其中 n > 1
	*/
    int fib(int n) {
			if (n < 2) return n;
			int b0 = 0, b1 = 1; 
			int ret = 0;
			for (int i = 2; i <=n; ++i) {
				ret = b0 + b1;
				b0 = b1;
				b1 = tmp;
			}
			return ret;
    }
};
