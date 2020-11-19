// 降维 动态规划：连续最大子序列和
class Solution {
public:
    vector<int> getMaxMatrix(vector<vector<int>>& matrix) {
        int N = matrix.size();
        int M = matrix[0].size();
        vector<int> dp(M), ans_pos(4);
        int dp_i;
        int ans = INT_MIN, r1=0, c1=0;
        for(int i=0;i<N;i++)
        {
            for(int t=0;t<M;t++) dp[t]=0;
            for(int j=i;j<N;j++)
            {
                dp_i=0;
                for(int k=0;k<M;k++)
                {
                    dp[k]+=matrix[j][k];
                    if(dp_i>0) dp_i+=dp[k];
                    else
                    {
                        dp_i=dp[k];
                        r1=i, c1=k;
                    }
                    if(dp_i>ans)
                    {
                        ans=dp_i;
                        ans_pos[0]=r1, ans_pos[1]=c1, ans_pos[2]=j, ans_pos[3]=k;
                    }
                }
            }
        }
        return ans_pos;
    }
};