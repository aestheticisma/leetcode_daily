class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n);
        if (!n) return matrix;
        for (int i=0; i<n; i++) matrix[i].resize(n);
        int t = 0;
        int b = n-1;
        int l = 0;
        int r = n-1;
        int v = 1;
        while (1) {
            for (int i=l; i<=r; i++) matrix[t][i] = v++;
            if (++t>b) break;
            for (int i=t; i<=b; i++) matrix[i][r] = v++;
            if (--r<l) break;
            for (int i=r; i>=l; i--) matrix[b][i] = v++;
            if (--b < t) break;
            for (int i=b; i>=t; i--) matrix[i][l] = v++;
            if (++l>r) break;
        }
        return matrix;
    }
};