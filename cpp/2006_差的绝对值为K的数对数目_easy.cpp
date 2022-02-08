class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        map<int, int> cnt;
        int ans = 0;
        for (const int & num : nums) {
            int higher = num + k; 
            int lower = num - k;
            ans += cnt.count(higher) ? cnt[higher] : 0;
            ans += cnt.count(lower) ? cnt[lower] : 0;
            ++cnt[num];
        }
        return ans;
    }
};