class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans;
        ans.push_back(0);
        for (int i = 1; i <= n; ++i) {
            int m = ans.size();
            for (int j = m-1; j >= 0; --j)
                ans.push_back(ans[j] | 1 << (i-1));
        }
        return ans;
    }
};