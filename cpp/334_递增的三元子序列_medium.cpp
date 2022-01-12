// 两次遍历
// 时间复杂度 O(n), 空间复杂度 O(n)
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return false;
        vector<int> leftMin(n);
        leftMin[0] = nums[0];
        for (int i = 1; i < n; ++i) leftMin[i] = min(leftMin[i-1], nums[i]);
        vector<int> rightMax(n);
        rightMax[n-1] = nums[n-1];
        for (int i = n-2; i >= 0; --i) rightMax[i] = max(rightMax[i+1], nums[i]);
        for (int i = 1; i < n-1; ++i)
            if (nums[i] > leftMin[i-1] && nums[i] < rightMax[i+1])
                return true;
        return false;
    }
};

// 贪心
// 时间复杂度 O(n), 空间复杂度 O(1)
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return false;
        int first = nums[0], second = INT_MAX;
        for (int i = 1; i < n; ++i)
            if (nums[i] > second) return true;
            else if (nums[i] > first) second = nums[i];
            else first = nums[i];
        return false;
    }
};

// 通用解法
// 参考 No.300 贪心 + 二分
// 时间复杂度 O(nlogn), 空间复杂度 O(n)
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return false;
        vector<int> dp;
        dp.push_back(nums[0]);
        for (int i = 1; i < n; ++i)
            if (dp.back() < nums[i]) dp.push_back(nums[i]);
            else {
                auto iter = lower_bound(dp.begin(), dp.end(), nums[i]);
                *iter = nums[i];
            }
            if (dp.size() >= 3) return true;
        return false;
    }
};