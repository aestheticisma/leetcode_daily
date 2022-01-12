class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        if (nums.size() == 1) return 0;
        int firstMaxIndex = nums[0] > nums[1] ? 0 : 1;
        int secondMaxIndex = nums[0] > nums[1] ? 1 : 0;
        for (int i = 2; i < nums.size(); ++i) {
            if (nums[i] > nums[firstMaxIndex]) {
                secondMaxIndex = firstMaxIndex;
                firstMaxIndex = i;
            }
            else if (nums[i] > nums[secondMaxIndex]) secondMaxIndex = i;
        }
        return nums[firstMaxIndex] >= nums[secondMaxIndex] * 2 ? firstMaxIndex : -1;
    }
};