class Solution {
public:
    int subRob(vector<int> &nums, int start, int end) {
        int first = nums[start], second = max(nums[start], nums[start+1]);
        for (int i=start+2; i<=end; i++) {
            int tmp = second;
            second = max(first+nums[i], second);
            first = tmp;
        }
        return second;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);
        return max(subRob(nums, 0, n-2), subRob(nums, 1, n-1));
    }
};