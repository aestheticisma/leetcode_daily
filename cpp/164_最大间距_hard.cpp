//要求线性时间复杂度，因此采用基数排序

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size()<2)
            return 0;
        int N = nums.size();
        int max_num = *max_element(nums.begin(), nums.end());
        vector<int> buff(N);
        int exp = 1;
        while(max_num>=exp){
            vector<int> cnt(10, 0);
            for(int i=0; i<N; i++){
                int digit = (nums[i]/exp) % 10;
                cnt[digit]++;
            }
            for(int i=0; i<10-1; i++)
                cnt[i+1] += cnt[i];
            for(int i=N-1; i>-1; i--){
                int digit = (nums[i]/exp) % 10;
                buff[cnt[digit]-1] = nums[i];
                cnt[digit]--;
            }
            copy(buff.begin(), buff.end(), nums.begin());
            exp *= 10;
        }
        int res = INT_MIN;
        for(int i=0; i<N-1; i++)
            res = max(nums[i+1]-nums[i], res);
        return res;
    }
};