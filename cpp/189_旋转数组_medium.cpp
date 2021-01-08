class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int N = nums.size();
        k %= N;
        reverse(nums, 0, N-1);
        reverse(nums, 0, k-1);
        reverse(nums, k, N-1);
    }
    void reverse(vector<int> &nums, int start, int end){
        while(start<end){
            swap(nums[start], nums[end]);
            start += 1;
            end -= 1;
        }
    }
};