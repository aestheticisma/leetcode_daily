class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ret(n, -1);
        stack<int> f;
        for (int i=0; i<2*n-1; i++) {
            while (!f.empty() && nums[f.top()] < nums[i%n]) {
                ret[f.top()] = nums[i%n];
                f.pop();
            }
            f.push(i%n);
        }
        return ret;
    }
};