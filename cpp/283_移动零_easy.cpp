class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int N = nums.size();
        int left=0, right=0;
        while(right<N)
        {
            if(nums[right])
            {
                swap(nums[left], nums[right]);
                left++;
            }
            right++;
        }
    }
};

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int N = nums.size();
        int index = 0;
        for(int i=0;i<N;i++)
            if(nums[i])
                nums[index++]=nums[i];
        for(int i=index;i<N;i++)
            nums[i]=0;
    }
};