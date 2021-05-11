class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        int n = encoded.size();
        vector<int> ans(n+1);
        int total = 0;
        for (int i=1; i<=n+1;i++)
            total ^= i;
        for (int i=1; i<n; i+=2)
            ans[0] ^= encoded[i];
        ans[0] ^= total;
        for (int i=1; i<=n; i++)
            ans[i] = ans[i-1] ^ encoded[i-1];
        return ans;
    }
};