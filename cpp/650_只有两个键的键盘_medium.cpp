class Solution {
public:
    int minSteps(int n) {
        vector<int> dp(n+1);
        for (int i=2; i<n+1; i++) {
            dp[i] = INT_MAX;
            for (int j=1; j*j <= i; j++) {
                int mod = i % j;
                if (mod == 0) {
                    int x = i / j;
                    dp[i] = min(dp[i], dp[j]+x);
                    dp[i] = min(dp[i], dp[x]+j);
                }
            }
        }
        return dp[n];
    }
};