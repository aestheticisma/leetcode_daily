class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        int ans = 0;
        vector<int> s(n+1);
        for (int i=0; i<n; i++)
            s[i+1] = s[i] ^ arr[i];
        unordered_map<int, int> cnt, total;
        for (int k=0; k<n; k++) {
            if (cnt[s[k+1]])
                ans += cnt[s[k+1]] * k - total[s[k+1]];
            ++cnt[s[k]];
            total[s[k]] += k;
        }
        return ans;
    }
};