class Solution {
public:
    double new21Game(int N, int K, int W) {
        if(K==0)
            return 1.0;
        vector<double> dp(K+W, 0.0);
        for(int i=K; i<=min(N, (K+W-1)); i++)
            dp[i] = 1.0;
        dp[K-1] = (min(N, K+W-1)-K+1)*1.0/W;
        for(int i=K-2; i>-1; i--)
            dp[i] = dp[i+1] - (dp[i+W+1] - dp[i+1])/W;
        return dp[0];
    }
};