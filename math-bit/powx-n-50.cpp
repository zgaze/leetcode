
class Solution {
public:
    double quickMul(double x, long n) {
			double ans = 1.0;
			double x_contribute = x;
			while (n > 0) {
				if (n % 2 == 1) {
					ans *= x_contribute;
				}
				x_contribute *= x_contribute;
				n /= 2;
			}
			return ans;
    }
		double myPow(double x, int n) {
			double ans = 1.0;
			long long N = n;
			return N >= 0 ? quickMul(x, N) : 1.0 / quickMul(x, -N);
		}
};
