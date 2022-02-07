class Solution {
private:
    unordered_map<int, int> umpR;
    unordered_map<int, int> umpC;
    unordered_map<int, int> umpRC;
    unordered_map<int, int> umpCR;
    unordered_set<long long> points;
    vector<int> ans;
public:
    vector<int> gridIllumination(int n, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        if (queries.empty()) return ans;
        ans.resize(queries.size());
        for (const auto & l : lamps) {
            int r = l[0], c = l[1];
            if (points.count(r * (long long)n + c)) continue;
            ++umpR[r];
            ++umpC[c];
            ++umpRC[r+c];
            ++umpCR[r-c];
            points.insert(r * (long long)n + c);
        }
        for (int i = 0; i < queries.size(); ++i) {
            int r = queries[i][0], c = queries[i][1];
            if (umpR.count(r) && umpR[r] > 0) ans[i] = 1;
            else if (umpC.count(c) && umpC[c] > 0) ans[i] = 1;
            else if (umpRC.count(r+c) && umpRC[r+c] > 0) ans[i] = 1;
            else if (umpCR.count(r-c) && umpCR[r-c] > 0) ans[i] = 1;
            for (int x = r-1; x <= r+1; ++x)
                for (int y = c-1; y <= c+1; ++y) {
                    if (x < 0 || x >= n || y < 0 || y >= n) continue;
                    auto p = points.find(x * (long long)n + y);
                    if (p != points.end()) {
                        points.erase(p);
                        --umpR[x];
                        --umpC[y];
                        --umpRC[x+y];
                        --umpCR[x-y];
                    }
                }
        }
        return ans;
    }
};