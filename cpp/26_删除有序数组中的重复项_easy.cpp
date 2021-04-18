class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int j = 1;
        if (n <= 1) return n;
        for (int i=1; i<n; i++)
            if (nums[i] != nums[j-1])
                nums[j++] = nums[i];
        return j;
    }
};