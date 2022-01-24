class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int>> graph(n+1);
        for (const auto & e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        vector<vector<int>> path(n+1, vector<int>(2, INT_MAX));
        path[1][0] = 0;
        queue<pair<int, int>> q;
        q.emplace(1, 0);
        while (path[n][1] == INT_MAX) {
            auto [cur, len] = q.front(); q.pop();
            for (const int &next: graph[cur]) {
                if (len + 1 < path[next][0]) {
                    path[next][0] = len + 1;
                    q.emplace(next, len+1);
                }
                else if ((len + 1 > path[next][0]) && (len + 1 < path[next][1])) {
                    path[next][1] = len + 1;
                    q.emplace(next, len+1);
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < path[n][1]; ++i) {
            int mod = ans % (2 * change);
            if (mod >= change)
                ans += 2 * change - mod;
            ans += time;
        }
        return ans;
    }
};