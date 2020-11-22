// 按部就班 
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums.size()==0)
            return 0;
        for(int i=0; i<nums.size(); i++)
            if(nums[i]==target)
                return i;
        int index=0;
        while(index<nums.size() && nums[index]<target)
            index++;
        return index;
    }
};

// 二分查找
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int N = nums.size();
        if(N==0) return 0;
        int low=0, high=N-1;
        while(low<=high){
            int mid = (low+high)/2;
            if(target==nums[mid])
                return mid;
            else if(target<nums[mid])
                high = mid-1;
            else low = mid+1;
        }
        return low;
    }
};
