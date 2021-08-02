class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        const int inf = INT_MAX / 2;
        vector<vector<int>> go(n, vector<int>(n, inf));
        for (auto &time : times) {
            int x = time[0]-1, y = time[1]-1;
            go[x][y] = time[2];
        }
        vector<int> dist(n, inf);
        dist[k-1] = 0;
        vector<int> used(n, false);
        for (int i=0; i<n; i++) {
            int x = -1;
            for (int y=0; y<n; y++)
                if (!used[y] && (x == -1 || dist[y] < dist[x]))
                    x = y;
            used[x] = true;
            for (int y=0; y<n; y++)
                dist[y] = min(dist[y], dist[x] + go[x][y]);
        }
        int ans = *max_element(dist.begin(), dist.end());
        return ans < inf ? ans : -1;

    }
};