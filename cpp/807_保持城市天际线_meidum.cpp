class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        int ans = 0;
        int m = grid.size(), n = grid[0].size();
        vector<int> row(m, 0), col(n, 0);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                col[i] = max(col[i], grid[j][i]);
        for (int i = 0; i < m; ++i) row[i] = *max_element(grid[i].begin(), grid[i].end());
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j) {
                ans += min(col[j], row[i]) - grid[i][j];
            }
        return ans;
    }
};