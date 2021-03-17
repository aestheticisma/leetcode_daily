class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.length();
        int n = t.length();
        if (m < n) return 0;
        vector<vector<long>> ans(m+1, vector<long>(n+1));
        for (int i=0; i<=m; i++)
            ans[i][n] = 1;
        for (int i=m-1; i>=0; i--)
            for (int j=n-1; j>=0; j--)
                if (s[i] == t[j])
                   ans[i][j] = ans[i+1][j+1] + ans[i+1][j];
                else
                    ans[i][j] = ans[i+1][j];
        return ans[0][0];  
   }
};