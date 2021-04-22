class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m = matrix.size(), n = matrix[0].size();
        int ans = INT_MIN;
        for (int i = 0; i < m; i++) {
            vector<int> d(n);
            for (int j = i; j < m; j++) {
                for (int c = 0; c < n; c++) {
                    d[c] += matrix[j][c];
                }
                set<int> sumSet{0};
                int s = 0;
                for (auto v : d) {
                    s += v;
                    auto lb = sumSet.lower_bound(s-k);
                    if (lb != sumSet.end())
                        ans = max(ans, s - *lb);
                    sumSet.insert(s);
                }
            }
        }
        return ans; 
    }
};