class Solution {
private:
    int MOD = 1337;
public:
    int superPow(int a, vector<int>& b) {
        int n = b.size();
        return dfs(a, b, n-1);
    }
    int dfs(int a, vector<int> &b, int i) {
        if (i == -1) return 1;
        return qpow(dfs(a, b, i-1), 10) * qpow(a, b[i]) % MOD;
    }
    // 快速幂
    int qpow(int a, int b) {
        int ans = 1;
        a %= MOD;
        while (b != 0) {
            if (b & 1) ans = ans * a % MOD;
            a = a * a % MOD;
            b >>= 1;
        }
        return ans;
    }
};