class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return {};
        int m = matrix.size(), n = matrix[0].size();
        vector<pair<int, int>> res_min(m, {-1, INT_MAX});
        vector<pair<int, int>> res_max(n, {-1, 0});
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] < res_min[i].second) res_min[i] = {i*n+j, matrix[i][j]};
                if (matrix[i][j] > res_max[j].second) res_max[j] = {i*n+j, matrix[i][j]};
            }
        vector<int> ans;
        for (int i = 0; i < m; ++i) 
            for (int j = 0; j < n; ++j) {
                if (res_min[i].first == res_max[j].first)
                    ans.push_back(res_min[i].second);
            }
        return ans;
    }
};