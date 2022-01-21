class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if (n < 2) return 0;
        unordered_map<int, vector<int>> sameSubGraph;
        for (int i = 0; i < n; ++i)
            sameSubGraph[arr[i]].push_back(i);
        unordered_set<int> visitedIdx;
        queue<pair<int, int>> q;
        q.emplace(0, 0);
        visitedIdx.emplace(0);
        while (!q.empty()) {
            auto [idx, step] = q.front(); q.pop();
            if (idx == n-1) return step;
            ++step;
            if (sameSubGraph.count(arr[idx])) {
                for (const int &next : sameSubGraph[arr[idx]]) {
                    if (!visitedIdx.count(next)) {
                        q.emplace(next, step);
                        visitedIdx.emplace(next);
                    }
                }
                sameSubGraph.erase(arr[idx]);
            }
            if (idx + 1 < n && !visitedIdx.count(idx + 1)) {
                q.emplace(idx+1, step);
                visitedIdx.emplace(idx+1);
            }
            if (idx - 1 >=0 && !visitedIdx.count(idx - 1)) {
                q.emplace(idx-1, step);
                visitedIdx.emplace(idx-1);
            }
        }
        return -1;
    }
};