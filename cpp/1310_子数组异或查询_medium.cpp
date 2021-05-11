class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = queries.size();
        int m = arr.size();
        vector<int> ans(n);
        vector<int> dict(m+1, 0);
        for (int i=1; i<m+1; i++)
            dict[i] = arr[i-1] ^ dict[i-1];
        for (int i=0; i<n; i++)
            ans[i] = dict[queries[i][0]] ^ dict[queries[i][1]+1];
        return ans;
    }
};