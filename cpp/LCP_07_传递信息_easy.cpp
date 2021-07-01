class Solution {
private:
    vector<vector<int>> graph;
    int ways = 0;
    int _n;
    int _k;
public:
    int numWays(int n, vector<vector<int>>& relation, int k) {
        graph.resize(n);
        for (auto r: relation)
            graph[r[0]].push_back(r[1]);
        _n = n;
        _k = k;
        dfs(0, 0);
        return ways;
    }
    void dfs(int index, int step) {
        if (step == _k) {
            if (index == _n-1)
                ways++;
            return;
        }
        for (auto to : graph[index])
            dfs(to, step+1);
    }
};