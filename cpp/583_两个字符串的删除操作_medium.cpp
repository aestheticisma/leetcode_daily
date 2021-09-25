class Solution {
public:
    int minDistance(string word1, string word2) {
        const int m = word1.length();
        const int n = word2.length();
        int dp[m+1][n+1];
        int maxLen = 0;
        for (int i=0; i<=m; i++)
            for (int j=0; j<=n; j++) {
                if (i == 0 || j == 0)
                    dp[i][j] = 0;
                else {
                    if (word1[i-1] == word2[j-1])
                        dp[i][j] = dp[i-1][j-1] + 1;
                    else
                        dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
                }
            }
        return m-dp[m][n] + n-dp[m][n];
    }
};