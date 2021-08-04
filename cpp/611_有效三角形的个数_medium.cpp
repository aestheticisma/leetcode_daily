class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = 0;
        for (int i=0; i<n-2; i++) {
            int k = i+1;
            for (int j=i+1; j<n-1; j++) {
                while (k+1 < n && nums[k+1] < nums[i] + nums[j])
                    ++k;
                ans += max(k-j, 0);
            }
        }
        return ans;
    }
};