class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> t;
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int mask=0; mask<(1<<n); mask++) {
            t.clear();
            int flag = 1;
            for (int i=0; i<n; i++) {
                if (mask & (1<<i)) {
                    if (i>0 && ((mask>>(i-1)) & 1) == 0 && nums[i] == nums[i-1]) {
                        flag = 0;
                        break;
                    }
                    t.push_back(nums[i]);
                }
            }
            if (flag)
                ans.push_back(t);
        }
        return ans;
    }
};