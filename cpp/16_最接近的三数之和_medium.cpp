class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        long ans = INT_MAX;
        int N = nums.size();
        for(int a=0; a<N-2; a++){
            int b = a+1;
            int c = N-1;
            while(b<c){
                int sum3 = nums[a]+nums[b]+nums[c];
                int gap = abs(sum3-target);
                if(gap<abs(ans-target)) ans = sum3;
                if(sum3 == target) return sum3;
                else if(sum3<target){while(b<c&&nums[b]==nums[b+1]) b++; b++;}
                else {while(b<c&&nums[c]==nums[c-1]) c--; c--;}
            }
        }
        return ans;
    }
};