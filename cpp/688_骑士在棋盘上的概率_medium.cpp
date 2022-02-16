class Solution {
    int dires[8][2] = {{-2, -1}, {2, -1}, {2, 1}, {-2, 1},
                       {-1, -2}, {-1, 2}, {1, 2}, {1, -2}};
public:
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<vector<double>>> dp(k+1, vector<vector<double>>(n, vector<double>(n, 0)));
        for (int i = 0; i <= k; ++i)
            for (int j = 0; j < n; ++j)
                for (int k = 0; k < n; ++k) {
                    if (i == 0) dp[i][j][k] = 1;
                    else {
                        for (const auto d : dires) {
                            int nj = j + d[0], nk = k + d[1];
                            if (nj >= 0 && nj < n && nk >= 0 && nk < n)
                                dp[i][j][k] += dp[i-1][nj][nk] / 8;
                        }
                    }
                }
        return dp[k][row][column];
    }
};