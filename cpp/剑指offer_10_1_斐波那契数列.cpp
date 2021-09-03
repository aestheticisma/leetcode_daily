class Solution {
public:
    int fib(int n) {
        const int MOD = 1000000007;
        if (n < 2)
            return n;
        int x = 0, y = 0, z = 1;
        for (int i=2; i<n+1; i++) {
            x = y;
            y = z;
            z = (x + y) % MOD;
        }
        return z;
    }
};