class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        int m = A.size(), n = A[0].size();
        int ans = m*(1<<(n-1));
        for(int j=1; j<n; j++){
            int nCount = 0;
            for(int i=0; i<m; i++)
                if(A[i][0]==1)
                    nCount += A[i][j];
                else
                    nCount += (1-A[i][j]);
            int k = max(nCount, m-nCount);
            ans += k*(1<<(n-j-1));
        }
        return ans;
    }
};