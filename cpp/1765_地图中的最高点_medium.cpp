class Solution {
private:
    vector<int> directions = {-1, 0, 1, 0, -1};
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size(), n = isWater[0].size();
        vector<vector<int>> ans(m, vector<int>(n, -1));
        queue<pair<int, int>> q;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (isWater[i][j]) {
                    ans[i][j] = 0;
                    q.emplace(i, j);
                }
        while (!q.empty()) {
            auto [x, y] = q.front(); q.pop();
            for (int i = 0; i < 4; ++i) {
                int nx = x + directions[i], ny = y + directions[i+1];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && ans[nx][ny] == -1) {
                    ans[nx][ny] = ans[x][y] + 1;
                    q.emplace(nx, ny);
                }
            }
        }
        return ans;
    }
};