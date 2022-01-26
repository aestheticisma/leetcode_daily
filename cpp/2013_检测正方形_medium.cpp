class DetectSquares {
private:
    vector<vector<int>> points;
    vector<vector<int>> directions = {{-1, -1}, {1, -1}, {1, 1}, {-1, 1}};
public:
    DetectSquares() {
        points.resize(1001, vector<int>(1001, 0));
    }
    
    void add(vector<int> point) {
        ++points[point[0]][point[1]];
    }
    
    int count(vector<int> point) {
        int x = point[0], y = point[1];
        int cnt = 0;
        for (int i = 0; i < 4; ++i) {
            int nx = x, ny = y;
            while (1) {
                nx += directions[i][0], ny += directions[i][1];
                if (nx < 0 || nx > 1000 || ny < 0 || ny > 1000) break;
                if (points[nx][y] && points[x][ny] && points[nx][ny])
                    cnt += points[nx][y] * points[x][ny] * points[nx][ny];
            }
        }
        return cnt;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */