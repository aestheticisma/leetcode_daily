class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int length = nums.size();
        long long x = 1;
        int index = 0;
        int ans = 0;
        while(x<=n)
            if(index < length && nums[index] < x+1){
                x += nums[index];
                index++;
            }
            else{
                x <<= 1;
                ans ++;
            }
        return ans;
    }
};