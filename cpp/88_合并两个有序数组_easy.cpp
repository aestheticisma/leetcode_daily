class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int tail = m + n - 1;
        int p1 = m - 1, p2 = n - 1;
        while (p1 >= 0 || p2 >= 0)
            if (p1 == -1)
                nums1[tail--] = nums2[p2--];
            else if (p2 == -1)
                nums1[tail--] = nums1[p1--];
            else if (nums1[p1] >= nums2[p2])
                nums1[tail--] = nums1[p1--];
            else
                nums1[tail--] = nums2[p2--];
    }
};