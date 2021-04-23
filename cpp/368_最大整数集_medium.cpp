class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        if (n==1) return {nums[0]};
        sort(nums.begin(), nums.end());
        vector<int> dp(n, 1);
        int maxVal = nums[0];
        int maxSize = 1;
        for (int i=1; i<n; i++) {
            for (int j=0; j<i; j++)
                if (nums[i] % nums[j] == 0)
                    dp[i] = max(dp[i], dp[j]+1);
            if (dp[i] > maxSize) {
                maxSize = dp[i];
                maxVal = nums[i];
            }
        }
        vector<int> res;
        for (int i=n-1; i>=0 && maxSize; i--)
            if (dp[i] == maxSize && maxVal % nums[i] == 0) {
                res.push_back(nums[i]);
                maxSize--;
                maxVal = nums[i];
            }
        return res;
    }
};