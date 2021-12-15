class Solution {
private:
    vector<vector<int>> edges;
    vector<int> d;
    vector<int> ans;

public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        ans.resize(n);
        for (int i = 0; i < n; ++i) ans[i] = i;
        edges.resize(n), d.resize(n);
        for (const auto r : richer) {
            edges[r[0]].push_back(r[1]);
            ++d[r[1]];
        }
        queue<int> q;
        for (int i = 0; i < n; ++i) if (!d[i]) q.push(i);
        while (!q.empty()) {
            int now = q.front();
            q.pop();
            for (const int next : edges[now]) {
                if (quiet[ans[now]] < quiet[ans[next]]) ans[next] = ans[now];
                if (--d[next]==0) q.push(next);
            }
        }
        return ans;
    }
};