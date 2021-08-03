class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int left = -1, right = -1;
        int minn = INT_MAX;
        int maxn = INT_MIN;
        int n = nums.size();
        for (int i=0; i<n; i++) {
            if (maxn > nums[i])
                right = i;
            else
                maxn = nums[i];
            if (minn < nums[n-i-1])
                left = n-i-1;
            else
                minn = nums[n-i-1];
        }
        return right == -1 ? 0 : right-left+1;

    }
};