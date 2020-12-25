class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty())
            return 0;
        int ans = 0;
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<vector<vector<int>>> dp(rows, vector<vector<int>>(cols, {0, 0, 0}));
        for(int i=0; i<rows; i++)
            for(int j=0; j<cols; j++)
                if(matrix[i][j] == '1'){
                    if(i==0 && j==0){
                        dp[i][j][0] = 1;
                        dp[i][j][1] = 1;
                        dp[i][j][2] = 1;
                    }
                    else if(i==0){
                        dp[i][j][0] = dp[i][j-1][0] + 1;
                        dp[i][j][1] = 1;
                        dp[i][j][2] = dp[i][j-1][2] + 1;
                    }
                    else if(j==0){
                        dp[i][j][0] = 1;
                        dp[i][j][1] = dp[i-1][j][1] + 1;
                        dp[i][j][2] = dp[i-1][j][2] + 1;
                    }
                    else{
                        dp[i][j][0] = dp[i][j-1][0] + 1;
                        dp[i][j][1] = dp[i-1][j][1] + 1;
                        int _cols_min = dp[i][j][0];
                        for(int k=0; k< dp[i][j][1]; k++){
                            _cols_min = min(_cols_min, dp[i-k][j][0]);
                            dp[i][j][2] = max(dp[i][j][2], _cols_min*(k+1));
                        }
                    }
                    ans = max(ans, dp[i][j][2]);
                }
        // return 1;
        return ans;
    }
};