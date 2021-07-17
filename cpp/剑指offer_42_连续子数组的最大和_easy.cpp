class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = INT_MIN, pre = 0;
        for (auto & num : nums) {
            pre = max(pre + num, num);
            ans = max(ans, pre);
        }
        return ans;
    }
};