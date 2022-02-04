class Solution {
private:
    int directions[5] = {-1, 0, 1, 0, -1};
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        int m = grid.size(), n = grid[0].size();
        int ans = 0;
        function<void(int, int, int)> dfs = [&](int x, int y, int gold) {
            gold += grid[x][y];
            ans = max(ans, gold);
            int rec = grid[x][y];
            grid[x][y] = 0;
            for (int i = 0; i < 4; ++i) {
                int nx = x + directions[i], ny = y + directions[i+1];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny])
                    dfs(nx, ny, gold);
            }
            grid[x][y] = rec;
        };
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (grid[i][j])
                    dfs(i, j, 0);
        return ans;
    }
};