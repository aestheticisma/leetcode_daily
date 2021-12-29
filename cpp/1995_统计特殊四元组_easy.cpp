// hash 存储 nums[d]
class Solution {
public:
    int countQuadruplets(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        unordered_map<int, int> cnt;
        for (int c = n-2; c >= 2; --c) {
            ++cnt[nums[c+1]];
            for (int a = 0; a < c; ++a)
                for (int b = a+1; b < c; ++b) {
                    int sum = nums[a] + nums[b] + nums[c];
                    if (cnt.count(sum)) ans += cnt[sum];
                }
        }
        return ans;
    }
};

// hash 存储 nums[d] - nums[c]
class Solution {
public:
    int countQuadruplets(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        unordered_map<int, int> cnt;
        for (int b = n-3; b >= 1; --b) {
            for (int d = b+2; d < n; ++d)
                ++cnt[nums[d] - nums[b+1]];
            for (int a = 0; a < b; ++a) {
                int sum = nums[a] + nums[b];
                if (cnt.count(sum)) ans += cnt[sum];
            }
        }
        return ans;
    }
};