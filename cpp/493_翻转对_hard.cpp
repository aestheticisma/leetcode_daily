class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int N = nums.size();
        if(N<2) return 0;
        return merge_count(nums, 0, N-1);
    }
    int merge_count(vector<int> &nums, int left, int right)
    {
        if(left==right)
            return 0;
        int mid = (left+right)/2;
        int res_left = merge_count(nums, left, mid);
        int res_right = merge_count(nums, mid+1, right);
        int res = res_left + res_right;
        int i = left;
        int j = mid+1;
        while(i<=mid){
            while(j<=right && (long long)nums[i]>2*(long long)nums[j]) j++;
            res += j-mid-1;
            i++;
        }
        vector<int> sorted(right-left+1);
        int p1 = left, p2 = mid+1, p = 0;
        while(p1<=mid || p2<=right){
            if(p1>mid)
                sorted[p++] = nums[p2++];
            else if(p2>right)
                sorted[p++] = nums[p1++];
            else
                if(nums[p1]>=nums[p2])
                    sorted[p++] = nums[p2++];
                else 
                    sorted[p++] = nums[p1++];
        }
        for(int i=0; i<sorted.size(); i++)
            nums[left+i] = sorted[i];
        return res;
    }
};