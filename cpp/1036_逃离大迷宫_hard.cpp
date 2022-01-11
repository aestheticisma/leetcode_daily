class Solution {
private:
    static const int FOUND = 1;
    static const int VALID = 0;
    static const int BLOCKED = -1;

    int directions[5] = {-1, 0, 1, 0, -1};
    static const int BOUNDARY = 1000000;
public:
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        if (blocked.size() < 2) return true;
        auto hash_fn = [fn = hash<long long>()](const pair<int, int> &o) ->size_t {
            auto &[x, y] = o;
            return fn((long long)x << 20 | y);
        };
        unordered_set<pair<int, int>, decltype(hash_fn)> hash_blocked(0, hash_fn);
        for (const auto &block : blocked) hash_blocked.insert({block[0], block[1]});
        auto check = [&](vector<int> &start, vector<int> &end) -> int {
            int sx = start[0], sy = start[1];
            int ex = end[0], ey = end[1];
            int countDown = blocked.size() * (blocked.size() - 1) / 2;
            unordered_set<pair<int, int>, decltype(hash_fn)> visited(0, hash_fn);
            queue<pair<int, int>> q;
            q.push({sx, sy});
            visited.insert({sx, sy});
            while (!q.empty() && countDown > 0) {
                auto [x, y] = q.front(); q.pop();
                for (int i = 0; i < 4; ++i) {
                    int nx = x + directions[i], ny = y + directions[i+1];
                    if (nx >= 0 && nx < BOUNDARY && ny >= 0 && ny < BOUNDARY && !hash_blocked.count({nx, ny}) && !visited.count({nx, ny})) {
                        if (nx == ex && ny == ey) return FOUND;
                        --countDown;
                        q.push({nx, ny});
                        visited.insert({nx, ny});
                    }
                }
            }
            if (countDown > 0) return BLOCKED;
            return VALID;
        };
        if (int result = check(source, target); result == FOUND) return true;
        else if (result == BLOCKED) return false;
        else {
            if (check(target, source) == BLOCKED) return false;
            else return true;
        }
    }
};