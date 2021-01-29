class Dist {
public: 
    int x, y, h;
public:
    Dist (int _x, int _y, int _h): x(_x), y(_y), h(_h){}
    bool operator < (const Dist &that) const {
        return h > that.h;
    }
};

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size();
        int columns = heights[0].size();
        priority_queue <Dist> q;
        vector<bool> seen(rows*columns, false);
        vector<int> dist(rows*columns, INT_MAX);
        dist[0] = 0;
        q.emplace(0, 0, 0);
        vector<vector<int>> directions = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
        while (!q.empty()) {
            auto [x, y, h] = q.top();
            q.pop();
            int id = x*columns+y;
            if (seen[id])
                continue;
            if (x == rows-1 && y == columns-1)
                break;
            seen[id] = true;
            for(int i=0; i<4; i++){
                int nx = x+directions[i][0];
                int ny = y+directions[i][1];
                if (nx>=0 && nx<rows && ny>=0 && ny<columns && max(h, abs(heights[nx][ny]-heights[x][y]))<=dist[nx*columns+ny]){
                    dist[nx*columns+ny] = max(h, abs(heights[nx][ny]-heights[x][y]));
                    q.emplace(nx, ny, dist[nx*columns+ny]);
                }
            }
        }
        return dist[rows*columns-1];
    }
};