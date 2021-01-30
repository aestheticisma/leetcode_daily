class Dist {
public:
    int h, x, y;
    Dist(int _h, int _x, int _y): h(_h), x(_x), y(_y) {}
    bool operator < (const Dist &that) const {
        return h > that.h;
    }
};
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int rows = grid.size();
        int columns = grid[0].size();
        vector<bool> seen(rows*columns);
        int ans = 0;
        vector<vector<int>> directions = {
            {0, 1},
            {1, 0},
            {0, -1},
            {-1, 0}
        };
        priority_queue <Dist> q;
        q.emplace(grid[0][0], 0, 0);
        while (!q.empty()) {
            auto [t, x, y] = q.top();
            q.pop();
            int id = x*columns+y;
            if (seen[id])
                continue;
            ans = max(ans, t);
            if (x == rows-1 && y == columns-1)
                break;
            seen[id] = true;
            for (int i=0; i<4; i++) {
                int nx = x + directions[i][0];
                int ny = y + directions[i][1];
                if (nx>=0&&nx<rows && ny>=0&&ny<columns && !seen[nx*columns+ny])
                    q.emplace(grid[nx][ny], nx, ny);
            }
        }
        return ans;
    }
};