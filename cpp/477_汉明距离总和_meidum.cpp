class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for (int i=0; i<30; i++) {
            int cnt = 0;
            for (auto num : nums)
                if ((num >> i) & 1)
                    cnt++;
            ans += cnt * (n - cnt);
        }
        return ans;
    }
};