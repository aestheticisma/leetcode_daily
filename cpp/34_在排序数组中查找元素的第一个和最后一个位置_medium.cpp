// 法1:
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int N = nums.size();
        if(N<1)
            return {-1, -1};
        if(nums[0]>target)
            return {-1, -1};
        int left = 0, right = N-1;
        int minPos = N, maxPos = -1;
        while(left<=right){
            int mid = (left+right)/2;
            if(nums[mid]==target){
                minPos = min(minPos, mid);
                maxPos = max(maxPos, mid);
                while(minPos-1>=0 && nums[minPos-1]==target) minPos--;
                while(maxPos+1<N && nums[maxPos+1]==target) maxPos++;
                return {minPos, maxPos};
            }
            else if(nums[mid]<target)
                left = mid+1;
            else right = mid-1;
        }
        return {-1, -1};
    }
};

// 法2:
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int N = nums.size();
        if(N<1)
            return {-1, -1};
        if(nums[0]>target)
            return {-1, -1};
        int left = binarysearch(nums, target, true);
        int right = binarysearch(nums, target, false)-1;
        if(left<=right && right<N && nums[left]==target && nums[right]==target)
            return {left, right};
        else return {-1, -1};
    }
    int binarysearch(vector<int> &nums, int target, bool low){
        int left = 0, right = nums.size()-1;
        int ans = nums.size();
        while(left<=right){
            int mid = (left+right)/2;
            if(nums[mid]>target || (low && nums[mid]>=target)){
                right = mid - 1;
                ans = mid;
            }
            else left = mid + 1;
        }
        return ans;
    }
};