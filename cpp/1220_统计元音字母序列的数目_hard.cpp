class Solution {
private:
    const long long MOD = 1e9 + 7;
    /*
    0 a: e, i, u    1 2 4
    1 e: a, i       0 2
    2 i: e, o       1 3
    3 o: i          2
    4 u: i, o       2 3
    */
public:
    int countVowelPermutation(int n) {
        if (n == 1) return 5;
        vector<long long> dp(5, 1);
        vector<long long> ndp(5);
        for (int i = 2; i <= n; ++i) {
            ndp[0] = (dp[1] + dp[2] + dp[4]) % MOD;
            ndp[1] = (dp[0] + dp[2]) % MOD;
            ndp[2] = (dp[1] + dp[3]) % MOD;
            ndp[3] = dp[2];
            ndp[4] = (dp[2] + dp[3]) % MOD;
            dp = ndp;
        }
        return accumulate(dp.begin(), dp.end(), 0LL) % MOD;
    }
};