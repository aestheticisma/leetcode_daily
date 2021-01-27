class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        int left = 0;
        for (int i=0; i<nums.size(); i++){
            if (2*left+nums[i] == total)
                return i;
            left += nums[i];
        }
        return -1;
    }
};