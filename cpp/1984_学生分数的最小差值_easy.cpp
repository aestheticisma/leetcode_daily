class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();
        if (n < 2 || k < 2) return 0;
        sort(nums.begin(), nums.end());
        int ans = nums[n-1] - nums[0];
        for (int i = 0; i + k - 1 < n; ++i) {
            ans = min(ans, nums[i+k-1] - nums[i]);
        }
        return ans;
    }
};