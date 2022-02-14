class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return -1;
        else if (n == 1) return nums.back();
        int left = 0, right = n;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == nums[mid ^ 1])
                left = mid + 1;
            else right = mid;
        }
        return left == n ? -1 : nums[left];
    }
};