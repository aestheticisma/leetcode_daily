class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        if (nums.empty()) return 0;
        int n = nums.size();
        int ans = -1, preMin = nums[0];
        for (int i = 1; i < n; ++i) {
            if (nums[i] > preMin)
                ans = max(ans, nums[i] - preMin);
            else
                preMin = nums[i];
        }
        return ans;
    }
};