class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        queue<tuple<int, int, int>> q;
        vector<vector<bool>> seen(n, vector<bool>(1<<n));
        int ans = 0;
        for (int i=0; i<n; i++) {
            q.emplace(i, 1<<i, 0);
            seen[i][1<<i] = true;
        }
        while (!q.empty()) {
            auto [u, mask, dist] = q.front();
            q.pop();
            if (mask == (1<<n) - 1) {
                ans = dist;
                break;
            }
            for (auto v : graph[u]) {
                int mask_v = mask | 1<<v;
                if (!seen[v][mask_v]) {
                    q.emplace(v, mask_v, dist+1);
                    seen[v][mask_v] = true;
                }
            }
        }
        return ans;
    }
};