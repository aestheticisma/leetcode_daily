#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
private:
    unordered_set<int> s;
    int directions[5] = {-1, 0, 1, 0, -1};
    int m, n;
public:
    int numEnclaves(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        m = grid.size(), n = grid[0].size();
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            dfs(grid, i, 0);
            dfs(grid, i, n-1);
        }
        for (int j = 1; j < n-1; ++j) {
            dfs(grid, 0, j);
            dfs(grid, m-1, j);
        }
        for (int i = 1; i < m-1; ++i)
            for (int j = 1; j < n-1; ++j)
                if (grid[i][j] == 1 && !s.count(i * n + j))
                    ++ans;
        return ans;
    }
    void dfs(vector<vector<int>> &grid, int r, int c) {
        if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] == 0 || s.count(r*n+c)) return;
        s.insert(r * n + c);
        for (int i = 0; i < 4; ++i) dfs(grid, r + directions[i], c + directions[i+1]);
    }
};