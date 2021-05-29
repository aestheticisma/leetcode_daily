class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int ans = 0;
        for (int i = 0; i < m; i++) {
            vector<int> data(n);
            for (int j = i; j < m; j++) {
                for (int c = 0; c < n; c++)
                    data[c] += matrix[j][c];
                ans += subArray(data, target);
            }
        }
        return ans;
    }
    int subArray(vector<int> &matrix, int k) {
        unordered_map<int, int> cnt;
        cnt[0] = 1;
        int pre = 0, ans = 0;
        for (auto m : matrix) {
            pre += m;
            if (cnt.find(pre-k) != cnt.end())
                ans += cnt[pre-k];
            cnt[pre]++;
        }
        return ans;
    }
};